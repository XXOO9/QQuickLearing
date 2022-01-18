# Qt使用多线程

## 1.墙裂建议不使用继承于QThread的这个方法，除非子线程干的事情简单的批爆。

## 2.使用继承于QOBject的类

### 使用方法:

>### 1.定义一个将要放入子线程的类work
>
>### 2.如果是在绑定信号槽之前将work类移动到了movetoThread中的话，在绑定信号槽的时候就不用写上第五个参数(虽然不知道为啥,但是还是挺好奇的)
>
>#### work.h
>
>```c++
>class work : public QObject
>{
>Q_OBJECT
>public:
>explicit CFunction(QObject *parent = nullptr);
>~CFunction();
>signals:
>void sigFuncDone();
>
>public slots:
>void display(); //在子线程中的复杂耗时操作
>
>void stopDisplay(); //控制停止复杂好事操作的接口
>
>private:
>bool       m_isRunning{ true }; //复杂耗时操作的运行标志位
>QMutex     m_mutex;		// 线程同步锁
>};
>```
>
>#### work.cpp
>
>```c++
>
>CFunction::CFunction(QObject *parent) : QObject(parent)
>{
>
>}
>
>CFunction::~CFunction()
>{
>
>}
>
>void CFunction::display()
>{
>static int i = 0;
>while ( true ) {
>   m_mutex.lock();
>   if( !m_isRunning || i > 10 ){
>       m_mutex.unlock();
>       break;
>   }
>   m_mutex.unlock();
>   i++;
>   qDebug() << "this is CFunction:: " << QThread::currentThreadId();
>   QThread::msleep( 500 );
>}
>qDebug() << "end of display...";
>}
>
>void CFunction::stopDisplay()
>{
>m_mutex.lock();
>m_isRunning = false;
>m_mutex.unlock();
>}
>
>```
>
>#### worker.h
>
>```c++
>class CWorkThread : public QObject
>{
>    Q_OBJECT
>public:
>    explicit CWorkThread(QObject *parent = nullptr);
>    ~CWorkThread();
>
>    void init();
>
>    void initConnection();
>
>    void startDisplay();
>
>signals:
>    void sigStartDisplay(); //多线程之间通过信号槽来通信
>
>public slots:
>
>private:
>    CFunction   m_func;
>    QThread     *m_pWorkThread; //work实际所在的线程
>};
>```
>
>#### worker.cpp
>
>```c++
>#include "CWorkThread.h"
>
>CWorkThread::CWorkThread(QObject *parent) : QObject(parent), m_pWorkThread( nullptr )
>{
>    init();
>
>    startDisplay();
>}
>
>CWorkThread::~CWorkThread()
>{
>    if( m_pWorkThread->isRunning() ){
>        qDebug() << "shut down while thread is still running...";
>        m_func.stopDisplay();
>        m_pWorkThread->quit();
>        bool ok = m_pWorkThread->wait(); //据说如果是堆分配的内存，只用绑定QThread的Finished信号和QObject的delelater槽函数,让其自杀
>        qDebug() << "ret = " << ok;
>    }else{
>        qDebug() << "shut down while thread is not running...";
>    }
>}
>
>void CWorkThread::init()
>{
>    m_pWorkThread = new QThread();
>    m_func.moveToThread( m_pWorkThread );
>
>    initConnection();
>    m_pWorkThread->start();
>}
>
>void CWorkThread::initConnection()
>{
>    connect( this, &CWorkThread::sigStartDisplay, &m_func, &CFunction::display );
>    connect( &m_func, &CFunction::sigFuncDone, m_pWorkThread, &QThread::quit );//这一行不是必须的
>    connect( m_pWorkThread, &QThread::finished, this, &QObject::deleteLater );
>    connect( m_pWorkThread, &QThread::finished, m_pWorkThread, &QObject::deleteLater );
>}
>
>void CWorkThread::startDisplay()
>{
>    qDebug() << "start display, ThreadID = " << QThread::currentThreadId();
>    emit sigStartDisplay();
>}
>
>```
>
>




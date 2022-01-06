#include "CMainControl.h"

CMainControl::CMainControl(int argc, char **argv, QObject *parent ) : QObject( parent ), m_pGuiApp( nullptr )
  ,m_pViewEngine( nullptr )
{
    initCore( argc, argv );
    initUI();
    m_DevCameraControler.openCamera();
    m_pGuiApp->exec();
}

CMainControl::~CMainControl()
{
    if( nullptr != m_pGuiApp ){
        delete m_pGuiApp;
        m_pGuiApp = nullptr;
    }
}

void CMainControl::init()
{

}

void CMainControl::initCore(int argc, char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    m_pGuiApp = new QGuiApplication( argc, argv );
    m_pViewEngine = new QQmlApplicationEngine( this );
}

void CMainControl::initUI()
{
    m_pViewEngine->addImageProvider( QLatin1String("faceView"), m_DevCameraControler.imgProvider() );
    m_pViewEngine->rootContext()->setContextProperty( QLatin1String("CameraControl"), &m_DevCameraControler );

    //最好是把上下文和imageprovider注册好了之后再加载url，不然终端里面会报错，但是貌似并不影响正常运行，目前尚未调查清楚，暂时还是先设置好了在load url
    m_pViewEngine->load( m_qmlUrl );

}

void CMainControl::initConnection()
{
    connect( m_pViewEngine, &QQmlApplicationEngine::objectCreated, this, &CMainControl::onViewEngineCreateFinished,
             Qt::QueuedConnection );
}

void CMainControl::onViewEngineCreateFinished( QObject *object, const QUrl &url )
{
    //如果qml对象为空或者加载的qml 的url跟预期设置的不同，则退出程序
    if( !object && (url == m_qmlUrl) ){
        QCoreApplication::exit( -1 );
    }
}

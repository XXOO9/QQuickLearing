TEMPLATE = subdirs


#CONFIG( debug, debug | release ){
#        DESTDIR     = $$PWD/bin/debug
#}else
#{
#        DESTDIR     = $$PWD/bin/release
#}

#MOC_DIR = temp/moc
#RCC_DIR = temp/rcc
#UI_DIR = temp/ui
#OBJECTS_DIR = temp/obj


SUBDIRS += \
#    QQuickControls         #####    qml 自定义控件demo
#    ffmpeg               #### ffmpeg 学习例子
#    DesignModel         ##### 设计模式
#    NetWorkModel   ###网络 模块
#    SqlDemo             #####   数据库sql操作( 批量插入GECG的假数据 )
#    ProcessMonit        ### 进程控制( 程序升级Demo )
#    CreateDmpFile       ## 创建Dump文件
#    QSqlTableModelDemo  ##据说一次最多只能查询256条数据，故暂时不研究这个
#    unitTest     \              ## 单元测试
#    EnumWithQuick \
#    RightMouseClicked
#    MyTableView                   \
#    CustQQuickVirtualKeyBoard      \
#    CustDialog                      \
#    CustListView
#    DynamicCreateComponent
#    CustPopup
#    ShowOpenCVFrame
#    CustStackView
#    CTestShardLibrary \
#    GoogleTest
#     CustComboBox       ##### 自定义的下拉框( 可移植 )
#    MultiThreadDemo \
#    CMultiThreadDemo
#    CustControls
#    ProcessChat
#    ProcessCommunication
#    QTimerDemo \
#    widgetSignPainter
#    SingletonHttpClicentThread
#    judgeDebugModel
#    SignalSync
#    CustProgressBar
#    UsageCfile
#    TableView_Version_2
#    CustLoading
#    QDateTimeIntervalDemo
#    EChartDemo
#    RegularExpressionDemo
#    QtTestFrameWork
#    gmy
#    DemoRadioBtn
 \#    QThreadControl
    QCustomPlot

#    QDebugLog  ### qDebug 重定向到日志文件中
#    QmlFunctionCallback ###  C++回调qml函数( 感觉 用处不大 )
#    DemoQMLUI
#    Demo
#    DemoJsModelTableView
#    DemoTextCode
#    DemoGrid
#    DemoTabView
#    DemoCircle
#    DemoQCustomplot
#    DemoVideoPlayer
#    DemoTextDisplayDifferentStyleText
#    DemoChartjs
#    DemoTreeView           #not yet
#    DemoChart
#    FileAutoBackup
#    CusWidgetControl
#    JavaScriptDemos            ##### 一些关于JS的Demo 例如  字符串函数
#    QSqlTableModelDemo
#    opencvDemo     ############   opencv 例子
#    callQmlFuncsInCpp
#    DemoModelFilter     ##数据模型排序过滤
#    DemoEnumVal2KeyString  ## 枚举转字符串       包含了注册枚举类型到qml
#    QPainterDemo        ##  可以参考 opencv例子
#    CusTools
#    QQuickRender        #### qml 渲染
#    Algorithm       ###算法小例子


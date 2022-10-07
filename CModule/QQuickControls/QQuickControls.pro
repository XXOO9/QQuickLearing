

#CONFIG( debug, debug | release ){
#        DESTDIR     = $$PWD/debug
#}else
#{
#        DESTDIR     = $$PWD/release
#}

TEMPLATE = subdirs


SUBDIRS += \
#    CusGridView        #### 自定义网格控件
#    BarView \
#    CusTableView \ ### 自定义表格控件
#    DemoFlowLayout ### 自定义流式布局
#    CusDynamicCreateComponent       ##管理 动态控件
#    DemoFlowLayout
#    CusDynamicCreateCmp
#    WorkScript ## qml 线程， 貌似没啥用
#    DemoDrag    ##  控件拖动demo
#    DemoPassParameters     #### qml和 c++ 传参测试
#    KeyEventDemo
#    CusMenu



#CONFIG( debug, debug | release ){
#        DESTDIR     = $$PWD/debug
#}else
#{
#        DESTDIR     = $$PWD/release
#}

TEMPLATE = subdirs


SUBDIRS += \
#    CusGridView                     #### 自定义网格控件
#    BarView \
#    CusTableView \                  ### 自定义表格控件
#    DemoFlowLayout                  ### 自定义流式布局
#    CusDynamicCreateComponent       ##管理 动态控件
#    DemoFlowLayout
#    CusDynamicCreateCmp
#    WorkScript                      ## qml 线程， 貌似没啥用
#    DemoDrag                        ##  控件拖动demo
#    DemoPassParameters              #### qml和 c++ 传参测试
#    KeyEventDemo                    ###  键盘按键测试
#    CusMenu                         ##  自定义菜单（未实现）
#     DemoStackVeiwAndStackLayout      ###  自定义堆栈视图和堆栈布局
 \#    DemoButtonGroup
    CusCalendar

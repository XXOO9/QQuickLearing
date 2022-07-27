

#CONFIG( debug, debug | release ){
#        DESTDIR     = $$PWD/debug
#}else
#{
#        DESTDIR     = $$PWD/release
#}

TEMPLATE = subdirs


SUBDIRS += \
#    CusGridView
#    BarView \
#    CusTableView \
 \#DemoFlowLayout
    CusDynamicCreateComponent
#DemoFlowLayout
#    CusDynamicCreateCmp
#    WorkScript ## qml 线程， 貌似没啥用
#    DemoDrag

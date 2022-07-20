

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

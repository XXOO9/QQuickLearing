TEMPLATE = subdirs

#CONFIG( debug, debug | release ){
#        DESTDIR     = $$PWD/bin/debug
#        MOC_DIR     = $$PWD/bin/debug/temp/moc
#        RCC_DIR     = $$PWD/bin/debug/temp/rcc
#        UI_DIR      = $$PWD/bin/debug/temp/ui
#        OBJECTS_DIR = $$PWD/bin/debug/temp/obj
#}else
#{
#        DESTDIR     = $$PWD/bin/release
#        MOC_DIR     = $$PWD/bin/release/temp/moc
#        RCC_DIR     = $$PWD/bin/release/temp/rcc
#        UI_DIR      = $$PWD/bin/release/temp/ui
#        OBJECTS_DIR = $$PWD/bin/release/temp/obj
#}

SUBDIRS += QCustomPlot/QCustomPlot.pro  \
           QCustomplotWidget/QCustomplotWidget.pro  \
           DemoQCustomplot/DemoQCustomplot.pro


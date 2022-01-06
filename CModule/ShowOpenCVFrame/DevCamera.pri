
INCLUDEPATH += $$PWD/thirdParty/opencv/include
HEADERS += \
    $$PWD/CDevCamera.h  \
          CImageProvider.h  \
          CDevCameraControl.h

SOURCES += \
    $$PWD/CDevCamera.cpp    \
          CImageProvider.cpp \
          CDevCameraControl.cpp \




CONFIG( debug, debug | release ){
        LIBS += -L$$PWD/thirdParty/opencv/lib -lopencv_world341d
}

CONFIG( release, debug | release ){
        LIBS += -L$$PWD/thirdParty/opencv/lib -lopencv_world341
}

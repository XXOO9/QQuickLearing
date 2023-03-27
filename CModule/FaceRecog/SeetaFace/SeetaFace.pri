HEADERS += \
    $$PWD/CFaceRecogDemo.h

SOURCES += \
    $$PWD/CFaceRecogDemo.cpp

INCLUDEPATH += $$PWD/../thirdParty/SeetaFace/FaceFaceDetector/include
INCLUDEPATH += $$PWD/../thirdParty/SeetaFace/FaceLandmarker/include
INCLUDEPATH += $$PWD/../thirdParty/SeetaFace/FaceRecognizer/include
INCLUDEPATH += $$PWD/../thirdParty/SeetaFace/QualityAssessor/include
INCLUDEPATH += $$PWD/../thirdParty/openCV341/include

CONFIG( debug, debug | release ){
    LIBS += -L$$PWD/../thirdParty/SeetaFace/lib/Debug -lSeetaFaceDetector_d     \
                                                      -lSeetaFaceLandmarker_d   \
                                                      -lSeetaFaceRecognizer_d   \
                                                      -SeetaFaceTracker_d       \
                                                      -SeetaQualityAssessor_d   \

    LIBS += -L$$PWD/../thirdParty/openCV341/lib/ -lopencv_world341d
    LIBS += -L$$PWD/../thirdParty/openCV341/bin/ -lopencv_world341d
}

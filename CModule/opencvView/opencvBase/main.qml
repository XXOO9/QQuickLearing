import QtQuick 2.12
import QtQuick.Window 2.12
import CameraDisplay 1.0
Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Hello World")

    CameraFrameDisplay{
        anchors.fill: parent
    }


}

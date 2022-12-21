import QtQuick 2.12
import QtQuick.Window 2.12
import CVideoFrameProvider 1.0
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CVideoFrameProvider{
        id: src
    }


    VideoOutput{
        width: 650
        height: width
        anchors.centerIn: parent
        source: src
    }

    Button{
        onClicked: src.start()
    }
}

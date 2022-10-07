import QtQuick 2.12
import QtQuick.Window 2.12
import VideoDecoder 1.0
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    VideoDecoder{
        id: videoDecoder
    }

    Button{
        onClicked: videoDecoder.start()
    }
}

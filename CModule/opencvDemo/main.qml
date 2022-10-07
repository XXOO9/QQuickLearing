import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12
import videoFrameProvider 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    FrameProvider{
        anchors.fill: parent

        Rectangle{
            width: 150
            height: width
            radius: width / 2
            color: "red"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: console.log( "clicked..." )
        }
    }

}

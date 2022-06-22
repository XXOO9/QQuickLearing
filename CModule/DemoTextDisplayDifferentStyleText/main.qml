import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Text {
        color: "black"
        font.pixelSize: 50
        text: "I'm green" + '<font color="#0BB664" size="1">绿色</font>'
        anchors.centerIn: parent
    }
}

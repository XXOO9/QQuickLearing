import QtQuick 2.12
import QtQuick.Window 2.12
import CustPlot 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12

Window {
    id: root
    visible: true
    width: Screen.width
    height: Screen.height
    title: qsTr("Hello World")

//    flags: Qt.FramelessWindowHint | Qt.Window

    SinglePlot{
        anchors.centerIn: parent
    }

//    ManyPlots{
//        anchors.fill: parent
//    }
}

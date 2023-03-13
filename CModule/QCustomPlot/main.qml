import QtQuick 2.12
import QtQuick.Window 2.12
import CustPlot 1.0
import QtQuick 2.12

Window {
    id: root
    visible: true
    width: Screen.width
    height: Screen.height
    title: qsTr("Hello World")

    flags: Qt.FramelessWindowHint | Qt.Window

    property real num1: 4
    property real num2: 4

    CustPlotItem{
        width: 300
        height: 900
        anchors.centerIn: parent
    }

//    GridView{
//        id: gridView
//        anchors.fill: parent
//        cellWidth: root.width / num1 * 0.99
//        cellHeight: root.height / num2
//        model: 16
//        delegate: CustPlotItem{
//            Component.onCompleted: {
//            }

//            width: root.width / num1 * 0.99
//            height: root.height / num2
//        }
//    }
}

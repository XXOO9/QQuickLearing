import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "."

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CustComboBox{
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    Cust2{
        anchors.right: parent.right
        anchors.rightMargin: 20
    }
}

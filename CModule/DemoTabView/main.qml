import QtQuick 2.15
import QtQuick.Window 2.15
import "."

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Hello World")

    CusTabView{
        anchors.centerIn: parent
    }
}

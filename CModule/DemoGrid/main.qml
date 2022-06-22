import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 900
    height: 900
    visible: true
    title: qsTr("Hello World")

    CusGridView{
        anchors.centerIn: parent
    }
}

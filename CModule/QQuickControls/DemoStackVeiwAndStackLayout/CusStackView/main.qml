import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 900
    height: width
    title: qsTr("Hello World")

    CusStackView{
        anchors.centerIn: parent
    }
}

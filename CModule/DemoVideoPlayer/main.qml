import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    width: 900
    height: 800
    visible: true
    title: qsTr("Hello World")

    CusVideoPlayer{
        anchors.centerIn: parent
    }
}

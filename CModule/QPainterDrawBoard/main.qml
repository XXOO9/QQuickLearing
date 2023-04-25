import QtQuick 2.12
import QtQuick.Window 2.12
import CusPainter 1.0
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Painter{
        id: painter
        width: 200
        height: width
        anchors.centerIn: parent
        z: 10
    }

    Row{
        Button{
            text: '保存'
            onClicked: painter.save( painter )
        }
        Button{
            text: '清除'
            onClicked: painter.clear()
        }
    }



}

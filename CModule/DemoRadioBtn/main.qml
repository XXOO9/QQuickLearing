import QtQuick 2.12
import QtQuick.Window 2.12
import  QtQuick.Controls 2.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Row{
        Repeater{
            id: repeter
            model: 2
            RadioButton{
                width: 150
                height: width
                checkable: false
                background: Rectangle{
                    anchors.fill: parent
                    radius: width / 2
                    color: "gray"
                }
            }
        }
    }

    Button{
        id: btn1
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: {
            repeter.itemAt( 1 ).checkable = true
        }
    }

    Button{
        id: btn2
        anchors.right: btn1.left
        anchors.bottom: parent.bottom
        onClicked: {
            repeter.itemAt( 0 ).checkable = true
        }
    }





}

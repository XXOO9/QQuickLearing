import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property real count: 0.1

    Component.onCompleted: {
    }

    Button{
        id: btn1
        text: "0.0"
        onClicked: {
            cust.setLoadPersent( 0 )
        }
    }

    Button{
        id: btn2
        text: "0.2"
        anchors.left: btn1.right
        onClicked: {
            cust.setLoadPersent( 0.2 )
        }
    }

    Button{
        id: btn3
        text: "0.8"
        anchors.left: btn2.right
        onClicked: {
            cust.setLoadPersent( 0.8 )
        }
    }
    CustProgressBar{
        id: cust
        anchors.centerIn: parent
    }
}

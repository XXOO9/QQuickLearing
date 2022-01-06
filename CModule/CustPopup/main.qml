import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        onClicked: {
            pop.open()
        }
    }

    Popup{
        id:pop
        width: 300
        height: width
        modal: true
        anchors.centerIn: parent
        contentItem: Rectangle{
            width: 300
            height: width
            anchors.centerIn: parent
            color: "red"
        }

        onClosed: {
            console.log( "closed" )
        }
    }

}

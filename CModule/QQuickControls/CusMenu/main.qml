import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        onClicked:{
            menu.x = mouse.x
            menu.y = mouse.y
            menu.open()

//            console.log( "datas = " + m )
        }
    }

    CusMenu{
        id: menu
    }
}

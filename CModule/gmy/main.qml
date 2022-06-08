import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./ProjectCommonDefine.js" as Config
import "./ViewControler.js" as ViewControler

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    Component.onCompleted: {
        ViewControler.turnAdminPage( mainLoader )
    }



    Loader{
        id: mainLoader
        anchors.fill: parent
    }

//    TextField{
//        id: textInput
//        width: 400
//        height: 200
//        anchors.top: textRecv.bottom
//        anchors.topMargin: 150

//    }

//    TextField{
//        id: textRecv
//        width: 400
//        height: 200
//        anchors.top: parent.top
//    }

//    Button{
//        id: btn1
//        text: "连接"
//        anchors.left: parent.left
//        anchors.bottom: parent.bottom
//        onClicked: {
//            ViewManager.connectedToServer()
//        }
//    }

//    Button{
//        id: btn2
//        text: "发送"
//        anchors.right: textInput.right
//        anchors.top: textInput.bottom
//        onClicked: {
//            let content = textInput.text
//            textInput.clear()
//            ViewManager.sendMsg( content )
//        }
//    }
}

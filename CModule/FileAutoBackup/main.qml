import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3
import Qt.labs.platform 1.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: {
        let tmp = "abcdefg";
        tmp = tmp.substring( 2 )
        console.log( tmp )
    }


    Button{
        id: btn1
        text: "选择路径"
        anchors{ top: textInput.bottom}
        onClicked: folderDialog.open()
    }

    Button{
        id: btn2
        text: "选择文件"
        anchors{ left: btn1.right; verticalCenter: btn1.verticalCenter }

        onClicked: fileDialog.open()
    }


    Button{
        id:btn3
        text: "确定"
        anchors{ left: btn2.right; verticalCenter: btn2.verticalCenter }
        onClicked: InterAction.appendPath( textInput.text )
    }

    Button{
        id: btn4
        text: "手动备份"
        anchors{ left: btn3.right; verticalCenter: btn2.verticalCenter }
        onClicked: InterAction.manualBackup()
    }

    TextField{
        id: textInput
        width: 400
        height: 50
        background: Rectangle{
            anchors.fill: parent
            border.color: "red"
        }
    }

    FileDialog{
        id: fileDialog

        onAccepted: {
            textInput.text = String( fileDialog.currentFile ).substring( 8 )
            InterAction.appendFile( textInput.text )
        }
    }

    FolderDialog{
        id: folderDialog


        onAccepted: {
            textInput.text = String( folderDialog.currentFolder ).substring( 8 )
            InterAction.appendPath( textInput.text )
        }
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Rectangle{
        anchors.fill: parent
        color: 'red'
    }

    Column{
        Button{
            text: 'check'
            onClicked: check()
        }
        Button{
            text: 'update'
            onClicked: runupdate()
        }
        Button{
            text: 'close'
            onClicked: CInterAction.closeProcess()
        }
        Button{
            text: 'run'
            onClicked: CInterAction.runTargetProcess()
        }

        Button{
            text: 'isTargetProcessRunning'
        }
        Button{
            text: 'biubiubiu~'
            onClicked: {
                runupdate()
                CInterAction.runTargetProcess()
            }
        }
    }

    Popup{
        id: pop
        width: 150
        height: width
        modal: true
        padding: 0
//        closePolicy: Popup.NoAutoClose
        Rectangle{
            anchors.fill: parent
            color: 'blue'
        }
    }


    function check(){
        let ok = CInterAction.checkExistedUpdateFiles()

        if( ok ){
            pop.open()
        }
    }

    function runupdate(){
        console.log( 'func update...' )
        CInterAction.copyNewExecuteToTargetDir( "./" )
    }

    function isTargetProcessRunning(){

    }

}

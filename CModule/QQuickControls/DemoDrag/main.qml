import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    visible: true
    width: 900
    height: 900
    title: qsTr("Hello World")

    ListModel{
        id: devListModel
    }

    Button{

    }


    CusDropArea_ListView{
        anchors{ left: parent.left; verticalCenter: parent.verticalCenter }
    }

    CusDragArea_ListView{
        devModel: devListModel
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    function generateTestDev(){
        for( let i = 0; i < 16; i++ ){
            devListModel.append( { "devNumber": "dev_" + i, "bindState": false, "bindUserNum": "-1" } )
        }
    }

    function reSetDevElement( devNum ){
        for( let i = 0; i < devListModel.count; i++ ){
            if( devListModel.get( i ).devNumber === devNum ){
                devListModel.get( i ).bindState = false
                return
            }
        }

        console.log( "没这个人..." )
    }




    /*
    ListModel{
        id:list
        objectName: "list"
        ListElement{ index: 0 }
        ListElement{ index: 1 }
        ListElement{ index: 2 }
    }

    ListView{
        width: 150
        height: 800

        spacing: 10
        anchors{ top: parent.top; left: parent.left }
        model: list
        delegate: listDelegate

        anchors.centerIn: parent
    }

    Component{
        id: listDelegate
        Item {
            id: name
            CusDropArea{

            }
        }
    }

    CusDragRect{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
    }
    */



}

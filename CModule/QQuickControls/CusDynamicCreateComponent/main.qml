import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import  "./Assistant.js" as Assistant


ApplicationWindow {
    id: mainn
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var obj

    Item {
        id: root
    }

    Button{
        id: btn1
        onClicked:  obj = Assistant.createObj( root, mainRect, { "anchors.top": root.bottom, color: "yellow" } )

        //还玩不转这种方法
//        onClicked: obj = Assistant.createObjFromUrl( "qrc:/CusRect.qml", root )
    }

    Button{
        id: btn2
        anchors.left: btn1.right
        onClicked: {
            console.log( typeof( obj ) )
            obj.color = "red"
        }
    }

    Button{
        id: btn3
        anchors.left: btn2.right
        onClicked: obj.destroy()
    }



    Component{
        id: mainRect
        Rectangle{
            width: 200
            height: width
            color: "green"
        }
    }

    function createObj(){
        mainRect.createObject( root, { "anchors.top": btn.bottom, color: "red" } )
    }
}

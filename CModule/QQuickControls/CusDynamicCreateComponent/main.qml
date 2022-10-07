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

    property var objMap: new Map()

    Component.onCompleted: {
        testMap()
    }

    Item {
        id: root
    }

    Button{
        id: btn1
//        onClicked:  obj = Assistant.createObj( root, mainRect, { "anchors.top": root.bottom, color: "yellow" } )

        onClicked: {
            obj = mainRect.createObject( mainn, { "anchors.centerIn": mainn, color: "yellow" } )
            objMap.set( "rect", obj )

            //不能转换为 QMap
            InterAction.testVariantMap( objMap )
        }

        //还玩不转这种方法----->  不推荐
        //        onClicked: obj = Assistant.createObjFromUrl( "qrc:/CusRect.qml", root )
    }

    Button{
        id: btn2
        anchors.left: btn1.right
        onClicked: {
            if( objMap.has( "rect" ) ){
                objMap.get( "rect" ).color = "red"
            }
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

            Component.onCompleted: {
                console.log( "going to construction..." )
            }

            Component.onDestruction: {
                console.log( "going to destruction..." )
            }
            width: 150
            height: width
            color: "green"
        }

    }

    function testMap(){
        let tmpMap = new Map()

        tmpMap.set( "1", "A" )
        tmpMap.set( "2", "B" )
        tmpMap.set( "3", "C" )
        tmpMap.set( "4", "D" )
        tmpMap.set( "1", "K" )

        for( let ele of tmpMap ){
            console.log( "ele = " + ele )
        }

        console.log( "size = " + tmpMap.size )
        console.log( "has = " + tmpMap.has( "1" ) )
        console.log( "has = " + tmpMap.keys().size )
    }
}

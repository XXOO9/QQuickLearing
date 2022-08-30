import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property int countt: 0

    Component.onCompleted: {
        for( let i = 0; i < 500000; i++ ){
            list.append( { "roleB": "roleA_" + i } )
        }

        console.log( "qml config finished..." )
    }

    Text {
        id: name
        text: countt
        z:5
    }

    ListModel{
        id: list
    }

    Timer{
        running: true
        repeat: true
        interval: 200

        onTriggered: countt++
    }

//    ListView{
//        width: 400
//        height: width
//        spacing: 10


//        model: list
////        model: DataModel

//        delegate: Rectangle{
//            width: 50
//            height: width
//            color: "gray"

//            Text {
//                text: roleB
//                color: "white"
//            }
//        }
//    }

    CusWorkScript{

    }
}

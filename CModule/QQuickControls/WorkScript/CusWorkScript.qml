import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{
    width: 400
    height: width

    color: "red"


    ListModel{
        id: listModel

//        ListElement{ name: "name" }
    }

    WorkerScript{

        id: worker
        source: "qrc:/wokerThread.js"

        onMessage: function ( msg ){
            console.log( "listModel count = " + listModel.count )
        }

    }

    MouseArea{
        anchors.fill: parent

        onClicked: {
            console.log( "clicked..." )
            let srcData = Interaction.getData()
            console.log( "WDNMD" )
            worker.sendMessage( { "tarModel": listModel, "dataSrc": srcData } )
            console.log( "send msg..." )
        }
    }


}



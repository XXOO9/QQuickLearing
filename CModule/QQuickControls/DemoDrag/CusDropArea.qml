import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root
    implicitWidth: 150; implicitHeight: width
    Component.onCompleted: {
        console.log( "1111:  " +  dropAera.children[0].width )
    }

    DropArea{
        id: dropAera
        keys: [ "WDNMD" ]
        anchors.fill: parent

        Rectangle{
            id: dropRectArea
            color: "gray"
            anchors.fill: parent
            states: State{
                when: dropAera.containsDrag
                PropertyChanges {
                    target: dropRectArea
                    color: "green"
                }
            }
        }



        onChildrenChanged: {
            console.log( children.length )
        }

        onContainsDragChanged: {
            let obj = drag.source
            console.log( "drag.source = " + obj )

            if( obj !== null ){
                console.log( "width = " + obj.width )
            }


        }

    }
}

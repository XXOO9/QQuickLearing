import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: root
    implicitWidth: 80
    implicitHeight: width

    MouseArea {
        id: dragArea
        objectName: "mouseObj"
        anchors.fill: parent
        drag.target: drapRect

        onReleased: {
            parent = ( drapRect.Drag.target === null ? root : drapRect.Drag.target )
//            console.log( "拖拽区域的parent = " + parent )
        }

        onParentChanged: {
            if( parent === root ){
                drapRect.color = "red"
                drapRect.radius = 0
            }else{
                drapRect.color = "yellow"
                drapRect.radius = width / 2
            }
        }

        states: State{
            when: dragArea.drag.active
            ParentChange { target: drapRect; parent: root }
            AnchorChanges{ target: drapRect; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
        }

        Rectangle {
            id: drapRect
            width: 80; height: width
            color: "red"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Drag.active: dragArea.drag.active
            Drag.keys: [ "WDNMD" ]

//            onParentChanged: {
//                console.log( "parent = " + parent )
//                if( parent === root ){
//                    console.log( "是root " )
//                }else{
//                    console.log( "不是 root" )
//                }
//            }
        }
    }

    Rectangle{
        anchors.fill: parent
        color: "black"
        z:5
    }


}



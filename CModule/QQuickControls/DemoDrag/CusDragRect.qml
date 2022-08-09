import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: root
    implicitWidth: 80; implicitHeight: width

    Rectangle{
        anchors.fill: parent
        color: "black"
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: drapRect

        onReleased: {
            parent = ( drapRect.Drag.target === null ? root : drapRect.Drag.target )
            console.log( "drapArea parent = " + parent )
        }

        states: State{
            when: dragArea.drag.active
            ParentChange { target: drapRect; parent: root }
            AnchorChanges{ target: drapRect; anchors.top: undefined; anchors.horizontalCenter: undefined }
        }

        Rectangle {
            id: drapRect
            width: 80; height: width
            color: "red"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Drag.active: dragArea.drag.active
            Drag.keys: [ "WDNMD" ]
        }
    }






}



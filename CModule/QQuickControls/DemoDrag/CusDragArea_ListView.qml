import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 200
    height: 800

    property alias devModel: devListView.model

    Component.onCompleted: {
        generateTestDev()
    }

    Rectangle{
        id: bkgRect
        anchors.fill: parent
        color: "gray"
    }


    ListView{
        id: devListView
        width: parent.width
        height: parent.height * 0.5
        anchors.centerIn: parent
        model: devListModel
        delegate: devDelegate
        spacing: 10
    }

    Component{
        id: devDelegate
        MouseArea{
            id: mouseArea
            width: root.width
            height: 100

            enabled: !bindState
            drag.target: dragRect

            //显式的调用 target的 Drag.drop() 才能在drop 区域接收到 on
            onReleased: dragRect.Drag.drop()

            Rectangle{
                id: dragRect

                property bool devBindFlag: bindState

                width: mouseArea.width
                height: mouseArea.height
                anchors{ verticalCenter: parent.verticalCenter; horizontalCenter: parent.horizontalCenter }
                color: "cadetblue"
                z: bindState ? 5 : 10

                Text {
                    text: devNumber
                    anchors.centerIn: parent
                }

                Drag.active: mouseArea.drag.active
                Drag.keys: [ "YYDS" ]
                Drag.hotSpot.x: 100
                Drag.hotSpot.y: 50

                function getInfo(){
                    bindState = true
                    console.log( "call func getInfo() ...", " bindState = " + bindState )
                    return devNumber
                }

                function setBindUserNumber( newUserNumber ){
                    bindUserNum = newUserNumber
                }

                Drag.onActiveChanged: {
                    console.log( "dev drag active = " + dragRect.Drag.active )
                    let tmpActive = dragRect.Drag.active
                }

                Drag.onDragStarted: {
                    console.log( "dev start drag..." )
                }

                Drag.onDragFinished: {
                    console.log( "dev drag finished..." )
                }
            }

            Rectangle{
                id: dragBkgRect
                anchors.fill: parent
                color: "black"
                z: bindState ? 10 : 5
                Text {
                    text: devNumber
                    anchors.centerIn: parent
                    color: "white"
                }
            }


            states: State{
                when: mouseArea.drag.active
                AnchorChanges{ target: dragRect; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
            }

        }
    }





}

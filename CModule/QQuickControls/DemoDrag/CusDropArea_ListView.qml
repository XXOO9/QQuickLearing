import QtQuick 2.12
import QtQuick.Controls 2.12


Item {
    id: root

    width: 400
    height: 600



    Rectangle{
        id: bkgRect
        anchors.fill: parent
        color: "gray"
    }

    ListView{
        id: listViewArea
        anchors.fill: parent
        spacing: 10
        model: ListDataModel
        delegate: listDelegate
        clip: true

    }

    Component{
        id: listDelegate
        Item {
            id: listElementItem
            width: listViewArea.width * 0.9
            height: 100

            Rectangle{
                id: rowBkgRect
                anchors.fill: parent
                color: "transparent"
            }

            Row{
                spacing: 10
                anchors.fill: parent

                Rectangle{
                    id: nameRect
                    width: parent.width * 0.5
                    height: listElementItem.height
                    Text {
                        text: userName
                        anchors.centerIn: parent
                    }
                }

                Item {
                    id: dragAndDropArea
                    width: listElementItem.width * 0.4
                    height: listElementItem.height

                    MouseArea{
                        id: bindDragArea
                        width: listElementItem.width * 0.4
                        height: listElementItem.height

                        drag.target: bindedRectBkg

                        onReleased: bindedRectBkg.Drag.drop()

                        onClicked: {
                            let tmpDevNumber = userNumber
                            bindedRectBkg.cancelBind( tmpDevNumber )

                            reSetDevElement( tmpDevNumber )
                        }

                        z: userBind ? 10 : 5

                        states: State{
                            when: bindDragArea.drag.active
                            PropertyChanges{ target: bindedRectBkg; parent: listViewArea }
                            AnchorChanges{ target:  bindedRectBkg; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
                        }

                        Rectangle{
                            id: bindedRectBkg

                            property bool devBindFlag: userBind

                            width: listElementItem.width * 0.4
                            height: listElementItem.height
                            color: "red"
                            anchors{ verticalCenter: parent.verticalCenter; horizontalCenter: parent.horizontalCenter }

                            Drag.active: bindDragArea.drag.active
//                            Drag.active: false
                            Drag.keys: [ "YYDS" ]

                            Drag.onDragFinished: {
                                console.log( "drag finished..." )
                            }

                            Text {
                                text: userNumber
                                anchors.centerIn: parent
                            }

                            function getInfo(){
                                return userNumber
                            }

                            function setBindDevNumber( newDebNumber ){
                                userBind = true
                                userNumber = newDebNumber
                            }

                            function cancelBind( devNum ){
                                userBind = false
                                userNumber = "未绑定"
                            }
                        }


                    }

                    DropArea{
                        id: bindDropArea
                        width: listElementItem.width * 0.4
                        height: listElementItem.height

                        keys: [ "YYDS" ]

                        z: userBind ? 5 : 10

                        Rectangle{
                            id: dropBkgRect
                            anchors.fill: parent
                            color: "green"
                            Text {
                                text: userNumber
                                anchors.centerIn: parent
                                color: "white"
                            }

                            states: State{
                                when: bindDropArea.containsDrag
                                PropertyChanges{ target: dropBkgRect; color: "red" }
                                PropertyChanges{ target: rowBkgRect; color: "skyblue" }
                            }
                        }

                        //在这里需要区分拖拽源是哪里， 如果是没有绑定的， 那么一定是来源于未绑定的设备, 如果是已经绑定了的， 那么一定是来源于人员列表
                        onDropped: {
                            let devBindFlag = drop.source.devBindFlag


                            //绑定新的设备
                            if( !userBind && !devBindFlag ){
                                userBind = true
                                userNumber = drop.source.getInfo()

                                return
                            }

                            //替换已经绑定的设备
                            if( !devBindFlag ){
                                userBind = true
                                let preBindDevNumber = userNumber
                                userNumber = drop.source.getInfo()

                                reSetDevElement( preBindDevNumber )

                                return
                            }

                            //已绑定的设备去绑定未绑定的人员
                            if( devBindFlag && !userBind ){
                                let tmpDevNum = drop.source.getInfo()
                                drop.source.cancelBind( tmpDevNum )

                                bindedRectBkg.setBindDevNumber( tmpDevNum )

                                return
                            }

                            //交换两个已经绑定的设备
                            let newDevNum = drop.source.getInfo()

                            drop.source.setBindDevNumber( userNumber )
                            userNumber = newDevNum
                        }
                    }
                }


            }
        }
    }
}

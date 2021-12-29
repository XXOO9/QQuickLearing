import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if( mouse.button === Qt.LeftButton ){
                console.log( "LeftButton clicked" )
            }else if( mouse.button === Qt.RightButton ){
                console.log( "RightButton clicked" )
                menu.popup()
            }
        }
    }

    Menu{
        id: menu

        //子菜单或者MenuBar里面才会显示
        title: "this is a WDNMD menu"


        delegate: MenuItem{
            id: menuItem

            MenuSeparator{
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2
                anchors.horizontalCenter: parent.horizontalCenter
            }

            //菜单内容
            contentItem: Text{
                font{ pixelSize: 20 }
                color: menuItem.highlighted ? "red" : "white"
                text: menuItem.text
                horizontalAlignment: Text.AlignHCenter
            }

            //多级菜单的指示器(多级菜单右边的指示器，类似于indicator)
            arrow:Item {
                id: menuArrow
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                Rectangle{
                    implicitWidth: 10
                    implicitHeight: width
                    color: "red"
                }
            }

            indicator:Item {
                id: menuIndicator
                implicitWidth: 30
                implicitHeight: width
                anchors.left: parent.left
                anchors.leftMargin: 30
                Rectangle{
                    id: outsideRect
                    implicitWidth: parent.width * 0.8
                    implicitHeight: width
                    anchors.centerIn: menuIndicator
                    radius: width / 5
                    color: "red"
                    Rectangle{
                        visible: menuItem.checked
                        anchors.centerIn: outsideRect
                        radius: width / 5
                        implicitWidth: parent.width * 0.8
                        implicitHeight: width
                        color: "gray"
                    }
                }
            }

            background: Rectangle{
                anchors.fill: parent
                color: menuItem.highlighted ? "lightgreen" : "gray"
            }
        }

        Menu{
            title: "subMenu"
        }

        Action{
            text: "Choose A"
            checkable: true
            shortcut: "Ctrl+C"
            onTriggered:  {
                console.log( "Choose A..." )
            }

        }
        Action{
            text:  "Choose B"
            checkable: true
            shortcut: "Ctrl+X"
            onTriggered:  {
                console.log( "Choose B..." )
            }
        }
        Action{ text:  "Choose C"
            checkable: true
            shortcut: "Ctrl+V"
            onTriggered:  {
                console.log( "Choose C..." )
            }
        }

    }

}

import QtQuick 2.12
import QtQuick.Controls 2.12
ComboBox{
    id: root

    implicitWidth: 200
    implicitHeight: width / 4

    ListModel{
        id: listModel
    }

    property string rectBkgColor: "skyblue"
    property string borderColor: "blue"
    property string hightLightColor: "#087485"
    property int bordeWidth: 2
    property string itemColor: "gray"
    property real itemHeight: 50
    property string itemTextColor: "white"
    property int maxDisplayCount: 5
    property real itemSpacing: 3
    property real contentWdith: width * 0.8

    contentItem: ItemDelegate{
        id: delegateItem
        implicitWidth: contentWdith

        padding: 0
        Text {
            text: currentText
            color: "red"
            font{ pixelSize: 20; bold: true }
            horizontalAlignment: Text.AlignLeft
            anchors{ verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 20 }
        }
        background: Rectangle{
            color: "transparent"
        }

        onClicked: pop.open()
    }

//    indicator: Rectangle{
//        width: root.width - contentWdith
//        height: delegateItem.height
//        color: "green"
//        anchors{ right: parent.right; }
//    }


    delegate: ItemDelegate{
        implicitWidth: root.width
        height: itemHeight

        contentItem: Text {
            text: name
            color: itemTextColor
            font.pixelSize: 30
            horizontalAlignment: Text.AlignLeft
        }

        background: Rectangle{
            color: itemColor
        }
    }



    background: Rectangle{
        id: bkgRect
        //        border.color: borderColor
        border.color: "red"
        //        border.width: bordeWidth
        border.width: 10
    }

    popup: Popup{
        id: pop
        y: root.height
        width: root.width
        padding: 0
        ListView{
            width: parent.width * 0.95
            height: maxDisplayCount * itemHeight
            model: pop.visible ? root.delegateModel : null
            spacing: itemSpacing
        }

        background: Rectangle{
            color: "black"
        }
    }

    Component{
        id: listDelegate
        ItemDelegate{
            width: root.width
            height: itemHeight

            contentItem: Item {
                Text {
                    text: name
                    color: "white"
                    font{ pixelSize: 20 }
                    anchors.centerIn: parent
                }
            }

            background: Rectangle{
                //                color: itemColor
                color: "transparent"
            }
        }
    }
}

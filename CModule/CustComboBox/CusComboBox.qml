import QtQuick 2.12
import QtQuick.Controls 2.12
ComboBox{
    id: root

    implicitWidth: 200
    implicitHeight: width / 4


    // name
    ListModel{
        id: listModel
    }

    //配置项
    property string bkgRectBorderColor: "green"                //主体部分边框颜色
    property real   bkgRectBorderWidth: 1                      //主体部分边框宽度

    property string displayContentTextColor: "red"             //主体部分文字颜色
    property string displayContentRectColor: "transparent"     //主体部分指示器左边部分矩形颜色
    property string displayContentRectBorderColor: "blue"      //主体部分指示器左边部分矩形边框颜色

    property string selectContentHighLightColor: "red"         //候选部分矩形高亮颜色
    property string selectContentColor:          "green"       //候选部分矩形的颜色
    property string selectContentBorderColor:    "blue"        //候选部分矩形边框的颜色

    property real  maxDisplayContentCnt: 5                     //最大显示的数量
    property real  itemHeight: 50                              //候选单个矩形的高度
    property string  itemTextColor: "black"                    // 候选文字颜色

    background: Rectangle{
        id: bkgRect
        border.color: bkgRectBorderColor
        border.width: bkgRectBorderWidth
    }

    contentItem: ItemDelegate{
        id: delegateItem
        implicitWidth: root.width
        padding: 0

        Text {
            text: currentText
            color: displayContentTextColor
            font{ pixelSize: 20; bold: true }
            horizontalAlignment: Text.AlignLeft
            anchors{ verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 20 }
        }

        background: Rectangle{
            color: displayContentRectColor
            border.color: displayContentRectBorderColor
        }

        onClicked: pop.open()
    }


    delegate: ItemDelegate{
        width: root.width
        height: itemHeight

        highlighted: index === root.highlightedIndex

        contentItem: Text {
            text: name
            color: itemTextColor
            font.pixelSize: 30
            horizontalAlignment: Text.AlignLeft
        }

        background: Rectangle{
            width: root.width
            color: highlighted ? selectContentHighLightColor : selectContentColor
            border.color: selectContentBorderColor
        }

    }

    popup: Popup{
        id: pop
        y: root.height
        width: root.width
        padding: 0

        onOpened: selectListView.currentIndex = 0

        ListView{
            id: selectListView
            width: parent.width
            height: root.maxDisplayContentCnt * itemHeight
            model: pop.opened ? root.delegateModel : null
            spacing: 0
            clip: true
        }
    }
}

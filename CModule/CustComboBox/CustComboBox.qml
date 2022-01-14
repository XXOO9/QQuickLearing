import QtQuick 2.12
import QtQuick.Controls 2.12

ComboBox{
    id: m_comboBox
    width: 220
    height: 40
    model: [ "W", "D", "N", "M", "D", "C", "N", "M" ]

//    delegate: ItemDelegate{
//        width: m_comboBox.width
//        contentItem: Text {
//            text: modelData
//            color: "green"
//            font{ pixelSize: 30 }
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter
//        }
//        highlighted: m_comboBox.highlightedIndex === index
//    }

    delegate: ItemDelegate{
        width: m_comboBox.width
        Rectangle{
            anchors.fill: parent
            color: "red"

            Text {
                text: modelData
                font{ pixelSize: 30 }
                color: "blue"
                anchors.centerIn: parent
            }
        }

        highlighted: m_comboBox.highlightedIndex === index
    }

    contentItem: Text {
        text: m_comboBox.displayText
        color: "red"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font{ pixelSize: 30 }
    }

    background: Rectangle{
        width: m_comboBox.width
        height: m_comboBox.height
        color: "gray"
        radius: 20
    }

    popup: Popup{
        width: m_comboBox.width
        height: 200
        y: m_comboBox.height + 5

        //这个padding他妈的也是个坑，我操他妈，不设置成1或者1附近的数，他妈的批靠是喊高亮框位置不对
        padding: 1
        contentItem: ListView{
            clip: true
            implicitHeight: contentHeight
            //这一句把老子坑安逸了，woc， 妈的应该写 m_comboBox.delegateModel， 不是写 m_comboBox.model
            model: m_comboBox.popup.visible ? m_comboBox.delegateModel : null
//            currentIndex: m_comboBox.highlightedIndex

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle{
            width: m_comboBox.width
            height: parent.height
            color: "gray"
            radius: 20
        }
    }
}

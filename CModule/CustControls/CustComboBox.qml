import QtQuick 2.12
import QtQuick.Controls 2.12

ComboBox{
    id: m_comboBox
    implicitWidth: 220
    implicitHeight: 50

    property var dataModel: [ "A", "B", "C", "D" ]
    property string fontStyle: "Microsoft YaHei"

    model: dataModel


    background: Rectangle{
        width: m_comboBox.width
        height: m_comboBox.height
        color: "transparent"
        border.color: "red"
    }

    contentItem: Text {
        text: m_comboBox.displayText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font{ family: fontStyle; pixelSize: 20 }
        color: "red"
    }

    //单个候选项的样式
    delegate: ItemDelegate{
        width: m_comboBox.width
        contentItem: Text {
            text: modelData
            font{ family: fontStyle; pixelSize: 20 }
            color: "yellow"
        }

        background: Rectangle{
            anchors.fill: parent
            color: highlighted() ? "skyblue" : "gray"
        }
    }


}

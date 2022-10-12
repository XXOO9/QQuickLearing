import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 400
    height: width

    ButtonGroup{
        buttons: rowBtn.children
    }

    Row{
        id: rowBtn
        spacing: 50
        Repeater{
            model: [ "确定", "取消" ]
            delegate: RadioButton{
                id: radioBtn
                width: 150
                height: width

                indicator: Rectangle{
                    id: indicator
                    width: 150
                    height: width
                    radius: width / 2
                    color: "transparent"
                    border.color: "green"

                    Rectangle{
                        visible: radioBtn.checked
                        width: parent.width * 0.7
                        height: width
                        radius: width / 2
                        color: "gray"
                        anchors.centerIn: parent
                    }
                }

                contentItem: Text {
                    text: "WDNMD"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    leftPadding: indicator.width + radioBtn.spacing
                }
            }
        }
    }
}

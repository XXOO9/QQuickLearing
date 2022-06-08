import QtQuick 2.12
import QtQuick.Controls 2.12
import "./ProjectCommonDefine.js" as Config
Item {
    id: root
    width: Config.windowWidth
    height: Config.heightHeight


    TextArea{
        id: textArea
        text: "WDNMD"
        anchors.fill: parent

        background: Rectangle{
            anchors.fill: parent
            color: "gray"
        }
    }
}

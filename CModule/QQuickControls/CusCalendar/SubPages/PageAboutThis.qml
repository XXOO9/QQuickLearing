import QtQuick 2.12
import QtQuick.Controls 2.12
import "../JavaScript/CommonDefine.js" as Common
import "../Components/"
import "../"

Item{
    id: root
    width: 300
    height: 500

    Rectangle{
        anchors.fill: parent
        radius: 20 * factor
        color: 'mediumseagreen'
        border{ width: 1.5 * factor; color: 'white' }
    }

    Column{
        width: parent.width * 0.9
        height: 500 * factor
        spacing: 100 * factor
        anchors.centerIn: parent

        Text {
            width: parent.width
            wrapMode: Text.WrapAnywhere
            text: '打工人，打工魂，打工都是人上人!'
            color: 'white'
            font{ family: "Microsoft YaHei"; pixelSize: 30 * factor }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            width: parent.width
            wrapMode: Text.WrapAnywhere
            text: '更多功能探索中...\n'
            color: 'white'
            font{ family: "Microsoft YaHei"; pixelSize: 30 * factor }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }

}

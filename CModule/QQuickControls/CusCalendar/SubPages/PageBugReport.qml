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

    Text {
        width: parent.width * 0.95
        wrapMode: Text.WrapAnywhere
        text: '哎呀, Bug嘛，难免嘛  ︽⊙_⊙︽'
        color: 'white'
        font{ family: "Microsoft YaHei"; pixelSize: 30 * factor }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors{ top: parent.top; topMargin: 20 * factor; horizontalCenter: parent.horizontalCenter }
    }

    Text {
        width: parent.width * 0.95
        wrapMode: Text.WrapAnywhere
        text: '发现Bug, 你就动动小手，截图个或者录个视频，发到这个邮箱哈!\n 1633084553@qq.com'
        color: 'white'
        font{ family: "Microsoft YaHei"; pixelSize: 20 * factor }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors{ top: parent.top; topMargin: 150 * factor; horizontalCenter: parent.horizontalCenter }
    }

    AnimatedImage{
        width: 80 * factor
        height: width
        source: 'qrc:/resource/sendEmail.gif'
        anchors{ top: parent.top; topMargin: 250 * factor; horizontalCenter: parent.horizontalCenter }
    }

}

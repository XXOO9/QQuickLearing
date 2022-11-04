import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{
    id: root
    width: 150
    height: 150
    color: 'green'

    signal sigClicked()

    Text {
        id: displayText
        text: '好了'
        font.family: "Microsoft YaHei"
        font.pixelSize: 15 * factor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.centerIn: parent
    }

    MouseArea{
        id: btnMous
        anchors.fill: parent
        onClicked: sigClicked()
    }

    states: [
        State{
            when: btnMous.pressed
            PropertyChanges{ target: root; opacity: 0.5 }
        }

    ]
}

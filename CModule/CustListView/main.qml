import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 900
    height: 1000
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    Button{
        onClicked: {
            m_listView.currentIndex = 25
        }
    }

    ListView{
        Component.onCompleted: {
            console.log( "content height = ", m_listView.contentItem.height )
        }

        id:m_listView
        width: 300
        height: 600
        model: 55
        clip: true
        highlightFollowsCurrentItem: true
        anchors.centerIn: parent
        delegate: Rectangle{
            implicitWidth: m_listView.width
            implicitHeight: 60
            color: "lightgreen"
            border.color: "black"
            Text {
                text: modelData
                anchors.centerIn: parent
                font.pixelSize: 30
            }
        }
    }

}

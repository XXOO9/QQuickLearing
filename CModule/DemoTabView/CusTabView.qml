import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Item {
    id: root
    width: 400
    height: 600

    TabBar{
        id: m_tabBar
        width: parent.width
        height: 40
        anchors.top: parent.top
        anchors.left: parent.left

        Repeater{
            model: [ "1", "2"]

            TabButton{
                implicitWidth: 50
                implicitHeight: m_tabBar.height
                text: modelData
            }
        }
    }

    SwipeView{
        id: m_swipView
        width: parent.width
        height: parent.height - m_tabBar.height
        clip: true
        currentIndex: m_tabBar.currentIndex
        anchors.top: m_tabBar.bottom
        anchors.left: m_tabBar.left
        Repeater{
            model: [ "qrc:/CusRect.qml", "qrc:/CusRectRed.qml"]
            Loader{
                anchors.fill: m_swipView
                source: modelData
            }
        }
    }
}



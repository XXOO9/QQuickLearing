import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 600
    height: 500

    ListModel{
        id: m_list
        ListElement{ order: 0; devNumber: "dev001"; hardWareVersion: "h1"; firmwareVersion: "f1" }
    }

    Row{
        id: horizontalHeader
    }

    TableView{
        id: m_tableView
        width: parent.width
        height: parent.height
        anchors.fill: parent
        model: m_list

        delegate: Rectangle{
            implicitWidth: 40
            implicitHeight: 20
            Text {
                id: c1
                text: order
            }

            Text {
                id: c2
                anchors.left: c1.right
                text: devNumber

            }
        }
    }

    Component{
        id: tableCell
        Rectangle{
            implicitWidth: m_tableView.width / 4
            implicitHeight: 41
            color: "gray"
            border.color: "#1A292D"
            Text {
//                text:
            }
        }
    }

    Component{
        id: headerDelegate

    }
}

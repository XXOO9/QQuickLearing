import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    implicitWidth: 800
    implicitHeight: width


    TableView{
        id: m_table
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
    }
}

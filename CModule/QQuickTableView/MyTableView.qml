import QtQuick 2.12
import QtQuick.Controls 2.12
import com.TME.CAbstractTableModel 1.0

Item {
    id: root
    implicitWidth: 400
    implicitHeight: width


    TableView{
        id: m_table
        anchors.fill: parent
        columnSpacing: -20
        rowSpacing: 1
        clip: true
        model:tableModel
        delegate: Rectangle{
            id:rectBase
            implicitWidth: 90
            implicitHeight: width
            border.color: "red"
            border.width: 1
            color: "lightgreen"
            Text {
                text: tableModel.data( tableModel.index( row , column ) )
                anchors.centerIn: parent
                font{ pixelSize: 20 }
            }
            Rectangle{
//                visible: tableModel.getValue( row, 8 ) === "true" ? true : false
                implicitWidth: rectBase.width / 6
                implicitHeight: width
                radius: width / 2
                anchors.left: rectBase.left
                anchors.verticalCenter: rectBase.verticalCenter
                color: "red"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    var tmp = tableModel.getValue( row, 8 )
                }
            }
        }
    }

}

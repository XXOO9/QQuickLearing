import QtQuick 2.12
import QtQuick.Controls 2.12
import com.TME.CDataModel 1.0
Item {

    property int rowHeight: 30
    property int columnWidth: 150
    property int fontSize: 30
    id: root
    implicitWidth: 600
    implicitHeight: 200


    Row{
        anchors.left: m_tableView.left
        anchors.bottom: m_tableView.top
        Repeater{
            model: m_tableView.columns > 0 ? m_tableView.columns : 1
            Rectangle{
                implicitWidth: m_tableView.columnWidthProvider( index )
                implicitHeight: m_tableView.rowHeightProvider( index )
                color: "lightblue"
                border.color: "black"
                Text {
                    text: Model.horizontalHeader( index )
                    font{ pixelSize: fontSize}
                    anchors.centerIn: parent
                }
            }
        }
    }

    TableView{
        id:m_tableView
        implicitWidth: root.width
        implicitHeight: root.height
        model: Model
        rowHeightProvider: function(row){ return rowHeight }
        columnWidthProvider: function(column){
            //这里可以自定义某一列的宽度width
            var stdWidth = root.width / columns
            return  stdWidth
        }
        clip: true
        flickableDirection: Flickable.VerticalFlick
        ScrollBar.vertical: ScrollBar { }
        delegate: Rectangle{
            implicitWidth: m_tableView.columnWidthProvider( column )
            implicitHeight: m_tableView.rowHeightProvider( row )
            color: row % 2 === 0 ? "lightgreen" : "yellow"
            border.color: "black"
            Text {
                text: Model.data( Model.index( row, column), CDataModel.DisplayRole )
                font{ pixelSize: fontSize; bold: true }
                anchors.centerIn: parent
            }
        }
    }
}

import QtQuick 2.12
import QtQuick.Controls 2.12
import com.TME.CDataModel 1.0
Item {

    property int rowHeight: 30
    property int columnWidth: 150
    property int fontSize: 30
    property real specificWidth: 80


    id: root
    implicitWidth: 600
    implicitHeight: 200


    Row{
        id:row
        anchors.left: m_tableView.left
        anchors.bottom: m_tableView.top
    }


    Component{
        id: horizontalHeaderCmp
        Rectangle{
            property int index: 0
            implicitWidth: m_tableView.columnWidthProvider( index )
            implicitHeight: m_tableView.rowHeightProvider( index )
            color: "lightblue"
            border.color: "black"
            Text {
                text: Model.horizontalHeader( index )
                font{ pixelSize: fontSize }
                anchors.centerIn: parent
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
            if( column === 2 ){
                return specificWidth
            }
            var commonWidth = (root.width - specificWidth) / Model.horizontalHeaderCount()
            return commonWidth
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



    function createMultiCmp( num, parent, cmp ){
        for( var i = 0; i < num; i++ ){
            cmp.createObject( parent, { index: i } )
        }
    }

    function test(){
        createMultiCmp( Model.horizontalHeaderCount(), row, horizontalHeaderCmp )
    }

    function destory(){
        var list = row.children
        console.log( "count = " + list.length )
        for( var i = 0; i < list.length; i++ ){
            list[i].destroy()
        }
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.TME.CDataModel 1.0

Window {
    visible: true
    width: 800
    height: 800
    title: qsTr("Hello World")

    Button{
        onClicked: {
            DataModel.setSingleData( "first_unique", CDataModel.FirstColumn, "false" )
        }
    }


    TableView{
        id:m_tableView
        implicitWidth: 700
        implicitHeight: width
        clip: true
        model: DataModel

        anchors.centerIn: parent

        delegate: Rectangle{
            id: outSideRect
            implicitWidth: 130
            implicitHeight: width
            border.color: "red"
            color: "lightgreen"
            Text {
                text: DataModel.data( DataModel.index( row, column ), CDataModel.DisplayRole )
                font{ pixelSize: 20; bold: true}
                anchors.centerIn: parent
            }
            Rectangle{
                id:insideRect
                visible: DataModel.data( DataModel.index( row, column ), CDataModel.DataRole ) === "true" ? true : false
                implicitWidth: outSideRect.width / 4
                implicitHeight: width
                radius: width / 2
                color: "red"
                anchors.left: outSideRect.left
                anchors.verticalCenter: outSideRect.verticalCenter
            }
        }
    }

}

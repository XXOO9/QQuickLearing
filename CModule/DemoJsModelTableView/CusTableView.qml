import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./JavaScript/DataModel.js" as DataModel
Item {
    id: root
    width: 700
    height: 800

    Component.onCompleted: {
//        DataModel.appendRows( m_dataModel )
    }

    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    ListModel{
        id: m_dataModel
    }

    ListModel{
        id: tmpModel
    }

    TableView{
        id: m_tableView
        implicitWidth: 600
        implicitHeight: 700

        anchors.centerIn: parent
                model: m_dataModel
        delegate: Row{
            spacing: 10
            Rectangle{
                implicitWidth: 20
                implicitHeight: 40
                Text {
                    text: m_dataModel.get( row ).name
                }
            }

            Rectangle{
                implicitWidth: 20
                implicitHeight: 40
                Text {
                    text: m_dataModel.get( row ).age
                }
            }
        }
    }

    Button{
        anchors.bottom: parent.bottom
        onClicked: {
            for( let i = 0 ; i < 10000; i++ ){
                InterAction.testFunc()
            }
        }
    }


    function loadData(){
        m_tableView.model = m_dataModel
    }

    Connections{
        target: InterAction
        onSigPassJson:{
            DataModel.parseJson( m_dataModel, jsString )
        }
    }
}

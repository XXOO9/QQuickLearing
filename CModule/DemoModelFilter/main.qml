import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


ApplicationWindow {
    visible: true
    width: 800
    height: 800
    title: qsTr("Hello World")

    ListView{

        width: 150
        height: 400
        Component.onCompleted: {
            console.log( "size = " + FilterModel.rowCount() )
        }

        model: OrginalFilterModel
        spacing: 5
        delegate: Rectangle{
            width: 150
            height: width
            color: "gray"
            Text {
                text: userName + "\n" + userDepartment
            }
        }
    }

    Button{
        anchors.right: parent.right
        onClicked: filteTargetModel()
    }

    function filteTargetModel(){
        OrginalFilterModel.setFilterWildcard( "*B" )
    }

    function queryIndexOfTargetUserNumber(){

    }

}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./JavaScript/DataModel.js" as DataModel

ApplicationWindow {
    visible: true
    width: 1000
    height: 1000
    title: qsTr("Hello World")

    CusTableView{
        anchors.centerIn: parent
    }

    Button{
        onClicked: {
//            InterAction.testFunc()
            testttttt()
        }
    }


    function testttttt(){
        let js = {"name": "zmc", "age": 18}
        console.log( "js = " + js )
        let obj = JSON.parse( js )

        console.log( "name = " + obj.name )
    }
}

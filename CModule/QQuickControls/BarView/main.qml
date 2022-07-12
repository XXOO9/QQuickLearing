import QtQuick 2.12
import QtQuick.Window 2.12
import QtCharts 2.3
import QtQuick.Controls 2.12


Window {
    visible: true
    width: 900
    height: 500
    title: qsTr("Hello World")

    property var type: []
    property var val: []

    Component.onCompleted: {
        testFunc()
        for( let i = 0; i < 50; i++ ){

            type.push( i )
            val.push( generateRadom(0,150) )
        }

        console.log(  "size=  ", type.length, val.length )

        loader.setSource( "qrc:/BarView.qml", { "typeArray": type, "valArray": val })
    }

    Loader{
        id: loader
        anchors.fill: parent
    }

    Button{
        onClicked: loader.item.append()
    }


    function generateRadom( max, min ){
        return Math.floor(Math.random()*(max-min+1))+min
    }

    function testFunc(){
        let tmpArray = [ "W", "D", "N", "M", "D" ]
        tmpArray.length = 0

        console.log( tmpArray.length )
    }
}

import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 2.12
ChartView {
    id: root
    width: 640
    height: 480

    property var typeArray: []
    property var valArray: []

    Component.onCompleted: {
        console.log( " chart size = ", typeArray.length, valArray.length )
    }

    title: "Bar series"
    anchors.fill: parent
    legend.alignment: Qt.AlignBottom
    antialiasing: true

    BarSeries {
        id: mySeries
        axisX: BarCategoryAxis { categories: typeArray }
        BarSet {
            id: barSet
//            label: "Bob"
            values: valArray
            color: "transparent"
            borderColor: "red"
        }
    }

    function append(){
        let val
        for( let i = 0; i < 200; i++ ){
            barSet.append( i )
        }

        for( let j = 0; j < barSet.count; j++ ){
            barSet.replace( j, valArray[ j ] )
        }

        root.update()

        console.log( "bar set size = ", barSet.count )
    }
}


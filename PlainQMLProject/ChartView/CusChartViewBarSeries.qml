import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 2.12

Item{
    id: root
    width: 500
    height: 400

    property var dataObj: ({})

    Component.onCompleted: {
        generateAxisXArray()

        barSeries.append( "WDNMD", dataObj.array )
    }

    ChartView{

        id: chartArea
        title: "this is title"
        anchors.fill: parent

        legend.alignment: Qt.AlignBottom
        antialiasing: true

        BarSeries{
            id: barSeries
            barWidth: 0.3
            axisX: BarCategoryAxis{ categories: generateCategories() }
        }
    }

    function generateAxisXArray(){
        let targetArray = []
        let targetCategories = []
        let a = {}

        for( let index = 0; index < 20; index++ ){
            targetArray.push( index * 2 )
        }
        dataObj["array"] = targetArray
    }

    function generateCategories(){
        let categories = []
        for( let index = 0; index < 5; index++ ){
            categories.push( "类目wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" + index )
        }

        return categories
    }
}

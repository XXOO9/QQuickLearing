import QtQuick 2.0

Item {
    id: root
    width: 1920
    height: 400

    readonly property string chartName: "bar"

    Chart{
        id: barSeries
        anchors.fill: parent
        chartType: chartName

        chartData: generateData()
    }

    function generateCategories(){
        let categoriesArray = []
        for( let index = 0; index < 40; index++ ){
            categoriesArray.push( "泰盟支队:" + index )
        }

        return categoriesArray
    }

    function generateCategoryDatas(){
        let categoriesArray = []
        for( let index = 0; index < 40; index++ ){
            categoriesArray.push( index )
        }

        return categoriesArray
    }

    function generateData(){
        let barDataObj = {}
        let barLabels = generateCategories()

        let dataArray = []
        let bar = {
            fillColor : "rgba(151,187,205,0.5)",
            strokeColor : "rgba(151,120,100,0.8)",
            highlightFill : "rgba(151,187,205,0.75)",
            highlightStroke : "rgba(151,187,205,1)",
            data : generateCategoryDatas()
        }

        dataArray.push( bar )

        barDataObj.labels = barLabels
        barDataObj.datasets = dataArray

        return barDataObj
    }
}

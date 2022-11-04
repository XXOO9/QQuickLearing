import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: root
    width: 800
    height: width

    readonly property string chartName: "bar"

    //窗口尺寸发生改变时，如果不重新加载数据，统计图的尺寸会出错，目前唯一的解决办法就是重新加载数据
    onWidthChanged: chartItem.chartData = generateData()

    Rectangle{
        anchors.fill: parent
        color: "blue"
    }

    Button{
        onClicked: {
            chartItem.chartData = generateData()
            //            chartItem.requestPaint()      //// 数据更改后， 调用重绘函数
        }
    }

    Rectangle{
        width: parent.width * 0.5
        height: parent.height * 0.8
        anchors.centerIn: parent
        color: 'white'

        Chart{
            id: chartItem
            anchors.fill: parent
            chartType: chartName

            chartData: generateData()
            chartOptions: testConfig()
        }
    }



    function testConfig(){
        let options = {}

        let optionScales = {
            yAxes: [{
                    type: "linear",
                    stacked: true,
                    scaleLabel: {
                        display: true,
                        labelString: 'Y-Title',   // Y轴的标题
                        position: 'left'
                    },

                    //网格线相关, 坐标轴的颜色在这里设置
                    gridLines: {
                        color: "red",
                        drawOnChartArea: false,   //是否绘制该轴的网格线
                        drawTicks: true,        // 是否绘制 Y 轴上，数值与坐标轴之间的连接线
                    },

                    //刻度相关
                    ticks: {
                        display: true,      // 改轴是否展示出来
                        fontColor: 'red',    // 改轴上文字的颜色
                        beginAtZero: true,       // 坐标轴从0开始绘制
                        stepSize: 1
                    }

                }],

            xAxes: [{
                    type: 'category',
                    stacked: true,
                    gridLines: {
                        color: "green",
                        drawOnChartArea: false,    //是否绘制该轴的网格线
                        drawTicks: true            // 是否绘制 X 轴上，数值与坐标轴之间的连接线
                    }
                }]
        }

        let tootipsConfig = {
            backgroundColor: "green",
            callbacks: {            //自定义tooltips 内容
                label: function( tooltipItem, data ){

                    let label = tooltipItem.value + '人'

                    return label
                }
            }
        }

        let titleConfig = {
            display: true,
            text: "WDNMD",
            position: 'top'
        }


        options[ "scales" ] = optionScales
        options[ "tooltips" ] = tootipsConfig
        options[ "title" ] = titleConfig

        return options
    }

    function generateCategories(){
        let categoriesArray = []
        for( let index = 0; index < 5; index++ ){
            categoriesArray.push( "泰盟支队:" + index )
        }

        return categoriesArray
    }

    function generateCategoryDatas(){
        let categoriesArray = []
        for( let index = 0; index < 5; index++ ){
            categoriesArray.push( index )
        }

        return categoriesArray
    }

    function generateData(){
        let barDataObj = {}
        let barLabels = generateCategories()
        let barOptions = {}

        let dataArray = []
        let bar1 = {
            backgroundColor: "green",
            hoverBackgroundColor: "blue",
            data : generateCategoryDatas()
        }

        let bar2 = {
            backgroundColor: "red",
            hoverBackgroundColor: "yellow",
            data : generateCategoryDatas()
        }

        dataArray.push( bar1 )
        dataArray.push( bar2 )

        barDataObj.labels = barLabels
        barDataObj.datasets = dataArray

        return barDataObj
    }

    function generateRandomVal( min = 0, max = 100 ){
        const tmp = Math.floor(Math.random() * (max - min + 1)) + min
        console.log( "ret = " + tmp )
        return tmp
    }

    function rePaint(){
        chartItem.requestPaint()

    }
}

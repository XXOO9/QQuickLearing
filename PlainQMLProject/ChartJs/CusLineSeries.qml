import QtQuick 2.0

Item {
    id: root
    implicitWidth: 400
    implicitHeight: width

    ListModel{
        id: lineDataModel

        function generateTestData(){
            for( let i = 0; i < 5; i++ ){
                lineDataModel.append( { "labelName": "label_" + i + 1, "labelVal": generateRandomVal() } )
//                lineDataModel.append( { "labelName": "label_" + i + 1, "labelVal": 0 } )
            }
        }

        function getLabelNames(){
            let labelArray = []
            let size = lineDataModel.count
            for( let index = 0; index < size; index++ ){
                labelArray.push( lineDataModel.get( index ).labelName )
            }

            return labelArray
        }

        function getLabelValues(){
            let labelArray = []
            let size = lineDataModel.count
            for( let index = 0; index < size; index++ ){
                labelArray.push( lineDataModel.get( index ).labelVal )
            }

            return labelArray
        }
    }

    Rectangle{
        anchors.fill: parent
        color: "blue"
    }


    Rectangle{
        width: parent.width * 0.8
        height: parent.height * 0.8
        anchors.centerIn: parent
        color: "gray"

        Chart{
            id: lineSeriesArea
            anchors.fill: parent
            chartType: 'line'
            chartData: generateTestData()
            chartOptions: generateConfigs()
        }
    }



    function generateTestData(){
        lineDataModel.generateTestData()

        let totalDataObj = {
            labels: lineDataModel.getLabelNames(),
            datasets: [{
                    label: '近5年平均心率指数走势',    //线条标题
                    fill: false,
                    lineTension: 0, //设置为 0 就是直线
                    //                    borderDash: [10, 2],     //每一根线条的长度和间距
                    backgroundColor:'#20EDE1', //  圆点的颜色
                    borderColor: '#20EDE1',
                    borderWidth: 1,
                    data: lineDataModel.getLabelValues()
                }]

        }

        return totalDataObj
    }

    function getLabels(){
        return [ "label1", "label2", "label3", "label4", "label5" ]
    }

    function getTestRandomData(){
        let tmpDataArray = []
        for( let i = 0; i < 5; i++ ){
            tmpDataArray.push( generateRandomVal() )
        }

        return tmpDataArray
    }

    function generateConfigs(){

        let options = {
            maintainAspectRatio: false,
            responsive: true
        }

        let titleConfig = {
            display: true,
            text: 'Chart.js Line Chart'
        }

        let tooltipsConfig = {
            mode: 'index',
            intersect: false,
            backgroundColor: 'lightblue',
            titleFontColor: 'red',   //  提示框：： 标题颜色
            bodyFontColor: 'green',      //提示框：： 内容颜色
            callbacks: {        //自定义tooltips 内容
                label: function( tooltipItem, data ){
                    return tooltipItem.label + ': ' + tooltipItem.value + '%'
                }
            }
        }

        let hoverConfig = {
            mode: 'nearest',
            intersect: true
        }

        let elementConfig = {
            tension: 0      //贝塞尔曲线张力。设置为 0 绘制直线。如果使用单调立方插值，则忽略此选项。
        }

        let animationConfig = {
            duration: 0
        }

        let chartAreaConfig = {
            backgroundColor: 'green'
        }

        let scalesConfig = {
            yAxes: [{
                    type: "linear",
                    display: true,
                    scaleLabel: {
                        display: true,
                        labelString: '指数',
                        position: 'top',
                        fontColor: 'whitet'
                    },

                    //网格线相关, 坐标轴的颜色在这里设置
                    gridLines: {
                        color: "red",
                        drawOnChartArea: false,   //是否绘制该轴的网格线
                        drawTicks: true,        // 是否绘制 Y 轴上，数值与坐标轴之间的连接线
                    },

                    ticks: {
                        beginAtZero: true,       // 坐标轴从0开始绘制
                        max: 200        //固定Y轴的最大值
                    }

                }],

            xAxes: [{
                    type: 'category',
                    display: true,
                    scaleLabel: {
                        display: true,
                        labelString: ''
                    },

                    //网格线相关, 坐标轴的颜色在这里设置
                    gridLines: {
                        color: "red",
                        drawOnChartArea: false,   //是否绘制该轴的网格线
                        drawTicks: true,        // 是否绘制 Y 轴上，数值与坐标轴之间的连接线
                    }
                }]
        }

        options[ 'title' ] = titleConfig
        options[ 'tooltips' ] = tooltipsConfig
        options[ 'hover' ] = hoverConfig
        options[ 'scales' ] = scalesConfig
        options[ 'element' ] = elementConfig
        options[ 'animation' ] = animationConfig
        options[ 'chartArea' ] = chartAreaConfig

        return options
    }

    function generateRandomVal( min = 0, max = 45 ){
        const tmp = Math.floor(Math.random() * (max - min + 1)) + min
        console.log( "ret = " + tmp )
        return tmp
    }
}

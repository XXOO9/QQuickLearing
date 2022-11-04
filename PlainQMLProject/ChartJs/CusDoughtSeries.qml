/*!
 * Elypson's Chart.qml adaptor to Chart.js
 * (c) 2020 ChartJs2QML contributors (starting with Elypson, Michael A. Voelkel, https://github.com/Elypson)
 * Released under the MIT License
 */
//https://chartjs.bootcss.com/docs/configuration/legend.html#chart-configuration-legend-item-interface

import QtQuick 2.0
import QtQuick.Controls 2.12

Item{
    id: root
    width: 800
    height: width

    Rectangle{
        anchors.fill: parent
        color: "blue"
    }


    Button{
        onClicked: {
            m_list.append( { val: 0.1, color: "#2DAF6A", tips: "tips1" } )
            chartItem.chartData = generate()
            chartItem.requestPaint()
        }
    }

    //所有的数据都是从这里取走的
    ListModel{
        id: m_list
        ListElement{ val: 0.1; color: "#2DAF6A";        tips: "tips1" }
        ListElement{ val: 0.2; color: "#5A5DD4";        tips: "tips2" }
        ListElement{ val: 0.2; color: "#D7B75E";      tips: "tips3" }
        ListElement{ val: 0.2; color: "#FE5578";     tips: "tips4" }
        ListElement{ val: 0.3; color: "#2B85D9";       tips: "tips5" }
    }

    Rectangle{
        width: root.width * 0.5
        height: width
        anchors.centerIn: parent
        color: "gray"

        Rectangle{
            width: parent.width * 0.8
            height: width
            anchors.centerIn: parent
            Chart {
                id: chartItem
                anchors.fill: parent
                chartType: "pie"

                chartData: generate()

                chartOptions: generateOptionConfig()
            }
        }


    }

    function generateOptionConfig(){
        let optionsConfig = {}
        optionsConfig = {
            maintainAspectRatio: false,
            responsive: false,

            legend: {
                display: true,
                position: 'bottom',

                labels: {
                    fontColor: 'red',
                    fontSize: 20
                }
            },

            animation: {
                animateScale:true
            },

            tooltips: {
                callbacks: {
                    label: function( tooltipsItem, data ){
                        const val = data.datasets[ tooltipsItem.datasetIndex ].data[ tooltipsItem.index ]
                        const tmpLabels = data.labels[ tooltipsItem.index ]
                        console.log( 'start..., ' + tmpLabels + ': ' + val )
                        return tmpLabels + ': ' + val
                    }
                }
            }
        }
        return optionsConfig
    }


    function generate(){
        let totalDataModel = {}
        let dataObj = {}
        let element
        let dataArray = []
        let colorArray = []
        let tipsArray = []
        let lenendConfig = {}

        for( let i = 0; i < m_list.count; i++ ){
            element = m_list.get( i )
            dataArray.push( element.val )
            colorArray.push( element.color )
            tipsArray.push( element.tips )
        }

        dataObj = {
            data: dataArray,
            backgroundColor: colorArray,
            borderColor: colorArray,          //可以同过这个控制表框
        }

        lenendConfig = {
            display: true,
            position: 'bottom'
        }

        totalDataModel = {
            datasets:[ dataObj ],
            labels: tipsArray,
            legend: lenendConfig
        }

        return totalDataModel
    }
}

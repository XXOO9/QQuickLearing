import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./ChartJs/"
import "./ChartView/"

ApplicationWindow {
    visible: true
    width: 1920
    height: 800

//    CusChartViewBarSeries{

//    }


    ScrollView{
        anchors.fill: parent
        clip: true
        contentWidth: aa.width
        contentHeight: aa.height

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        CusChartJsBarSeries{
            id: aa
            anchors.centerIn: parent
        }
    }



}

import QtQuick 2.12
import QtQuick.Controls 2.12
import "../JavaScript/CommonDefine.js" as Common
import "../Components/"
import "../"
Item{
    id: root
    width: 300
    height: 500

    Rectangle{
        anchors.fill: parent
        radius: 20 * factor
        color: 'mediumseagreen'
        border{ width: 1.5 * factor; color: 'white' }
    }

    Column{
        id: legeneColumn
        width: 250 * factor
        height: 200 * factor
        anchors{ top: parent.top; topMargin: 50 * factor;  horizontalCenter: parent.horizontalCenter}
        spacing: 20 * factor
        Component.onCompleted: {
            eachLegend.createObject( legeneColumn, { 'legendColor': 'gray', 'legendText': '时长 <= 0 h' } )
            eachLegend.createObject( legeneColumn, { 'legendColor': 'khaki', 'legendText': '时长 0 ~ 2.5h' } )
            eachLegend.createObject( legeneColumn, { 'legendColor': 'salmon', 'legendText': '时长 2.5 ~ 5h' } )
            eachLegend.createObject( legeneColumn, { 'legendColor': 'red', 'legendText': '时长 >= 6 h' } )
        }
    }

    Text {
        color: 'white'
        width: parent.width * 0.9
        wrapMode: Text.WrapAnywhere
        text: 'tips: 结算后的时长 = 实际时长 x 当日倍率 ( 并未将当日的请假时长纳入计算范围 )'
        font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors{ left: parent.left; top: legeneColumn.bottom; topMargin: 150 * factor }
    }



    Component{
        id: eachLegend
        Row{
            property alias legendColor: legendRect.color
            property alias legendText: detailHour.text
            width: 250 * factor
            height: 50 * factor
            spacing: 10 * factor

            Rectangle{
                id: legendRect
                width: 80 * factor
                height: 50 * factor
                radius: 20 * factor
                color: 'gray'
            }

            Text {
                id: detailHour
                text: '时长 <= 0 h'
                font{ family: "Microsoft YaHei"; pixelSize: 20 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenter: legendRect.verticalCenter
            }
        }
    }
}

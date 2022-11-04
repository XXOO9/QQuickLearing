import QtQuick 2.12
import QtQuick.Controls 2.12
import "./JavaScript/CommonDefine.js" as Common
import "./Components/"

Item {
    id: root
    width: perColumnWidth * 7
    height: perRowHeight * 8

    property real localFactor: 1

    readonly property real perColumnWidth: 100 * localFactor
    readonly property real perRowHeight: 100 * localFactor

    signal sigQueryDetailDateInfo( var dateIndex, var hour, var timeCnt )

    Component.onCompleted: {
        queryDays( 2022, 11 )
    }

    ListModel{  // dateIndex -> 日期 ,   hours  ->  加班时长 , timeCnt -> 倍率 , today -> 今天的日期
        id: dateInfoModel

        function findDay( tarDayIndex ){
            const size = dateInfoModel.count

            for( let index = 0; index < size; index++ ){
                if( dateInfoModel.get( index ).dateIndex === tarDayIndex ){
                    return dateInfoModel.get( index )
                }
            }

            return undefined
        }

        function setHighLight( tarDayIndex ){
            let ret = findDay( tarDayIndex )

            if( ret === undefined ){
                return
            }

            ret.today = rue
        }
    }

    Rectangle{
        anchors.fill: parent
        border{ width: 1.5; color: 'black'}
    }

    Item{
        id: dateAdjustArea
        width: perColumnWidth * 7
        height: perRowHeight
        anchors{ top: parent.top;  horizontalCenter: parent.horizontalCenter }
        Rectangle{
            anchors.fill: parent
            color: 'cadetblue'
        }

        Row{
            spacing: 0
            anchors.centerIn: parent
            NumberAdjustSpin{
                id: yearAdjust
                width: dateAdjustArea.width / 2
                height: dateAdjustArea.height
                onAdjustNumberChanged: queryDays( yearAdjust.adjustNumber, monthAdjust.adjustNumber )
            }

            NumberAdjustSpin{
                id: monthAdjust
                width: dateAdjustArea.width / 2
                height: dateAdjustArea.height
                adjustNumber: 11
                adjustUnit: '月'
                max: 12
                min: 1
                onAdjustNumberChanged: queryDays( yearAdjust.adjustNumber, monthAdjust.adjustNumber )
            }
        }

    }

    Item{
        id: calendarArea
        width: perColumnWidth * 7
        height: perRowHeight * 7
        anchors{ top: dateAdjustArea.bottom; left: dateAdjustArea.left }

        Rectangle{
            anchors.fill: parent
            color: 'black'
        }

        Row{
            id: dayWeekRow
            anchors{ top: parent.top; left: parent.left }
            Repeater{
                model: [ '一', '二', '三', '四', '五', '六', '日' ]
                delegate: weekDayCmp
            }
        }

        GridView{
            id: calendarGridView
            width: perColumnWidth * 7
            height: perRowHeight * 6
            cellWidth: perColumnWidth
            cellHeight: perRowHeight
            model: dateInfoModel
            anchors{ top: dayWeekRow.bottom; left: dayWeekRow.left }
            delegate: perRectCmp
        }
    }

    function generateListModelData( days, startWeekDay ){
        dateInfoModel.clear()


        for( let offsetIndex = 1; offsetIndex < startWeekDay; offsetIndex++ ){
            dateInfoModel.append( { 'dateIndex': 0, 'hours': 0, 'today': false, 'timeCnt': 0 } )
        }

        for( let daysIndex = 1; daysIndex <= days; daysIndex++ ){
            dateInfoModel.append( { 'dateIndex': daysIndex, 'hours': 0, 'today': false, 'timeCnt': 1 } )
        }

        while( dateInfoModel.count < 42 ){
            dateInfoModel.append( { 'dateIndex': 0, 'hours': 0, 'today': false, 'timeCnt': 0 } )
        }

    }

    function queryDays( year, month ){
        let ret = InterAction.queryTargetDateMonthInfo( year, month )
        generateListModelData( ret.daysInMonth, ret.startWeekDay )
    }

    function setTargetDateIndexInfo( targetDateIndex, hour, timeCnt ){
        let ret = dateInfoModel.findDay( targetDateIndex )

        ret.hours = hour
        ret.timeCnt = timeCnt
    }

    Component{
        id: weekDayCmp
        Rectangle{
            id: rect
            visible: modelData !== 0
            width: perColumnWidth
            height: perRowHeight
            color: 'cornflowerblue'
            Text {
                text: modelData
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor; bold: true }
                anchors.centerIn: parent
            }
        }
    }

    Component{
        id: perRectCmp
        Rectangle{
            id: rect
            visible: dateIndex !== 0
            width: perColumnWidth
            height: perRowHeight
            color: 'gray'

            Text {
                text: dateIndex
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor; bold: true }
                anchors.centerIn: parent
            }
            MouseArea{
                id: rectMouse
                hoverEnabled: true
                anchors.fill: parent
                onEntered: {
                    rect.border.width = 2 * localFactor
                    rect.border.color = 'blue'
                    rect.color = 'green'
                }

                onExited: {
                    rect.border.width = 0 * localFactor
                    rect.color = 'gray'
                }

                onDoubleClicked: {
                    Common.curYear = yearAdjust.adjustNumber
                    Common.curMonth = monthAdjust.adjustNumber
                    Common.curDateIndex = dateIndex
                    sigQueryDetailDateInfo( dateIndex, hours, timeCnt )
                }
            }
        }
    }
}

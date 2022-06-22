import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.12

ChartView {
    id: chart
    width: 300
    height: width
    backgroundColor: "blue"

    legend.labelColor: "#FFFFFF"

    legend.alignment: Qt.AlignBottom

    legend.markerShape: Legend.MarkerShapeCircle

    PieSeries {
        id: pieSeries
        PieSlice { label: "Volkswagen"; value: 70; color: "green" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
        PieSlice { label: "Toyota"; value: 30; color: "red" }
    }

    function append( color, value ){
        pieSeries.append( "", value )
    }
}



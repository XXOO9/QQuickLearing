import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 400
    height: 300

    ListModel{
        id: m_list
        ListElement{ displayText: "1" }
        ListElement{ displayText: "2" }
        ListElement{ displayText: "3" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
        ListElement{ displayText: "4" }
    }

    GridView{
        id: m_gridView
        //显式的指明长宽
        width: 500
        height: width

        cellWidth: 50
        cellHeight: 50

        model: m_list

        delegate: cellDelegate
    }


    Component{
        id: cellDelegate
        Rectangle{
            width: 50
            height: width
            color: "black"

            Text {
                text: displayText
                color: "white"
                anchors.centerIn: parent
            }
        }
    }
}

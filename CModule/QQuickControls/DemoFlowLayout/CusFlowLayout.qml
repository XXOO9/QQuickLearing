import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 500
    height: 400

    property int wid: 0.8 * root.width
    property real hei: flow.height / 5

    ListModel{
        id: m_list
        ListElement{ displayText: "1" }
        ListElement{ displayText: "1" }
        ListElement{ displayText: "1" }
        ListElement{ displayText: "1" }
        ListElement{ displayText: "1" }
    }

    Rectangle{
        width: 400
        height: width
        color: "gray"

        Flow{
            id: flow
            anchors.fill: parent
            spacing: 10
            flow: Flow.TopToBottom
            rightPadding: 50
            anchors.centerIn: parent

            Repeater{
                model: m_list

                delegate: delegate
            }

            onPositioningComplete: {
                console.log( "WDNMD" )
            }
        }
    }



    Button{
        onClicked: m_list.remove( 0 )
    }


    Component{
        id: delegate
        Rectangle{
            id: rect
            color: "yellow"
            width: 100
            height: 50
            Text {
                text: displayText
                font.pixelSize: 20
                anchors.centerIn: parent
            }

            //            Behavior on x{
            //                NumberAnimation{
            //                    duration: 500
            //                }
            //            }

            Behavior on y{
                NumberAnimation{
                    duration: 500
                }
            }

            Behavior on width{
                NumberAnimation{
                    duration: 500
                }
            }

            Behavior on height{
                NumberAnimation{
                    duration: 500
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    m_list.append( {"displayText": "2" } )

                }
            }
        }
    }
}

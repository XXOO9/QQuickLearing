import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        spacing: 10

        anchors.centerIn: parent

        Repeater{
            model: SuggestionsModel
//            model: 10
            delegate: Rectangle{
                width: 50
                height: width
                color: "gray"

                Text {
                    text: display
                }
            }
        }
    }

    Button{
        onClicked: SuggestionsModel.setFilterWildcard( "马*" )
    }
}

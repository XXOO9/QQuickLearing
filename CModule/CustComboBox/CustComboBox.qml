import QtQuick 2.12
import QtQuick.Controls 2.12
Item {
    id: root

    property int contentheight: 40
    property int maxContentCount: 5
    property string contentBkgColor: "yellow"
    property string contentHightlightColor: "lightgreen"
    property alias dataModel: m_combobox.model

    ComboBox{
        id: m_combobox
        width: 400
        height: width / 4

        background: Rectangle{
            anchors.fill: parent
            radius: 10
            smooth: true
            color: "skyblue"
            border.color: "red"
        }

        delegate: ItemDelegate{
            id: comboboxDelegate
            width: m_combobox.width
            height: contentheight

            highlighted: m_combobox.highlightedIndex === index

            background: Rectangle{
                border.color: "blue"
                color: parent.highlighted ? contentHightlightColor : contentBkgColor
            }

            contentItem: Text {
                text: modelData
                color: "gray"
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        popup: Popup{
            id: popHeight
            y: parent.height
            width: parent.width
            height: popHeihgtProvider()
            padding: 1
            contentItem: ListView{
                anchors.fill: parent
                clip: true
                snapMode: ListView.SnapToItem
                model: m_combobox.popup.visible ? m_combobox.delegateModel : null
                ScrollIndicator.vertical: ScrollIndicator { }
            }
        }
        onAccepted: onComboboxAccept()

        onActivated: onComboboxActived()
    }

    function setModel( dataModel ){
        m_combobox.model = dataModel
    }

    function popHeihgtProvider(){
        if( m_combobox.model.count < maxContentCount ){
            return contentheight * m_combobox.model.count
        }

        return maxContentCount * contentheight
    }

    function onComboboxAccept(){
        console.log( m_combobox.currentIndex )
    }

    function onComboboxActived(){
        console.log( m_combobox.currentIndex )
    }
}


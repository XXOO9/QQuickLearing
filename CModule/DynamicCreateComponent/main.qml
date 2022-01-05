import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        onClicked: {
            m_column.createObject(this)
        }
    }

    Button{
        anchors.right: parent.right
        onClicked: {
            m_column.destroy(this)
        }
    }


    //定义组件, Component只能定义id， 不能定义其他属性!!!
    Component{
        id:m_column
        Column{
            id:hapi
            spacing: 5
            Component.onCompleted: {
                console.log( "start to create m_column" )
                createRect( 10, hapi, custComponent, {displayText: "WDNMD"} )
            }
            Component.onDestruction: {
                console.log( "start to desroty m_column" )
            }

        }
    }

    Component{
        id:custComponent
        Rectangle{
            property string displayText: ""
            implicitWidth: 20
            implicitHeight: width
            color: "lightgreen"
            Text {
                text: displayText
            }
        }
    }

    //循环创建 num 个以 parent 为父对象的 cmp 组件,  并且设置属性propertyDate
    function createRect( num, parent, cmp, propertyDate = {} ){
        for( var i = 0; i < num; i++ ){
            cmp.createObject(parent, propertyDate )
        }
    }
}

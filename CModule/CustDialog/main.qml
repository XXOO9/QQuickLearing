import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        onClicked: {
            m_dialog.open()
        }
    }

    //自定义对话框，貌似不能关掉title栏
    Dialog{
        //自定义信号
        signal clicked()
        id:m_dialog
        contentItem: Rectangle{
            //设置高宽还TM只能用implicitWidhwdth？？
            implicitWidth: 500
            implicitHeight: 300
            color: "red"

            Rectangle{
                implicitWidth: 100
                implicitHeight: width
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        m_dialog.clicked()
                        console.log( "WDNMD" )
                    }
                }
            }
        }
    }

    Connections{
        target: m_dialog
        onClicked:{
            console.log( "recv clicked signal" )
        }
    }

}

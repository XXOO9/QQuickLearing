import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

/*
  2022.01.08 23:52
  参考链接:https://www.bilibili.com/video/BV1Ay4y1W7xd?p=44&spm_id_from=pageDriver
  看了B站这个博主的介绍，感觉：
  1.StavkView主要是应用于临时的界面跳转(不太容易使数据持久化)(或者局部界面的跳转(界面堆栈))
  2.StackLayout 貌似更偏向于界面整体的跳转,虽然MVC的思想就是数据与界面分离，但是完全绝对的分离好像还是挺麻烦的
 (要完全分离的话，数据应该怎么存放?全部放到交互类里面吗?)
  */

ApplicationWindow {
    visible: true
    width: 900
    height: 780
    title: qsTr("Hello World")


//    HowToTraversalJavaScriptArray{
//        id:testFunc
//    }



//    Button{
//        onClicked: {
//            testFunc.func2()
//        }
//    }

    CustStackLayout{
        anchors.centerIn: parent
    }


}

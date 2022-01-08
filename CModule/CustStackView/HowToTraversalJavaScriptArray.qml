import QtQuick 2.0


/*
  主要介绍遍历Js数组的方法
  */

Item {
    id: root
    width: 0
    height: 0
    property var array: [ "W", "D", "N", "M", "p" ]

    function func1(){
        array.forEach( array => console.log( "ret = ", array ) )
    }

    //回调函数(匿名函数)
    function func2(){
        array.forEach( function( content, index ){
            console.log( "content = " + content )
            console.log( "index = " + index )
        })
    }
}

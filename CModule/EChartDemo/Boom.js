.pragma library
.import "./Calculate.js" as Calculate

func()

var femaleArr = [ "选择体测项目", "肺活量", "立定跳远", "坐位体前屈",
                 "引体向上", "仰卧起坐", "800米跑步", "50米短跑", "跳绳", "握力", "视力", "肺通气量", "俯卧撑", "往返跑" ]


var person = { name: 'null',
    age: 99,
    sex: 'male',
    isStu: false,

    fullName : function(){
//        var ret = new car()
        return this.name + this.sex
    }
}

function createCar(){
    var cc = new Calculate.Car( "VM", "380TSI", "gray" )
}

function arrTest( index ){
    console.log( "index val = " + femaleArr[ index ] )
}




function func( str = "WDNMD" ) {
    let ret = Calculate.add( 1, 2 )
    console.log( "ret = " + str )
}

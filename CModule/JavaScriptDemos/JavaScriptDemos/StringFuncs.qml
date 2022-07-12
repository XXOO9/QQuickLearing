import QtQuick 2.0

Item {

    function func_subString(){
        let key = "FOUL:"
        let str = "FOUL:WDasdasdasdsadNMD"
        let ret = str.substring( key.length, str.length )

        console.log( ret )
    }
}

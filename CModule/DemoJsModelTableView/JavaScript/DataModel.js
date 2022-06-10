.pragma library

var tableElement = {
    "checked": false,
    "id": "0",
    "name": "WDNMD",
}

var horizontalHeaders = [ "1", "2", "3" ];

var dataModel = [ tableElement ]


function appendRows( listView ){
    let jsObj = { name: "WDNMD", age: "1"  }
    for( let i = 0; i < 100000; i++ ){
        listView.append( jsObj )
    }
}


function appendRow( listModel, jsObj ){
    listModel.append( jsObj )
}

function parseJson( jsString ){

    appendRow( JSON.parse( jsString) )
}



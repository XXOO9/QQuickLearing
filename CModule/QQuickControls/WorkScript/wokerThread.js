WorkerScript.onMessage = function( message ){


    console.log( "11111model name = " + message.tarModel.count )

    console.log( "src count = " + message.dataSrc.length )

    let dataModel = message.tarModel
    for( let ele of message.dataSrc ){
//        console.log( "ele = " + JSON.parse( ele ).A )
        dataModel.append( JSON.parse( ele ) )
    }

    dataModel.sync()


    console.log( "22222model name = " + dataModel.count )

    WorkerScript.sendMessage( { "reply": dataModel } )
}

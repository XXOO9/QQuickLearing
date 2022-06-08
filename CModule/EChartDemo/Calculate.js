.pragma library

class Car{
    constructor( logo, engine, color ){
        this.logo = logo;
        this.engine = engine;
        this.color = color;
    }

    setDriver( driverName ){
        this.driverName = driverName;
    }
}

class DreamCar extends Car{
    constructor( logo, engine, color, light ){
        super( logo, engine, color );
        this.light = light;
    }

    display(){
        console.log( "infos = " + logo )
    }
}

function getCar(){
    var ret = new Car( "VM", "380TSI", "gray" )
    console.log( "engine = " + ret.engine )
    return ret
}

function add( x, y ){
    return x + y;
}

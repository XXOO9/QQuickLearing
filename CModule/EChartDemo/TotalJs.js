.pragma library
.import "./Calculate.js" as Car
.import "./Boom.js" as   Demo

class FireCar extends Car.DreamCar{
    constructor( logo, engine, color, fire ){
        super( logo, engine, color );
        this.fire = fire;
    }

    setDriver( driverName ){
        console.log( "WDNMD = " + driverName )
    }
}

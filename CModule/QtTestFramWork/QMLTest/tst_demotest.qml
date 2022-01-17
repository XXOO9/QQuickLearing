import QtQuick 2.12
import QtQuick.Controls 2.12
import QtTest 1.0

TestCase {
    id: test
    name: "DemoTest"

    function initTestCase() {
    }

    function cleanupTestCase() {
    }

    function test_case1() {
        compare( 1 + 1, 2, "sanity check" );
        verify( true );
    }

    function test_case2(){
        test.mouseClick( btn )
    }
    Button{
        id:btn
        onClicked: {
            console.log( "WDNMD" )
        }
    }

}





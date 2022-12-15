#include "CInteraction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{

}

void CInteraction::test_qml_callback(QVariant parameters, QJSValue func)
{
    qDebug() << "parameters = " << parameters;
    QJSValueList parameterList;

    parameterList.append( func.engine()->toScriptValue( parameters ) );

    if( !func.isCallable() ){
        return;
    }



    auto ret = func.call( parameterList );

    //检查是否调用成功
    if( ret.isError() ){
        qDebug() << "callback failed...";
    }
}

void CInteraction::changeColor(QJSValue func)
{
    QVariant targetColor = "green";
    QJSValueList parameters;
    parameters.append( func.engine()->toScriptValue( targetColor ) );

    if( !func.isCallable() ){
        return;
    }

    func.call( parameters );
}

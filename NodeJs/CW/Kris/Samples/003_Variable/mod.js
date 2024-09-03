//Переменные обьявленные внутри модуля, являются локальными для модуля
var x = 10;

function Sum(a,b)
{
    return a+b;
}

function test()
{ 
    console.log("Сумма =" + '${Sum(1,2)}');
    console.log(x); 
};


exports.X=x;
exports.mytest=test;
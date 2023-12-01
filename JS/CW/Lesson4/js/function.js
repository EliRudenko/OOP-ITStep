function Mult(a,b)
{
    return a*b;
}
function Sum(a,b)
{
    return a+b;
}

function Min(a,b)
{
    return a-b;
}

//передава аргументов в функцию 
//spred - передача бесконечное кол во аргументов
//rest - обьязательно передача нескольких аргументов. При реализации rest находится в самом конце

function SumArr(...spred)
{
    let sum = 0;
    for(let i in spred)
    {
        sum += spred[i];
    }
    return sum;
}

function SumRest(a,b, ...rest)
{
    let sum = 0;
    sum = a+b;
    for(let i in rest)
    {
        sum += rest[i];
    }
    return sum;
}
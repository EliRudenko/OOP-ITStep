//Лексическое окружение

function Func1()
{
    let f1 = 0;

    function Func2()
    {
        let f2 = 1;
        f1 = 5;
        console.log(f1);
    }
    Func2();
}

Func1();
Func1();
Func1();

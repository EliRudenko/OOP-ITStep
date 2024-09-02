const readline = require('readline');

function add(a, b) { return a + b; }

function subtract(a, b) { return a - b; }

function multiply(a, b) { return a * b; }

function divide(a, b) 
{
    if (b === 0) { return 'Ошибка: деление на ноль'; }

    return a / b;
}

function Calc() 
{
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('Введите первое число: ', (num1) => 
    {
        rl.question('Введите операцию (+, -, *, /): ', (operation) => 
        {
            rl.question('Введите второе число: ', (num2) => 
            {
                const a = parseFloat(num1);
                const b = parseFloat(num2);
                let result;

                switch (operation) 
                {
                    case '+':
                        result = add(a, b);
                        break;
                    case '-':
                        result = subtract(a, b);
                        break;
                    case '*':
                        result = multiply(a, b);
                        break;
                    case '/':
                        result = divide(a, b);
                        break;
                    default:
                        result = 'Ошибка: неизвестная операция';
                }

                console.log(`Результат: ${result}`);
                rl.close();
            });
        });
    });
}

module.exports = Calc;

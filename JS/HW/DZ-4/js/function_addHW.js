//1
function stringFrom() 
{
    return Array.from(arguments).join(' ');
}

//2
function min() 
{
    if (arguments.length === 0) { return undefined; }

    let min_argument = arguments[0];
    for (let i = 1; i < arguments.length; i++) 
    {
        if (arguments[i] < min_argument) {min_argument = arguments[i]; }
    }
    return min_argument;
}

//3
function numbers() 
{
    let count = 0;
    for (let i = 0; i < arguments.length; i++) 
    {
        if (typeof arguments[i] === 'number') { count++; }
    }
    return count;
}

//4
function mean() 
{
    let sum = 0;
    let count = 0;
    for (let i = 0; i < arguments.length; i++) 
    {
        if (typeof arguments[i] === 'number') 
        {
            sum += arguments[i];
            count++;
        }
    }
    return count === 0 ? 0 : sum / count;
}

//5
function Power(x) 
{
    if (x === 1) 
    {
        return true;
    } 
    else if (x < 1 || x % 2 !== 0) 
    {
        return false;
    }
    return Power(x / 2);
}

//6
function reverse_number(number) 
{
    if (number < 10) 
    {
        return number.toString();

    } else { return (number % 10) + reverse_number(Math.floor(number / 10)); }
}

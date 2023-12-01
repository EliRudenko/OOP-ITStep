//1
function days_work(initial_volume) 
{
    const leak_percentage = 0.1;
    const emergency_volume = 10;
    let days_work = 0;

    while (initial_volume >= emergency_volume) 
    {
        initial_volume -= initial_volume * leak_percentage;
        days_work++;
    }

    return days_work;
}

//2
function sayError() { alert("Some error occurred!"); }

//3
function showError(x) { alert(`Error ${x} occurred!`); }


//4
function createHeaders(N) 
{
    for (let i = 1; i <= N; i++) 
    {
        const header = document.createElement('h2');
        header.textContent = `Header${i}`;
        document.body.appendChild(header);
    }
}


//5
function checkPassword(x) 
{
    const valid_passwords = ['Step', 'Web', 'JavaScript'];
    return valid_passwords.includes(x);
}


//6
function sign(x) 
{
    if (x < 0) 
    {
        return -1;
    } 
    else if (x > 0) 
    {
        return 1;

    } else { return 0; }
}


// Задача 6
function day_name_number(number) 
{
    const days_week = 
    [
        'Sunday',
        'Monday',
        'Tuesday',
        'Wednesday',
        'Thursday',
        'Friday',
        'Saturday'
    ];
    return days_week[number] || 'Invalid day number';
}

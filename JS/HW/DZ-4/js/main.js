//1
const initial_volume = parseFloat(prompt("Enter the initial volume of water:"));
const days = days_work(initial_volume);
alert(`Water will last for ${days} days`);

//2
sayError();

//3
showError('Out of memory occurred!');

//4
createHeaders(3);

//5
const password1 = 'Step';
const password2 = 'Web';
const password3 = 'JavaScript';
const password4 = 'Invalid';

console.log(checkPassword(password1));
console.log(checkPassword(password2));
console.log(checkPassword(password3));
console.log(checkPassword(password4));

//6
const negative = -7;
const zero = 0;
const positive = 5;
console.log(sign(negative));
console.log(sign(zero)); 
console.log(sign(positive));

//7
console.log(day_name_number(0));
console.log(day_name_number(5));


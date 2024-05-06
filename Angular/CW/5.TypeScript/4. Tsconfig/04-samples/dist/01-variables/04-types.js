// Boolean
let isDone = false;
//isDone = 1; // [ts] - type '1' is not assignable to type 'boolean'
console.log(isDone);
//  Number
let a1_decimal = 10;
let a2_hex = 0x000a;
let a3_binary = 0b1010;
let a4_octal = 0o12;
console.log(a1_decimal);
console.log(a2_hex);
console.log(a3_binary);
console.log(a4_octal);
// String
let firstName = "Ivan";
let age = 25;
let messageTemplate = `Hello, my name is ${firstName} I'm ${age} years old.`; // template string
let messageConcat = "Hello, my name is " + firstName + " I'm " + age + " years old."; // concatenation
console.log(messageTemplate);
console.log(messageConcat);
//# sourceMappingURL=04-types.js.map
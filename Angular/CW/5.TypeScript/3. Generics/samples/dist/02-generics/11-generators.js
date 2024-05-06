// function* - generator function
function* stringSequence() {
    yield "Hello";
    yield " ";
    yield "world";
    yield "!";
}
let iterable1 = stringSequence(); // получение generator object само тело функции не выполняется
let result = "";
// когда будет вызван метод next начнет выполнятся generator funciton до первого ключевого слова yield
// после этого функция приостановит свою работу до следующего вызова метода next
for (const item of iterable1) {
    result += item;
}
console.log(result);
class MyStringCollection {
    constructor() {
        this.values = [];
        this.values[0] = "Hello";
        this.values[1] = " ";
        this.values[2] = "world";
        this.values[3] = "!";
    }
    *getValues() {
        for (let i = 0; i < this.values.length; i++) {
            yield this.values[i];
        }
    }
}
let iterable2 = new MyStringCollection().getValues();
result = "";
for (const item of iterable2) {
    result += item;
}
console.log(result);
console.log(iterable2);
//# sourceMappingURL=11-generators.js.map
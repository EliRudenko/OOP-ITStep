function let1() {

    //console.log(i); // [ts] cannot find name i
    //console.log(test); // [ts] cannot find name test

    for(let i = 0; i < 10; i ++) {
        let test = i;
    }

    //console.log(i); // [ts] cannot find name i
    //console.log(test); // [ts] cannot find name test
}

let1();


// Повторное определение переменной не приводит к ошибке.
function let2() {
    let a = 10;
    //var a = 20; // [ts] cannot redeclare block-scoped variable a
    console.log(a); // 10
}

let2();

// 0, 1, 2, 3, 4
// будет работать только при наличии опции для компилятора "target": "es6",
function let3() {
    for (let i = 0; i < 5; i++) {
        setTimeout(function() { console.log(i) }, 10);     
    }
}

let3();
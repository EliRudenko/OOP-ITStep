class MyGenericClass {
    method1(value1) {
        console.log(value1);
    }
    method2() {
        return this.value;
    }
}
// Экземпляр обобщенного типа, закрытого типом number
let myGenericNumber = new MyGenericClass();
myGenericNumber.method1(10);
myGenericNumber.value = 100;
console.log(myGenericNumber.method2());
// Экземпляр обобщенного типа, закрытого типом string
let myGenericString = new MyGenericClass();
myGenericString.method1("hello");
myGenericString.value = "world";
console.log(myGenericString.method2());
//# sourceMappingURL=04-generic-class.js.map
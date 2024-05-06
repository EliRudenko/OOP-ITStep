class KeyValuePair {
    set key(value) {
        if (value == null || value == undefined) {
            throw new Error("Значение value не может быть пустым.");
        }
        this._key = value;
    }
    get key() {
        return this._key;
    }
    set value(value) {
        if (value == null || value == undefined) {
            throw new Error("Значение value не может быть пустым.");
        }
        this._value = value;
    }
    get value() {
        return this._value;
    }
}
let strAndNum = new KeyValuePair();
strAndNum.key = "key1";
strAndNum.value = 123;
//strAndNum.value = "123";
strAndNum.key = null;
//# sourceMappingURL=05-generic-class.js.map
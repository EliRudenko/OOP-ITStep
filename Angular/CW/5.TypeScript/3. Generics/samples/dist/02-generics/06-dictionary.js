class Dictionary {
    constructor() {
        this.data = [];
    }
    add(key, value) {
        let entry = new KeyValuePair();
        entry.key = key;
        entry.value = value;
        this.data.push(entry);
    }
    getValue(key) {
        for (let i = 0; i < this.data.length; i++) {
            if (this.data[i].key == key) {
                return this.data[i].value;
            }
        }
        return null;
    }
}
let dictionary = new Dictionary();
dictionary.add("hello", "привет");
dictionary.add("book", "книга");
dictionary.add("apple", "яблоко");
console.log(dictionary.getValue("book"));
let dictionary2 = new Dictionary();
dictionary2.add(1, true);
dictionary2.add(2, false);
dictionary2.add(7, true);
console.log(dictionary2.getValue(7));
//# sourceMappingURL=06-dictionary.js.map
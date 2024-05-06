class Dictionary<TKey, TValue> {

    private data: KeyValuePair<TKey, TValue>[] = [];

    public add(key: TKey, value: TValue) {
        let entry = new KeyValuePair<TKey, TValue>();
        entry.key = key;
        entry.value = value;
        this.data.push(entry);
    }
    
    public getValue(key: TKey) : TValue | null {
        for(let i = 0; i < this.data.length; i ++) {
            if(this.data[i].key == key) {
                return this.data[i].value;
            }
        }

        return null;
    }
}

let dictionary = new Dictionary<string, string> ();
dictionary.add("hello", "привет");
dictionary.add("book", "книга");
dictionary.add("apple", "яблоко");

console.log(dictionary.getValue("book"));


let dictionary2 = new Dictionary<number, boolean> ();
dictionary2.add(1, true);
dictionary2.add(2, false);
dictionary2.add(7, true);

console.log(dictionary2.getValue(7));
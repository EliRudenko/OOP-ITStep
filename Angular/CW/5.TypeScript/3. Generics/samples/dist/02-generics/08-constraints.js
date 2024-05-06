// Для EqualityComparer<T> type variable будет такой же как для UniqueCollection
class UniqueCollection {
    constructor() {
        this.data = [];
    }
    add(item) {
        let unique = this.data.every(x => !x.equals(item));
        if (unique) {
            this.data.push(item);
        }
    }
    showData() {
        this.data.forEach(x => console.log(x));
    }
}
class Order {
    constructor(id, customer, product) {
        this.id = id;
        this.customer = customer;
        this.product = product;
    }
    equals(item) {
        return item.id == this.id;
    }
}
let order1 = new Order(1, "John", "Laptop");
let order2 = new Order(2, "Robin", "Mobile Phone");
let order3 = new Order(3, "Bob", "Book");
let order4 = new Order(1, "Stephan", "Book");
let collection = new UniqueCollection();
collection.add(order1);
collection.add(order2);
collection.add(order3);
collection.add(order4);
collection.showData();
//# sourceMappingURL=08-constraints.js.map
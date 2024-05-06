interface EqualityComparer<T> {
    equals(item: T): boolean;
}

// Для EqualityComparer<T> type variable будет такой же как для UniqueCollection
class UniqueCollection<T extends EqualityComparer<T>> {

    private data: T[] = [];

    public add(item: T) {
        let unique: boolean = this.data.every(x => !x.equals(item));
        if (unique) {
            this.data.push(item);
        }
    }

    public showData() {
        this.data.forEach(x => console.log(x));
    }
}

class Order implements EqualityComparer<Order> {

    constructor(
        public id: number,
        public customer: string,
        public product: string
    ) { }

    equals(item: Order): boolean {
        return item.id == this.id;
    }

}

let order1 = new Order(1, "John", "Laptop");
let order2= new Order(2, "Robin", "Mobile Phone");
let order3 = new Order(3, "Bob", "Book");
let order4= new Order(1, "Stephan", "Book");

let collection = new UniqueCollection<Order>();
collection.add(order1);
collection.add(order2);
collection.add(order3);
collection.add(order4);

collection.showData();
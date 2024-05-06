// <T extends Countable> - ограничение, указывающее на то, что T (type variable) 
// должна быть типом данных, который реализовывает интерфейс Countable, так как
// логика класса SortableList подразумевает использование свойства count
class SortableList {
    constructor() {
        this.data = [];
    }
    add(item) {
        this.data.push(item);
    }
    showSorted() {
        // (a, b) => a.count - b.count - данное выражение компилируется благодаря
        // ограничению. TS компилятор знает, что тип данных переданный в качестве T
        // будет содержать свойство count
        let sorted = this.data.sort((a, b) => a.count - b.count);
        sorted.forEach(x => console.log(x));
    }
}
class OrdersArchive {
    constructor(month, count, totalAmount) {
        this.month = month;
        this.count = count;
        this.totalAmount = totalAmount;
    }
}
let list = new SortableList();
list.add(new OrdersArchive("January", 11, 23400));
list.add(new OrdersArchive("February", 8, 18100));
list.add(new OrdersArchive("March", 12, 22900));
list.showSorted();
//# sourceMappingURL=07-constraints.js.map
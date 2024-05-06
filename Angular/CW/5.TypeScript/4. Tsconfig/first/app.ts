class User {
    name: string; //string name;
    constructor(_name: string) {

        this.name = _name;
    }
}

const tom: User = new User("Том"); // User tom = new User("Tom");
const header = this.document.getElementById("header");

header.innerHTML = "Hello " + tom.name;

let obj1 = new User(" Irina");
header.innerHTML += obj1.name;








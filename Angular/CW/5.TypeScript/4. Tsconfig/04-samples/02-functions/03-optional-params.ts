// В TypeScript все параметры функции являются обязательными.
// но если после имени параметра указать символ ? параметр становиться опциональным, и если при вызове его не предоставить
// значение этого параметра будет undefined 
// Опциональные параметры могут быть только последними параметрами в списке параметров метода.

// optional parameters
function getFullName(firstName: string, lastName?: string): string { 
    if (lastName) {
        return firstName + " " + lastName;
    }
    else {
        return firstName;
    }
}

let fullNmae1: string = getFullName("Ivan", "Ivanov");
let fullNmae2: string = getFullName("Ivan");

console.log(fullNmae1);
console.log(fullNmae2);

// Параметры со значением по умолчанию - параметры метода, для которых в объявлении функции присвоено значение,
// которое будет использоваться если функция будет вызвана без указания значения для данного параметра или 
// если в качестве значение будет передано undefined

// default-iniatialize parametes
function getDisplayName(firstName: string, lastName: string = "Ivanov") {
    return "Display Name: " + firstName + " " + lastName;
}

let fullNmae3: string = getDisplayName("Ivan", "Ivanov");
let fullNmae4: string = getDisplayName("Ivan");
let fullNmae5: string = getDisplayName("Ivan", undefined); // идентичен предыдущему вызову

console.log(fullNmae3);
console.log(fullNmae4);
console.log(fullNmae5);

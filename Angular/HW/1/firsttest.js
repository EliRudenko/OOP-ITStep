var Student = /** @class */ (function () {
    function Student(fullName, birthdate, phoneNumber, city, country, university, groupNumber) {
        this._fullName = fullName;
        this._birthdate = birthdate;
        this._phoneNumber = phoneNumber;
        this._city = city;
        this._country = country;
        this._university = university;
        this._groupNumber = groupNumber;
    }
    Object.defineProperty(Student.prototype, "fullName", {
        get: function () { return this._fullName; },
        set: function (value) { this._fullName = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "birthdate", {
        get: function () { return this._birthdate; },
        set: function (value) { this._birthdate = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "phoneNumber", {
        get: function () { return this._phoneNumber; },
        set: function (value) { this._phoneNumber = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "city", {
        get: function () { return this._city; },
        set: function (value) { this._city = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "country", {
        get: function () { return this._country; },
        set: function (value) { this._country = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "university", {
        get: function () { return this._university; },
        set: function (value) { this._university = value; },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Student.prototype, "groupNumber", {
        get: function () { return this._groupNumber; },
        set: function (value) { this._groupNumber = value; },
        enumerable: false,
        configurable: true
    });
    Student.prototype.displayData = function () {
        console.log("Full Name: ".concat(this._fullName));
        console.log("Birthdate: ".concat(this._birthdate.toDateString()));
        console.log("Phone Number: ".concat(this._phoneNumber));
        console.log("City: ".concat(this._city));
        console.log("Country: ".concat(this._country));
        console.log("University: ".concat(this._university));
        console.log("Group Number: ".concat(this._groupNumber));
    };
    return Student;
}());
var students = [
    new Student("Lara May", new Date(2003, 7, 30), "0680506080", "Odesa", "Ukrain", "STEP", "KH--1"),
    new Student("Mark Laur", new Date(2001, 11, 13), "0674846080", "Kyev", "Ukraine", "STEP", "KH-2"),
];
var table = document.createElement("table");
table.border = "2";
table.style.borderCollapse = "collapse";
table.style.width = "100%";
table.style.textAlign = "center";
var headerRow = document.createElement("tr");
["Full Name", "Birthdate", "Phone Number", "City", "Country", "University", "Group Number"].forEach(function (headerText) {
    var headerCell = document.createElement("th");
    headerCell.textContent = headerText;
    headerRow.appendChild(headerCell);
});
table.appendChild(headerRow);
students.forEach(function (student) {
    var row = document.createElement("tr");
    [student.fullName, student.birthdate.toDateString(), student.phoneNumber, student.city, student.country, student.university, student.groupNumber].forEach(function (cellText) {
        var cell = document.createElement("td");
        cell.textContent = cellText;
        row.appendChild(cell);
    });
    table.appendChild(row);
});
document.body.appendChild(table);

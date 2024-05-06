class Student 
{
    private _fullName: string;
    private _birthdate: Date;
    private _phoneNumber: string;
    private _city: string;
    private _country: string;
    private _university: string;
    private _groupNumber: string;

    constructor(fullName: string, birthdate: Date, phoneNumber: string, city: string, country: string, university: string, groupNumber: string) 
    {
        this._fullName = fullName;
        this._birthdate = birthdate;
        this._phoneNumber = phoneNumber;
        this._city = city;
        this._country = country;
        this._university = university;
        this._groupNumber = groupNumber;
    }

    get fullName(): string { return this._fullName; }
    set fullName(value: string) { this._fullName = value; }

    get birthdate(): Date { return this._birthdate; }
    set birthdate(value: Date) { this._birthdate = value; }

    get phoneNumber(): string { return this._phoneNumber; }
    set phoneNumber(value: string) { this._phoneNumber = value; }

    get city(): string { return this._city; }
    set city(value: string) { this._city = value; }

    get country(): string { return this._country; }
    set country(value: string) { this._country = value; }

    get university(): string { return this._university; }
    set university(value: string) { this._university = value; }

    get groupNumber(): string { return this._groupNumber; }
    set groupNumber(value: string) { this._groupNumber = value; }


    displayData(): void 
    {
        console.log(`Full Name: ${this._fullName}`);
        console.log(`Birthdate: ${this._birthdate.toDateString()}`);
        console.log(`Phone Number: ${this._phoneNumber}`);
        console.log(`City: ${this._city}`);
        console.log(`Country: ${this._country}`);
        console.log(`University: ${this._university}`);
        console.log(`Group Number: ${this._groupNumber}`);
    }
}

let students: Student[] = 
[
    new Student("Lara May", new Date(2003, 7, 30), "0680506080", "Odesa", "Ukrain", "STEP", "KH--1"),
    new Student("Mark Laur", new Date(2001, 11, 13), "0674846080", "Kyev", "Ukraine", "STEP", "KH-2"),
];


const table = document.createElement("table");
table.border = "2";
table.style.borderCollapse = "collapse";
table.style.width = "100%";
table.style.textAlign = "center";

const headerRow = document.createElement("tr");
["Full Name", "Birthdate", "Phone Number", "City", "Country", "University", "Group Number"].forEach(headerText => 
{
    const headerCell = document.createElement("th");
    headerCell.textContent = headerText;
    headerRow.appendChild(headerCell);
});
table.appendChild(headerRow);

students.forEach(student => 
{
    const row = document.createElement("tr");
    [student.fullName, student.birthdate.toDateString(), student.phoneNumber, student.city, student.country, student.university, student.groupNumber].forEach(cellText => 
    {
        const cell = document.createElement("td");
        cell.textContent = cellText;
        row.appendChild(cell);
    });
    table.appendChild(row);
});

document.body.appendChild(table);

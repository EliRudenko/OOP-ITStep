const Student = require('./Student');

class Group 
{
    constructor() { this.students = []; }

    addStudent(name, id) 
    {
        const student = new Student(name, id);
        this.students.push(student);
    }

    removeStudent(id) { this.students = this.students.filter(student => student.id !== id); }

    editStudent(id, newName) 
    {
        const student = this.students.find(student => student.id === id);

        if (student) { student.name = newName; }
    }

    printAllStudents() { this.students.forEach(student => student.printInfo()); }
}

module.exports = Group;

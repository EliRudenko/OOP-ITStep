const Group = require('./Group');

const group = new Group();

group.addStudent('Лара Ивановна', 1);
group.addStudent('Катя Олеговна', 2);

group.printAllStudents();

group.editStudent(1, 'Маша Дмитровна');
group.printAllStudents();

group.removeStudent(2);
group.printAllStudents();


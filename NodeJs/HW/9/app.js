const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const mssql = require('mssql');

const app = express();
const port = 8080;

const config = 
{
    server: 'Elin-TUF\\ELI',
    database: 'Library',

    user: 'admin',
    password: 'admin',

    options: 
    {
        encrypt: true,
        trustServerCertificate: true,
    },
    port: 1433,
};

app.use(bodyParser.urlencoded({ extended: true }));
app.use('/styles', express.static(path.join(__dirname, 'styles')));

app.get('/', (req, res) => 
{
    res.send(`
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>University Management System</title>
            <link rel="stylesheet" href="/styles/style.css">
        </head>
        <body>
            <h1>University Management System</h1>
            <ul>
                <li><a href="/faculties">Faculties</a></li>
                <li><a href="/groups">Groups</a></li>
                <li><a href="/students">Students</a></li>
            </ul>
        </body>
        </html>
    `);
});


app.get('/faculties', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Faculties</h1>
        <ul>
            <li><a href="/faculties/add">Add Faculty</a></li>
            <li><a href="/faculties/edit">Edit Faculty</a></li>
            <li><a href="/faculties/delete">Delete Faculty</a></li>
        </ul>
        <a href="/">Back to Home</a>
    `);
});

app.get('/faculties/add', (req, res) =>
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Add New Faculty</h1>
        <form action="/faculties/add" method="post">
            <label for="name">Faculty Name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Add Faculty</button>
        </form>
        <a href="/faculties">Back to Faculties</a>
    `);
});

app.post('/faculties/add', (req, res) => 
{
    const facultyName = req.body.name;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('facultyName', mssql.VarChar, facultyName)
            .query('INSERT INTO Faculties (Name) VALUES (@facultyName)');
    }).then(result =>
    {
        res.send(`
            <h1>Faculty "${facultyName}" added successfully</h1>
            <a href="/faculties">Back to Faculties</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/faculties/edit', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Edit Faculty</h1>
        <form action="/faculties/edit" method="post">
            <label for="id">Faculty ID:</label>
            <input type="number" id="id" name="id" required>
            <label for="name">New Faculty Name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Edit Faculty</button>
        </form>
        <a href="/faculties">Back to Faculties</a>
    `);
});

app.post('/faculties/edit', (req, res) => 
{
    const facultyId = req.body.id;
    const newName = req.body.name;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('facultyId', mssql.Int, facultyId)
            .input('newName', mssql.VarChar, newName)
            .query('UPDATE Faculties SET Name = @newName WHERE FacultyID = @facultyId');
    }).then(result => 
    {
        res.send(`
            <h1>Faculty with ID ${facultyId} updated to "${newName}" successfully</h1>
            <a href="/faculties">Back to Faculties</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/faculties/delete', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Delete Faculty</h1>
        <form action="/faculties/delete" method="post">
            <label for="id">Faculty ID:</label>
            <input type="number" id="id" name="id" required>
            <button type="submit">Delete Faculty</button>
        </form>
        <a href="/faculties">Back to Faculties</a>
    `);
});

app.post('/faculties/delete', (req, res) => 
{
    const facultyId = req.body.id;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('facultyId', mssql.Int, facultyId)
            .query('DELETE FROM Faculties WHERE FacultyID = @facultyId');
    }).then(result => 
    {
        res.send(`
            <h1>Faculty with ID ${facultyId} deleted successfully</h1>
            <a href="/faculties">Back to Faculties</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});


app.get('/groups', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Groups</h1>
        <ul>
            <li><a href="/groups/add">Add Group</a></li>
            <li><a href="/groups/edit">Edit Group</a></li>
            <li><a href="/groups/delete">Delete Group</a></li>
        </ul>
        <a href="/">Back to Home</a>
    `);
});

app.get('/groups/add', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Add New Group</h1>
        <form action="/groups/add" method="post">
            <label for="name">Group Name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Add Group</button>
        </form>
        <a href="/groups">Back to Groups</a>
    `);
});

app.post('/groups/add', (req, res) => 
{
    const groupName = req.body.name;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('groupName', mssql.VarChar, groupName)
            .query('INSERT INTO Groups (Name) VALUES (@groupName)');
    }).then(result => 
    {
        res.send(`
            <h1>Group "${groupName}" added successfully</h1>
            <a href="/groups">Back to Groups</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/groups/edit', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Edit Group</h1>
        <form action="/groups/edit" method="post">
            <label for="id">Group ID:</label>
            <input type="number" id="id" name="id" required>
            <label for="name">New Group Name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Edit Group</button>
        </form>
        <a href="/groups">Back to Groups</a>
    `);
});

app.post('/groups/edit', (req, res) => 
{
    const groupId = req.body.id;
    const newName = req.body.name;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('groupId', mssql.Int, groupId)
            .input('newName', mssql.VarChar, newName)
            .query('UPDATE Groups SET Name = @newName WHERE GroupID = @groupId');
    }).then(result => 
    {
        res.send(`
            <h1>Group with ID ${groupId} updated to "${newName}" successfully</h1>
            <a href="/groups">Back to Groups</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/groups/delete', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Delete Group</h1>
        <form action="/groups/delete" method="post">
            <label for="id">Group ID:</label>
            <input type="number" id="id" name="id" required>
            <button type="submit">Delete Group</button>
        </form>
        <a href="/groups">Back to Groups</a>
    `);
});

app.post('/groups/delete', (req, res) => 
{
    const groupId = req.body.id;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('groupId', mssql.Int, groupId)
            .query('DELETE FROM Groups WHERE GroupID = @groupId');
    }).then(result => 
    {
        res.send(`
            <h1>Group with ID ${groupId} deleted successfully</h1>
            <a href="/groups">Back to Groups</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});


app.get('/students', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Students</h1>
        <ul>
            <li><a href="/students/add">Add Student</a></li>
            <li><a href="/students/edit">Edit Student</a></li>
            <li><a href="/students/delete">Delete Student</a></li>
        </ul>
        <a href="/">Back to Home</a>
    `);
});

app.get('/students/add', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Add New Student</h1>
        <form action="/students/add" method="post">
            <label for="name">Student Name:</label>
            <input type="text" id="name" name="name" required>
            <label for="group">Group ID:</label>
            <input type="number" id="group" name="group" required>
            <button type="submit">Add Student</button>
        </form>
        <a href="/students">Back to Students</a>
    `);
});

app.post('/students/add', (req, res) => 
{
    const studentName = req.body.name;
    const groupId = req.body.group;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('studentName', mssql.VarChar, studentName)
            .input('groupId', mssql.Int, groupId)
            .query('INSERT INTO Students (Name, GroupID) VALUES (@studentName, @groupId)');
    }).then(result => 
    {
        res.send(`
            <h1>Student "${studentName}" added successfully</h1>
            <a href="/students">Back to Students</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/students/edit', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Edit Student</h1>
        <form action="/students/edit" method="post">
            <label for="id">Student ID:</label>
            <input type="number" id="id" name="id" required>
            <label for="name">New Student Name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Edit Student</button>
        </form>
        <a href="/students">Back to Students</a>
    `);
});

app.post('/students/edit', (req, res) => 
{
    const studentId = req.body.id;
    const newName = req.body.name;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('studentId', mssql.Int, studentId)
            .input('newName', mssql.VarChar, newName)
            .query('UPDATE Students SET Name = @newName WHERE StudentID = @studentId');
    }).then(result => 
    {
        res.send(`
            <h1>Student with ID ${studentId} updated to "${newName}" successfully</h1>
            <a href="/students">Back to Students</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.get('/students/delete', (req, res) => 
{
    res.send(`
        <link rel="stylesheet" href="/styles/style.css">
        <h1>Delete Student</h1>
        <form action="/students/delete" method="post">
            <label for="id">Student ID:</label>
            <input type="number" id="id" name="id" required>
            <button type="submit">Delete Student</button>
        </form>
        <a href="/students">Back to Students</a>
    `);
});

app.post('/students/delete', (req, res) =>
{
    const studentId = req.body.id;

    mssql.connect(config).then(pool => 
    {
        return pool.request()
            .input('studentId', mssql.Int, studentId)
            .query('DELETE FROM Students WHERE StudentID = @studentId');
    }).then(result => 
    {
        res.send(`
            <h1>Student with ID ${studentId} deleted successfully</h1>
            <a href="/students">Back to Students</a>
        `);
    }).catch(err => 
    {
        res.status(500).send(err.message);
    });
});

app.listen(port, () => 
{
    console.log(`Server is running on http://localhost:${port}`);
});

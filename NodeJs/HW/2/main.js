const EventEmitter = require('events');

class FileStream extends EventEmitter 
{
    constructor() { super(); }

    readFile(fileName) 
    {
        console.log('файл прочитан');
      
        this.emit('fileRead', fileName);
    }
    writeFile(fileName) 
    {
        console.log('файл записан');

        this.emit('fileWritten', fileName);
    }
}


const fileStream = new FileStream();


fileStream.on('fileRead', (fileName) => { console.log(`Обработчик события: файл ${fileName} был прочитан.`); });

fileStream.on('fileWritten', (fileName) => { console.log(`Обработчик события: файл ${fileName} был записан.`); });

fileStream.readFile('example.txt');
fileStream.writeFile('example.txt');

const Contender = require('./Contender');

class Cat extends Contender 
{
    constructor() 
    {
        super();
        this.name = 'Cat';
    }
}

module.exports = Cat;

const Contender = require('./Contender');

class Robot extends Contender 
{
    constructor() 
    {
        super();
        this.name = 'Robot';
    }
}

module.exports = Robot;

const Contender = require('./Contender');

class Human extends Contender 
{
    constructor() 
    {
        super();
        this.name = 'Human';
    }
}

module.exports = Human;

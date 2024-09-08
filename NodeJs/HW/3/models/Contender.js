class Contender 
{
    constructor() 
    {
        this.name = '';
        this.limiting = 0;
    }

    jumping() { return `${this.name} is jumping`; }

    running() { return `${this.name} is running`; }

    setLimit(limit) { this.limiting = limit; }
    
}

module.exports = Contender;

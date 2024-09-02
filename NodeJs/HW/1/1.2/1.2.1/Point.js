class Point 
{
    constructor(x, y) 
    {
        this.x = x;
        this.y = y;
    }

    static isParallelToAxis(p1, p2) 
    {
        if (p1.x === p2.x) 
        {
            return 'Прямая параллельна оси Y';
        } 
        else if (p1.y === p2.y) 
        {
            return 'Прямая параллельна оси X';
        } 
        else { return 'Прямая не параллельна осям X или Y'; }
    }
}

module.exports = Point;

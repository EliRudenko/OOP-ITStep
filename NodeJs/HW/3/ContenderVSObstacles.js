const GettingOver = require('./GettingOver');

function ContenderVSObstacles(contenders, obstacles) 
{
    for (let i = 0; i < contenders.length; i++) 
    {
        let oneContSum = 0;
        let completeCheck = true;

        for (let j = 0; j < obstacles.length; j++) 
        {
            if (GettingOver(contenders[i], obstacles[j]))
            {
                oneContSum += obstacles[j].distance;
            } 
            else 
            {
                console.log(`Contender ${i + 1}(${contenders[i].name}) failed the course of obstacles at obstacle ${j + 1} (${obstacles[j].name}) with the distance ${oneContSum}`);
                completeCheck = false;
                break;
            }
        }

        if (completeCheck) { console.log(`Contender ${i + 1} completed the course of obstacles`); }
        
    }
}

module.exports = ContenderVSObstacles;

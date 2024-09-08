const crypto = require('crypto');
const Cat = require('./models/Cat');
const Human = require('./models/Human');
const Robot = require('./models/Robot');
const Wall = require('./obstacles/Wall');
const Track = require('./obstacles/Track');
const ContenderVSObstacles = require('./ContenderVSObstacles');


function initializeData() 
{
    let contenders = [];
    for (let i = 0; i < 10; i++) 
    {
        let randContType = crypto.randomInt(0, 3); 
        let randLimit = crypto.randomInt(30, 3000);

        switch (randContType) 
        {
            case 0:
                let cat = new Cat();
                cat.setLimit(randLimit);
                contenders.push(cat);
                break;
            case 1:
                let robot = new Robot();
                robot.setLimit(randLimit);
                contenders.push(robot);
                break;
            case 2:
                let human = new Human();
                human.setLimit(randLimit);
                contenders.push(human);
                break;
        }
    }

    let obstacles = [];
    for (let i = 0; i < 10; i++) 
    {
        let randObstType = crypto.randomInt(0, 2); 
        let randLimit = crypto.randomInt(30, 200);

        switch (randObstType) {
            case 0:
                let wall = new Wall();
                wall.setDistance(randLimit);
                obstacles.push(wall);
                break;
            case 1:
                let track = new Track();
                track.setDistance(randLimit);
                obstacles.push(track);
                break;
        }
    }

    ContenderVSObstacles(contenders, obstacles);
}

module.exports = initializeData;

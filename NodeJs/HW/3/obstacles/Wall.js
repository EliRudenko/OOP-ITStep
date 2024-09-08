const Obstacle = require('./Obstacle');

class Wall extends Obstacle {
    constructor() {
        super();
        this.name = 'Wall';
    }

    isJumpable() {
        return true;
    }
}

module.exports = Wall;

const Obstacle = require('./Obstacle');

class Track extends Obstacle {
    constructor() {
        super();
        this.name = 'Track';
    }

    isRunnable() {
        return true;
    }
}

module.exports = Track;

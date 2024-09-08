class Obstacle {
    constructor() {
        this.name = '';
        this.distance = 0;
    }

    isRunnable() {
        return false;
    }

    isJumpable() {
        return false;
    }

    setDistance(num) {
        this.distance = num;
    }
}

module.exports = Obstacle;

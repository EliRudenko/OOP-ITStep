function GettingOver(contender, obstacle) 
{
    if (contender.limiting >= obstacle.distance) 
    {
        if (obstacle.isJumpable())
        {
            console.log(contender.jumping(), 'over the', obstacle.name);
        } 
        else if (obstacle.isRunnable()) 
        {
            console.log(contender.running(), 'on the', obstacle.name);
        }

        contender.limiting -= obstacle.distance;
        return true;
    }
    
    return false;
}

module.exports = GettingOver;

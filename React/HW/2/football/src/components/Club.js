import React, { Component } from 'react';
import ClubInfo from './ClubInfo';
import Achievements from './Achievements';
import Compound from './Compound';

class Club extends Component 
{
    render() 
    {
        const { club, style } = this.props;
        return (
            <div style={style.container}>
                <ClubInfo 
                    name={club.name} 
                    city={club.city} 
                    founded={club.founded} 
                    logo={club.logo} 
                    style={style.clubInfo} 
                />
                <Achievements 
                    achievements={club.achievements} 
                    style={style.achievements} 
                />
                <Compound 
                    players={club.players} 
                    style={style.compound} 
                />
            </div>
        );
    }
}

export default Club;

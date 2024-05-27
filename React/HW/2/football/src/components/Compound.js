import React, { Component } from 'react';
class Compound extends Component 
{
    render() 
    {
        const { players, style } = this.props;
        return (
            <div style={style}>
                <h3>Текущий состав команды</h3>
                <ul>
                    {players.map((player, index) => (
                        <li key={index}>{player.name} - {player.position}</li>
                    ))}
                </ul>
            </div>
        );
    }
}

export default Compound;

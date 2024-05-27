import React, { Component } from 'react';
class Achievements extends Component 
{
    render() 
    {
        const { achievements, style } = this.props;
        return (
            <div style={style}>
                <h3>Достижения</h3>
                <ul>
                    {achievements.map((achievement, index) => (
                        <li key={index}>{achievement}</li>
                    ))}
                </ul>
            </div>
        );
    }
}

export default Achievements;

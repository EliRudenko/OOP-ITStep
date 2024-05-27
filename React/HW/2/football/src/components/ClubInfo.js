import React, { Component } from 'react';
class ClubInfo extends Component 
{
    render() 
    {
        const { name, city, founded, logo, style } = this.props;
        return (
            <div style={style}>
                <h2>{name}</h2>
                <p>Город: {city}</p>
                <p>Дата основания: {founded}</p>
                <img 
                    src={logo}
                    alt={`Герб ${name}`}
                    style={{ width: '150px', marginTop: '10px' }}
                />
            </div>
        );
    }
}

export default ClubInfo;

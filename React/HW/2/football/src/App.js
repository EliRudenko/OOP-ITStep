import React, { Component } from 'react';
import Club from './components/Club';
import styles from './styles';
import './App.css';

class App extends Component 
{
    constructor(props) 
    {
        super(props);
        this.state = 
        {
            clubs: 
            [
                {
                    id: 1,
                    name: 'ФК Динамо Киев',
                    city: 'Киев',
                    founded: 1927,
                    logo: 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQK7AG9QfMOv_4wCUz3_nqpkRTB98ADeraxQJaH3cJWXCfFpbCz4nMBc72PRTJFli3Wp0o&usqp=CAU',
                    
                    achievements: 
                    [
                        'Лига чемпионов УЕФА: 1961, 1965, 1977, 1986',
                        'Чемпионат Украины: 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2007, 2009, 2015, 2016, 2021',
                        'Забитые голы: более 2000 голов в различных турнирах'
                    ],
                    
                    players: 
                    [
                        { name: 'Георгий Бущан', position: 'Вратарь' },
                        { name: 'Александр Караваев', position: 'Защитник' },
                        { name: 'Виктор Цыганков', position: 'Нападающий' }
                    ]
                },
                {
                
                    id: 2,
                    name: 'ФК Шахтёр Донецк',
                    city: 'Донецк',
                    founded: 1936,
                    logo: 'https://pbs.twimg.com/profile_images/846631399323045888/wg2DFA2y_400x400.jpg',
                    
                    achievements: 
                    [
                        'Лига чемпионов УЕФА: 1972',
                        'Чемпионат Украины: 2002, 2005, 2006, 2008, 2010, 2011, 2012, 2013, 2014, 2017, 2018',
                        'Кубок Украины: 2001, 2002, 2004, 2008, 2011, 2012, 2013, 2016, 2017, 2019',
                        'Суперкубок Украины: 2005, 2008, 2010, 2012, 2013, 2014, 2015, 2017, 2020'
                    ],
                    
                    players: 
                    [
                        { name: 'Андрей Пятов', position: 'Вратарь' },
                        { name: 'Тете', position: 'Защитник' },
                        { name: 'Виктор Коваленко', position: 'Полузащитник' },
                        { name: 'Манор Соломон', position: 'Нападающий' }
                    ]
                }
            ]
        };
    }

    render() 
    {
        const randomStyle = styles[Math.floor(Math.random() * styles.length)];
        const { clubs } = this.state;

        return (
            <div className="App">
                <header>
                    <p style={randomStyle.compound}>При перезагрузке, меняется стиль, проверте</p>
                    <h1>Информация о футбольных клубах</h1>
                </header>
                
                {clubs.map((club) => 
                (
                    <div key={club.id} style={{ marginBottom: '20px' }}>
                        <Club club={club} style={randomStyle} />
                        <hr style={{ margin: '100px 0' }} />
                    </div>
                ))}
            </div>
        );
    }
}

export default App;

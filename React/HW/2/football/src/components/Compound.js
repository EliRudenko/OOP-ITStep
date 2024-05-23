const Compound = ({ style }) => 
{
    const players = 
    [
        { name: 'Георгий Бущан', position: 'Вратарь' },
        { name: 'Александр Караваев', position: 'Защитник' },
        { name: 'Виктор Цыганков', position: 'Нападающий' }
    ];

    return (
        <div style={style}>
            <h3>Текущий состав команды</h3>
            <ul>
                {players.map((player, index) => ( <li key={index}>{player.name} - {player.position}</li> ) ) }
            </ul>
        </div>
    );
};

export default Compound;

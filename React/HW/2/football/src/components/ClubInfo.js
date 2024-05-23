const ClubInfo = ({ style }) => 
{
    return (
        <div style={style}>
            <h2>ФК Динамо Киев</h2>
            <p>Город: Киев</p>
            <p>Дата основания: 1927</p>
            <img 
                src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQK7AG9QfMOv_4wCUz3_nqpkRTB98ADeraxQJaH3cJWXCfFpbCz4nMBc72PRTJFli3Wp0o&usqp=CAU" 
                alt="Герб ФК Динамо Киев" 
                style={{ width: '150px', marginTop: '10px' }}
            />
        </div>
    );
};

export default ClubInfo;

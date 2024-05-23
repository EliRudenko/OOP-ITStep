import ClubInfo from './components/ClubInfo';
import Achievements from './components/Achievements';
import Compound from './components/Compound';
import styles from './styles';
import './App.css';

const App = () => 
{
    const randomStyle = styles[Math.floor(Math.random() * styles.length)];

    return (
        <div className="App">
            <header>
                <p style={randomStyle.compound} >При перезагрузке, меняется стиль, проверте</p>
                <h1>Информация о ФК Динамо Киев</h1>
            </header>
            <ClubInfo style={randomStyle.clubInfo} />
            <Achievements style={randomStyle.achievements} />
            <Compound style={randomStyle.compound} />
        </div>
    );
};

export default App;

import './App.css';
import { Card } from './components/cards';

function App() {
    return (
        <div className='pricing-container'>
            <Card tarif="Basic" color="#f28b82" price="99.99"></Card>
            <Card tarif="Standard" color="#fbbc04" price="199.99"></Card>
            <Card tarif="Premium" color="#34a853" price="299.99"></Card>
        </div>
    );
}

export default App;


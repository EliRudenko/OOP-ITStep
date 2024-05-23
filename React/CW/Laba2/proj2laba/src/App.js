import React from 'react';
import Header from './components/Header';
import Portrait from './components/Portrait';
import Biography from './components/Biography';
import Footer from './components/Footer';
import './App.css';

const App = () => 
{
    return (
        <div className="App">
            <Header />
            <Portrait />
            <Biography />
            <Footer />
        </div>
    );
};

export default App;

import React from 'react';
import './App.css';
import { ClickCounter } from './components/ClickCounter';
import { List } from './components/List';

const numbers = [1,2,3,4,5];

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <ClickCounter />
        <List items={numbers} />
        <List items={numbers} />
        <p>
          Hello World !!!
        </p>
       
         </header>
    </div>
  );
}

export default App;

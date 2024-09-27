import React from 'react';
import './Header.css';

const Header = () => {
  return (
    <header className="header">
      <div className="header-top">
        <div className="header-left">
          <p>0487021111 Одеса PIZZA TRACKER НОВИНИ ЗАЛИШИТИ ВІДГУК</p>
        </div>
        <div className="header-right">
          <p>Укр Увійти</p>
        </div>
      </div>
      <div className="header-bottom">
        <img src="https://dominos.ua/_next/image/?url=https%3A%2F%2Fmedia-v3.dominos.ua%2Fmedia%2Fimages%2Fblue-logo.png&w=256&q=75" alt="logo" className="logo" />
        <nav>
          <ul>
            <li>Акції</li>
            <li>Піца</li>
            <li>Напої</li>
            <li>Сайди</li>
            <li>Десерти</li>
          </ul>
        </nav>
        <div className="cart">
          <span>00</span>
          <button>Замовити</button>
        </div>
      </div>
    </header>
  );
};

export default Header;

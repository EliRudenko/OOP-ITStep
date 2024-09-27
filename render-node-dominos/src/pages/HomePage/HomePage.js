import React from 'react';
import Header from '../../components/Header/Header';
import PromoCarousel from '../../components/PromoCarousel/PromoCarousel';
import Filter from '../../components/Filter/Filter';
import PizzaList from '../../components/PizzaList/PizzaList';
import './HomePage.css';

const HomePage = () => {
  return (
    <div className="home-page">
      <Header />
      <PromoCarousel />
      <div className="filter-sort-section">
        <Filter />
      </div>
      <PizzaList />
    </div>
  );
};

export default HomePage;

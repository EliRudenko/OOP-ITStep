import React from 'react';
import PizzaCard from '../PizzaCard/PizzaCard';
import './PizzaList.css';

import pizza1 from '../../assets/pizza1.png';
import pizza2 from '../../assets/pizza1.png';
import pizza3 from '../../assets/pizza1.png';
import pizza4 from '../../assets/pizza1.png';


const pizzas = [
  {
    name: 'Піца з в\'яленими томатами та куркою',
    description: 'Соус Альфредо, В\'ялені томати, Курка, Моцарела',
    price: 335,
    image: pizza1
  },

  {
    name: 'Піца солодка',
    description: 'Моцарела, Банан, Мигдаль, Шоколадний соус',
    price: 275,
    image: pizza2
  },
  {
    name: 'Піца з грушею і блакитним сиром',
    description: 'Соус Альфредо, Груша, Блакитний сир, Моцарела',
    price: 290,
    image: pizza3
  },
  {
    name: 'Піца Бiф енд Криспі',
    description: 'Соус Барбекю, Яловичина, Сир Моцарела, Перець',
    price: 335,
    image: pizza4
  }
];

const PizzaList = () => {
  return (
    <div className="pizza-list">
      {pizzas.map((pizza, index) => (
        <PizzaCard key={index} pizza={pizza} />
      ))}
    </div>
  );
};

export default PizzaList;

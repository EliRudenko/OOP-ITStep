import React, { useState } from 'react';
import './PizzaCard.css';

const PizzaCard = ({ pizza }) => {
  const [quantity, setQuantity] = useState(0);

  const handleAddToCart = () => {
    setQuantity(quantity + 1);
  };

  const handleRemoveFromCart = () => {
    if (quantity > 0) {
      setQuantity(quantity - 1);
    }
  };

  return (
    <div className="pizza-card">
      <img src={pizza.image} alt={pizza.name} className="pizza-image" />
      <h3>{pizza.name}</h3>
      <p>{pizza.description}</p>
      <p>Ціна: {pizza.price} грн</p>

      <div className="pizza-options">
        <label>Розмір:</label>
        <select>
          <option>Мала</option>
          <option>Середня</option>
          <option>Велика</option>
        </select>

        <label>Тісто:</label>
        <select>
          <option>Тонке</option>
          <option>Пухке</option>
        </select>

        <label>Борт:</label>
        <select>
          <option>Звичайний</option>
          <option>Хот-дог</option>
        </select>
      </div>

      <div className="cart-actions">
        {quantity === 0 ? (
          <button className="add-to-cart" onClick={handleAddToCart}>В кошик</button>
        ) : (
          <div className="cart-quantity">
            <button onClick={handleRemoveFromCart}>-</button>
            <span>{quantity}</span>
            <button onClick={handleAddToCart}>+</button>
          </div>
        )}
      </div>
    </div>
  );
};

export default PizzaCard;

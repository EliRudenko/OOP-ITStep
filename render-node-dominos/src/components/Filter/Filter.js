import React from 'react';
import './Filter.css';

const Filter = () => {
  return (
    <div className="filter-sort">
      <div className="filter">
        <button>Фільтр</button>
      </div>
      <div className="sort">
        <select>
          <option>Сортувати</option>
          <option>За ціною</option>
          <option>За популярністю</option>
        </select>
      </div>
    </div>
  );
};

export default Filter;

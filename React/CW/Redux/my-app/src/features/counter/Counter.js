import React, { useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import 
{
  decrement,
  increment,
  incrementByAmount,
  subtractAmount,
  incrementIfOdd,
  subtractIfOdd,
  selectCount,
} from './counterSlice';
import styles from './Counter.module.css';

export function Counter() 
{
  const count = useSelector(selectCount);
  const dispatch = useDispatch();
  const [incrementAmount, setIncrementAmount] = useState('2');

  const incrementValue = Number(incrementAmount) || 0;

  return (
    <div>
      {count % 10 === 0 && count !== 0 && (
        <div style={{ fontSize: '2rem', color: 'red' }}>
          Значение кратно 10!
        </div>
      )}

      <div className={styles.row}>
        <button
          className={styles.button}
          aria-label="Increment value"
          onClick={() => dispatch(increment())}
        > +
        </button>

        <span className={styles.value}>{count}</span>

        <button
          className={styles.button}
          aria-label="Decrement value"
          onClick={() => dispatch(decrement())}
        > -
        </button>

      </div>

      <div className={styles.row}>
        <input
          className={styles.textbox}
          aria-label="Set increment amount"
          value={incrementAmount}
          onChange={e => setIncrementAmount(e.target.value)}
        />
        
        <button
          className={styles.button}
          onClick={() => dispatch(incrementByAmount(incrementValue))}
        > Add Amount
        </button>

        <button
          className={styles.button}
          onClick={() => dispatch(subtractAmount(incrementValue))}
        > Subtract Amount
        </button>

        <button
          className={styles.asyncButton}
          onClick={() => dispatch(incrementIfOdd())}
        > Add If Odd
        </button>

        <button
          className={styles.asyncButton}
          onClick={() => dispatch(subtractIfOdd())}
        > Subtract If Odd
        </button>

      </div>
    </div>
  );
}

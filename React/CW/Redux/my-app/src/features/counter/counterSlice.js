import { createSlice } from '@reduxjs/toolkit';

export const counterSlice = createSlice({
  name: 'counter',
  initialState: { value: 0,},
  reducers: 
  {
    increment: state => { state.value += 1; },
    decrement: state => { state.value -= 1; },
    incrementByAmount: (state, action) => { state.value += action.payload; },
    subtractAmount: (state, action) => { state.value -= action.payload; },
    incrementIfOdd: state => 
    {
      if (state.value % 2 !== 0) { state.value += 1; }
    },
    subtractIfOdd: state => 
    {
      if (state.value % 2 !== 0) { state.value -= 1; }
    },
  },
});

export const { increment, decrement, incrementByAmount, subtractAmount, incrementIfOdd, subtractIfOdd } = counterSlice.actions;

export const selectCount = state => state.counter.value;

export default counterSlice.reducer;

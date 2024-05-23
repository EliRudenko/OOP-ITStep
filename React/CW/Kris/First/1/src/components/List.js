import React from 'react';

const ListItem = props => {
  const value = props.value;
  return <li>{value}</li>
}

export const List = ({ items }) => {
  return (
    <ul>{
      items.map(item => <ListItem key={item.toString()} value={item}/>)
    }</ul>
  );
}

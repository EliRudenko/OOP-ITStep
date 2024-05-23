import React from 'react';

export class ClickCounter extends React.Component {
  constructor(props){
    super(props);
    this.state = {
      count: 0
    }
  }

  handleClick = (data) => (e) => {
    this.setState({ count: this.state.count + 1 })
  };

  render(){
    return (
      <div>
        <h1>{this.state.count}</h1>
        <button onClick={this.handleClick('data text')}>Increment</button>
      </div>
    )
  }
}

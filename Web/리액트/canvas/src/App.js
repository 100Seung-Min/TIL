import { Component } from 'react';
import './App.css';
import Canvas from './components/canvas'
import Toolbar from './components/toolline';

class App extends Component {

  constructor(props){
    super(props)
    this.state = {
      select: "wall"
    }
  }

  render(){
    return (
      <div className="App">
        <div>
          <Canvas select={this.state.select}></Canvas>
          <Toolbar select={this.state.select} onSelect={function(_select){
            this.setState({
              select: _select
            })
          }.bind(this)}></Toolbar>
        </div>
        <button onClick={function(){
          
        }}>저장하기</button>
      </div>
    );
  }
}

export default App;

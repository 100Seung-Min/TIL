import logo from './logo.svg';
import './App.css';
import LifeCycle from './LifeCycle';
import Info from './Info';
import React, {Component, useState} from 'react';
import Average from './Average'

function getRandomColor() {
  return '#' + Math.floor(Math.random() * 16777215).toString(16);
}

// class App extends Component {
//   state = {
//     color: '#0000000'
//   }

//   handleClick=()=> {
//     this.setState({
//       color:getRandomColor()
//     })
//   }

//   render() {
//     return(
//       <div>
//         <button onClick={this.handleClick}>랜덤색상</button>
//         <LifeCycle color={this.state.color}></LifeCycle>
//         <button onClick={()=> {
//           setVisible(!visible)
//         }}>{visible ? '숨기기': '보이기'}</button>
//         <Info></Info>
//       </div>
//     )
//   }
// }

const App=()=> {
  const [visible, setVisible] = useState(false)
  return (
    <>
      <Average></Average>
      <button onClick={()=> {
        setVisible(!visible)
      }}>{visible ? '숨기기': '보이기'}</button>
      {visible && <Info></Info>}
    </>
  )
}

export default App;

import React, {Component, Fragment, fragment} from 'react'
import './App.css';
import MyComponent from './MyComponent';
import Counter from './Counter';
import Say from './Say';
import EventPractice from './EventPractice';

// function App() {
//   const name = '리액트'
//   // const style={
//   //   backgroundColor:'black',
//   //   color:'aqua',
//   //   fontSize:'48px',
//   //   fontWeight:'bold',
//   //   padding:16
//   // }
//   return (
//     <Fragment>
//       {name === '리액트' ? (
//         <h1>리액트 입니다.</h1>
//       ) : (
//         <h2>리액트가 아닙니다.</h2>
//       )}
//       <h1>{name} 안녕</h1>
//       <div className='react'>잘 작동하니?</div>
//       {name === '리액트' && <h1>리액트 입니다.</h1>}
//     </Fragment>
//   );
// }

class App extends Component {
  render() {
    const name = "react";
    return (
      <div className='react'>
        {name}
        <MyComponent name={name}>리액트</MyComponent>
        <Counter></Counter>
        <Say></Say>
        <EventPractice></EventPractice>
      </div>
    )
  }
}

export default App;

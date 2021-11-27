import React, {Component} from 'react';
import './App.css';


class Subject extends Component{
  render(){
    return(
      <header>
        <h1>{this.props.title}</h1>
          {this.props.sub}
      </header>
    );
  }
}

class Navigation extends Component{
  render(){
    return (
      <nav>
        <ul>
          <li><a href="1.html">HTML</a></li>
          <li><a href="2.html">CSS</a></li>
          <li><a href="3.html">JavaScript</a></li>
        </ul>
      </nav>
    );
  }
}

class Article extends Component{
  render(){
    return (
      <article>
      <h2>{this.props.title}</h2>
      {this.props.desc}
    </article>
    );
  }
}

class App extends Component {
  render() {
    return (
      // <div className="App">
      //   <header className="App-header">
      //     <img src={logo} className="App-logo" alt="logo" />
      //     <p>
      //       Edit <code>src/App.js</code> and save to reload.
      //     </p>
      //     <a
      //       className="App-link"
      //       href="https://reactjs.org"
      //       target="_blank"
      //       rel="noopener noreferrer"
      //     >
      //       Learn React {name}
      //     </a>
      //   </header>
      // </div>
      <div>
        <Subject title="WEB" sub="World Wide Web!"></Subject>
        <Navigation></Navigation>
        <Article title="HTML" desc="HTML is Markup Language."></Article>
      </div>
    );
  }
    
}

export default App;

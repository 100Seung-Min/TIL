import React, {Component} from 'react';
import './App.css';
import Navigation from './components/Navigation';
import Subject from './components/Subject';
import Article from './components/Article';

class App extends Component {

  constructor(props){
    super(props);
    this.state = {
      subject:{title:'WEB', sub:'World Wide Web!'},
      article:{title:'HTML', desc:'HTML is Markup Language.'},
      contents:[
        {id:1, title:'HTML', desc:'HTML is HyperText ...'},
        {id:2, title:'CSS', desc:'CSS is for design'},
        {id:3, title:'JavaScript', desc:'JavaScript is for interactive'},
      ]
    }
  }

  render() {
    return (
      <div>
        <Subject title={this.state.subject.title} sub={this.state.subject.sub}></Subject>
        <Navigation data={this.state.contents}></Navigation>
        <Article title={this.state.article.title} desc={this.state.article.desc}></Article>
      </div>
    );
  }
    
}

export default App;

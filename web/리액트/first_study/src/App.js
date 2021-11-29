import React, {Component} from 'react';
import './App.css';
import Navigation from './components/Navigation';
import Subject from './components/Subject';
import Article from './components/Article';

class App extends Component {

  constructor(props){
    super(props);
    this.state = {
      mode:'welcome',
      selected_content_id:2,
      subject:{title:'WEB', sub:'World Wide Web!'},
      welcome:{title:'Welcome', desc:'Hello, React!!'},
      contents:[
        {id:1, title:'HTML', desc:'HTML is HyperText ...'},
        {id:2, title:'CSS', desc:'CSS is for design'},
        {id:3, title:'JavaScript', desc:'JavaScript is for interactive'},
      ]
    }
  }

  render() {
    let _title, _desc = null;
    if(this.state.mode === 'welcome'){
      _title = this.state.welcome.title;
      _desc = this.state.welcome.desc;
    } else if(this.state.mode === 'read'){
      _title = this.state.contents[this.state.selected_content_id - 1].title;
      _desc = this.state.contents[this.state.selected_content_id - 1].desc;
    }
    return (
      <div className="App">
        <Subject 
        title={this.state.subject.title}
        sub={this.state.subject.sub} 
        onChangePage={function(){
          this.setState({
            mode:'welcome'
          });
        }.bind(this)}></Subject>

        <Navigation 
        data={this.state.contents}
        onChangePage={function(id){
          this.setState({
            mode:'read',
            selected_content_id:id
          })
        }.bind(this)}></Navigation>

        <Article 
        title={_title} 
        desc={_desc}></Article>
      </div>
    );
  }
    
}

export default App;

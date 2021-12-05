import React, {Component} from 'react';
import './App.css';
import Navigation from './components/Navigation';
import Subject from './components/Subject';
import ReadArticle from './components/ReadArticle';
import Control from './components/Control';
import CreateArticle from './components/CreateArticle';

class App extends Component {

  constructor(props){
    super(props);
    this.max_contents_id = 3;
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
    let _title, _desc, _article = null;
    if(this.state.mode === 'welcome'){
      _title = this.state.welcome.title;
      _desc = this.state.welcome.desc;
      _article = <ReadArticle title={_title} desc={_desc}></ReadArticle>;
    } else if(this.state.mode === 'read'){
      _title = this.state.contents[this.state.selected_content_id - 1].title;
      _desc = this.state.contents[this.state.selected_content_id - 1].desc;
      _article = <ReadArticle title={_title} desc={_desc}></ReadArticle>;
    } else if(this.state.mode === 'create'){
      _article = <CreateArticle onSubmit={function(_title, _desc){
        this.max_contents_id += 1;
        this.state.contents.push(
          {id:this.max_content_id, title: _title, desc: _desc}
        );
        this.setState({
          contents: this.state.contents
        });
      }}></CreateArticle>
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

        <Control onChangeMode={function(_mode){
          this.setState({
            mode:_mode
          })
        }.bind(this)}></Control>

       {_article}

      </div>
    );
  }
    
}

export default App;

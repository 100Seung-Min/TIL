import React, {Component} from 'react';
import './App.css';
import Navigation from './components/Navigation';
import Subject from './components/Subject';
import ReadArticle from './components/ReadArticle';
import Control from './components/Control';
import CreateArticle from './components/CreateArticle';
import UpdateArticle from './components/UpdateArticle';

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

  getContent(){
    let _title, _desc, _article = null;
    if(this.state.mode === 'welcome'){
      _title = this.state.welcome.title;
      _desc = this.state.welcome.desc;
      _article = <ReadArticle title={_title} desc={_desc}></ReadArticle>;
    } else if(this.state.mode === 'read'){
      let _content = this.getReadContent();
      // _title = this.state.contents[this.state.selected_content_id - 1].title;
      // _desc = this.state.contents[this.state.selected_content_id - 1].desc;
      _article = <ReadArticle title={_content.title} desc={_content.desc}></ReadArticle>;
    } else if(this.state.mode === 'create'){
      _article = <CreateArticle onSubmit={function(_title, _desc){
        this.max_contents_id += 1;
        // let _contents = this.state.contents.concat(
        //   {id:this.max_contents_id, title: _title, desc: _desc}
        // );
        let _contents = Array.from(this.state.contents);
        _contents.push({id: this.max_contents_id, title: _title, desc: _desc});
        this.setState({
          contents: _contents,
          mode: 'read',
          selected_content_id: this.max_contents_id
        });
      }.bind(this)}></CreateArticle>
    } else if(this.state.mode === 'update'){
      let _content = this.getReadContent();
      _article = <UpdateArticle data={_content} onSubmit={function(_id, _title, _desc){
        var _contents = Array.from(this.state.contents);
        let i = 0;
        while(i < _contents.length){
          if(_contents[i].id === _id){
            _contents[i] = {id: _id, title: _title, desc: _desc};
            break;
          }
          i += 1;
        }
        this.setState({
          contents: _contents,
          mode: 'read'
        });
      }.bind(this)}></UpdateArticle>
    }
    return _article;
  }

  getReadContent(){
    let i = 0;
    while(i < this.state.contents.length){
      var data = this.state.contents[i];
      if(data.id === this.state.selected_content_id){
        return data;
      }
      i += 1;
    }
  }

  render() {
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
            selected_content_id:Number(id)
          })
        }.bind(this)}></Navigation>

        <Control onChangeMode={function(_mode){
          if(_mode === 'delete'){
            let _contents = Array.from(this.state.contents);
            if(window.confirm('진짜로??')){
              let i = 0;
              while(i < this.state.contents.length){
                if(_contents[i].id === this.state.selected_content_id){
                  _contents.splice(i,1);
                  break;
                }
                i += 1;
              }
              this.setState({
                contents: _contents,
                mode: 'welcome'
              })
              alert('삭제되었습니다');
            }
          }else {
            this.setState({
              mode:_mode
            });
          }
        }.bind(this)}></Control>

       {this.getContent()}
      </div>
    );
  }
    
}

export default App;

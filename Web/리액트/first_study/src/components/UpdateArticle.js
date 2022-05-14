import React, {Component} from "react";

class UpdateArticle extends Component{
  constructor(props){
    super(props)
    this.state = {
      title: this.props.data.title,
      desc: this.props.data.desc,
      id: this.props.data.id
    }
    this.inputFormHandler = this.inputFormHandler.bind(this);
  }

  inputFormHandler(e){
    this.setState({
      [e.target.name]: e.target.value
    });
  }

  render(){
    return (
    <article>
      <h2>Update</h2>
      <form action="/create_process" method="post" onSubmit={function(e){
        e.preventDefault();
        this.props.onSubmit(this.state.id, this.state.title, this.state.desc);
      }.bind(this)}>
        <input type="hidden" name="id" value={this.state.id}></input>
        <p>
          <input type="text" 
            name="title" 
            placeholder="title"
            value={this.state.title}
            onChange={this.inputFormHandler}></input>
        </p>
        <p>
          <textarea name="desc" 
            placeholder="description" 
            value={this.state.desc}
            onChange={this.inputFormHandler}></textarea>
        </p>
        <p>
          <input type="submit"></input>
        </p>
      </form>
    </article>
    );
  }
}

export default UpdateArticle;
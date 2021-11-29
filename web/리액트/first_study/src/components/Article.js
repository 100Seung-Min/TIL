import React, {Component} from "react";

class Article extends Component{
  render(){
    console.log(this.props.title);
    return (
      <article>
      <h2>{this.props.title}</h2>
      {this.props.desc}
    </article>
    );
  }
}

export default Article;
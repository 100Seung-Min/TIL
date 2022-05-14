import React from "react";

const SideBar = (props) => {
  let _content = [];
  if(props.select === "del"){
    _content.push(<button onClick={function(e){
      e.preventDefault() 
      props.delMode(0)}}>삭제</button>);
    _content.push(<button onClick={function(e){
      e.preventDefault() 
      props.delMode(1)}}>완전삭제</button>);
  } else if(props.select === "wall") {
    _content.push(<button onClick={function(e){
      e.preventDefault() 
      props.drawMode(0)}}>검은색</button>);
    _content.push(<button onClick={function(e){
      e.preventDefault() 
      props.drawMode(1)}}>빨간색</button>);
    _content.push(<button onClick={function(e){
      e.preventDefault() 
      props.drawMode(2)}}>초록색</button>);
  }

  return(
    <div
    style={{width: (window.innerWidth - ((window.innerWidth - 100) * 0.85)), height: (window.innerHeight - 570) * 2, backgroundColor: "green"}}>
      {_content}
    </div>
  )
}

export default SideBar
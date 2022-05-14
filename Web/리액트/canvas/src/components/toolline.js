import React from "react";

const Toolbar = (props) => {
  return(
    <div 
    style={{width: window.innerWidth, backgroundColor: "green", height: (window.innerHeight - 570), overflow: "hidden"}}>
      <button onClick={function(e){
        e.preventDefault();
        props.onSelect("del");
      }}>삭제</button>
      <button onClick={function(e){
        e.preventDefault();
        props.onSelect("wall");
      }}>벽</button>
    </div>
  )
}

export default Toolbar
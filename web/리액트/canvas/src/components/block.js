import React from "react";

const Block = (props) => {

  let i;
  let j;
  let list = [];

  if(props.isDrawing === true){
    props.map[Math.floor(props.y / 5)][props.x] = 1
  }

  console.log(props.x, props.y)


  for(i = 0;i < 20; i++){
    if(i !== 0){
      list.push(
        <tr></tr>
      )
    }
    for(j = 0; j < 100; j++){
      if(props.map[i][j] === 1){
        list.push(
          <td style={{border: "1px solid black", width: (props.width / 100) - 1, height: ((props.height / 10) - 1) / 2, padding: "0px", backgroundColor: "black"}}></td>
        )
      }
      else{
        list.push(
          <td style={{border: "1px solid black", width: (props.width / 100) - 1, height: ((props.height / 10) - 1) / 2, padding: "0px"}}></td>
        )
      }
    }
  }
  return(
    <div>
      <table style={{borderCollapse: "collapse", borderStyle: "none", padding: "0px"}}>
        {list}
      </table>
    </div>
  )
}

export default Block;
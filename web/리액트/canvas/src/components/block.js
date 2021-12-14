import React from "react";

const Block = (props) => {

  console.log(props.x, props.y)
  let i;
  let list = [];
  for(i = 0;i < 2000; i++){
    if(i % 100 === 0 && i !== 0){
      list.push(
        <tr></tr>
      )
    }
    list.push(
      <td style={{border: "1px solid black", width: ((window.innerWidth - 100) * 0.85 / 100) - 1, height: ((window.innerHeight - 300) / 10) - 1, padding: "0px"}}></td>
    )
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
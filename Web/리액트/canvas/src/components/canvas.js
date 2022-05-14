import React, {useRef, useEffect, useState} from "react";
import Block from './block'
import SideBar from "./sidebar";

const Canvas = (props) => {
  const canvasRef = useRef(null);
  const contextRef = useRef(null);

  let list = new Array(20);
  for(let i = 0; i < 20; i++){
    list[i] = new Array(100).fill(0)
  }
  const [ctx, setCtx] = useState();
  const [isDrawing, setIsDrawing] = useState(false);
  const [x, setX] = useState(0);
  const[y, setY] = useState(0);
  const[map] = useState(list);
  const[height, setHeight] = useState();
  const[width, setWidth] = useState();
  const[del, setDel] = useState(0);
  const[drawMode, setDraw] = useState(0);

  useEffect(() => {
    const canvas = canvasRef.current;
    
    canvas.height = (window.innerHeight - 570) * 2;
    canvas.width = ((window.innerWidth - 100) * 0.85);
    setHeight(canvas.height);
    setWidth(canvas.width);

    const context = canvas.getContext("2d");
    // context.strokeStyle = "red";
    // context.lineWidth = 10;
    contextRef.current = context;

    setCtx(contextRef.current);
  }, []);

  const startDrawing = () => {
    setIsDrawing(true);
  };

  const finishDrawing = () => {
    setIsDrawing(false);
  };

  const drawing = ({nativeEvent}) => {
    let {offsetX, offsetY} = nativeEvent;
    setX(Math.floor(100 / ((window.innerWidth - 100) * 0.85) * offsetX));
    setY(Math.floor(100 / ((window.innerHeight - 300) * 2) * offsetY));
    if(ctx){
      // if(!isDrawing){
      //   ctx.beginPath();
      //   ctx.moveTo(offsetX, offsetY);
      // } else{
      //   ctx.lineTo(offsetX, offsetY);
      //   ctx.stroke();
      // }
    }
  };

  return(
    <div>
      <div
      className="canvas_wrap"
      style={{position: "relative", display: "flex", width: window.innerWidth}}>
        <canvas
        ref={canvasRef}
        style={{position: "absolute"}}
        onMouseDown={startDrawing}
        onMouseUp={finishDrawing}
        onMouseMove={drawing}
        onMouseLeave={finishDrawing}>
        </canvas>
        <Block x={x} y={y} isDrawing={isDrawing} map={map} width={width} height={height} select={props.select} delete={del} delMode={function(_del){setDel(_del)}} drawMode={drawMode}></Block>
        <SideBar
         select={props.select}
         delet={del} 
         delMode={function(_del){
          setDel(_del);
        }}
         drawMode={function(_draw){
          setDraw(_draw);
         }}></SideBar>
      </div>
    </div>
    
  );
}

export default Canvas;
import React, {useRef, useEffect, useState} from "react";
import Block from './block'

const Canvas = () => {
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
  const[map, setMap] = useState(list);

  const[height, setHeight] = useState();
  const[width, setWidth] = useState();

  useEffect(() => {
    const canvas = canvasRef.current;
    
    canvas.height = (window.innerHeight - 300) * 2;
    canvas.width = (window.innerWidth - 100) * 0.85;
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
    //   if(!isDrawing){
    //     ctx.beginPath();
    //     ctx.moveTo(offsetX, offsetY);
    //   } else{
    //     ctx.lineTo(offsetX, offsetY);
    //     ctx.stroke();
    //   }
    }
  };

  return(
    <div
     className="canvas_wrap"
     style={{position: "relative"}} >
      <canvas
       ref={canvasRef}
       style={{position: "absolute"}}
       onMouseDown={startDrawing}
       onMouseUp={finishDrawing}
       onMouseMove={drawing}
       onMouseLeave={finishDrawing}>
       </canvas>
       <Block x={x} y={y} isDrawing={isDrawing} map={map} width={width} height={height}></Block>
    </div>
  );
}

export default Canvas;
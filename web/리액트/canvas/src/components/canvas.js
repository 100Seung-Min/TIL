import React, {useRef, useEffect, useState} from "react";
import Block from './block'

const Canvas = () => {
  const canvasRef = useRef(null);
  const contextRef = useRef(null);

  var x;
  var y;

  const [ctx, setCtx] = useState();
  const [isDrawing, setIsDrawing] = useState(false);

  useEffect(() => {
    const canvas = canvasRef.current;
    canvas.height = (window.innerHeight - 300) * 2;
    canvas.width = (window.innerWidth - 100) * 0.85;

    const context = canvas.getContext("2d");
    context.strokeStyle = "red";
    context.lineWidth = 10;
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
    x = 100 / ((window.innerWidth - 100) * 0.85) * offsetX;
    y = 100 / ((window.innerHeight - 300) * 2) * offsetY;
    console.log("x좌표", x, " y좌표", y)
    if(ctx){
      if(!isDrawing){
        ctx.beginPath();
        ctx.moveTo(offsetX, offsetY);
      } else{
        ctx.lineTo(offsetX, offsetY);
        ctx.stroke();
      }
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
       <Block x={x} y={y}></Block>
    </div>
  );
}

export default Canvas;
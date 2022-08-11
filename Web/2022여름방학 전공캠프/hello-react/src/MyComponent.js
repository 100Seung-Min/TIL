import React from "react";

const MyComponent = (props) => {
  return (
    <div>
      나의 새롭고 멋진 컴포넌트 {props.name}<br/>
      {props.children}
    </div>
  );
};

MyComponent.defaultProps={
  name:'기본이름'
}

export default MyComponent;
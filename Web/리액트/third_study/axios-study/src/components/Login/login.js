import React, { useState } from "react"
import axios from "axios"

const Login = () => {
  const [email, setEmail] = useState();
  const [password, setPw] = useState();

  function login_send(){
    axios.post('http://10.120.74.70:3001/auth/login',
      {
        email: {email}.email,
        password: {password}.password
      },
      {
        headers:{
          'Content-type': 'application/json', 
          'Accept': 'application/json' 
        }
      }).then((Response) => {
        console.log(Response.data.user)
        const isLogin = Response.data.user
        if(!isLogin){
          alert('로그인 실패')
        } else {
          document.location.href = '/main'
        }
      })
      .catch((Error) => {console.log(Error)})
  }
  
  return (
    <>
      <from>
        <input
          type="text"
          placeholder="아이디"
          onChange={e => {setEmail(e.target.value)}}/>
        <input 
          type="password" 
          placeholder="비밀번호" 
          onChange={e => setPw(e.target.value)}></input>
        <button onClick={login_send}>로그인</button>
      </from>
    </>
  )
}

export default Login
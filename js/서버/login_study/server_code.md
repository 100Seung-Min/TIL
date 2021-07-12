# express로 서버 띄우기
```js
const express = require("express");
const app = express();

app.get("/", (req, res) => {
  res.send("여기는 루트입니다");
});

app.get("/login", (req, res) => {
  res.send("여기는 로그인 화면입니다");
})

app.listen(3000, ( ) => {
  console.log("콘솔 가동");
});
```
---
# http로 서버 띄우기
```js
const http = require("http");
const app = http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "text/html; charset=utf-8"})
  if(req.url == '/') {
    res.end("여기는 루트입니다");
  }
  else if(req.url == '/login') {
    res.end("여기는 로그인입니다");
  }
});

app.listen(3001, ( ) => {
  console.log("http로 가동");
});
```
---
# 기본 로그인페이지(하드코딩)
```js
const express = require("express");
const app = express();

app.get("/", (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="ko">
    <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>login</title>
    </head>
    <body>
     여기는 루트입니다
    </body>
    </html>
  `);
});

app.get("/login", (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="ko">
    <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>login</title>
    </head>
    <body>
      <input type="text" placeholder="아이디">
      <br>
      <input type="text" placeholder="비밀번호">
      <br>
      <button>로그인</button>
    </body>
    </html>
  `);
})

app.listen(3000, ( ) => {
  console.log("express 가동");
});
```
# html 분리 하는 법
> 앱 세팅
```js
app.set("views", "./views");
app.set("view engine", "ejs");
```
> html형식을 ejs로 저장
```
<!DOCTYPE html>
<html lang="ko">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>login</title>
</head>
<body>
  <input type="text" placeholder="아이디">
  <br>
  <input type="text" placeholder="비밀번호">
  <br>
  <button>로그인</button>
</body>
</html>
```
> get에 파일연동
```js
 res.render("파일경로");
 ```
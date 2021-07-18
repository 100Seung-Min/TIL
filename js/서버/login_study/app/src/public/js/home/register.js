"use strict";

const id = document.querySelector("#id"),
  name = document.querySelector("#name"),
  password = document.querySelector("#password"),
  confirmpswd = document.querySelector("#confirm_pswd"),
  registerbtn = document.querySelector("#button");

registerbtn.addEventListener("click", register);

function register(){
  const req = {
    id: id.value,
    name: name.value,
    password: password.value,
    confirmpswd: confirmpswd.value
  };

  fetch("/register", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(req),
  })
  .then((res) => res.json())
  .then((res) => {
    if (res.success) {
      location.href = "/login";
    } else {
      alert(res.msg);
    }
  })
  .catch((err) => {
    console.error(new Error("회원가입 중 에러 발생"));
  });
}
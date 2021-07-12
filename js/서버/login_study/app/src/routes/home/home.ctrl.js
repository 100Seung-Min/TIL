"use strict";


const first = (req, res) => {
  res.render("home/index");
};

const login = (req, res) => {
  res.render("home/login");
}

module.exports = {
  first,
  login
};
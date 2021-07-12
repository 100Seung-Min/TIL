"use strict";

const express = require("express");
const router = express.Router();

const ctrl = require("./home.ctrl");

router.get("/", ctrl.first);

router.get("/login", ctrl.login);

module.exports = router;
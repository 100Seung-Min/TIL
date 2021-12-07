const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const app = express();

const config = require('./server/config/keys');

app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json());

app.use('/api/dialogflow', require('./server/router/dialogflow'));

if(process.env.NODE_ENV === 'production'){
  app.use(express.static('./client/build'));

  app.get("*", (req, res) => {
    res.sendFile(path.resolve(__dirname, "client", "build", "index.html"));
  });
}

const port = process.env.PORT || 5000;

app.listen(port, () => {
  console.log("${port} 가동");
})
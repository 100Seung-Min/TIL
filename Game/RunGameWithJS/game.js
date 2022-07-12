var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');
var score = document.getElementById('score');
var gameover = document.getElementById('gameover');

canvas.width = window.innerWidth - 8;
canvas.height = 300;

var img1 = new Image();
img1.src = 'fuck.png';

var img2 = new Image();
img2.src = 'player.jpg';

var dino = {
  x : 10,
  y : 100,
  width : 50,
  height : 50,
  draw() {
    ctx.fillStyle = 'green';
    ctx.fillRect(this.x, this.y, this.width, this.height);
    ctx.drawImage(img2, this.x, this.y);
  }
}

dino.draw();

class Cactus {
  constructor() {
    this.x = 1400;
    this.y = 100;
    this.width = 50;
    this.height = 50;
  }
  draw() {
    ctx.fillStyle = 'red';
    ctx.fillRect(this.x, this.y, this.width, this.height);
    ctx.drawImage(img1, this.x, this.y);
  }
}

var timer = 0;
var cactuss = [];
var animation;
var speed = 3;
var sponeTime = 1;

function run_frame() {
  animation = requestAnimationFrame(run_frame);
  score.innerText="Score : " + Math.floor(timer / 10);
  timer++;

  ctx.clearRect(0, 0, canvas.width, canvas.height);

  if(timer % sponeTime === 0) {
    var cactus = new Cactus();
    cactuss.push(cactus);
    sponeTime = Math.floor(Math.random() * 100) + 100;
  }
  cactuss.forEach((a, i, o) => {
    if (a.x < 0) {
        o.splice(i, 1);
    }
    a.x -= speed;

    checkCollison(dino, a);

    a.draw();
  })

  if (isJump == true && dino.y > 0) {
    dino.y -= 2;
  }

  if (isJump == false) {
    if (dino.y < 100) {
      dino.y += 2;
    }
  }

  if (dino.y <= 0) {
    isJump = false;
  }

  dino.draw();
}

run_frame();

var isDead = false;

function checkCollison(dino, cactus) {
  var xDifrence = cactus.x - (dino.x + dino.width);
  var yDifrence = cactus.y - (dino.y + dino.height);
  if(xDifrence < 0 && yDifrence < 0) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    gameover.style.visibility = "visible";
    cancelAnimationFrame(animation);
    isDead = true;
  }
}

var isJump = false;
document.addEventListener('keydown', function(e) {
  if (e.code === 'Space' && isJump == false) {
    isJump = true;
    if(isDead == true) {
      this.location.reload();
    }
  }
})
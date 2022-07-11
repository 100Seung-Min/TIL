var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

canvas.width = window.innerWidth - 100;
canvas.height = window.innerHeight - 100;

var dino = {
  x : 10,
  y : 200,
  width : 50,
  height : 50,
  draw() {
    ctx.fillStyle = 'green';
    ctx.fillRect(this.x, this.y, this.width, this.height);
  }
}

dino.draw();

class Cactus {
  constructor() {
    this.x = 500;
    this.y = 200;
    this.width = 50;
    this.height = 50;
  }
  draw() {
    ctx.fillStyle = 'red';
    ctx.fillRect(this.x, this.y, this.width, this.height);
  }
}

var timer = 0;
var cactuss = [];
var jumpTime = 0;
var animation;

function run_frame() {
  animation = requestAnimationFrame(run_frame);
  timer++;

  ctx.clearRect(0, 0, canvas.width, canvas.height);

  if(timer % 120 === 0) {
    var cactus = new Cactus();
    cactuss.push(cactus);
  }
  cactuss.forEach((a, i, o) => {
    if (a.x < 0) {
        o.splice(i, 1);
    }
    a.x--;

    checkCollison(dino, a);

    a.draw();
  })

  if (isJump == true) {
    dino.y--;
    jumpTime++;
  }

  if (isJump == false) {
    if (dino.y < 200) {
      dino.y++;
    }
  }

  if (jumpTime > 100) {
    isJump = false;
    jumpTime = 0;
  }

  dino.draw();
}

run_frame();

function checkCollison(dino, cactus) {
  var xDifrence = cactus.x - (dino.x + dino.width);
  var yDifrence = cactus.y - (dino.y + dino.height);
  if(xDifrence < 0 && yDifrence < 0) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    cancelAnimationFrame(animation);
  }
}

var isJump = false;
document.addEventListener('keydown', function(e) {
  if (e.code === 'Space') {
    isJump = true;
  }
})
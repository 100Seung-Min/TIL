var heading = document.querySelector('#heading');
heading.onclick = function(){
  console.log("클릭했습니다");
  heading.style.color = "red";
}

var number = document.querySelector('#num');
number.onclick = function(){
  var num = prompt("숫자를 입력해주세요");
  var num1 = prompt("숫자를 입력해주세요");
  
  var sum = parseInt(num) + parseInt(num1);
  document.write(`합은 ${sum} 입니다`);
  if(sum != null){
    if(sum % 2== 0){
      alert("짝수입니다");
    } else {
      alert("홀수입니다")
    }
  }else {
    alert ("입력되지않았습니다")
  }
}

var chier = document.querySelector('#chier');
chier.onclick = function(){
  var pep = prompt("사람 수를 입력 해주세요");
  var line = prompt("한 줄에 앉을 사람수는 ?");
  var che = parseInt(pep / line);
  if(pep % line != 0){
    che += 1;
  }
 var i, j, k = 0;
 for(i = 1; i<=che;i++){
   for(j = 1;j<=line;j++){
     if(k == pep){
       break;
     }
     k++;
     document.write(`좌석 ${k}`);
   }
   document.write("<br>");
 }
}

var money = document.querySelector('#money');
money.onclick = function(){
  var con = prompt("나라를 입력하세요");
  if(con == "미국"){
    var dolor = prompt("돈을 입력하세요");
    var han = parseInt(dolor) * 1148.67;
    document.write(`${dolor}달러는 ${han}원 입니다.`);
  } else if(con == "한국"){
    var han = prompt("돈을 입력하세요");
    var dolor = parseInt(han) * 0.00087;
    document.write(`${han}은 ${dolor}달러 입니다.`);
  } else {
    document.write("지원되지 않습니다");
  } 
}

var sum = document.querySelector('#sum');
sum.onclick = function(){
  var i;
  var numb = 0;
  for(i = 1 ; i <= 10000 ; i++) {
    numb += i;
  }
  document.write(`1부터 10000까지의 합은 ${numb}`);
}

var gop = document.querySelector('#gop');
gop.onclick = function(){
  var i, j;
  for(i = 1 ; i <= 9 ; i++) {
    document.write("<div>");
    document.write(`<center><h3>${i}단</h3><br></center>`);
    for(j = 1; j <= 9 ; j++) {
      document.write(`<center>${i} x ${j} = ${i*j}</center><br>`);
    }
    document.write("</div>");
  }
}

var plus = document.querySelector('#plus');
plus.onclick = function(){
  var i, sum = 0;
  for(i = 0;i<100;i++){
    if(i % 2 == 0){
      if(i%5==0){
        continue;
      }
    }
    sum += i;
  }
  document.write(`답은 ${sum}`);
}
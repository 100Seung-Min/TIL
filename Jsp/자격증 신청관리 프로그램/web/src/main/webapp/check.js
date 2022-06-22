function add(){
	if(frm.name.length==0){
		alert("자격증명이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if (frm.avg.length==0){
		alert("평균점수가 입력되지 않았습니다.");
		frm.avg.focus();
		return false;
	}
	else if (frm.teacher.length==0){
		alert("담당강사가 선택되지 않았습니다.");
		frm.teacher.focus();
		return false;
	}
	else if (frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false){
		alert("요일이 선택되지 않았습니다.");
		frm.week.focus();
		return false;
	}
	else if (frm.start.length==0){
		alert("시작시간이 입력되지 않았습니다.");
		frm.start.focus();
		return false;
	}
	else if (frm.end.length==0){
		alert("종료시간이 입력되지 않았습니다.");
		frm.end.focus();
		return false;
	}
	else {
		alert("자격증이 추가되었습니다.");
		document.frm.submit();
		return true;
	}
}

function list() {
	window.location = "list.jsp"
}

function change(){
	if(frm.name.length==0){
		alert("자격증명이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if (frm.avg.length==0){
		alert("평균점수가 입력되지 않았습니다.");
		frm.avg.focus();
		return false;
	}
	else if (frm.teacher.length==0){
		alert("담당강사가 선택되지 않았습니다.");
		frm.teacher.focus();
		return false;
	}
	else if (frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false){
		alert("요일이 선택되지 않았습니다.");
		frm.week.focus();
		return false;
	}
	else if (frm.start.length==0){
		alert("시작시간이 입력되지 않았습니다.");
		frm.start.focus();
		return false;
	}
	else if (frm.end.length==0){
		alert("종료시간이 입력되지 않았습니다.");
		frm.end.focus();
		return false;
	}
	else {
		alert("자격증정보수정이 완료되었습니다.");
		document.frm.submit();
		return true;
	}
}
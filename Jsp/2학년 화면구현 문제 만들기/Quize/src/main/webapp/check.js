function addCheck(){
	if(frm.id.value.length==0){
		alert("교과목 코드가 입력되지 않았습니다.");
		frm.id.focus();
		return false;
	}
	else if(frm.name.value.length==0){
		alert("과목명이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if(frm.phone.value.length==0){
		alert("학점이 입력되지 않았습니다.");
		frm.credit.focus();
		return false;
	}
	else if(frm.volunteer.value==0){
		alert("담당강사가 선택되지 않았습니다.");
		frm.lecturer.focus();
		return false;
	}
	else if(frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false && frm.week[3].checked==false && frm.week[4].checked==false){
		alert("요일이 선택되지 않았습니다.");
		frm.week.focus();
		return false;
	}
	else if(frm.hour.value.length==0){
		alert("시작시간이 입력되지 않았습니다.");
		frm.start_hour.focus();
		return false;
	}
	else{
		alert("교과목 등록이 완료되었습니다!");
		document.frm.submit();
	return true;
	}
}

function search(){
	window.location = "list.jsp"
}
function addCheck(){
	if(frm.name.value.length==0){
		alert("이름이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if(frm.phone.value.length==0){
		alert("전화번호가 입력되지 않았습니다.");
		frm.credit.focus();
		return false;
	}
	else if(frm.password.value.length==0){
		alert("비밀번호가 입력되지 않았습니다.");
		frm.password.focus();
		return false;
	}
	else if(frm.volunteer.value==0){
		alert("봉사가 선택되지 않았습니다.");
		frm.lecturer.focus();
		return false;
	}
	else if(frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false && frm.week[3].checked==false && frm.week[4].checked==false){
		alert("요일이 선택되지 않았습니다.");
		frm.week.focus();
		return false;
	}
	else if(frm.hour.value.length==0){
		alert("봉사시간이 입력되지 않았습니다.");
		frm.hour.focus();
		return false;
	}
	else {
		alert("봉사 신청이 완료되었습니다!");
		document.frm.submit();
	return true;
	}
}

function search(){
	window.location = "list.jsp"
}
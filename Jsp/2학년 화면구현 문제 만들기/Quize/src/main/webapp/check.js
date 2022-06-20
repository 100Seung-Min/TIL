function addCheck() {
	if(frm.name.value.length==0){
		alert("이름이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if(frm.phone.value.length==0){
		alert("전화번호가 입력되지 않았습니다.");
		frm.phone.focus();
		return false;
	}
	else if(frm.password.value.length==0){
		alert("비밀번호가 입력되지 않았습니다.");
		frm.password.focus();
		return false;
	}
	else if(frm.volunteer.value==0){
		alert("봉사가 선택되지 않았습니다.");
		frm.volunteer.focus();
		return false;
	}
	else if(frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false && frm.week[3].checked==false && frm.week[4].checked==false && frm.week[5].checked==false && frm.week[6].checked==false){
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
		document.frm.submit();
		return true;
	}
}

function addCheck2(){
	if(frm.name.value.length == 0) {
		alert("봉사이름이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if(frm.place.value.length == 0) {
		alert("봉사장소가 입력되지 않았습니다.");
		frm.place.focus();
		return false;
	}
	else if(frm.day.value.length == 0) {
		alert("봉사날짜가 입력되지 않았습니다.");
		frm.day.focus();
		return false;
	}
	else if(frm.maxpersonnel.value.length == 0) {
		alert("봉사인원이 입력되지 않았습니다.");
		frm.maxpersonnel.focus();
		return false;
	}
	else if(frm.hours.value.length == 0) {
		alert("봉사시간이 입력되지 않았습니다.");
		frm.hours.focus();
		return false;
	}
	else {
		alert("봉사개설이 완료되었습니다!");
		document.frm.submit();
		return true;
	}
}

function addCheck3(){
	if(frm.name.value.length==0){
		alert("이름이 입력되지 않았습니다.");
		frm.name.focus();
		return false;
	}
	else if(frm.phone.value.length==0){
		alert("전화번호가 입력되지 않았습니다.");
		frm.phone.focus();
		return false;
	}
	else if(frm.password.value.length==0){
		alert("비밀번호가 입력되지 않았습니다.");
		frm.password.focus();
		return false;
	}
	else if(frm.week[0].checked==false && frm.week[1].checked==false && frm.week[2].checked==false && frm.week[3].checked==false && frm.week[4].checked==false && frm.week[5].checked==false && frm.week[6].checked==false){
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
		document.frm.submit();
		return true;
	}
}

function search(){
	window.location = "list.jsp"
}
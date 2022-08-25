function check() {
	if(frm.memberName.value == "고객명") {
		alert("고객명이 선택되지 않았습니다.");
		frm.memberName.focus();
		return false;
	}
	else if(frm.job[0].checked == false && frm.job[1].checked == false && frm.job[2].checked == false) {
		alert("직업이 선택되지 않았습니다.");
		frm.job.focus();
		return false;
	}
	else if(frm.day.value.length == 0) {
		alert("대여날짜가 입력되지 않았습니다.");
		frm.day.focus();
		return false;
	}
	else {
		alert("대여 완료");
		document.frm.submit();
		return true;
	}
}

function changeName() {
	frm.mNo.value = frm.memberName.options[frm.memberName.selectedIndex].value
}

function reset() {
	document.frm.reset();
}

function back() {
	window.location = "check.jsp"
}

function return_book() {
	document.frm.submit();
}
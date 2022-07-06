function check() {
	if(frm.jumin_num.value.length == 0) {
		alert("주민번호가 입력되지 않았습니다!");
		frm.jumin_num.focus();
		return false;
	}
	else if(frm.name.value.length == 0) {
		alert("성명이 입력되지 않았습니다!");
		frm.name.focus();
		return false;
	}
	else if(frm.vote_num.value.length == 0) {
		alert("후보번호가 입력되지 않았습니다!");
		frm.vote_num.focus();
		return false;
	}
	else if(frm.vote_time.value.length == 0) {
		alert("투표시간이 입력되지 않았습니다!");
		frm.vote_time.focus();
		return false;
	}
	else if(frm.vote_place.value.length == 0) {
		alert("투표장소가 입력되지 않았습니다!");
		frm.vote_place.focus();
		return false;
	}
	else if(frm.check_vote[0].checked == false && frm.check_vote[1].checked == false) {
		alert("유권자확인이 선택되지 않았습니다!");
		frm.check_vote.focus();
		return false;
	}
	else {
		alert("투표하기 정보가 정상적으로 등록 되었습니다!");
		document.frm.submit();
		return true;
	}
}
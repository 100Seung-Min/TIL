function select_cName() {
	frm.c_no.value = frm.c_name.value
	select_class_name();
}

function select_class_name() {
	if(frm.c_no.value >= 20000) {
		frm.class_price.value = frm.class_name.value / 2
	} else {
		frm.class_price.value = frm.class_name.value
	}	
}

function re_write() {
	alert("정보를 지우고 처음부터 다시 입력합니다!")
	frm.reset()
}

function join() {
	if(frm.regist_month.value.length == 0) {
		frm.regist_month.focus()
	} 
	else if(frm.c_name.value.length == 0) {
		frm.c_name.focus()
	}
	else if(frm.class_area.value.length == 0) {
		frm.class_area.focus()
	}
	else if(frm.class_name.value.length == 0) {
		frm.class_name.focus()
	}
	else {
		alert("수강신청이 정상적으로 완료되었습니다!")
		frm.submit()	
	}
}
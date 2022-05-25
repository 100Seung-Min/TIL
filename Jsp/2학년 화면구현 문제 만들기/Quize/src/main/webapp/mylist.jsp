<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>봉사 신청 조회/ 수정</b></h2>
<form name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<table border="1">
<tr>
	<td>신청한 봉사</td>
	<td>신청 요일</td>
	<td>봉사 시간</td>
	<td>봉사 수정</td>
	<td>봉사 취소</td>
</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
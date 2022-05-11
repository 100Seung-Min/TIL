<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>insert</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>교과목 추가</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;">
<table border="1" style="text-align: center;">
	<tr>
		<td>과목코드</td>
		<td><input type="text" name="id" style="width: 100%"></td>
	</tr>
<tr>
	<td>과목명</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>학점</td>
	<td><input type="text" name="credit" style="width: 100%"></td>
</tr>
<tr>
	<td>담당강사</td>
	<td>
	<select name="lecturer" style="width: 100%">
		<option value="">담당강사선택</option>
		<option value="1">김교수</option>
		<option value="2">이교수</option>
		<option value="3">박교수</option>
		<option value="4">우교수</option>
		<option value="5">최교수</option>
		<option value="6">임교수</option>
	</select>
</tr>
<tr>
	<td>요일</td>
	<td>
	<input type="radio" name="week" value="1">월
	<input type="radio" name="week" value="2">화
	<input type="radio" name="week" value="3">수
	<input type="radio" name="week" value="4">목
	<input type="radio" name="week" value="5">금
	</td>
</tr>
<tr>
	<td>시작시간</td>
	<td><input type="text" name="start_hour" style="width: 100%"></td>
</tr>
<tr>
	<td>종료시간</td>
	<td><input type="text" name="end_hout" style="width: 100%"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="추가" onclick="addCheck()"> &nbsp; &nbsp;
	<input type="button" value="목록" onclick="search()">
	</td>
</tr>
</table>
</form>
</section>

<jsp:include page="footer.jsp"/>
</body>
</html>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="DBPKG.Utill"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>join</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>봉사 신청</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;">
<input type="hidden" name="mode" value="insert">
<%
Connection conn = Utill.getConnection();
String sql = "select max(id)+1 from member";
PreparedStatement pstmt = conn.prepareStatement(sql);
ResultSet rs = pstmt.executeQuery();
rs.next();
String volu_id = rs.getString(1);
%>
<table border="1" style="text-align: center;">
	<tr>
		<td>봉사번호</td>
		<td><input type="text" name="id" style="width: 100%" value="<%=volu_id %>" readonly></td>
	</tr>
<tr>
	<td>이름</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>비밀번호</td>
	<td><input type="text" name="password" style="width: 100%"></td>
</tr>
<tr>
	<td>전화번호</td>
	<td><input type="text" name="phone" style="width: 100%"></td>
</tr>
<tr>
	<td>봉사활동</td>
	<td>
	<select name="volunteer" style="width: 100%">
		<option value="">봉사 선택</option>
		<option value="1">쓰레기 줍기</option>
		<option value="2">독거노인 돕기</option>
		<option value="3">연탄봉사</option>
		<option value="4">도서관 봉사</option>
		<option value="5">헌혈하기</option>
		<option value="6">재능 기부</option>
		<option value="7">농촌 일손 돕기</option>
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
	<td>봉사시간</td>
	<td>
	<input type="text" name="hour" style="width: 100%">
	</td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="신청" onclick="addCheck()"> &nbsp; &nbsp;
	<input type="button" value="목록" onclick="search()">
	</td>
</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
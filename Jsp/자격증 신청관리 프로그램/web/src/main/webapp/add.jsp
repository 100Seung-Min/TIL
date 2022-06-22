<%@page import="java.sql.ResultSet"%>
<%@page import="web.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="width: 100%; height: 100%; background-color: lightgray; position: fixed; top: 60px">
<h2 style="text-align: center;"><b>자격증 추가</b></h2><br>
<form method="post" name="frm" action="action.jsp" style="display: flex; align-items: center; justify-content: center; text-align: center;" accept-charset="utf-8">
<input type="hidden" name="mode" value="add">
<table border="1">
<%
request.setCharacterEncoding("UTF-8");
Connection conn = null;
String sql = "select max(id)+1 from certificate_tbl";
PreparedStatement pstmt = null;
ResultSet rs = null;
String start = null;
String end = null;
try {
	conn = Util.getConnection();
	pstmt = conn.prepareStatement(sql);
	rs = pstmt.executeQuery();
	rs.next();
} catch (Exception e) {
	e.printStackTrace();
}
%>
<tr>
	<td>자격증번호</td>
	<td><input type="text" name="id" value=<%=rs.getString(1) %> readonly></td>
</tr>
<tr>
	<td>자격증명</td>
	<td><input type="text" name="name"></td>
</tr>
<tr>
	<td>평균점수</td>
	<td><input type="text" name="avg"></td>
</tr>
<tr>
	<td>담당강사</td>
	<td>
	<select name="teacher" style="width: 100%">
		<option value="">담당강사선택</option>
		<option value="1">김교수</option>
		<option value="2">이교수</option>
		<option value="3">박교수</option>
		<option value="4">무교수</option>
	</select>
	</td>
</tr>
<tr>
	<td>요일</td>
	<td>
		<input type="radio" name="week" value=1>월
		<input type="radio" name="week" value=2>수
		<input type="radio" name="week" value=3>금
	</td>
</tr>
<tr>
	<td>시작시간</td>
	<td><input type="text" name="start"></td>
</tr>
<tr>
	<td>종료시간</td>
	<td><input type="text" name="end"></td>
</tr>
<tr>
	<td colspan="2">
		<input type="button" value="추가" onclick="add()"> &nbsp; &nbsp;
		<input type="button" value="목록" onclick="list()">
	</td>
</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
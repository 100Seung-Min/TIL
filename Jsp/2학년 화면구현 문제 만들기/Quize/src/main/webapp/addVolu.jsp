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
<title>modify</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>봉사 추가</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;" accept-charset="utf-8">
<input type="hidden" name="mode" value="create_volu">
<%
request.setCharacterEncoding("UTF-8");
try{
	Connection conn = Utill.getConnection();
	String sql = "select max(id)+1 from voulnteer";
	PreparedStatement pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	%>

<table border="1" style="text-align: center;">
<tr>
	<td>봉사번호</td>
	<td><input type="text" name="id" style="width: 100%" value="<%=rs.getString(1) %>" readonly></td>
</tr>
<tr>
	<td>봉사이름</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>봉사장소</td>
	<td><input type="text" name="place" style="width: 100%"></td>
</tr>
<tr>
	<td>봉사날짜</td>
	<td><input type="text" name="day" style="width: 100%"></td>
</tr>
<tr>
	<td>최대 봉사 인원</td>
	<td><input type="text" name="maxpersonnel" style="width: 100%"></td>
</tr>
<tr>
	<td>최대 봉사 시간</td>
	<td><input type="text" name="hours" style="width: 100%"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="만들기" onclick="addCheck2()"> &nbsp; &nbsp;
	<input type="button" value="취소" onclick="search()">
	</td>
</tr>
</table>
<%
} catch (Exception e) {
	e.printStackTrace();
}
%>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
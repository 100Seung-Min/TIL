<%@page import="java.text.SimpleDateFormat"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>modify</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>

<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 60px; width: 100%; height: 100%;
background-color: lightgray">
<h2 style="text-align: center;"><b>홈쇼핑 회원 정보 수정</b></h2><br>
<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<input type="hidden" name="mode" value="modify">
<table border="1">
<%
Connection conn = null;
Statement stmt = null;
String mod_custno = request.getParameter("mod_custno");
String custname = "";
String phone = "";
String address = "";
Date joindate;
String grade = "";
String city = "";
String joindateStr = "";
try {
	conn = Util.getConnection();
	stmt = conn.createStatement();
	String sql = "SELECT * FROM member_tbl WHERE custno = " + mod_custno;
	ResultSet rs = stmt.executeQuery(sql);
	rs.next();
	custname = rs.getString("custname");
	phone = rs.getString("phone");
	address = rs.getString("address");
	joindate = rs.getDate("joindate");
	grade = rs.getString("grade");
	city = rs.getString("city");
	
	SimpleDateFormat transFormat = new SimpleDateFormat("yyyy-MM-dd");
	joindateStr = transFormat.format(joindate);
} catch(Exception e){
	e.printStackTrace();
}
%>
<tr>
	<td>회원번호</td>
	<td><input type="text" name="custno" value="<%=mod_custno %>" readonly></td>
</tr>
<tr>
	<td>회원성명</td>
	<td><input type="text" name="custname" value="<%=custname %>"></td>
</tr>
<tr>
	<td>회원전화</td>
	<td><input type="text" name="phone" value="<%=phone %>"></td>
</tr>
<tr>
	<td>회원주소</td>
	<td><input type="text" name="address" value="<%=address %>"></td>
</tr>
<tr>
	<td>가입일자</td>
	<td><input type="text" name="joindate" value="<%=joindateStr %>"></td>
</tr>
<tr>
	<td>고객등급[a:VIP, b:일반, C:직원]</td>
	<td><input type="text" name="grade" value="<%=grade %>"></td>
</tr>
<tr>
	<td>도시코드</td>
	<td><input type="text" name="city" value="<%=city %>"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="submit" value="수정" onclick="return modify()">
	<input type="button" value="조회" onclick="return search()">
	</td>
</tr>
</table>
</form>
</section>

<jsp:include page="footer.jsp"/>

</body>
</html>
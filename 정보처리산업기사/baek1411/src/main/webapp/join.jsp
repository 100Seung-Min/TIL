<%@page import="java.sql.*"%>
<%@page import="DBPKG.Util"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>join</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>

<%
Connection conn = null;
Statement stmt = null;
String custno = "";

try{
	conn = Util.getConnection();	//DB연결
	stmt = conn.createStatement();	//sql을 위한 변수 생성
	String sql = "SELECT max(custno)+1 custno FROM member_tbl";
	ResultSet rs = stmt.executeQuery(sql); //stmt를 통해 sql 실행결과
	rs.next();	//1개의 결과를 출력
	custno = rs.getString("custno");
	System.out.println(custno);
}catch(Exception e){
	e.printStackTrace();
}
%>

<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 60px; width: 100%; height: 100%;
background-color: lightgray">
<h2 style="text-align: center;"><b>홈쇼핑 회원 등록</b></h2><br>
<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<input type="hidden" name="mode" value="insert">
<table border="1">
<tr>
	<td>회원번호(자동발생)</td>
	<td><input type="text" name="custno"  value="<%=custno %>" readonly></td>
</tr>
<tr>
	<td>회원성명</td>
	<td><input type="text" name="custname"></td>
</tr>
<tr>
	<td>회원전화</td>
	<td><input type="text" name="phone"></td>
</tr>
<tr>
	<td>회원주소</td>
	<td><input type="text" name="address"></td>
</tr>
<tr>
	<td>가입일자</td>
	<td><input type="text" name="joindate"></td>
</tr>
<tr>
	<td>고객등급[a:VIP, b:일반, C:직원]</td>
	<td><input type="text" name="grade"></td>
</tr>
<tr>
	<td>도시코드</td>
	<td><input type="text" name="city"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="submit" value="등록" onclick="return joinCheck()">
	<input type="button" value="조회" onclick="return search()">
	</td>
</tr>
</table>
</form>
</section>

<jsp:include page="footer.jsp"/>

</body>
</html>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>action</title>
</head>
<body>
<%
request.setCharacterEncoding("UTF-8");
Connection conn = null;
Statement stmt = null;
String mode = request.getParameter("mode");
String custno = request.getParameter("custno");
String custname = request.getParameter("custname");
String phone = request.getParameter("phone");
String address = request.getParameter("address");
String joindate = request.getParameter("joindate");
String grade = request.getParameter("grade");
String city = request.getParameter("city");
try{
	conn = Util.getConnection();
	stmt = conn.createStatement();
	String sql = "";
	
	switch(mode){
	case "insert" :
		sql = "INSERT INTO member_tbl VALUES(" + custno + ", " +
											"'" + custname + "', " +
											"'" + phone + "', " + 
											"'" + address + "', " +
											"TO_DATE('" + joindate + "', 'yyyy-MM-dd'), " +
											"'" + grade + "', " + 
											"'" + city + "')";
		stmt.executeUpdate(sql);
		
%>
<jsp:forward page="join.jsp"></jsp:forward>
<%
		break;
	case "modify" :
		sql = "UPDATE member_tbl SET " + 
				"custname = '" + custname + "', " +
				"phone = '" + phone + "', " + 
				"address = '" + address + "', " + 
				"joindate = TO_DATE('" + joindate + "', 'yyyy-MM-dd'), " + 
				"grade = '" + grade + "', " + 
				"city = '" + city + "' " + 
				"WHERE custno = " + custno;
		System.out.println(sql);
		stmt.executeUpdate(sql);
%>
<jsp:forward page="modify.jsp"></jsp:forward>
<%
		break;
	}
} catch(Exception e){
	e.printStackTrace();
}
%>
</body>
</html>
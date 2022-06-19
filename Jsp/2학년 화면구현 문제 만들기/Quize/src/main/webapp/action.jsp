<%@page import="java.sql.PreparedStatement"%>
<%@page import="DBPKG.Utill"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
request.setCharacterEncoding("UTF-8");
String mode = request.getParameter("mode");
String id = request.getParameter("id");
String volunteer = request.getParameter("volunteer");
String name = request.getParameter("name");
String phone = request.getParameter("phone");
String password = request.getParameter("password");
String hour = request.getParameter("hour");
String week = request.getParameter("week");

try {
	Connection conn = Utill.getConnection();
	String sql = null;
	PreparedStatement pstmt = null;
	switch(mode){
	case "insert":
		sql = "insert into member values (?, ?, ?, ?, ?, ?, ?)";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, id);
		pstmt.setString(2, volunteer);
		pstmt.setString(3, name);
		pstmt.setString(4, phone);
		pstmt.setString(5, password);
		pstmt.setString(6, hour);
		pstmt.setString(7, week);
		pstmt.executeUpdate();
		break;
	case "delete_user":
		sql = "delete from ";
		pstmt.executeUpdate();
		break;
	case "update_user":
		sql = "update set ";
		pstmt.executeUpdate();
		break;
	case "delete_voul":
		sql = "delete from";
		pstmt.executeUpdate();
		break;
	case "update_voul":
		sql = "update set";
		pstmt.executeUpdate();
		break;
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
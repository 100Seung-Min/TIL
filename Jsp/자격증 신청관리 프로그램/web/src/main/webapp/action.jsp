<%@page import="web.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
request.setCharacterEncoding("UTF-8");
Connection conn = null;
String sql = null;
PreparedStatement pstmt = null;

String mode = request.getParameter("mode");
String id = request.getParameter("id");
String name = request.getParameter("name");
String avg = request.getParameter("avg");
String teacher = request.getParameter("teacher");
String week = request.getParameter("week");
String start = request.getParameter("start");
String end = request.getParameter("end");

try {
	conn = Util.getConnection();
	switch(mode) {
	case "delete":
		sql = "delete from certificate_tbl where id = ?";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, id);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="list.jsp"/>
		<%
		break;
	case "add":
		sql = "insert into certificate_tbl values (?, ?, ?, ?, ?, ?, ?)";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, id);
		pstmt.setString(2, name);
		pstmt.setString(3, avg);
		pstmt.setString(4, teacher);
		pstmt.setString(5, week);
		pstmt.setString(6, start);
		pstmt.setString(7, end);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="add.jsp"/>
		<%
		break;
	case "modify":
		sql = "update certificate_tbl set name = ?, average = ?, lecturerId = ?, week = ?, start_time = ?, end_time = ? where id = ?";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, name);
		pstmt.setString(2, avg);
		pstmt.setString(3, teacher);
		pstmt.setString(4, week);
		pstmt.setString(5, start);
		pstmt.setString(6, end);
		pstmt.setString(7, id);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="list.jsp"></jsp:forward>
		<%
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
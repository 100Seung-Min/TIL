<%@page import="java.sql.ResultSet"%>
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

String volu_day = request.getParameter("day");
String volu_personnel = request.getParameter("maxpersonnel");
String volu_plcace = request.getParameter("place");
String volu_hours = request.getParameter("hours");
if (week != null) {
	switch(week){
	case "1": week = "월"; break;
	case "2": week = "화"; break;
	case "3": week = "수"; break;
	case "4": week = "목"; break;
	case "5": week = "금"; break;
	case "6": week = "토"; break;
	case "7": week = "일"; break;
	}	
}

try {
	Connection conn = Utill.getConnection();
	String sql = null;
	String subSql = null;
	PreparedStatement pstmt = null;
	PreparedStatement subPstmt = null;
	int hours = 0;
	int maxpersonnel = 0;
	int personnel = 0;
	String day = null;
	
	if(!mode.equals("create_volu")){
		if(mode.equals("update_user")) {
			String findIdSql = "select id from voulnteer where name = \'" + volunteer + "\'";
			PreparedStatement findIdPstmt = conn.prepareStatement(findIdSql);
			ResultSet rs = findIdPstmt.executeQuery();
			rs.next();
			volunteer = rs.getString(1);
		}
		subSql = "select day, hours, maxpersonnel, personnel from voulnteer where id = " + volunteer;
		subPstmt = conn.prepareStatement(subSql);
		ResultSet rs = subPstmt.executeQuery();
		rs.next();
		day = rs.getString(1);
		hours = rs.getInt(2);
		maxpersonnel = rs.getInt(3);
		personnel = rs.getInt(4);	
	}
	
	switch(mode) {
	case "insert":
		if(hours < Integer.parseInt(hour)) {
			%>
			<jsp:forward page="fail.jsp?becuse=hours"/>
			<%
			break;
		}
		else if(personnel == maxpersonnel){
			%>
			<jsp:forward page="fail.jsp?becuse=personnel"></jsp:forward>]
			<%
		}
		else if(!day.contains(week)) {
			%>
			<jsp:forward page="fail.jsp?becuse=day"/>
			<%
		}
		else {
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
			
			String subSql2 = "update voulnteer set personnel = " + (personnel+1) + " where id = " + volunteer;
			PreparedStatement subPstmt2 = conn.prepareStatement(subSql2);
			subPstmt2.executeUpdate();
			%>
			<jsp:forward page="join.jsp"/>
			<%
		}
		break;
	case "delete_user":
		sql = "delete from member where id = " + id;
		pstmt = conn.prepareStatement(sql);
		pstmt.executeUpdate();		
		
		String subSql2 = "update voulnteer set personnel = " + (personnel-1) + " where id = " + volunteer;
		PreparedStatement subPstmt2 = conn.prepareStatement(subSql2);
		subPstmt2.executeUpdate();
		break;
	case "update_user":
		if(hours < Integer.parseInt(hour)) {
			%>
			<jsp:forward page="fail.jsp?becuse=hours"/>
			<%
			break;
		}
		else if(personnel == maxpersonnel){
			%>
			<jsp:forward page="fail.jsp?becuse=personnel"></jsp:forward>]
			<%
		}
		else if(!day.contains(week)) {
			%>
			<jsp:forward page="fail.jsp?becuse=day"/>
			<%
		}
		else {
			sql = "update member set name=?, volu_id=?, phone=?, password=?, volu_time=?, day=? where id=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, name);
			pstmt.setString(2, volunteer);
			pstmt.setString(3, phone);
			pstmt.setString(4, password);
			pstmt.setString(5, hour);
			pstmt.setString(6, week);
			pstmt.setString(7, id);
			pstmt.executeUpdate();
			%>
			<jsp:forward page="login.jsp"></jsp:forward>
			<%
		}
		break;
	case "create_volu":
		System.out.println(id + name + volu_plcace + volu_day + volu_personnel + volu_hours);
		sql = "insert into voulnteer values (?, ?, ?, ?, ?, ?, ?)";
		
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, id);
		pstmt.setString(2, name);
		pstmt.setString(3, volu_plcace);
		pstmt.setString(4, volu_day);
		pstmt.setString(5, "0");
		pstmt.setString(6, volu_personnel);
		pstmt.setString(7, volu_hours);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="list.jsp"/>
		<%
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
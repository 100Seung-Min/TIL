<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>list</title>
</head>
<body>
<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>교과목 목록 조회/수정</b></h2>
<form name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<table border="1">
<tr>
	<td>과목코드</td>
	<td>과목명</td>
	<td>학점</td>
	<td>담당강사</td>
	<td>요일</td>
	<td>시작시간</td>
	<td>종료시간</td>
	<td>삭제</td>
</tr>
<%
request.setCharacterEncoding("UTF-8");
try{
	Connection conn = Util.getConnection();
	String sql = "Select id, co.name cname, credit, le.name lname, week, start_hour, end_hour FROM course_tbl co, lecturer_tbl le WHERE co.lecturer=le.idx ORDER BY id";
	PreparedStatement pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	while(rs.next()){
		String week = rs.getString(5);
		switch(week){
		case "1": week = "월요일"; break;
		case "2": week = "화요일"; break;
		case "3": week = "수요일"; break;
		case "4": week = "목요일"; break;
		case "5": week = "금요일"; break;
		case "6": week = "토요일"; break;
		case "7": week = "일요일"; break;
		}
		
		String start_hour = rs.getString(6);
		while(start_hour.length()<4){
			start_hour = "0" + start_hour;
		}
		start_hour = start_hour.substring(0,2) + "시" + start_hour.substring(2,4) + "분";
		
		String end_hour = rs.getString(7);
		while(end_hour.length()<4){
			end_hour = "0" + end_hour;
		}
		end_hour = end_hour.substring(0,2) + "시" + end_hour.substring(2,4) + "분";
%>
	<tr>
		<td><a href="modify.jsp?id=<%=rs.getString(1) %>"><%=rs.getString(1) %></a></td>
		<td><%=rs.getString(2) %></td>
		<td><%=rs.getString(3) %></td>
		<td><%=rs.getString(4) %></td>
		<td><%=week %></td>
		<td><%=start_hour %></td>
		<td><%=end_hour %></td>
		<td><a href="action.jsp?id=<%=rs.getString(1) %>&mode=delete">삭제</a></td>
	</tr>
<%
	}
}catch(Exception e){
	e.printStackTrace();
}
%>
</table>
</form>
</section>

<jsp:include page="footer.jsp"/>
</body>
</html>
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
<h2 style="text-align: center;"><b>������ ��� ��ȸ/����</b></h2>
<form name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<table border="1">
<tr>
	<td>�����ڵ�</td>
	<td>�����</td>
	<td>����</td>
	<td>��簭��</td>
	<td>����</td>
	<td>���۽ð�</td>
	<td>����ð�</td>
	<td>����</td>
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
		case "1": week = "������"; break;
		case "2": week = "ȭ����"; break;
		case "3": week = "������"; break;
		case "4": week = "�����"; break;
		case "5": week = "�ݿ���"; break;
		case "6": week = "�����"; break;
		case "7": week = "�Ͽ���"; break;
		}
		
		String start_hour = rs.getString(6);
		while(start_hour.length()<4){
			start_hour = "0" + start_hour;
		}
		start_hour = start_hour.substring(0,2) + "��" + start_hour.substring(2,4) + "��";
		
		String end_hour = rs.getString(7);
		while(end_hour.length()<4){
			end_hour = "0" + end_hour;
		}
		end_hour = end_hour.substring(0,2) + "��" + end_hour.substring(2,4) + "��";
%>
	<tr>
		<td><a href="modify.jsp?id=<%=rs.getString(1) %>"><%=rs.getString(1) %></a></td>
		<td><%=rs.getString(2) %></td>
		<td><%=rs.getString(3) %></td>
		<td><%=rs.getString(4) %></td>
		<td><%=week %></td>
		<td><%=start_hour %></td>
		<td><%=end_hour %></td>
		<td><a href="action.jsp?id=<%=rs.getString(1) %>&mode=delete">����</a></td>
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
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
<jsp:include page="header.jsp"/>
<section style="width: 100%; height: 100%; background-color: lightgray; position: fixed; top: 60px">
<h2 style="text-align: center;"><b>�ڰ��� ���</b></h2><br>
<form style="display: flex; align-items: center; justify-content: center; text-align: center;" accept-charset="utf-8">
<table border="1">
<tr>
	<td>�ڰ�����ȣ</td>
	<td>�ڰ�����</td>
	<td>�������</td>
	<td>��簭��</td>
	<td>����</td>
	<td>���۽ð�</td>
	<td>����ð�</td>
	<td>����</td>
</tr>
<%
Connection conn = null;
PreparedStatement pstmt = null;
try {
	conn = Util.getConnection();
	String sql = "select ct.id, ct.name, ct.average, lt.name, ct.week, ct.start_time, ct.end_time from certificate_tbl ct, lecturer_tbl lt where ct.lecturerId = lt.idx order by ct.id";
	pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	while(rs.next()){
		String week = rs.getString(5);
		switch(week){
		case "1": week = "������"; break;
		case "2": week = "������"; break;
		case "3": week = "�ݿ���"; break;
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
			<td><a href="change.jsp?id=<%=rs.getString(1)%>"><%=rs.getString(1) %></a></td>
			<td><%=rs.getString(2) %></td>
			<td><%=rs.getString(3) %></td>
			<td><%=rs.getString(4) %></td>
			<td><%=week %></td>
			<td><%=start_hour %></td>
			<td><%=end_hour %></td>
			<td><a href="action.jsp?mode=delete&id=<%=rs.getString(1)%>">����</td>
		</tr>
		<%
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
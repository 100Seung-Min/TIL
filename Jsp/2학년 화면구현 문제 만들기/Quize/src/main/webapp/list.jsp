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
<title>list</title>
</head>
<body>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>���� ��� ��ȸ/ ����</b></h2>
<form name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<table border="1">
<tr>
	<td>���� �̸�</td>
	<td>���� ���</td>
	<td>���� ����</td>
	<td>�ִ� ��û �ο�</td>
	<td>��û �ο�</td>
	<td>�ִ� ���� �ð�</td>
	<td>����</td>
	<td>����</td>
</tr>
<%
request.setCharacterEncoding("UTF-8");
try {
	Connection conn = Utill.getConnection();
	String sql = "select name, place, day, personnel, maxpersonnel, hours from voulnteer order by id";
	PreparedStatement pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	while(rs.next()) {
		
%>
<tr>
	<td><%=rs.getString(1) %></td>
	<td><%=rs.getString(2) %></td>
	<td><%=rs.getString(3) %></td>
	<td><%=rs.getString(5) %></td>
	<td><%=rs.getString(4) %></td>
	<td><%=rs.getString(6) %></td>
	<td></td>
	<td></td>
<tr>
<%
	}
} catch (Exception e){
	e.printStackTrace();
}
%>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
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
<title>modify</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>���� ����</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;" accept-charset="utf-8">
<input type="hidden" name="mode" value="update_user">
<%
request.setCharacterEncoding("UTF-8");
String id = request.getParameter("id");
try{
	Connection conn = Utill.getConnection();
	String sql = "select mem.name, mem.password, mem.phone, mem.volu_time, vo.name from member mem, voulnteer vo where vo.id = mem.volu_id and mem.id = " + id;
	PreparedStatement pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	%>

<table border="1" style="text-align: center;">
	<tr>
		<td>�����ȣ</td>
		<td><input type="text" name="id" style="width: 100%" value="<%=id %>" readonly></td>
	</tr>
<tr>
	<td>�̸�</td>
	<td><input type="text" name="name" style="width: 100%" value="<%=rs.getString(1) %>"></td>
</tr>
<tr>
	<td>��й�ȣ</td>
	<td><input type="text" name="password" style="width: 100%" value="<%=rs.getString(2) %>"></td>
</tr>
<tr>
	<td>��ȭ��ȣ</td>
	<td><input type="text" name="phone" style="width: 100%" value="<%=rs.getString(3) %>"></td>
</tr>
<tr>
	<td>����Ȱ��</td>
	<td><input type="text" name="volunteer" style="width: 100%" value="<%=rs.getString(5) %>" readonly></td>
</tr>
<tr>
	<td>����</td>
	<td>
	<input type="radio" name="week" value="1">��
	<input type="radio" name="week" value="2">ȭ
	<input type="radio" name="week" value="3">��
	<input type="radio" name="week" value="4">��
	<input type="radio" name="week" value="5">��
	<input type="radio" name="week" value="6">��
	<input type="radio" name="week" value="7">��
	</td>
</tr>
<tr>
	<td>����ð�</td>
	<td>
	<input type="text" name="hour" style="width: 100%"  value="<%=rs.getString(4) %>">
	</td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="��û" onclick="addCheck()"> &nbsp; &nbsp;
	<input type="button" value="���" onclick="search()">
	</td>
</tr>
</table>
<%
} catch (Exception e) {
	e.printStackTrace();
}
%>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
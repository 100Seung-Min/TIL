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
<title>join</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>���� ��û</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;">
<input type="hidden" name="mode" value="insert">
<%
Connection conn = Utill.getConnection();
String sql = "select max(id)+1 from member";
PreparedStatement pstmt = conn.prepareStatement(sql);
ResultSet rs = pstmt.executeQuery();
rs.next();
String volu_id = rs.getString(1);
%>
<table border="1" style="text-align: center;">
	<tr>
		<td>�����ȣ</td>
		<td><input type="text" name="id" style="width: 100%" value="<%=volu_id %>" readonly></td>
	</tr>
<tr>
	<td>�̸�</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>��й�ȣ</td>
	<td><input type="text" name="password" style="width: 100%"></td>
</tr>
<tr>
	<td>��ȭ��ȣ</td>
	<td><input type="text" name="phone" style="width: 100%"></td>
</tr>
<tr>
	<td>����Ȱ��</td>
	<td>
	<select name="volunteer" style="width: 100%">
		<option value="">���� ����</option>
		<option value="1">������ �ݱ�</option>
		<option value="2">���ų��� ����</option>
		<option value="3">��ź����</option>
		<option value="4">������ ����</option>
		<option value="5">�����ϱ�</option>
		<option value="6">��� ���</option>
		<option value="7">���� �ϼ� ����</option>
	</select>
</tr>
<tr>
	<td>����</td>
	<td>
	<input type="radio" name="week" value="1">��
	<input type="radio" name="week" value="2">ȭ
	<input type="radio" name="week" value="3">��
	<input type="radio" name="week" value="4">��
	<input type="radio" name="week" value="5">��
	</td>
</tr>
<tr>
	<td>����ð�</td>
	<td>
	<input type="text" name="hour" style="width: 100%">
	</td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="��û" onclick="addCheck()"> &nbsp; &nbsp;
	<input type="button" value="���" onclick="search()">
	</td>
</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
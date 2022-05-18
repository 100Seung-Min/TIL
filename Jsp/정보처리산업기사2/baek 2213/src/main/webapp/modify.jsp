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
<title>modify</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>������ ����</b></h2>
<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center">
<input type="hidden" name="mode" value="modify">
<table border="1">
<%
request.setCharacterEncoding("UTF-8");
String id = request.getParameter("id");

try{
	Connection conn = Util.getConnection();
	String sql = "select * from course_tbl where id = ?";
	PreparedStatement pstmt = conn.prepareStatement(sql);
	pstmt.setString(1, id);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	String lecturer = rs.getString(4);
	String week = rs.getString(5);
	String start_hour = rs.getString(6);
	while(start_hour.length()<4){
		start_hour = "0" + start_hour;
	}
	
	String end_hour = rs.getString(7);
	while(end_hour.length()<4){
		end_hour = "0" + end_hour;
	}
	%>
	<tr>
		<td>�����ڵ�</td>
		<td><input type="text" name="id" style="width: 100%;" value="<%=id %>" readonly></td>
	</tr>
	<tr>
		<td>�����</td>
		<td><input type="text" name="name" style="width: 100%;" value="<%=rs.getString(2) %>"></td>
	</tr>
	<tr>
		<td>����</td>
		<td><input type="text" name="credit" style="width: 100%;" value="<%=rs.getString(3) %>"></td>
	</tr>
	<tr>
		<td>��簭��</td>
		<td>
		<select name="lecturer" style="width: 100%">
			<option value="">��簭�缱��</option>
			<option value="1" <% if(lecturer.equals("1")) out.println("selected"); %>>�豳��</option>
			<option value="2" <% if(lecturer.equals("2")) out.println("selected"); %>>�̱���</option>
			<option value="3" <% if(lecturer.equals("3")) out.println("selected"); %>>�ڱ���</option>
			<option value="4" <% if(lecturer.equals("4")) out.println("selected"); %>>�챳��</option>
			<option value="5" <% if(lecturer.equals("5")) out.println("selected"); %>>�ֱ���</option>
			<option value="6" <% if(lecturer.equals("6")) out.println("selected"); %>>�ӱ���</option>
		</select>
		</td>
	</tr>
	<tr>
		<td>����</td>
		<td>
			<input type="radio" name="week" value="1" <% if(week.equals("1")) out.println("checked"); %>>��
			<input type="radio" name="week" value="2" <% if(week.equals("2")) out.println("checked"); %>>ȭ
			<input type="radio" name="week" value="3" <% if(week.equals("3")) out.println("checked"); %>>��
			<input type="radio" name="week" value="4" <% if(week.equals("4")) out.println("checked"); %>>��
			<input type="radio" name="week" value="5" <% if(week.equals("5")) out.println("checked"); %>>��
		</td>
	</tr>
	<tr>
		<td>���۽ð�</td>
		<td><input type="text" name="start_hour" style="width: 100%;" value="<%=start_hour %>"></td>
	</tr>
	<tr>
		<td>����ð�</td>
		<td><input type="text" name="end_hour" style="width: 100%;" value="<%=end_hour %>"></td>
	</tr>
	<tr>
		<td colspan="2">
			<input type="button" value="����" onclick="modify()"> &nbsp; &nbsp;
			<input type="button" value="���" onclick="res()">
		</td>
	</tr>
	<%
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
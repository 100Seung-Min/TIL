<%@page import="java.time.LocalDate"%>
<%@page import="java.sql.Date"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DBPKG.Util"%>
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
<section style="position: fixed; width: 100%; height: 100%; top: 70px; bottom: 30px; background-color: lightgray; left: 0px">
<h2 style="text-align: center;">��ǥ�˼���ȸ</h2>
<form style="display: flex; align-items: center; justify-content: center; text-align: center;">
<table border="1">
	<tr>
		<td>����</td>
		<td>�������</td>
		<td>����</td>
		<td>����</td>
		<td>�ĺ���ȣ</td>
		<td>��ǥ�ð�</td>
		<td>������Ȯ��</td>
	</tr>
	<%
	request.setCharacterEncoding("utf-8");
	Connection conn = null;
	PreparedStatement pstmt = null;
	try {
		conn = Util.getConnection();
		String sql = "select * from TBL_VOTE_202005 where V_AREA='��1��ǥ��'";
		pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()){
			String birth = rs.getString(1).substring(0, 6);
			birth = "19" + birth.substring(0, 2) + "��" + birth.substring(2, 4) + "��" + birth.substring(4, 6) + "�ϻ�"; 
			String sex = rs.getString(1).substring(6,7).equals("1") ? "��" : "��";
			int age = LocalDate.now().getYear() - (Integer.parseInt(birth.substring(2, 4)) + 1900); 
			String check = rs.getString(6).equals("Y") ? "Ȯ��" : "��Ȯ��";
			String time = rs.getString(4).substring(0, 2) + ":" + rs.getString(4).substring(2, 4);
		%>
		<tr>
			<td><%=rs.getString(2) %></td>
			<td><%=birth %></td>
			<td>�� <%=age %>��</td>
			<td><%=sex %></td>
			<td><%=rs.getString(3) %></td>
			<td><%=time %></td>
			<td><%=check %></td>
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
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
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="position: fixed; width: 100%; height: 100%; top: 70px; bottom: 30px; background-color: lightgray; left: 0px">
<h2 style="text-align: center;">��ǥ�ϱ�</h2>
<form name="frm" method="post" action="action.jsp" style="display: flex; align-items: center; justify-content: center; text-align: center;">
<input type="hidden" value="vote" name="type">
<table border="1">
	<tr>
		<td>�ֹι�ȣ</td>
		<td><input type="text" name="jumin_num"></td>
	</tr>
	<tr>
		<td>����</td>
		<td><input type="text" name="name"></td>
	</tr>
	<tr>
		<td>��ǥ��ȣ</td>
		<td>
			<select name="vote_num" style="width: 100%">
				<option value=""></option>
				<%
				Connection conn = null;
				PreparedStatement pstmt = null;
				try {
					conn = Util.getConnection();
					String sql = "select m_no, m_name from tbl_member_202005";
					pstmt = conn.prepareStatement(sql);
					ResultSet rs = pstmt.executeQuery();
					while(rs.next()) {
						%>
						<option value=<%=rs.getString(1) %>>[<%=rs.getString(1) %>] <%=rs.getString(2) %></option>
						<%
					}
				} catch(Exception e) {
					e.printStackTrace();
				}
				%>
			</select>
		</td>
	</tr>
	<tr>
		<td>��ǥ�ð�</td>
		<td><input type="text" name="vote_time"></td>
	</tr>
	<tr>
		<td>��ǥ���</td>
		<td><input type="text" name="vote_place"></td>
	</tr>
	<tr>
		<td>������Ȯ��</td>
		<td>
			<input type="radio" name="check_vote" value="Y">Ȯ��
			<input type="radio" name="check_vote" value="N">��Ȯ��
		</td>
	</tr>
	<tr>
		<td colspan="2">
			<input type="button" value="��ǥ�ϱ�" onclick="check()">
			<input type="button" value="�ٽ��ϱ�">
		</td>
	</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
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
<section style="width: 100%; position: fixed; height: 100%; margin-bottom: 40px; background-color: lightgray; margin-top: 120px; top: 0px; right: 0px">
<h2 style="text-align: center;">������û</h2>
<form style="display: flex; align-items: center; justify-content: center;" action="action.jsp" method="post" name="frm">
<table border="1" style="border-collapse: collapse; width: 40%"> 
<%
Connection con = null;
PreparedStatement pstmt = null;
try {
	con = Util.getConnection();
%>
	<tr>
		<td style="text-align: center;">������</td>
		<td><input name="regist_month">2022�� 3�� ��)202203</td>
	</tr>
	<tr>
		<td style="text-align: center;">ȸ����</td>
		<td>
			<select name="c_name" onchange="select_cName()" style="width: 30%">
				<option value="">ȸ����
				<%
				String sql = "select c_name, c_no from tbl_member_202201";
				pstmt = con.prepareStatement(sql);
				ResultSet rs = pstmt.executeQuery();
				while(rs.next()) {
					%>
					<option value=<%=rs.getString(2) %>><%=rs.getString(1) %>
					<%
				}
				%>
			</select>
		</td>
	</tr>
	<tr>
		<td style="text-align: center;">ȸ����ȣ</td>
		<td><input readonly="readonly" name="c_no">��)10001</td>
	</tr>
	<tr>
		<td style="text-align: center;">�������</td>
		<td>
			<select name="class_area" style="width: 30%">
				<option value="">�������
				<option value="���ﺻ��">���ﺻ��
				<option value="�����п�">�����п�
				<option value="�λ�п�">�λ�п�
				<option value="�뱸�п�">�뱸�п�
			</select>
		</td>
	</tr>
	<tr>
		<td style="text-align: center;">���Ǹ�</td>
		<td>
			<select name="class_name" onchange="select_class_name()" style="width: 30%">
				<option value="">���Ǹ�
				<%
				sql = "select class_name, class_price from tbl_teacher_202201";
				pstmt = con.prepareStatement(sql);
				rs = pstmt.executeQuery();
				while(rs.next()) {
					%>
					<option value=<%=rs.getString(2) %>><%=rs.getString(1) %>
					<%
				}
				%>
			</select>
		</td>
	</tr>
	<tr>
		<td style="text-align: center;">������</td>
		<td><input readonly="readonly" name="class_price">��</td>
	</tr>
	<tr>
		<td colspan="2" style="text-align: center;">
			<input type="button" value="������û" onclick="join()">
			<input type="button" value="�ٽþ���" onclick="re_write()">
		</td>
	</tr>
<%
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
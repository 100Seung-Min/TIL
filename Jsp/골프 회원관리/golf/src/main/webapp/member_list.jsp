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
<section style="width: 100%; position: fixed; height: 100%; margin-bottom: 40px; background-color: lightgray; margin-top: 120px; top: 0px; right: 0px">
<h2 style="text-align: center;">회원정보조회</h2>
<form style="display: flex; align-items: center; justify-content: center;">
<table border="1" style="border-collapse: collapse; text-align: center;"> 
	<tr>
		<td>수강일</td>
		<td>회원번호</td>
		<td>회원명</td>
		<td>강의명</td>
		<td>강의장소</td>
		<td>수강료</td>
		<td>등급</td>
	</tr>
	<%
	Connection con = null;
	PreparedStatement pstmt = null;
	try {
		con = Util.getConnection();
		String sql = "select c.regist_month, m.c_no, m.c_name, t.class_name, c.class_area, c.tuition, m.grade from tbl_member_202201 m, tbl_class_202201 c, tbl_teacher_202201 t where m.c_no = c.c_no and t.teacher_code = c.teacher_code";
		pstmt = con.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			%>
			<tr>
				<td><%=rs.getString(1).substring(0, 4) + "년" + rs.getString(1).substring(4) + "월" %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
				<td><%=rs.getString(4) %></td>
				<td><%=rs.getString(5) %></td>
				<td><%="\\" + String.format("%,d", rs.getInt(6)) %></td>
				<td><%=rs.getString(7) %></td>
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
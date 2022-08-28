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
<h2 style="text-align: center;">강사조회</h2>
<form style="display: flex; align-items: center; justify-content: center;">
<table border="1" style="border-collapse: collapse; text-align: center;"> 
	<tr>
		<td>강사코드</td>
		<td>강사명</td>
		<td>강의명</td>
		<td>수강료</td>
		<td>강사자격취득일</td>
	</tr>
	<%
	Connection con = null;
	PreparedStatement pstmt = null;
	try {
		con = Util.getConnection();
		String sql = "select * from tbl_teacher_202201";
		pstmt = con.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			%>
			<tr>
				<td><%=rs.getString(1) %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
				<td><%="\\" + String.format("%,d", rs.getInt(4)) %></td>
				<td><%=rs.getString(5).substring(0, 4) + "년" +  rs.getString(5).substring(4, 6) + "월" + rs.getString(5).substring(6) + "일"%></td>
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
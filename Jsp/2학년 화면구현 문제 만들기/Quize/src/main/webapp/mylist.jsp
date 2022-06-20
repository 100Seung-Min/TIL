<%@page import="DBPKG.Utill"%>
<%@page import="java.sql.*"%>
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
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>봉사 신청 조회/ 수정</b></h2>
<form name="frm" style="display: flex; align-items: center; justify-content: center; text-align: center" accept-charset="utf-8">
<table border="1">
<tr>
	<td>신청한 봉사</td>
	<td>신청 요일</td>
	<td>봉사 시간</td>
	<td>봉사 수정</td>
	<td>봉사 취소</td>
</tr>
<%
request.setCharacterEncoding("UTF-8");
String name = request.getParameter("name");
String password = request.getParameter("password");
try {
	Connection conn = Utill.getConnection();
	String sql = "select voul.name, mem.day, mem.volu_time, mem.id, voul.id from voulnteer voul, member mem where voul.id = mem.volu_id and mem.name = \'" + name + "\' and mem.password = \'" + password + "\'";
	PreparedStatement pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	while(rs.next()) {
		
%>
<tr>
	<td><%=rs.getString(1) %></td>
	<td><%=rs.getString(2) %></td>
	<td><%=rs.getString(3) %></td>
	<td><a href="changeVolu.jsp?id=<%=rs.getString(4) %>">수정</a></td>
	<td><a href="action.jsp?id=<%=rs.getString(4)%>&mode=delete_user&volunteer=<%=rs.getString(5)%>">취소</a></td>
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
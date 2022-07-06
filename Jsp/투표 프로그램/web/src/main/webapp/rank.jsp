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
<h2 style="text-align: center;">후보자 등수</h2>
<form style="display: flex; align-items: center; justify-content: center; text-align: center;">
<table border="1">
	<tr>
		<td>후보번호</td>
		<td>성명</td>
		<td>총투표건수</td>
	</tr>
	<%
	Connection conn = null;
	PreparedStatement pstmt = null;
	try {
		conn = Util.getConnection();
		String sql = "select m.m_no, m.m_name, count(*) as all_vote from tbl_member_202005 m, tbl_vote_202005 v where m.m_no=v.m_no and v.v_confirm='Y' group by m.m_no, m.m_name order by all_vote desc";
		pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			%>
			<tr>
				<td><%=rs.getString(1) %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
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
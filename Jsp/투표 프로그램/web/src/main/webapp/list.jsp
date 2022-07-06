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
<h2 style="text-align: center;">후보조회</h2>
<form style="display: flex; align-items: center; justify-content: center; text-align: center;">
<table border="1">
	<tr>
		<td>후보번호</td>
		<td>성명</td>
		<td>소속정당</td>
		<td>학력</td>
		<td>주민번호</td>
		<td>지역구</td>
		<td>대표전화</td>
	</tr>
	<%
	Connection conn = null;
	PreparedStatement pstmt = null;
	try {
		conn = Util.getConnection();
		String sql = "select m.m_no, m.m_name, p.p_name, m.p_school, m.m_jumin, m.m_city, p.p_tel1, p.p_tel2, p.p_tel3 from tbl_member_202005 m, tbl_party_202005 p where m.p_code=p.p_code order by m.m_no asc";
		pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			String jumin_num = rs.getString(5).substring(0, 6) + "-" + rs.getString(5).substring(6);
			String school = "";
			switch(rs.getString(4)) {
			case "1" : school = "고졸"; break;
			case "2" : school = "학사"; break;
			case "3" : school = "석사"; break;
			case "4" : school = "박사"; break;
			}
			%>
			<tr>
				<td><%=rs.getString(1) %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
				<td><%=school %></td>
				<td><%=jumin_num %></td>
				<td><%=rs.getString(6) %></td>
				<td><%=rs.getString(7) %>-<%=rs.getString(8) %>-<%=rs.getString(9) %></td>
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
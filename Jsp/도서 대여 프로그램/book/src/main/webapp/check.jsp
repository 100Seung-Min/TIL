<%@page import="java.util.Calendar"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<jsp:include page="header.jsp"/>
<section style="width: 100%; height: 100%; margin-bottom: 25px; margin-top: 70px; position: fixed; right: 0px">
<h2 style="text-align: center;">대여 정보 확인하기</h2>
<form style="display: flex; align-items: center; justify-content: center;" accept-charset="utf-8">
<table border="1" style="border-collapse: collapse; text-align: center;">
	<tr>
		<td>대여번호</td>
		<td>고객번호</td>
		<td>고객이름</td>
		<td>연락처</td>
		<td>도서명</td>
		<td>대여날짜</td>
		<td>대여기한</td>
		<td>반납여부</td>
	</tr>
	<%
	Connection con = null;
	PreparedStatement pstmt = null;
	try {
		con = Util.getConnection();
		String sql = "select bo.bor_no, bo.m_no, bo.m_name, me.phone, bo.bookname, bo.bor_date, bo.re_book, bo.bookno from borrow_tbl bo, mem_tbl me where bo.m_name = me.m_name order by bor_no";
		pstmt = con.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			String borrow = rs.getString(7).equals("반납") ? "" : "반납하기";
			SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd"); 
			String day = dateFormat.format(rs.getDate(6));
			%>
			<tr>
				<td><%=rs.getString(1) %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
				<td><%=rs.getString(4) %></td>
				<td><%=rs.getString(5) %></td>
				<td><%=day %></td>
				<td><%=day.substring(0, 8) + String.format("%02d", (Integer.parseInt(day.substring(8)) + 6)) %></td>
				<td><a href="return.jsp?id=<%=rs.getString(1) %>&mNa=<%=rs.getString(3) %>&mNo=<%=rs.getString(2) %>&bNa=<%=rs.getString(5) %>&day=<%=day %>&bNo=<%=rs.getString(8) %>"><%=borrow %></a></td>
			</tr>
			<%
		}
	} catch(Exception e) {
		e.printStackTrace();
	}
	%>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
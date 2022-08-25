<%@page import="java.sql.ResultSet"%>
<%@page import="com.sun.net.httpserver.Authenticator.Result"%>
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
<h2 style="text-align: center;">전체 도서 리스트</h2>
<form style="align-items: center; display: flex; justify-content: center;" accept-charset="utf-8">
<table border="1" style="border-collapse: collapse; text-align: center;">
	<tr>
		<td>도서번호</td>
		<td>도서명</td>
		<td>장르</td>
		<td>가격</td>
		<td>남은 수량</td>
		<td>대출가능여부</td>
	</tr>		
	<%
	Connection con = null;
	PreparedStatement pstmt = null;
	try {
		con = Util.getConnection();
		String sql = "select bo.bookno, bo.bookname, bo.genre, bo.price, bo.amount, count(bor.re_book) from book_tbl bo left outer join (select * from borrow_tbl where re_book = '대여') bor on bo.bookno = bor.bookno group by bo.bookno, bo.bookname, bo.genre, bo.price, bo.amount order by bo.bookno";
		pstmt = con.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		while(rs.next()) {
			String borrow = rs.getInt(5) - rs.getInt(6) > 0 ? "대출하기" : "";
			%>
			<tr>
				<td><%=rs.getString(1) %></td>
				<td><%=rs.getString(2) %></td>
				<td><%=rs.getString(3) %></td>
				<td><%="₩" + String.format("%,d", rs.getInt(4)) %></td>
				<td><%=rs.getInt(5) - rs.getInt(6) + "권" %></td>
				<td><a href="borrow.jsp?bo=<%=rs.getString(1)%>&bn=<%=rs.getString(2) %>"><%=borrow %></a></td>
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
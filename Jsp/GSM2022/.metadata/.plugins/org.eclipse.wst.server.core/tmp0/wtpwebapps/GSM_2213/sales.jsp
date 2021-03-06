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
<section style="position: fixed; top: 70px; width: 100%; height: 100%;background-color: lightgray; left: 0px">
<h2 style="text-align: center;">카페 매출 조회 프로그램</h2>
<form style="justify-content: center; display: flex; align-items: center; text-align: center;">
<table border="1">
	<tr>
		<td>메뉴번호</td>
		<td>메뉴이름</td>
		<td>주문량</td>
		<td>합계</td>
	</tr>
<%
request.setCharacterEncoding("UTF-8");
Connection conn = null;
PreparedStatement pstmt = null;
try {
	conn = Util.getConnection();
	String sql = "select m.menuno, m.menuname, sum(o.amount), m.price from menu_tbl m, order_tbl o where m.menuno=o.menuno group by m.menuno, m.menuname, m.price order by m.menuno";
	pstmt = conn.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	while(rs.next()){
		String price = rs.getInt(3) * rs.getInt(4) + "원";
	%>
	<tr>
		<td><%=rs.getString(1) %></td>
		<td><%=rs.getString(2) %></td>
		<td><%=rs.getString(3) %></td>
		<td><%=price %></td>
	</tr>
	<%
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
	<tr>
		<td colspan="4">
			<input type="button" value="확인" onclick="check()">
		</td>
	</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
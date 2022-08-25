<%@page import="java.sql.ResultSet"%>
<%@page import="com.sun.net.httpserver.Authenticator.Result"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="DBPKG.Util"%>
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
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="width: 100%; height: 100%; margin-bottom: 25px; margin-top: 70px; position: fixed; right: 0px">
<h2 style="text-align: center;">도서 대여 프로그램</h2>
<%
request.setCharacterEncoding("UTF-8");
String bookNo = request.getParameter("bo");
String bookNa = request.getParameter("bn");
%>
<form style="display: flex; align-items: center; justify-content: center;" action="action.jsp" method="post" accept-charset="utf-8" name="frm">
<input type="hidden" name="mode" value="borrow">
<table border="1" style="border-collapse: collapse;">
<%
Connection con = null;
PreparedStatement pstmt = null;
try {
	con = Util.getConnection();
	String sql = "select max(bor_no)+1 from borrow_tbl";
	pstmt = con.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	%>
	<tr>
		<td>대여번호</td>
		<td><input name="id" readonly="readonly" value=<%=rs.getString(1) %>></td>
	</tr>
	<tr>
		<td>고객이름</td>
		<td>
		<select name="memberName" onchange="changeName()">
		<option>고객명
		<%
		sql = "select m_name, m_no from mem_tbl";
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
		<td>고객번호</td>
		<td><input readonly="readonly" name="mNo">예) 101</td>
	</tr>
	<tr>
		<td>직업</td>
		<td>
			<input type="radio" name="job" value="1"> 학생
			<input type="radio" name="job" value="2"> 교사
			<input type="radio" name="job" value="3"> 외부인
		</td>
	</tr>
	<tr>
		<td>도서명</td>
		<td>
		<select name="bookNo">
		<option value=<%=bookNo %>><%=bookNa %></option>
		<%
		sql = "select bookname, bookno from book_tbl where bookno != '" + bookNo + "'";
		pstmt = con.prepareStatement(sql);
		rs = pstmt.executeQuery();
		while(rs.next()) {
			%>
			<option value=<%=rs.getString(2) %>><%=rs.getString(1) %></option>
			<%
		}
		%>
		</select>
		</td>
	</tr>
	<tr>
		<td>대여날짜</td>
		<td><input name="day" placeholder="예) 20220303"></td>
	</tr>
	<tr>
		<td colspan="2" style="text-align: center;">
			<input type="button" onclick="check()" value="대출하기">
			<input type="button" onclick="reset()" value="다시하기">
		</td>
	</tr>
<%
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
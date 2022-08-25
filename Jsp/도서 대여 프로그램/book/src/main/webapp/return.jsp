<%@page import="java.text.SimpleDateFormat"%>
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
<section style="width: 100%; height: 100%; margin-bottom: 25px; margin-top: 70px; position: fixed; right: 0px">
<h2 style="text-align: center;">도서 반납</h2>
<%
request.setCharacterEncoding("UTF-8");
String id = request.getParameter("id");
String mNa = request.getParameter("mNa");
String mNo = request.getParameter("mNo");
String bNa = request.getParameter("bNa");
String day = request.getParameter("day");
String bNo = request.getParameter("bNo");
%>
<form style="display: flex; align-items: center; justify-content: center;" action="action.jsp" method="post" accept-charset="utf-8" name="frm">
<input type="hidden" name="mode" value="return">
<table border="1" style="border-collapse: collapse;">
<%
Connection con = null;
PreparedStatement pstmt = null;
try {
	con = Util.getConnection();
	String sql = "select job from mem_tbl where m_no = " + mNo;
	pstmt = con.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	String job = rs.getString(1);
%>
	<tr>
		<td>대여번호</td>
		<td><input name="id" readonly="readonly" value=<%=id %>></td>
	</tr>
	<tr>
		<td>고객이름</td>
		<td>
		<select name="memberName">
		<option value=<%=mNa %>><%=mNa %>
		</select>
		</td>
	</tr>
	<tr>
		<td>고객번호</td>
		<td><input readonly="readonly" name="mNo" value=<%=mNo %>>예) 101</td>
	</tr>
	<tr>
		<td>직업</td>
		<td>
			<input type="radio" name="job" value="1" <% if(job.equals("학생")) out.println("checked"); %>> 학생
			<input type="radio" name="job" value="2" <% if(job.equals("교사")) out.println("checked"); %>> 교사
			<input type="radio" name="job" value="3" <% if(job.equals("외부인")) out.println("checked"); %>> 외부인
		</td>
	</tr>
	<tr>
		<td>도서명</td>
		<td>
		<select name="bookNo">
		<option value=<%=bNo %>><%=bNa %></option>
		</select>
		</td>
	</tr>
	<tr>
		<td>대여날짜</td>
		<td><input name="day" value=<%=day %> readonly="readonly"></td>
	</tr>
	<tr>
		<td colspan="2" style="text-align: center;">
			<input type="button" onclick="return_book()" value="반납하기">
			<input type="button" onclick="back()" value="뒤로가기">
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
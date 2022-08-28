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
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>
<section style="width: 100%; position: fixed; height: 100%; margin-bottom: 40px; background-color: lightgray; margin-top: 120px; top: 0px; right: 0px">
<h2 style="text-align: center;">수강신청</h2>
<form style="display: flex; align-items: center; justify-content: center;" action="action.jsp" method="post" name="frm">
<table border="1" style="border-collapse: collapse;"> 
<%
Connection con = null;
PreparedStatement pstmt = null;
try {
	con = Util.getConnection();
%>
	<tr>
		<td>수강일</td>
		<td><input name="regist_month">2022년 3월 예)202203</td>
	</tr>
	<tr>
		<td>회원명</td>
		<td>
			<select name="c_name" onchange="select_cName()">
				<option value="">회원명
				<%
				String sql = "select c_name, c_no from tbl_member_202201";
				pstmt = con.prepareStatement(sql);
				ResultSet rs = pstmt.executeQuery();
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
		<td>회원번호</td>
		<td><input readonly="readonly" name="c_no">예)10001</td>
	</tr>
	<tr>
		<td>강의장소</td>
		<td>
			<select name="class_area">
				<option value="">강의장소
				<option value="서울본원">서울본원
				<option value="대전분원">대전분원
				<option value="부산분원">부산분원
				<option value="대구분원">대구분원
			</select>
		</td>
	</tr>
	<tr>
		<td>강의명</td>
		<td>
			<select name="class_name" onchange="select_class_name()">
				<option value="">강의명
				<%
				sql = "select class_name, class_price from tbl_teacher_202201";
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
		<td>수강료</td>
		<td><input readonly="readonly" name="class_price">원</td>
	</tr>
	<tr>
		<td colspan="2" style="text-align: center;">
			<input type="button" value="수강신청" onclick="join()">
			<input type="button" value="다시쓰기" onclick="re_write()">
		</td>
	</tr>
<%
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
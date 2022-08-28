<%@page import="java.sql.ResultSet"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
request.setCharacterEncoding("UTF-8");
String regist_month = request.getParameter("regist_month");
String c_no = request.getParameter("c_no");
String class_area = request.getParameter("class_area");
String class_price = request.getParameter("class_price");
Connection con = null;
PreparedStatement pstmt = null;
int price = Integer.parseInt(class_price);
try {
	if(Integer.parseInt(c_no) >= 20000) {
		price = Integer.parseInt(class_price) * 2;
	}
	con = Util.getConnection();
	String sql = "select teacher_code from tbl_teacher_202201 where class_price = " + price;
	pstmt = con.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	String teacher_code = rs.getString(1);
	
	sql = "insert into tbl_class_202201 values (?, ?, ?, ?, ?)";
	pstmt = con.prepareStatement(sql);
	pstmt.setString(1, regist_month);
	pstmt.setString(2, c_no);
	pstmt.setString(3, class_area);
	pstmt.setString(4, class_price);
	pstmt.setString(5, teacher_code);
	pstmt.executeUpdate();
	%>
	<jsp:include page="index.jsp"/>
	<%
} catch(Exception e) {
	e.printStackTrace();
}
%>
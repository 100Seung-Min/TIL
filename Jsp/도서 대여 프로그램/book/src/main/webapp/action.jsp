<%@page import="java.sql.ResultSet"%>
<%@page import="com.sun.net.httpserver.Authenticator.Result"%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
request.setCharacterEncoding("utf-8");
String mode = request.getParameter("mode");
String id = request.getParameter("id");
String mNo = request.getParameter("mNo");
String bNo = request.getParameter("bookNo");
String day = request.getParameter("day");
Connection con = null;
PreparedStatement pstmt = null;
try {
	con = Util.getConnection();
	String sql = "select bookname from book_tbl where bookno = " + bNo;
	pstmt = con.prepareStatement(sql);
	ResultSet rs = pstmt.executeQuery();
	rs.next();
	String bNa = rs.getString(1);
	sql = "select m_name from mem_tbl where m_no = " + mNo;
	pstmt = con.prepareStatement(sql);
	rs = pstmt.executeQuery();
	rs.next();
	String mName = rs.getString(1);
	switch(mode) {
	case "borrow" : 
		sql = "insert into borrow_tbl values (?, ?, ?, ?, ?, ?, ?)";
		pstmt = con.prepareStatement(sql);
		pstmt.setString(1, id);
		pstmt.setString(2, mNo);
		pstmt.setString(3, mName);
		pstmt.setString(4, bNo);
		pstmt.setString(5, bNa);
		pstmt.setString(6, day);
		pstmt.setString(7, "´ë¿©");
		pstmt.executeUpdate();
		%>
		<jsp:forward page="index.jsp"/>
		<%
		break;
	case "return" : 
		sql = "update borrow_tbl set re_book = \'¹Ý³³\'  where bor_no = " + id;
		pstmt = con.prepareStatement(sql);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="index.jsp"/>
		<%
		break;
	}
	%>
	<%
} catch(Exception e) {
	e.printStackTrace();
}
%>
<%@page import="DBPKG.Util"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
    
<%
request.setCharacterEncoding("utf-8");
String type = request.getParameter("type");
String jumin_num = request.getParameter("jumin_num");
String name = request.getParameter("name");
String vote_num = request.getParameter("vote_num");
String vote_time = request.getParameter("vote_time");
String vote_place = request.getParameter("vote_place");
String check_vote = request.getParameter("check_vote");

Connection conn = null;
PreparedStatement pstmt = null;
try {
	conn = Util.getConnection();
	switch(type) {
	case "vote" :
		String sql = "insert into TBL_VOTE_202005 values(?, ?, ?, ?, ?, ?)";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, jumin_num);
		pstmt.setString(2, name);
		pstmt.setString(3, vote_num);
		pstmt.setString(4, vote_time);
		pstmt.setString(5, vote_place);
		pstmt.setString(6, check_vote);
		pstmt.executeUpdate();
		%>
		<jsp:forward page="index.jsp"/>
		<%
	}
} catch (Exception e) {
	e.printStackTrace();
}
%>
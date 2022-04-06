<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR" trimDirectiveWhitespaces="true"%>
<html>
<head>
<title>Welcome</title>
<style type="text/css">
* {
padding: 0;
margin: 0
}
</style>
</head>
<body>

<%@ include file="menu.jsp" %>


<article style="background: #e0e0e0; width: 100%; height: 170px">
<h1 style="line-height: 170px; margin-left: 10px; font-size: 70px; text-align: center">웹 쇼핑몰에 오신 것을 환영합니다</h1>
</article>

<article style="width: 100%; height: 70px">
<h1 style="text-align: center; line-height: 70px; font-size: 30px">Welcome to Web Market!</h1>
</article>

<%! 
Date date = new Date();
String day = (date.getHours()>12 ? date.getHours()-12 : date.getHours()) + ":" + date.getMinutes() + ":" + date.getSeconds(); 
%>
<article style="width: 100%; height: 70px">
<p style="text-align: center; font-size: 17px">현재 접속 시간은 <%= day%> <% if(date.getHours() > 12) out.print(" PM"); else out.print(" AM"); %>
</article>


<%@ include file="footer2.jsp" %>
</body>
</html>
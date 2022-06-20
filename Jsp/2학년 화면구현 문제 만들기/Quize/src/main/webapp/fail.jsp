<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>fail join</title>
</head>
<body>
<%
request.setCharacterEncoding("UTF-8");
String error = request.getParameter("becuse");
switch(error) {
case "hours": error = "시간을 다시 확인해주세요"; break;
case "personnel": error = "인원수를 초과했습니다"; break;
case "day": error = "날짜를 다시 확인해주세요"; break;
}
%>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<p1><%=error %></p1>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
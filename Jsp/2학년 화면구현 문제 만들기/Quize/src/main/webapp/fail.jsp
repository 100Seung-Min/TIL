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
case "hours": error = "�ð��� �ٽ� Ȯ�����ּ���"; break;
case "personnel": error = "�ο����� �ʰ��߽��ϴ�"; break;
case "day": error = "��¥�� �ٽ� Ȯ�����ּ���"; break;
}
%>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<p1><%=error %></p1>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
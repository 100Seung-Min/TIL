<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<jsp:include page="header.jsp"/>
<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<form method="post" action="mylist.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;" accept-charset="utf-8">
<table>
<tr>
	<td>이름</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>비밀번호</td>
	<td><input type="text" name="password" style="width: 100%"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="submit" value="입력" style="width: 100%">
	</td>
</tr>
</table>
</form>
</section>
<jsp:include page="footer.jsp"/>
</body>
</html>
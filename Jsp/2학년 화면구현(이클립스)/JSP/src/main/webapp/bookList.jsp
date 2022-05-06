<%@page import="dto.Book"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<jsp:useBean id="bookDao" class="dao.BookRepository" scope="session"></jsp:useBean>
<html>
<head>
<title>도서목록</title>
<style type="text/css">
* {
padding: 0;
margin: 0
}
</style>
</head>
<body>
<%
ArrayList<Book> listOfProducts = bookDao.getAllBooks();
%>
<jsp:include page="menu.jsp"></jsp:include>

<article style="background: #e0e0e0; width: 100%; height: 170px">
<h1 style="line-height: 170px; margin-left: 10px; font-size: 70px">도서 목록</h1>
</article>

<article style="width: 100%; margin-top: 20px">
<%
for (int i = 0; i < listOfProducts.size(); i++){
	Book book = listOfProducts.get(i);
%>
<div style="width: 100%; margin-left: 5px; margin-right: 5px">
<h3><%= book.getName() %></h3>
<p style="margin-top: 20px"><%= book.getDescription() %></p>
<p style="margin-top: 20px"><%= book.getAuthor() %> | <%= book.getPublisher() %> | <%= book.getUnitPrice() %>원</p>
<hr style="margin-top: 10px; margin-bottom: 10px">
</div>
<%
}
%>
</article>
<jsp:include page="footer2.jsp"></jsp:include>
</body>
</html>
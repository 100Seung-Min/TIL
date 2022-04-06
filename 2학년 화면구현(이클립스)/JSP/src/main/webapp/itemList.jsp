<%@page import="dto.Product"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<jsp:useBean id="productDao" class="dao.ProductRepository" scope="session"></jsp:useBean>
<html>
<head>
<title>��ǰ���</title>
<style type="text/css">
* {
padding: 0;
margin: 0
}
</style>
</head>
<body>
<%
ArrayList<Product> listOfProducts = productDao.getAllProducts();
%>
<jsp:include page="menu.jsp"></jsp:include>

<article style="background: #e0e0e0; width: 100%; height: 170px">
<h1 style="line-height: 170px; margin-left: 10px; font-size: 70px">��ǰ���</h1>
</article>

<article style="display: flex; width: 100%; height: 100px; margin-top: 20px">
<%
for (int i = 0; i < listOfProducts.size(); i++){
	Product product = listOfProducts.get(i);
%>
<div style="width: 30%; text-align: center; margin-left: 5px; margin-right: 5px">
<h3><%= product.getPname() %></h3>
<p><%= product.getDescription() %></p>
<p style="margin-top: 20px"><%= product.getUnitPrice() %>��</p>
</div>
<%
}
%>
</article>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>
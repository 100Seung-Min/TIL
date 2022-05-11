<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="dto.Product" %>
<jsp:useBean id="productDAO" class="dao.ProductRepository" scope="session"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>상품 상세 정보</title>
<style type="text/css">
* {
padding: 0;
margin: 0
}
</style>
</head>
<body>
<jsp:include page="menu.jsp"></jsp:include>
<article style="background: #e0e0e0; width: 100%; height: 120px">
<h3 style="line-height: 120px; margin-left: 10px; font-size: 45px">상품목록</h3>
</article>
<%
	String id = request.getParameter("id");
	Product product = productDAO.getProductById(id);
%>
<article style="width: 100%; height: 200px; padding-left: 10px; padding-top: 15px">
<h3 style="font-size: 25px"><%=product.getPname() %></h3>
<p style="font-size: 12px"><%=product.getDescription() %>
<p style="margin-top: 5px"><b>상품 코드 : </b><span><%=product.getProductId() %></span>
<p style="margin-top: 5px"><b>제조사</b> : <%=product.getManufacturer() %>
<p style="margin-top: 5px"><b>분류</b> : <%=product.getCategory() %>
<p style="margin-top: 5px"><b>재고 수</b> : <%=product.getUnitsInStock() %>
<h4 style="margin-top: 5px"><%=product.getUnitPrice() %>원</h4>
<p style="margin-top: 5px"> <a href="#" style="background: orange;padding: 3px; text-decoration: none; font-size: 12px; color: white;">상품 주문 &raquo;</a>
<a href="./itemList.jsp" style="background: orange;padding: 3px; text-decoration: none; font-size: 12px; color: white;">상품 목록 &raquo;</a>
</article>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>
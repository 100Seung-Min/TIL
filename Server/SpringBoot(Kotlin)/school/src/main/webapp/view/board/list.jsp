<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>
<%@ page isELIgnored="false" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Bootstrap Example</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/css/bootstrap.min.css">
    <script src="https://cdn.jsdelivr.net/npm/jquery@3.6.3/dist/jquery.slim.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body>

<div class="card">
    <div class="card-header">
        <div class="jumbotron jumbotron-fluid">
            <div class="container">
                <h1>Spring Framework~</h1>
                <p>Spring Web MVC, MySQL, JS(jQuery,Ajax,JSON)...</p>
            </div>
        </div>
    </div>
    <div class="card-body">
        <div class="row">
            <div class="col-2">
                <jsp:include page="left.jsp"/>
            </div>
            <div class="col-7">
                <div class="card">
                    <div class="card-body">
                        <h4 class="card-title">BOARD</h4>
                        <p class="card-text">게시판 리스트</p>
                        <table class="table table-hover">
                            <thead>
                            <tr>
                                <th>번호</th>
                                <th>제목</th>
                                <th>작성자</th>
                                <th>작성일</th>
                                <th>조회수</th>
                            </tr>
                            </thead>
                            <tbody>
                            <c:forEach var="vo" items="${list}">
                                <tr>
                                    <td>${vo.num}</td>
                                    <td>${vo.title}</td>
                                    <td>${vo.writer}</td>
                                    <td>${vo.date}</td>
                                    <td>${vo.count}</td>
                                </tr>
                            </c:forEach>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
            <div class="col-3">
                <jsp:include page="right.jsp"/>
            </div>
        </div>
    </div>
    <div class="card-footer">
        광주소프트웨어마이스터고_3-2(백승민)
    </div>
</div>

</body>
</html>
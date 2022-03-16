<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Welcome</title>
</head>
<style>
    * {
        margin: 0;
        padding: 0;
    }
</style>
<body>
<%!
    String a = "Book Market Mall";
    String b = "Welcome to Web Market";
%>
    <header style="width: 100%; height: 40px; background: black">
        <p style="line-height:40px; color: white">Home</p>
    </header>

    <article style="background: #e0e0e0; width: 100%; height: 150px">
        <p style="line-height: 150px; font-size: 40px"><%= a%></p>
    </article>

    <article style="width: 100%; height: 60px">
        <p style="text-align: center; line-height: 60px"><%= b%></p>
    </article>

    <footer style="width: 100%; height: 20px">
        <p style="font-size: 15px">ⓒ BookMarket</p>
    </footer>
</body>
</html>

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
<%!
String name = "Book Market Mall";
String welcome = "Welcome to Web Market!";
%>
<header style="background: black;width: 100%; height: 50px">
<a><p style="color: white; line-height: 50px; margin-left: 10px">Home</p></a>
</header>

<article style="background: #e0e0e0; width: 100%; height: 170px">
<h1 style="line-height: 170px; margin-left: 10px; font-size: 60px"><%= name %></h1>
</article>

<article style="width: 100%; height: 70px">
<h1 style="text-align: center; line-height: 70px"><%= welcome %></h1>
</article>

<footer style="width: 100%; height: 20px">
<p style="margin-left: 10px; font-size: 15px">ⓒBookMarket</p>
</footer>
</body>
</html>
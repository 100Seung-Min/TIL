<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>insert</title>
</head>
<body>
<script type="text/javascript" src="check.js"></script>
<jsp:include page="header.jsp"/>

<section style="position: fixed; top: 70px; left: 0px; width: 100%; height: 100%; background-color: lightgray">
<h2 style="text-align: center;"><b>������ �߰�</b></h2>

<form method="post" action="action.jsp" name="frm" style="display: flex; align-items: center; justify-content: center;">
<table border="1" style="text-align: center;">
	<tr>
		<td>�����ڵ�</td>
		<td><input type="text" name="id" style="width: 100%"></td>
	</tr>
<tr>
	<td>�����</td>
	<td><input type="text" name="name" style="width: 100%"></td>
</tr>
<tr>
	<td>����</td>
	<td><input type="text" name="credit" style="width: 100%"></td>
</tr>
<tr>
	<td>��簭��</td>
	<td>
	<select name="lecturer" style="width: 100%">
		<option value="">��簭�缱��</option>
		<option value="1">�豳��</option>
		<option value="2">�̱���</option>
		<option value="3">�ڱ���</option>
		<option value="4">�챳��</option>
		<option value="5">�ֱ���</option>
		<option value="6">�ӱ���</option>
	</select>
</tr>
<tr>
	<td>����</td>
	<td>
	<input type="radio" name="week" value="1">��
	<input type="radio" name="week" value="2">ȭ
	<input type="radio" name="week" value="3">��
	<input type="radio" name="week" value="4">��
	<input type="radio" name="week" value="5">��
	</td>
</tr>
<tr>
	<td>���۽ð�</td>
	<td><input type="text" name="start_hour" style="width: 100%"></td>
</tr>
<tr>
	<td>����ð�</td>
	<td><input type="text" name="end_hout" style="width: 100%"></td>
</tr>
<tr>
	<td colspan="2">
	<input type="button" value="�߰�" onclick="addCheck()"> &nbsp; &nbsp;
	<input type="button" value="���" onclick="search()">
	</td>
</tr>
</table>
</form>
</section>

<jsp:include page="footer.jsp"/>
</body>
</html>
<%@ page import="book.bean.BookInfo" pageEncoding="GBK"%>
<html>
<head>
<title>�޸�ͼ����Ϣ</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
		BookInfo bi = (BookInfo) request.getAttribute("bi");
	%>
	<form action="update.do" method="post">
		<input type="hidden" name="id" value="<%=bi.getId()%>">
		<table style="width: 50%">
			<caption>�޸�ͼ����Ϣ</caption>
			<tr>
				<th width="30%">������</th>
				<td width="70%"><input name="bookname" type="text"
					value="<%=bi.getBookname()%>"></td>
			</tr>
			<tr>
				<th>���ߣ�</th>
				<td><input name="author" type="text"
					value="<%=bi.getAuthor()%>"></td>
			</tr>
			<tr>
				<th>�۸�</th>
				<td><input name="price" type="text" value="<%=bi.getPrice()%>">Ԫ</td>
			</tr>
			<tr>
				<th colspan="2"><input type="submit" value="�޸�"> <input
					type="reset" value="����"></th>
			</tr>
		</table>
	</form>
</body>
</html>


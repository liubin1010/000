<%@ page import="book.bean.BookInfo" pageEncoding="GBK"%>
<html>
<head>
<title>修改图书信息</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
		BookInfo bi = (BookInfo) request.getAttribute("bi");
	%>
	<form action="update.do" method="post">
		<input type="hidden" name="id" value="<%=bi.getId()%>">
		<table style="width: 50%">
			<caption>修改图书信息</caption>
			<tr>
				<th width="30%">书名：</th>
				<td width="70%"><input name="bookname" type="text"
					value="<%=bi.getBookname()%>"></td>
			</tr>
			<tr>
				<th>作者：</th>
				<td><input name="author" type="text"
					value="<%=bi.getAuthor()%>"></td>
			</tr>
			<tr>
				<th>价格：</th>
				<td><input name="price" type="text" value="<%=bi.getPrice()%>">元</td>
			</tr>
			<tr>
				<th colspan="2"><input type="submit" value="修改"> <input
					type="reset" value="重置"></th>
			</tr>
		</table>
	</form>
</body>
</html>


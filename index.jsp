<%@ page pageEncoding="GBK"
	import="java.util.ArrayList,book.bean.BookInfo"%>
<html>
<head>
<title>图书管理系统</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<h1>图书管理系统</h1>
	<a href="add.html">增加图书信息</a>
	<p />
	<table style="width: 50%">
		<tr>
			<th>书名</th>
			<th>作者</th>
			<th>价格</th>
			<th>管理</th>
		</tr>
		<%
			@SuppressWarnings("unchecked")
			//ArrayList<BookInfo> list = BookInfo.getBookList();
			ArrayList<BookInfo> list = (ArrayList<BookInfo>) request.getAttribute("list");
			for (BookInfo bi : list) {
				String id = bi.getId();
		%>
		<tr>
			<td><%=bi.getBookname()%></td>
			<td><%=bi.getAuthor()%></td>
			<td><%=bi.getPrice()%></td>
			<td><a href="edit.do?id=<%=id%>">修改</a> <a
				href="delete.do?id=<%=id%>">删除</a></td>
		</tr>
		<%
			}
		%>
	</table>
	<br />
	<hr />
	<div style="text-align: center; width: 100%; font-size: 12px; color: #333;">
		&copy;版权所有：石家庄铁道大学信息科学与技术学院&nbsp;&nbsp;<a href="Lab04-1.png"
			target="_blank">网站地图</a>
	</div>
</body>
</html>

<%@ page pageEncoding="GBK"
	import="java.util.ArrayList,book.bean.BookInfo"%>
<html>
<head>
<title>ͼ�����ϵͳ</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<h1>ͼ�����ϵͳ</h1>
	<a href="add.html">����ͼ����Ϣ</a>
	<p />
	<table style="width: 50%">
		<tr>
			<th>����</th>
			<th>����</th>
			<th>�۸�</th>
			<th>����</th>
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
			<td><a href="edit.do?id=<%=id%>">�޸�</a> <a
				href="delete.do?id=<%=id%>">ɾ��</a></td>
		</tr>
		<%
			}
		%>
	</table>
	<br />
	<hr />
	<div style="text-align: center; width: 100%; font-size: 12px; color: #333;">
		&copy;��Ȩ���У�ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ&nbsp;&nbsp;<a href="Lab04-1.png"
			target="_blank">��վ��ͼ</a>
	</div>
</body>
</html>

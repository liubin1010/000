package servlets;

import java.io.IOException;
import java.util.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.*;

import book.bean.BookInfo;

/**
 * 截取所有后缀为.action的操作
 */
@WebServlet("*.action")
public class AjaxController extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public AjaxController() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		
		String actionUrl = request.getServletPath(); // 获取用户请求的路径
		System.out.println(actionUrl);
		if (actionUrl.equals("/list.action")) { // 访问主页请求
			ArrayList<BookInfo> list = BookInfo.getBookList(); // 调用BookInfo获取全部图书赋给list变量
			//以下代码将list图书转换成json字符串发送给客户端
			JSONArray jsonArray = new JSONArray();
			for (int i = 0; i < list.size(); i++) {
				BookInfo book = list.get(i);
				Map<String, Object> map = new HashMap<String, Object>();
				map.put("id",  book.getId());
				map.put("bookname", book.getBookname());
				map.put("author", book.getAuthor());
				map.put("price", book.getPrice());
				JSONObject BookObj = new JSONObject(map);
				jsonArray.put(BookObj);
			}
			response.getWriter().print(jsonArray.toString());
			
		} else if (actionUrl.equals("/add.action")) { // 增加图书请求
			String name = request.getParameter("bookname");
			String author = request.getParameter("author");
			String price = request.getParameter("price");
			System.out.println(name);
			int r = BookInfo.addBook(name, author, price); // 调用BookInfo增加图书
			response.getWriter().print(r);

		} else if (actionUrl.equals("/edit.action")) { // 编辑图书请求
			String id = request.getParameter("id");
			BookInfo bi = BookInfo.getBookById(id); // 调用BookInfor查询指定图书Id的信息，赋给bi变量
			//以下代码将bi转换成为json字符串发送给客户端
			Map<String, Object> map = new HashMap<String, Object>();
			map.put("id",  bi.getId());
			map.put("bookname", bi.getBookname());
			map.put("author", bi.getAuthor());
			map.put("price", bi.getPrice());
			JSONObject BookObj = new JSONObject(map);
			response.getWriter().print(BookObj.toString());
			
		} else if (actionUrl.equals("/update.action")) { // 更新图书请求
			String id = request.getParameter("id");
			String name = request.getParameter("bookname");
			String author = request.getParameter("author");
			String price = request.getParameter("price");
			int r = BookInfo.updateBook(id, name, author, price);// 调用BookInfo进行更新操作
			response.getWriter().print(r);

		} else if (actionUrl.equals("/delete.action")) { // 删除图书请求
			String id = request.getParameter("id");
			int r = BookInfo.deleteBook(id); // 调用BookInfo进行删除操作
			response.getWriter().print(r);
		}
	}

}

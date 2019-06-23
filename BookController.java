package servlets;

import java.io.IOException;
import java.util.ArrayList;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import book.bean.BookInfo;

@WebServlet("*.do")
public class BookController extends HttpServlet {

	/**
	 * 截获所有的后缀为.do请求，并转到相应的处理程序
	 */
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request,response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("GBK");
		String actionUrl=request.getServletPath();		//获取用户请求的路径

		if(actionUrl.equals("/index.do")){			//访问主页请求
			ArrayList<BookInfo> list=BookInfo.getBookList();  //调用BookInfo获取图书列表赋给list变量
			request.setAttribute("list", list);					//request中增加list属性，其值为list变量的值
			request.getRequestDispatcher("/index.jsp").forward(request, response);//转发给index.jsp文件
		
		}else if(actionUrl.equals("/add.do")){			//增加图书请求
			String name=request.getParameter("bookname");
			String author=request.getParameter("author");
			String price=request.getParameter("price");
			int r = BookInfo.addBook(name, author, price);	//调用BookInfor增加图书
			if(r==1)
				request.getRequestDispatcher("success.html").forward(request, response);
			else
				request.getRequestDispatcher("failure.html").forward(request, response);
		
		}else if(actionUrl.equals("/edit.do")){			//编辑图书请求			
			String id=request.getParameter("id");
			BookInfo bi=BookInfo.getBookById(id);		//调用BookInfor查询指定图书Id的信息，赋给bi变量
			request.setAttribute("bi", bi);				//request中增加bi属性，其值为bi变量的值
			request.getRequestDispatcher("/edit.jsp").forward(request, response);
		
		}else if(actionUrl.equals("/update.do")){	    //更新图书请求
			String id=request.getParameter("id");
			String name=request.getParameter("bookname");
			String author=request.getParameter("author");
			String price=request.getParameter("price");
			int r=BookInfo.updateBook(id,name, author, price);//调用BookInfo进行更新操作
			if(r==1)
				request.getRequestDispatcher("/success.html").forward(request, response);
			else
				request.getRequestDispatcher("/failure.html").forward(request, response);
		
		}else if(actionUrl.equals("/delete.do")){			//删除图书请求
			String id=request.getParameter("id");
			int r=BookInfo.deleteBook(id);			//调用BookInfo进行删除操作
			if(r==1)
				request.getRequestDispatcher("/success.html").forward(request, response);
			else
				request.getRequestDispatcher("/failure.html").forward(request, response);
		}
	}

}

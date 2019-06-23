package book.bean;

import java.sql.*;
import java.util.*;
/**
 * 本类构建Book模型，其属性与数据库Student表相同
 * */
public class BookInfo {
	
	private String id;
	private String bookname;
	private String author;
	private String price;
	public String getBookname() {
		return bookname;
	}
	public void setBookname(String bookname) {
		this.bookname = bookname;
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getPrice() {
		return price;
	}
	public void setPrice(String price) {
		this.price = price;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getId() {
		return id;
	}
	/**
	 * 返回所有的Book对象列表
	 * */
	public static ArrayList<BookInfo> getBookList(){
		ArrayList<BookInfo> list=new ArrayList<BookInfo>();
		String sql="select * from bookinfo";
		DBBean jdbc=new DBBean();
		ResultSet rs=jdbc.executeQuery(sql);
        try {
			while(rs.next()){
				BookInfo bi=new BookInfo();
				bi.setId(rs.getString("id"));
				bi.setBookname(rs.getString("bookname"));
				bi.setAuthor(rs.getString("author"));
				bi.setPrice(rs.getString("price"));
				list.add(bi);
			}
			 rs.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
        jdbc.close();
        return list;
	}
	/**
	 * 返回指定id的Book对象
	 * */
	public static BookInfo getBookById(String id){
		String sql="select * from bookinfo where id="+id;
		DBBean jdbc=new DBBean();
		ResultSet rs=jdbc.executeQuery(sql);
		BookInfo bi=new BookInfo();
        try {
			if(rs.next()){
				bi.setId(rs.getString("id"));
				bi.setBookname(rs.getString("bookname"));
				bi.setAuthor(rs.getString("author"));
				bi.setPrice(rs.getString("price"));
			}
			 rs.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
        jdbc.close();
        return bi;
	}
	/**
	 * 修改指定参数的book
	 * */
	public static int updateBook(String id,String bookname,String author,String price){
		int result=0;
		String sql="update bookinfo set bookname='"+bookname+"',author='"+author+"',price="+price+" where id="+id;
		DBBean jdbc=new DBBean();
		result=jdbc.executeUpdate(sql);
		jdbc.close();
		return result;
	}
	
	/**
	 * 删除指定id的book
	 * */
	public static int deleteBook(String id){
		int result=0;
		String sql="delete from bookinfo where id="+id;
		DBBean jdbc=new DBBean();
		result=jdbc.executeUpdate(sql);
		jdbc.close();
		return result;
	}
	/**
	 * 新增一条book记录
	 * */
	public static int addBook(String bookname,String author,String price){
		int result=0;
		String sql="insert into bookinfo values(null,'"+bookname+"','"+author+"',"+price+")";
		DBBean jdbc=new DBBean();
		result=jdbc.executeUpdate(sql);
		jdbc.close();
		return result;
	}
}

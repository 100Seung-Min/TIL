package DBPKG;

import java.sql.*;

public class Utill {
	public static Connection getConnection() throws Exception{
		Class.forName("oracle.jdbc.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/XE", "dong", "youtube");
		return con;
	}
}

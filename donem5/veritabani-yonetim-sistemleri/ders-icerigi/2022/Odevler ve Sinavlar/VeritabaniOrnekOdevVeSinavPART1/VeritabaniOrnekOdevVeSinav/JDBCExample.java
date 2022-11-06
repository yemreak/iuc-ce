import java.sql.*;

public class JDBCExample {
 
	public static void main(String[] argv) {
 
		try {
			Class.forName("org.postgresql.Driver");
		} catch (ClassNotFoundException e) {
			System.out.println("Where is your PostgreSQL JDBC Driver? "	+ "Include in your library path!");
			e.printStackTrace();
			return;
		}
		//System.out.println("PostgreSQL JDBC Driver Registered!");
		Connection connection = null;
		try {
			connection = DriverManager.getConnection("jdbc:postgresql://127.0.0.1:5432/crime", "atakan", "kurt");
		} catch (SQLException e) {
			System.out.println("Connection Failed! Check output console");
			e.printStackTrace();
			return;
		}
		if (connection != null)
			System.out.println("You made it, take control your database now!");
		else
			System.out.println("Failed to make connection!");
		try {
			Statement st = connection.createStatement();
			ResultSet rs = st.executeQuery("SELECT * FROM crime");
			while (rs.next()){
			   System.out.println(rs.getString(1));
			} 
			rs.close();
			st.close(); 
		} catch (SQLException e) {
			System.out.println("Error occurred");
			e.printStackTrace();
			return;
		}		
	}
 
}
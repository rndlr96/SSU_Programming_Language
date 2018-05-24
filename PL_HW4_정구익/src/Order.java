
public class Order {
	private String day;
	private String name;
	private String menu;
	
	Order(String day, String name, String menu)
	{
		this.day = day;
		this.name = name;
		this.menu = menu;
	}
	
	public String getday() {
		return this.day;
	}
	
	public String getname() {
		return this.name;
	}
	
	public String getmenu() {
		return this.menu;
	}
}


public class Customer {
	private int ID;
	private String join_day;
	private String name;
	private String phone_num;
	private String birth;
	private int order_count;
	
	public Customer(int ID, String join_day, String name, String phone_num, String birth)
	{
		this.ID = ID;
		this.join_day = join_day;
		this.name = name;
		this.phone_num = phone_num;
		this.birth = birth;
		
		order_count = 0;
	}
	
	public int getID()
	{
		return ID;
	}
	
	public String getday()
	{
		return join_day;
	}
	
	public String getname()
	{
		return name;
	}
	
	public String getphone()
	{
		return phone_num;
	}
	
	public String getbirth()
	{
		return birth;
	}
	
	public int getcount()
	{
		return order_count;
	}
	
	public void order_cound_up()
	{
		order_count++;
	}
	
	public void order_count_init()
	{
		order_count = 0;
	}

}

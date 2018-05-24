import java.util.Vector;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CustomerManager {
	Scanner scan = new Scanner(System.in);
	Vector<Customer> Customers = new Vector<Customer>();
	
	public void addMember(int ID, String join_day, String name, String phone_num, String birth)
	{
		Customer customer = new Customer(ID, join_day, name, phone_num, birth);
		Customers.add(customer);
	}
	
	public void removeMember(int ID)
	{
		Customer customer = Find(ID);
		if(customer == null)
		{
			// 예외처러
		}
		Customers.remove(customer);
	}
	
	public void menuorder(int ID, String menu, String orderday)
	{
		Customer customer = Find(ID);
		File file = new File("custom.txt");
		FileWriter writer = null;
		String message = "정구익"+" : "+menu+"("+orderday+")";
		
		try
		{
			writer = new FileWriter(file, true);
			writer.write(message);
			writer.flush();
		} catch(IOException e) {
			e.printStackTrace();
		} finally {
            try {
                if(writer != null) writer.close();
            } catch(IOException e) {
                e.printStackTrace();
            }
		}
		
		if(customer == null)
		{
			// 예외처리
		}
		if(customer.getcount() == 3)
		{
			// 쿠폰 발송 이벤트 발생
			
			customer.order_count_init();
		}
		else
			customer.order_cound_up();
	}
	
	public Customer Find(int ID) 
	{
		int cnt = Customers.size();
		for(Customer customer : Customers)
		{
			if(customer.getID() == ID)
			{
				return customer;
			}
		}
		return null;
	}
	
}

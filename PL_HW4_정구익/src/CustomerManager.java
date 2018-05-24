import java.util.Vector;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class CustomerManager {
	Scanner scan = new Scanner(System.in);
	Vector<Customer> Customers = new Vector<Customer>();
	
	public void AddMember(int ID, String join_day, String name, String phone_num, String birth)
	{
		Customer customer = new Customer(ID, join_day, name, phone_num, birth);
		Customers.add(customer);
	}
	
	public void RemoveMember(int ID)
	{
		Customer customer = Find(ID);
		if(customer == null)
		{
			// ����ó��
		}
		Customers.remove(customer);
	}
	
	public void MenuOrder(int ID, String menu, String orderday)
	{
		Customer customer = Find(ID);
		File file = new File("custom.txt");
		FileWriter writer = null;
		String message = "������"+" : "+menu+"("+orderday+")";
		
		try
		{
			writer = new FileWriter(file, true);
			writer.write(message+"\n");
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
			// ����ó��
		}
		if(customer.getcount() == 3)
		{
			// ���� �߼� �̺�Ʈ �߻�
			
			customer.order_count_init();
		}
		else
			customer.order_cound_up();
	}
	
	public void OrderCancle(int ID, String menu, String orderday)
	{
		Customer customer = Find(ID);
		File file = new File("custom.txt");
		FileWriter writer = null;
		FileReader reader = null;
		BufferedReader breader = null;
		BufferedWriter bwriter = null;
		String read = null;
		String message = "������"+" : "+menu+"("+orderday+")";
		
		try
		{
			reader = new FileReader(file);
			writer = new FileWriter(file, false);
			breader = new BufferedReader(reader);
			bwriter = new BufferedWriter(writer);
			while((read=breader.readLine())!=null)
			{
				if(!read.equals(message)) // ��ġ���� ���� �ֹ��̸� �ٽ� �ؽ�Ʈ ���Ͽ� �Է�
				{
					bwriter.write(read);
					bwriter.newLine();
				}
			}
		}  catch (FileNotFoundException e) {
			e.printStackTrace();
		}  catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(breader != null)
				try {
					breader.close();
				} catch (IOException e) {}
		}
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

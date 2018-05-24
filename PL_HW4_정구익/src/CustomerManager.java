import java.util.Vector;

import javax.swing.JOptionPane;

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
	Vector<Order> Orders = new Vector<Order>();
	
	public void AddMember(int ID, String join_day, String name, String phone_num, String birth)
	{
		Customer customer = new Customer(ID, join_day, name, phone_num, birth);
		if(Find(ID) == null)
			Customers.add(customer);
		else
			JOptionPane.showMessageDialog(null, "����ȣ�� �ߺ��˴ϴ�..", "�ߺ� ����", JOptionPane.ERROR_MESSAGE);

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
		if(customer == null)
		{
			JOptionPane.showMessageDialog(null, "ȸ�� ������ �����ϴ�.\n ��ϵ� ȸ���� �ƴմϴ�.", "ȸ�� ���� ����", JOptionPane.ERROR_MESSAGE);
		}
		else
		{
			File file = new File("custom.txt");
			FileWriter writer = null;
			BufferedWriter bwriter = null;
			Order order = new Order(orderday, customer.getname(), menu);
			Orders.add(order);
			String message = customer.getname()+" : "+menu+"("+orderday+")";

			try
			{
				writer = new FileWriter(file, true);
				bwriter = new BufferedWriter(writer);
				bwriter.write(message);
				bwriter.newLine();
				bwriter.flush();
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				try {
					if (writer != null)
						writer.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		
			if (customer.getcount() == 2) {
				// ���� �߼� �̺�Ʈ �߻�
				JOptionPane.showMessageDialog(null, ID + "�� ����\n���������� ��۵Ǿ����ϴ�.", "���� ����", JOptionPane.PLAIN_MESSAGE);

				customer.order_count_init();
			} 
			else
				customer.order_cound_up();
		}
	}
	
	public void OrderCancle(int ID, String menu, String orderday)
	{
		Customer customer = Find(ID);
		Order order = OrderFind(orderday, customer.getname(), menu);
		System.out.println(order.getname());
		if(order != null)
		{
			Orders.remove(order);
			
			File file = new File("custom.txt");
			FileWriter writer = null;
			BufferedWriter bwriter = null;
			
			try
			{
				writer = new FileWriter(file, false);
				bwriter = new BufferedWriter(writer);
			
				for(Order temp_order : Orders)			
				{			
					String message = temp_order.getname()+" : "+temp_order.getmenu()+" ("+temp_order.getday()+") ";			
					System.out.println(message);
					bwriter.write(message);	
					bwriter.newLine();
					bwriter.flush();
				}
			}  catch (FileNotFoundException e) {
				e.printStackTrace();
			}  catch (IOException e) {
				e.printStackTrace();
			} 
		}
		else
			JOptionPane.showMessageDialog(null, "�ֹ� ������ �����ϴ�.", "�ֹ� ���� ����", JOptionPane.ERROR_MESSAGE);

	}

	
	
	public Customer Find(int ID) 
	{
		for(Customer customer : Customers)
		{
			if(customer.getID() == ID)
			{
				return customer;
			}
		}
		return null;
	}
	
	public Order OrderFind(String day, String name, String menu)
	{
		for(Order order : Orders)
		{
			if( order.getname().equals(name) && order.getmenu() == menu && order.getday().equals(day))
			{
				return order;
			}
		}
		return null;
	}
	
}

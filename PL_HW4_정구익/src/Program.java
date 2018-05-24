import javax.swing.*;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Program extends JFrame{
	
	private CustomerManager manager = new CustomerManager();
	
	public Program() 
	{
		  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		  TabPanel();
		  setTitle("�������ý���");
		  setSize(500, 350);
		    
		  setVisible(true);
	}

	
	void TabPanel()
	{
		String menu[] = {"���", "���", "������", "���", "����", "Ƣ��"};
		
		JTabbedPane tPane = new JTabbedPane();
		add(tPane);
		  
		JLabel first_Label1 = new JLabel(" ��     ¥");
		first_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label2 = new JLabel(" ����ȣ");
		first_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label3 = new JLabel(" ��     ��");
		first_Label3.setPreferredSize(new Dimension(100, 40));
		JButton first_Button1 = new JButton("�ֹ�");
		JButton first_Button2 = new JButton("�ֹ����");		
		JTextArea first_txt1 = new JTextArea(2, 30);
		JTextArea first_txt2 = new JTextArea(2, 30);
		JComboBox first_combo = new JComboBox<String>(menu);
		first_combo.setPreferredSize(new Dimension(330, 35));
		
		JPanel mainPanel = new JPanel();
		  
		mainPanel.add(first_Label1);
		mainPanel.add(first_txt1);
		mainPanel.add(first_Label2);
		mainPanel.add(first_txt2);
		mainPanel.add(first_Label3);
		mainPanel.add(first_combo);
		mainPanel.add(first_Button1);
		mainPanel.add(first_Button2);
		tPane.addTab("�ֹ���ȸ", mainPanel);
		
		
		ActionListener order = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				
				if(first_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "��¥�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "����ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				
				else
				{
					char charinput;
					boolean first_isValid = true;
						
//============================ ��¥ ���� ó�� ==========================================================================================
					for (int i = 0; i < first_txt1.getText().length(); i++) {
						charinput = first_txt1.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "���ڿ� '/'�� �Է��� �� �ֽ��ϴ�..", "���� ���� ����",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ �� ��ȣ ���� ó�� ==========================================================================================
				
					for (int i = 0; i < first_txt2.getText().length(); i++) {

						charinput = first_txt2.getText().charAt(i);

						if ( // Ư������ ����ó��
						(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
								|| (charinput >= '��' && charinput <= '�R') || (charinput >= '��' && charinput <= '��')
								|| (charinput >= '��' && charinput <= '��') || (charinput >= '0' && charinput <= '9')) {
						}

						else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "Ư�� ���ڴ� ����� �� �����ϴ�.", "Ư�� ���� ����",
									JOptionPane.ERROR_MESSAGE);
						}

					}		
//==============================================================================================================================
				
					if(first_isValid) { // ��� ���� ó���� ��ġ�� ������ ���ٸ� ��� ����
						manager.MenuOrder(
								Integer.parseInt(first_txt2.getText()), 
								first_combo.getItemAt(first_combo.getSelectedIndex()).toString(),
								first_txt1.getText()
								);
					}
				}
			}
		};
		first_Button1.addActionListener(order);
		
		ActionListener order_cencle = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(first_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "��¥�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "����ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				
				else
				{
				manager.OrderCancle(
						Integer.parseInt(first_txt2.getText()), 
						first_combo.getItemAt(first_combo.getSelectedIndex()).toString(),
						first_txt1.getText()
						);
				}
			}
		};
		first_Button2.addActionListener(order_cencle);
		  
		JLabel second_Label1 = new JLabel(" ����ȣ");
		second_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label2 = new JLabel(" �� �� ��");
		second_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label3 = new JLabel(" ��ȭ��ȣ");
		second_Label3.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label4 = new JLabel(" �� �� ��");
		second_Label4.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label5 = new JLabel(" ��     ��");
		second_Label5.setPreferredSize(new Dimension(100, 40));
		JButton second_Button1 = new JButton("�����");
		JButton second_Button2 = new JButton("���˻�");	
		JButton second_Button3 = new JButton("������");		
		JTextArea second_txt1 = new JTextArea(2, 30);
		JTextArea second_txt2 = new JTextArea(2, 30);
		JTextArea second_txt3 = new JTextArea(2, 30);
		JTextArea second_txt4 = new JTextArea(2, 30);
		JTextArea second_txt5 = new JTextArea(2, 30);

		JPanel mainPane2 = new JPanel();
		
		mainPane2.add(second_Label1);
		mainPane2.add(second_txt1);
		mainPane2.add(second_Label2);
		mainPane2.add(second_txt2);
		mainPane2.add(second_Label3);
		mainPane2.add(second_txt3);
		mainPane2.add(second_Label4);
		mainPane2.add(second_txt4);
		mainPane2.add(second_Label5);
		mainPane2.add(second_txt5);
		mainPane2.add(second_Button1);
		mainPane2.add(second_Button2);
		mainPane2.add(second_Button3);
		tPane.addTab("������", mainPane2);	
		
//============================= �� ��� ��ư ������ =====================================================================================

		ActionListener join = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "����ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(second_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "���� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(second_txt3.getText().equals(""))
					JOptionPane.showMessageDialog(null, "��ȭ��ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(second_txt4.getText().equals(""))
					JOptionPane.showMessageDialog(null, "�������� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				if(second_txt5.getText().equals(""))
					JOptionPane.showMessageDialog(null, "������ �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);

				else 
				{

					char charinput;
					boolean second_isValid = true;

//============================ �̸� ���� ó�� ==========================================================================================
				
					if (second_txt2.getText().length() > 10) { // �̸� 10�� �̳� ���� ó��
						JOptionPane.showMessageDialog(null, "�̸��� 10�� �̳��� �����մϴ�.", "�̸� �Է� ����",
								JOptionPane.ERROR_MESSAGE);
					} else {
						for (int i = 0; i < second_txt2.getText().length(); i++) {
							charinput = second_txt2.getText().charAt(i);
							if ( // Ư������ ����ó��
							(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
									|| (charinput >= '��' && charinput <= '�R') || (charinput >= '��' && charinput <= '��')
									|| (charinput >= '��' && charinput <= '��')) {
							} else {
								second_isValid = false;
								JOptionPane.showMessageDialog(null, "Ư�� ���ڴ� ����� �� �����ϴ�.", "Ư�� ���� ����",
										JOptionPane.ERROR_MESSAGE);
							}
						}
					}
					
//==============================================================================================================================
					
				
//============================ ��ȭ ��ȣ ���� ó�� ==========================================================================================
				
					for (int i = 0; i < second_txt3.getText().length(); i++) {
						charinput = second_txt3.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '-')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "���ڿ� '-'�� �Է��� �� �ֽ��ϴ�..", "���� ���� ����",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================
					
//============================ ���� ���� ó�� ==========================================================================================
					for (int i = 0; i < second_txt5.getText().length(); i++) {
						charinput = second_txt5.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "���ڿ� '/'�� �Է��� �� �ֽ��ϴ�..", "���� ���� ����",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ �̸� ���� ó�� ==========================================================================================
				
					for (int i = 0; i < second_txt2.getText().length(); i++) {
					
						charinput = second_txt2.getText().charAt(i);
					
						if ( // Ư������ ����ó��
							(charinput >= 0x61 && charinput <= 0x7A) || 
						(charinput >= 0x41 && charinput <= 0x5A) || 
						(charinput >= '��' && charinput <= '�R') || 
						(charinput >= '��' && charinput <= '��') || 
						(charinput >= '��' && charinput <= '��') ||
						(charinput >= '0' && charinput <= '9')) 
						{} 
					
						else 
						{
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "Ư�� ���ڴ� ����� �� �����ϴ�.", "Ư�� ���� ����", JOptionPane.ERROR_MESSAGE);
						}
					
					}		
//==============================================================================================================================
				
					if(second_isValid) { // ��� ���� ó���� ��ġ�� ������ ���ٸ� ��� ����
						manager.AddMember(				
								Integer.parseInt(second_txt1.getText()), 			
								second_txt4.getText(), 			
								second_txt2.getText(), 			
								second_txt3.getText(), 			
								second_txt5.getText()			
								);	
					}
				}
			}
		};
		second_Button1.addActionListener(join);

//==============================================================================================================================

		
//============================= �� �˻� ��ư ������ =====================================================================================

		ActionListener search = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "����ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null) {
						second_txt2.setText(customer.getname());
						second_txt3.setText(customer.getphone());
						second_txt4.setText(customer.getday());
						second_txt5.setText(customer.getbirth());
					} else
						JOptionPane.showMessageDialog(null, "�� ������ ã�� �� �����ϴ�.", "�� �˻� ����", JOptionPane.ERROR_MESSAGE);

				}
			}
		};
		second_Button2.addActionListener(search);

//==============================================================================================================================
		
		
//============================= �� ���� ��ư ������ =====================================================================================
		
		ActionListener remove = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "����ȣ�� �Է����ּ���.", "���� ����", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null)
						manager.RemoveMember(customer.getID());
					else
						JOptionPane.showMessageDialog(null, "�� ������ ã�� �� �����ϴ�..", "�� �˻� ����",JOptionPane.ERROR_MESSAGE);
				}
			}
		};
		second_Button3.addActionListener(remove);
	}

//==============================================================================================================================

	
	public static void main(String[] args){
		new Program();
	} 
	
}

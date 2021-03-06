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
		  setTitle("고객관리시스템");
		  setSize(500, 350);
		    
		  setVisible(true);
	}

	
	void TabPanel()
	{
		String menu[] = {"김밥", "라면", "떡볶이", "돈까스", "오뎅", "튀김"};
		
		JTabbedPane tPane = new JTabbedPane();
		add(tPane);
		  
		JLabel first_Label1 = new JLabel(" 날     짜");
		first_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label2 = new JLabel(" 고객번호");
		first_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label3 = new JLabel(" 메     뉴");
		first_Label3.setPreferredSize(new Dimension(100, 40));
		JButton first_Button1 = new JButton("주문");
		JButton first_Button2 = new JButton("주문취소");		
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
		tPane.addTab("주문조회", mainPanel);
		
		
		ActionListener order = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				
				if(first_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "날짜를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				
				else
				{
					char charinput;
					boolean first_isValid = true;
						
//============================ 날짜 예외 처리 ==========================================================================================
					for (int i = 0; i < first_txt1.getText().length(); i++) {
						charinput = first_txt1.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "숫자와 '/'만 입력할 수 있습니다..", "예외 형식 오류",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ 고객 번호 예외 처리 ==========================================================================================
				
					for (int i = 0; i < first_txt2.getText().length(); i++) {

						charinput = first_txt2.getText().charAt(i);

						if ( // 특수문자 예외처리
						(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
								|| (charinput >= '가' && charinput <= '힣') || (charinput >= 'ㄱ' && charinput <= 'ㅎ')
								|| (charinput >= 'ㅏ' && charinput <= 'ㅢ') || (charinput >= '0' && charinput <= '9')) {
						}

						else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "특수 문자는 사용할 수 없습니다.", "특수 문자 오류",
									JOptionPane.ERROR_MESSAGE);
						}

					}		
//==============================================================================================================================
				
					if(first_isValid) { // 모든 예외 처리를 거치고 문제가 없다면 등록 실행
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
					JOptionPane.showMessageDialog(null, "날짜를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				
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
		  
		JLabel second_Label1 = new JLabel(" 고객번호");
		second_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label2 = new JLabel(" 고 객 명");
		second_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label3 = new JLabel(" 전화번호");
		second_Label3.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label4 = new JLabel(" 가 입 일");
		second_Label4.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label5 = new JLabel(" 생     일");
		second_Label5.setPreferredSize(new Dimension(100, 40));
		JButton second_Button1 = new JButton("고객등록");
		JButton second_Button2 = new JButton("고객검색");	
		JButton second_Button3 = new JButton("고객삭제");		
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
		tPane.addTab("고객관리", mainPane2);	
		
//============================= 고객 등록 버튼 리스너 =====================================================================================

		ActionListener join = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(second_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객명를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(second_txt3.getText().equals(""))
					JOptionPane.showMessageDialog(null, "전화번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(second_txt4.getText().equals(""))
					JOptionPane.showMessageDialog(null, "가입일을 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				if(second_txt5.getText().equals(""))
					JOptionPane.showMessageDialog(null, "생일을 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);

				else 
				{

					char charinput;
					boolean second_isValid = true;

//============================ 이름 예외 처리 ==========================================================================================
				
					if (second_txt2.getText().length() > 10) { // 이름 10자 이내 예외 처리
						JOptionPane.showMessageDialog(null, "이름은 10자 이내만 가능합니다.", "이름 입력 오류",
								JOptionPane.ERROR_MESSAGE);
					} else {
						for (int i = 0; i < second_txt2.getText().length(); i++) {
							charinput = second_txt2.getText().charAt(i);
							if ( // 특수문자 예외처리
							(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
									|| (charinput >= '가' && charinput <= '힣') || (charinput >= 'ㄱ' && charinput <= 'ㅎ')
									|| (charinput >= 'ㅏ' && charinput <= 'ㅢ')) {
							} else {
								second_isValid = false;
								JOptionPane.showMessageDialog(null, "특수 문자는 사용할 수 없습니다.", "특수 문자 오류",
										JOptionPane.ERROR_MESSAGE);
							}
						}
					}
					
//==============================================================================================================================
					
				
//============================ 전화 번호 예외 처리 ==========================================================================================
				
					for (int i = 0; i < second_txt3.getText().length(); i++) {
						charinput = second_txt3.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '-')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "숫자와 '-'만 입력할 수 있습니다..", "예외 형식 오류",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================
					
//============================ 생일 예외 처리 ==========================================================================================
					for (int i = 0; i < second_txt5.getText().length(); i++) {
						charinput = second_txt5.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "숫자와 '/'만 입력할 수 있습니다..", "예외 형식 오류",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ 이름 예외 처리 ==========================================================================================
				
					for (int i = 0; i < second_txt2.getText().length(); i++) {
					
						charinput = second_txt2.getText().charAt(i);
					
						if ( // 특수문자 예외처리
							(charinput >= 0x61 && charinput <= 0x7A) || 
						(charinput >= 0x41 && charinput <= 0x5A) || 
						(charinput >= '가' && charinput <= '힣') || 
						(charinput >= 'ㄱ' && charinput <= 'ㅎ') || 
						(charinput >= 'ㅏ' && charinput <= 'ㅢ') ||
						(charinput >= '0' && charinput <= '9')) 
						{} 
					
						else 
						{
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "특수 문자는 사용할 수 없습니다.", "특수 문자 오류", JOptionPane.ERROR_MESSAGE);
						}
					
					}		
//==============================================================================================================================
				
					if(second_isValid) { // 모든 예외 처리를 거치고 문제가 없다면 등록 실행
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

		
//============================= 고객 검색 버튼 리스너 =====================================================================================

		ActionListener search = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null) {
						second_txt2.setText(customer.getname());
						second_txt3.setText(customer.getphone());
						second_txt4.setText(customer.getday());
						second_txt5.setText(customer.getbirth());
					} else
						JOptionPane.showMessageDialog(null, "고객 정보를 찾을 수 없습니다.", "고객 검색 오류", JOptionPane.ERROR_MESSAGE);

				}
			}
		};
		second_Button2.addActionListener(search);

//==============================================================================================================================
		
		
//============================= 고객 삭제 버튼 리스너 =====================================================================================
		
		ActionListener remove = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "고객번호를 입력해주세요.", "공백 오류", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null)
						manager.RemoveMember(customer.getID());
					else
						JOptionPane.showMessageDialog(null, "고객 정보를 찾을 수 없습니다..", "고객 검색 오류",JOptionPane.ERROR_MESSAGE);
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

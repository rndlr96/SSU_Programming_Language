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
		  setTitle("°í°´°ü¸®½Ã½ºÅÛ");
		  setSize(500, 350);
		    
		  setVisible(true);
	}

	
	void TabPanel()
	{
		String menu[] = {"±è¹ä", "¶ó¸é", "¶±ººÀÌ", "µ·±î½º", "¿Àµ­", "Æ¢±è"};
		
		JTabbedPane tPane = new JTabbedPane();
		add(tPane);
		  
		JLabel first_Label1 = new JLabel(" ³¯     Â¥");
		first_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label2 = new JLabel(" °í°´¹øÈ£");
		first_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel first_Label3 = new JLabel(" ¸Þ     ´º");
		first_Label3.setPreferredSize(new Dimension(100, 40));
		JButton first_Button1 = new JButton("ÁÖ¹®");
		JButton first_Button2 = new JButton("ÁÖ¹®Ãë¼Ò");		
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
		tPane.addTab("ÁÖ¹®Á¶È¸", mainPanel);
		
		
		ActionListener order = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				
				if(first_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "³¯Â¥¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				
				else
				{
					char charinput;
					boolean first_isValid = true;
						
//============================ ³¯Â¥ ¿¹¿Ü Ã³¸® ==========================================================================================
					for (int i = 0; i < first_txt1.getText().length(); i++) {
						charinput = first_txt1.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "¼ýÀÚ¿Í '/'¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù..", "¿¹¿Ü Çü½Ä ¿À·ù",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ °í°´ ¹øÈ£ ¿¹¿Ü Ã³¸® ==========================================================================================
				
					for (int i = 0; i < first_txt2.getText().length(); i++) {

						charinput = first_txt2.getText().charAt(i);

						if ( // Æ¯¼ö¹®ÀÚ ¿¹¿ÜÃ³¸®
						(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
								|| (charinput >= '°¡' && charinput <= 'ÆR') || (charinput >= '¤¡' && charinput <= '¤¾')
								|| (charinput >= '¤¿' && charinput <= '¤Ò') || (charinput >= '0' && charinput <= '9')) {
						}

						else {
							first_isValid = false;
							JOptionPane.showMessageDialog(null, "Æ¯¼ö ¹®ÀÚ´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.", "Æ¯¼ö ¹®ÀÚ ¿À·ù",
									JOptionPane.ERROR_MESSAGE);
						}

					}		
//==============================================================================================================================
				
					if(first_isValid) { // ¸ðµç ¿¹¿Ü Ã³¸®¸¦ °ÅÄ¡°í ¹®Á¦°¡ ¾ø´Ù¸é µî·Ï ½ÇÇà
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
					JOptionPane.showMessageDialog(null, "³¯Â¥¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(first_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				
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
		  
		JLabel second_Label1 = new JLabel(" °í°´¹øÈ£");
		second_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label2 = new JLabel(" °í °´ ¸í");
		second_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label3 = new JLabel(" ÀüÈ­¹øÈ£");
		second_Label3.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label4 = new JLabel(" °¡ ÀÔ ÀÏ");
		second_Label4.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label5 = new JLabel(" »ý     ÀÏ");
		second_Label5.setPreferredSize(new Dimension(100, 40));
		JButton second_Button1 = new JButton("°í°´µî·Ï");
		JButton second_Button2 = new JButton("°í°´°Ë»ö");	
		JButton second_Button3 = new JButton("°í°´»èÁ¦");		
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
		tPane.addTab("°í°´°ü¸®", mainPane2);	
		
//============================= °í°´ µî·Ï ¹öÆ° ¸®½º³Ê =====================================================================================

		ActionListener join = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(second_txt2.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¸í¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(second_txt3.getText().equals(""))
					JOptionPane.showMessageDialog(null, "ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(second_txt4.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°¡ÀÔÀÏÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				if(second_txt5.getText().equals(""))
					JOptionPane.showMessageDialog(null, "»ýÀÏÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);

				else 
				{

					char charinput;
					boolean second_isValid = true;

//============================ ÀÌ¸§ ¿¹¿Ü Ã³¸® ==========================================================================================
				
					if (second_txt2.getText().length() > 10) { // ÀÌ¸§ 10ÀÚ ÀÌ³» ¿¹¿Ü Ã³¸®
						JOptionPane.showMessageDialog(null, "ÀÌ¸§Àº 10ÀÚ ÀÌ³»¸¸ °¡´ÉÇÕ´Ï´Ù.", "ÀÌ¸§ ÀÔ·Â ¿À·ù",
								JOptionPane.ERROR_MESSAGE);
					} else {
						for (int i = 0; i < second_txt2.getText().length(); i++) {
							charinput = second_txt2.getText().charAt(i);
							if ( // Æ¯¼ö¹®ÀÚ ¿¹¿ÜÃ³¸®
							(charinput >= 0x61 && charinput <= 0x7A) || (charinput >= 0x41 && charinput <= 0x5A)
									|| (charinput >= '°¡' && charinput <= 'ÆR') || (charinput >= '¤¡' && charinput <= '¤¾')
									|| (charinput >= '¤¿' && charinput <= '¤Ò')) {
							} else {
								second_isValid = false;
								JOptionPane.showMessageDialog(null, "Æ¯¼ö ¹®ÀÚ´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.", "Æ¯¼ö ¹®ÀÚ ¿À·ù",
										JOptionPane.ERROR_MESSAGE);
							}
						}
					}
					
//==============================================================================================================================
					
				
//============================ ÀüÈ­ ¹øÈ£ ¿¹¿Ü Ã³¸® ==========================================================================================
				
					for (int i = 0; i < second_txt3.getText().length(); i++) {
						charinput = second_txt3.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '-')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "¼ýÀÚ¿Í '-'¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù..", "¿¹¿Ü Çü½Ä ¿À·ù",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================
					
//============================ »ýÀÏ ¿¹¿Ü Ã³¸® ==========================================================================================
					for (int i = 0; i < second_txt5.getText().length(); i++) {
						charinput = second_txt5.getText().charAt(i);
						if ((charinput >= '0' && charinput <= '9') || (charinput == '/')) {
						} else {
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "¼ýÀÚ¿Í '/'¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù..", "¿¹¿Ü Çü½Ä ¿À·ù",
									JOptionPane.ERROR_MESSAGE);
						}
					}
//==============================================================================================================================

//============================ ÀÌ¸§ ¿¹¿Ü Ã³¸® ==========================================================================================
				
					for (int i = 0; i < second_txt2.getText().length(); i++) {
					
						charinput = second_txt2.getText().charAt(i);
					
						if ( // Æ¯¼ö¹®ÀÚ ¿¹¿ÜÃ³¸®
							(charinput >= 0x61 && charinput <= 0x7A) || 
						(charinput >= 0x41 && charinput <= 0x5A) || 
						(charinput >= '°¡' && charinput <= 'ÆR') || 
						(charinput >= '¤¡' && charinput <= '¤¾') || 
						(charinput >= '¤¿' && charinput <= '¤Ò') ||
						(charinput >= '0' && charinput <= '9')) 
						{} 
					
						else 
						{
							second_isValid = false;
							JOptionPane.showMessageDialog(null, "Æ¯¼ö ¹®ÀÚ´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.", "Æ¯¼ö ¹®ÀÚ ¿À·ù", JOptionPane.ERROR_MESSAGE);
						}
					
					}		
//==============================================================================================================================
				
					if(second_isValid) { // ¸ðµç ¿¹¿Ü Ã³¸®¸¦ °ÅÄ¡°í ¹®Á¦°¡ ¾ø´Ù¸é µî·Ï ½ÇÇà
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

		
//============================= °í°´ °Ë»ö ¹öÆ° ¸®½º³Ê =====================================================================================

		ActionListener search = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null) {
						second_txt2.setText(customer.getname());
						second_txt3.setText(customer.getphone());
						second_txt4.setText(customer.getday());
						second_txt5.setText(customer.getbirth());
					} else
						JOptionPane.showMessageDialog(null, "°í°´ Á¤º¸¸¦ Ã£À» ¼ö ¾ø½À´Ï´Ù.", "°í°´ °Ë»ö ¿À·ù", JOptionPane.ERROR_MESSAGE);

				}
			}
		};
		second_Button2.addActionListener(search);

//==============================================================================================================================
		
		
//============================= °í°´ »èÁ¦ ¹öÆ° ¸®½º³Ê =====================================================================================
		
		ActionListener remove = new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				if(second_txt1.getText().equals(""))
					JOptionPane.showMessageDialog(null, "°í°´¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.", "°ø¹é ¿À·ù", JOptionPane.ERROR_MESSAGE);
				else
				{
					Customer customer = manager.Find(Integer.parseInt(second_txt1.getText()));
					if (customer != null)
						manager.RemoveMember(customer.getID());
					else
						JOptionPane.showMessageDialog(null, "°í°´ Á¤º¸¸¦ Ã£À» ¼ö ¾ø½À´Ï´Ù..", "°í°´ °Ë»ö ¿À·ù",JOptionPane.ERROR_MESSAGE);
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

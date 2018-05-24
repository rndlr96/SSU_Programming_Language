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
		  setSize(500, 300);
		    
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
				manager.menuorder(
						Integer.parseInt(first_txt2.getText()), 
						first_combo.getItemAt(first_combo.getSelectedIndex()).toString(),
						first_txt1.getText()
						);
			}
		};
		first_Button1.addActionListener(order);
		
		
		  
		JLabel second_Label1 = new JLabel(" °í°´¹øÈ£");
		second_Label1.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label2 = new JLabel(" °í °´ ¸í");
		second_Label2.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label3 = new JLabel(" ÀüÈ­¹øÈ£");
		second_Label3.setPreferredSize(new Dimension(100, 40));
		JLabel second_Label4 = new JLabel(" °¡ ÀÔ ÀÏ");
		second_Label4.setPreferredSize(new Dimension(100, 40));
		JButton second_Button1 = new JButton("°í°´µî·Ï");
		JButton second_Button2 = new JButton("°í°´°Ë»ö");	
		JButton second_Button3 = new JButton("°í°´»èÁ¦");		
		JTextArea second_txt1 = new JTextArea(2, 30);
		JTextArea second_txt2 = new JTextArea(2, 30);
		JTextArea second_txt3 = new JTextArea(2, 30);
		JTextArea second_txt4 = new JTextArea(2, 30);

		JPanel mainPane2 = new JPanel();
		
		mainPane2.add(second_Label1);
		mainPane2.add(second_txt1);
		mainPane2.add(second_Label2);
		mainPane2.add(second_txt2);
		mainPane2.add(second_Label3);
		mainPane2.add(second_txt3);
		mainPane2.add(second_Label4);
		mainPane2.add(second_txt4);
		mainPane2.add(second_Button1);
		mainPane2.add(second_Button2);
		mainPane2.add(second_Button3);
		tPane.addTab("°í°´°ü¸®", mainPane2);	
		
	}

	
	public static void main(String[] args){
		new Program();
	} 
	
}

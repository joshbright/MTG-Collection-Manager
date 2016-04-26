import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JSplitPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import java.awt.BorderLayout;
import javax.swing.JToolBar;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JSeparator;
import javax.swing.JPanel;
import javax.swing.border.TitledBorder;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JList;
import java.awt.SystemColor;
import javax.swing.JComboBox;
import javax.swing.JTextArea;
import java.awt.Font;

/**
*@authors Daniel LaBorde and Laila Dinn
*MTG COLLECTION MANAGER GUI
*/

public class Frame {

	private JFrame frmMtgCollectionManager;
	private JTextField txtSearch;
	private JTable table;
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Frame window = new Frame();
					window.frmMtgCollectionManager.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Frame() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmMtgCollectionManager = new JFrame();
		frmMtgCollectionManager.getContentPane().setBackground(SystemColor.windowBorder);
		frmMtgCollectionManager.setTitle("MTG Collection Manager");
		frmMtgCollectionManager.setBounds(100, 100, 1053, 672);
		frmMtgCollectionManager.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmMtgCollectionManager.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setForeground(SystemColor.inactiveCaption);
		panel.setBackground(SystemColor.scrollbar);
		panel.setBorder(new TitledBorder(null, "JPanel title", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		panel.setBounds(185, -16, 23, 628);
		frmMtgCollectionManager.getContentPane().add(panel);
		panel.setLayout(null);
		
		//Search List
		String[] cardTypeList = {"Name", "Cost", "Attack", "Health"};
		JComboBox comboBox = new JComboBox(cardTypeList);
		comboBox.setBackground(SystemColor.activeCaptionBorder);
		comboBox.setBounds(32, 42, 108, 20);
		frmMtgCollectionManager.getContentPane().add(comboBox);
		
		//TEXTBOX
		txtSearch = new JTextField();
		txtSearch.setText("Search");
		
		
		txtSearch.setBackground(SystemColor.activeCaptionBorder);
		txtSearch.setBounds(25, 138, 134, 34);
		frmMtgCollectionManager.getContentPane().add(txtSearch);
		txtSearch.setColumns(10);
		
		
		JLabel lblSearchBy = new JLabel("Search By:");
		lblSearchBy.setBounds(58, 23, 64, 20);
		frmMtgCollectionManager.getContentPane().add(lblSearchBy);
		
		JButton btnNewButton = new JButton("Search");
		btnNewButton.setBounds(35, 183, 117, 29);
		frmMtgCollectionManager.getContentPane().add(btnNewButton);
		
		 //OUTPUT Collection
		String[] columnColNames = {"Column1",
                "Column2",
                "Column3",
                "Column4"};
                //needs to be changed to different data type to actually get cards
		String[][] dataCol = {
			    {"Name", "Cost",
			     "Attack", "Health"},
			    {"", "",
			     "",""},
			    {"", "",
			     "",""},
			    {"", "",
			     "",""},
			    {"", "",
				 "",""},
			    {"", "",
			    "",""},
			    {"", "",
				"",""},
			    {"", "",
			    "",""},
			};
		table = new JTable(dataCol, columnColNames);
		table.setBounds(641, 42, 384, 573);
		frmMtgCollectionManager.getContentPane().add(table);
		
		//OUTPUT Deck
		String[] columnDeckNames = {"Column1",
                "Column2",
                "Column3",
                "Column4"};
                //needs to be changed
		String[][] dataDeck = {
			    {"Name", "Cost",
			     "Attack", "Health"},
			    {"", "",
			     "",""},
			    {"", "",
			     "",""},
			    {"", "",
			     "",""},
			    {"", "",
				 "",""},
			    {"", "",
			    "",""},
			    {"", "",
				"",""},
			    {"", "",
			    "",""},
			};
		
		table = new JTable(dataDeck, columnDeckNames);
		table.setBounds(218, 42, 380, 570);
		frmMtgCollectionManager.getContentPane().add(table);
		
		JPanel panel_1 = new JPanel();
		panel_1.setLayout(null);
		panel_1.setForeground(SystemColor.inactiveCaption);
		panel_1.setBorder(new TitledBorder(null, "JPanel title", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		panel_1.setBackground(SystemColor.scrollbar);
		panel_1.setBounds(608, -16, 23, 628);
		frmMtgCollectionManager.getContentPane().add(panel_1);
		
		JLabel lblDeckView = new JLabel("Deck View:");
		lblDeckView.setFont(new Font("Tahoma", Font.BOLD, 15));
		lblDeckView.setBounds(782, 11, 108, 20);
		frmMtgCollectionManager.getContentPane().add(lblDeckView);
		
		JLabel lblCollection = new JLabel("Collection:");
		lblCollection.setFont(new Font("Tahoma", Font.BOLD, 15));
		lblCollection.setBounds(352, 11, 108, 20);
		frmMtgCollectionManager.getContentPane().add(lblCollection);
		
		//MENU
		JMenuBar menuBar = new JMenuBar();
		menuBar.setForeground(SystemColor.windowBorder);
		menuBar.setBackground(SystemColor.windowBorder);
		frmMtgCollectionManager.setJMenuBar(menuBar);
		
		//OPEN Button
		JMenu mnOpen = new JMenu("Open");
		mnOpen.setFont(new Font("Segoe UI", Font.BOLD, 13));
		mnOpen.setBackground(Color.LIGHT_GRAY);
		menuBar.add(mnOpen);
		
		JMenuItem mntmNewDeck = new JMenuItem("New Deck");
		mnOpen.add(mntmNewDeck);
		
		
	}
}



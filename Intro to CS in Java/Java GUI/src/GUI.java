// Nils Fenske
// 4/23/14 
// JFrame Assignment #6
// Bill Iverson CS211 11:20
//
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

public class GUI implements ActionListener {
    
    JFrame frame = new JFrame();
    String[] buttons = {"New", "Save", "Open", "Quit"};				//labels for the top 4 buttons
   
    JTextArea textArea = new JTextArea(15, 25);						//Makes a text box with large enough scope
    Font f = new Font("Times New Roman", Font.PLAIN, 12);			//Sets the default settings for the text
    
    String[] fb = {"Foreground", "Background"};						//Labels for bottom 2 buttons
    
    JTextField sizeInput  = new JTextField(5);						//Makes a text field for the user to input font size
    
    int canSave;
    int canOpen;
    
    public static void main(String[] args) {
		new GUI();
	}
    
    public GUI() {
    	frame.setLayout(new BorderLayout());
    	
    	JPanel b = new JPanel();						//Makes a panel to hold the buttons
        b.setLayout(new GridLayout(0, 4));
        for (int i=0; i<4; i++) {						//Constructs the 4 buttons
        	JButton button = new JButton(buttons[i]);
        	button.addActionListener(this);
        	b.add(button);   	
		}      	
        
        JPanel text = new JPanel(new GridLayout());		//Makes a panel to hold the text box
    	text.add(textArea);
    	textArea.setLineWrap(true);
    	textArea.setFont(f);
    	
    	JScrollPane scroll = new JScrollPane(textArea); //Makes a new scroll bar
    	text.add(scroll);
    	
    	JPanel colors = new JPanel();					//Makes a panel for the bottom 2 buttons
    	for (int i=0; i<2; i++) {						//Constructs the 2 bottom buttons
        	JButton edit = new JButton(fb[i]);
        	edit.addActionListener(this);
        	colors.add(edit);         	
		}
    	
    	JPanel font = new JPanel();						//Makes a new panel for the text size editing
    	font.add(new JLabel("Font size:"));
    	font.add(sizeInput);
    	sizeInput.addActionListener(this);
    	
    	JPanel editors = new JPanel(new BorderLayout());	//Makes a new panel to hold the size editing panel
    	editors.add(colors, BorderLayout.NORTH);			//and the panel for the bottom 2 buttons
    	editors.add(font, BorderLayout.SOUTH);

        frame.add(b, BorderLayout.NORTH);
        frame.add(text, BorderLayout.CENTER);
        frame.add(editors, BorderLayout.SOUTH);
        frame.pack();
        frame.setVisible(true);
        frame.setTitle("Microstuff JavaPad XP");
    }
    
    public void actionPerformed(ActionEvent event) {
    	
        String command = event.getActionCommand();
        
        if (command.equals(buttons[0])) {					//When the "New" button is pressed
        	textArea.setText("");							
        	textArea.setBackground(Color.WHITE);
        	textArea.setForeground(Color.BLACK);
    	} 	
        else if (command.equals(buttons[1])) {				//When the "Save" button is pressed
        	JFileChooser save = new JFileChooser();
        	canSave = save.showSaveDialog(null);

        	if(canSave == JFileChooser.APPROVE_OPTION) {
        		try {
        			BufferedWriter out = new BufferedWriter(new FileWriter(save.getSelectedFile().getPath()));
        			out.write(textArea.getText());
        			out.close();
        		}
        		catch (Exception e){
        			JOptionPane.showMessageDialog(frame, "Could not Save");
        		}
        	}
    	}
        else if (command.equals(buttons[2])) {				//When the "Open" button is pressed
        	JFileChooser open = new JFileChooser();
        	canOpen = open.showOpenDialog(null);
        	
        	if (canOpen == JFileChooser.APPROVE_OPTION) {
        		textArea.setText("");
        		
        		try {
        			Scanner fileText = new Scanner(new FileReader(open.getSelectedFile().getPath()));
        			while (fileText.hasNext()) 
        				textArea.append(fileText.nextLine());
        				fileText.close();
        		}
        		catch (Exception e) {
        			JOptionPane.showMessageDialog(frame, "Could not Open");
        		}
        	}
        }
        else if (command.equals(buttons[3])) {				//When the "Quit" button is pressed
             System.exit(0);           
        } 
        else if (command.equals(fb[0])) {					//When the foreground button is pressed
        	Color colorF = JColorChooser.showDialog(textArea, "Choose text color", textArea.getForeground());
        	textArea.setForeground(colorF);
    	}
        else if (command.equals(fb[1])) {					//When the Background button is pressed
        	Color colorB = JColorChooser.showDialog(textArea, "Choose background color", textArea.getBackground());
        	textArea.setBackground(colorB);
    	}
        else if (command.equals(sizeInput.getText())) {		//When the user enters a font size and hits "Enter"
            Font f = new Font("Times New Roman", Font.PLAIN, Integer.parseInt(sizeInput.getText()));
        	textArea.setFont(f);
        }
    }
}
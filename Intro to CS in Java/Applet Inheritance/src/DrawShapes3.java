//Nils Fenske
//CS211 Bill Iverson
//Java Applet Assign.

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawShapes3 extends JApplet implements MouseListener, MouseMotionListener {
    
	public int recX = 25;		//Stores coordinates of rectangle to be printed.
	public int recY = 50;		
	public int mX; 				//Tracks the position of the mouse within the applet.
	public int mY;
	public int offsetX;			//Keeps track of the distance from the click and the rec coordinates.
	public int offsetY;
	boolean position; 			//True if the mouse coordinates are within the rectangle coordinates.
	
	public void init() {		//Initialization of the interfaces needed.
		setSize(400, 200);
		addMouseListener(this);
		addMouseMotionListener(this);
 }
	
	public void paint(Graphics g) {		//Paints the initial rectangle when applet starts.
        g.fillRect(25, 50, 20, 20);		
    }

	public void mouseClicked(MouseEvent arg0) {}	//These methods are required for the 
	public void mouseEntered(MouseEvent arg0) {}	//interfaces but are not utilized.
	public void mouseExited(MouseEvent arg0) {}
	public void mousePressed(MouseEvent arg0) {}
	public void mouseReleased(MouseEvent arg0) {}
	
	public void mouseDragged(MouseEvent drag) {		
		Graphics g = this.getGraphics();
		
		if ( position ){									//When the boolean is true, the mouse is 
			g.setColor( Color.WHITE );						//clicked and dragged. The new coordinates
			g.fillRect( recX - 15, recY - 15, 50, 50 );		//of the drag are stored and a white rec is 
			g.setColor( Color.BLACK );						//printed, covering the old black one and a 
			recX = drag.getX() - offsetX;								//new black one is printed centered on the mouse.
			recY = drag.getY() - offsetY;		
			g.fillRect( recX, recY, 20, 20 );
		}
	}
	
	public void mouseMoved( MouseEvent e ){
		mX = e.getX();								//Stores the coordinates of the mouse on
		mY = e.getY();								//the screen.
		offsetX = mX - recX;
		offsetY = mY - recY;
		
		position= ( mX > recX && 			//Tests if the position of the mouse is within 
					mX < recX + 20 &&		//the coordinates of the black rectangle.
					mY > recY && 
					mY < recY + 20 );		 
			
	}
}
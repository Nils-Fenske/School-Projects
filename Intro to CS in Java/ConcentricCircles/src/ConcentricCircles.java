// Nils Fenske
// Programming Assignment 4
// 2/13/14
//
// This program will draw four groups of objects on a drawing panel

import java.awt.*;

public class ConcentricCircles {
    
    public static void main( String[] args ) {
        DrawingPanel panel = new DrawingPanel( 400, 400 );			
        panel.setBackground( Color.CYAN );
        Graphics g = panel.getGraphics();
        
       drawSquaredCircle( g, 0, 0, 100, 100, 5 ); 			// int x = x pos
       group( g, 10, 120, 24, 24, 4, 5 );					// int y = y pos
       group( g, 150, 20, 40, 40, 5, 6 );					// int h = height
       group( g, 130, 275, 36, 36, 3, 3 );					// int w = width
    }												      	// int c = # of circles
    														// int r = # of rows/cols
    
    public static void group( Graphics g, int x, int y, int h, int w, int c, int r ) { 
    	for ( int i = 0; i < r; i++ ) {														
    		for ( int j = 0; j < r; j++ ){					// Draws groups in different locations
    			drawSquaredCircle( g, x, y, h, w, c );		// and of different parameters such
    			x = x + w;									// as number of circles, rows/cols and 
    		}												// size of SquaredCircle						
    		x = x - ( w * ( r ) );
    		y = y + h;
    	}
    	
    }
    
    public static void drawSquaredCircle( Graphics g, int x, int y, int h, int w, int c ) {
    	
    	g.setColor( Color.GREEN );								// Draws a number of circles inside a 
    	g.fillRect( x, y, w, h );	// green square in back		// square of different size 
    	
    	g.setColor( Color.YELLOW );
    	g.fillOval( x, y, w, h );	// yellow circle behind rings 
    	
    	g.setColor( Color.BLACK );
    	g.drawRect( x, y, w, h );						// black border line around square
    	for ( int i = 0; i <= c - 1; i++ ) {
    		g.drawOval( x + ( ( w / 2 ) / c * i ), 		// black rings of different quantity
    					y + ( ( h / 2 ) / c * i ), 
    					w - ( w / c * i ), 
    					h - ( h / c * i ) );
    	}
    	g.drawLine( x + w / 2, 							// vertical black line
    				y, 
    				x + w / 2, 
    				y + h );
    	g.drawLine( x, 									// horizontal black line
    				y + h / 2, 
    				x + w, 
    				y + h / 2 );
    }
}
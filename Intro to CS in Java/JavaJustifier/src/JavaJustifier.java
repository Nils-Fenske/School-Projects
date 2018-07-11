import java.util.*; // Scanner
import java.io.*; // File
/**
 * File: JavaJustifier
 *
 * Author: Your name goes here
 * 
 * Version: Winter 2014 - CS 210
 *
 * This program reads a file and formats it
 * according to Java standards for indenting.
 *
 */
public class JavaJustifier {					// Could you take a quick look at this if you have a chance? 
    public static void main( String[] args ) 	// I am getting stuck and  I need to go to work :(
               throws FileNotFoundException {
    
        final int TAB_SIZE = 4; // sets the level of indent
        
        // call justifyJava with Test1.java, Test2.java, etc.
        for( int i = 1; i < 6; i++ ) {
            justifyJava( "Test" + i + ".java", 
                         "Justified" + i + ".java", 
                         TAB_SIZE );
        }                
    }
    public static void justifyJava( String inputFileName,
                                    String outputFileName,
                                    int tabSize ) throws FileNotFoundException {
        // Your code goes here.
    	Scanner input = new Scanner( new File( inputFileName ) );
    	    	
    	inputFileName.trim();
    	
    	String tab = "";
    		
    		for ( int i = 0; i < tabSize; i++ ){
    		
    			tab += " ";
    		}
    		
    	
    	String str = input.nextLine();
    	
    	String editLine = input.nextLine( );
    	
    	PrintStream output = new PrintStream( new File( outputFileName ) );
    	
    	while ( input.hasNextLine( ) ){
    		
    		int count = 1;
    		
    		if ( str.contains( "{" ) ){  			
    			
    			output.print( tab + editLine );		// add a tab before the next line
    			
    			while ( !str.contains( "}" )
    				 || !str.contains( "{" ) ){
    				
    				for ( int i = 0; i < count; i++ ){
    					
    					output.print( tab + editLine ); // keep adding tabs until a } appears
    				}
    				
    				count++;
    			}
    		}
    		
    		else if ( str.contains( "}" ) ){				// i am stuck here where I need to decrease the number
    			 
    			for ( int i = 0; i < count -1; i++ ){
    				 
    				output.print( tab + editLine );	
    			 }
    			
    			count--;
    		}
    	}
    }
    
}
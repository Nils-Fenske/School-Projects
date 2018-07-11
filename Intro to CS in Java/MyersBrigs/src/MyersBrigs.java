import java.io.*; 
import java.util.*;

/*********************************************/
// Nils Fenske
// CS 210 Programming Assignment 7
// 3/6/2014
//
// This program will determine the Myers Brigs personality of a character after analyzing 
// the either A or B responses to a set of questions. 
/*********************************************/

public class MyersBrigs { 
     
    public static void main( String [ ] args )
        throws FileNotFoundException {
        Scanner input = new Scanner( new File("MB.txt") );
        
        final int NUM_GROUPS = 10;  // The pattern, 1223344, is repeated in
        final int NUM_IN_GROUP = 7; // the question sequence NUM_GROUPS times.
        
        final char A = 'A'; // The only valid answers to a
        final char B = 'B'; // question are A and B.
          
        // record # of Bs. for each dimension, I/E, S/N, T/F, J/P.
        final int[] dimensions = { 0, 0, 0, 0 };
        // Associate indexes with dimensions.
        final int IE = 0; // Introversion / Extroversion.
        final int SN = 1; // Sensing / Intuition.
        final int TF = 2; // Thinking / Feeling.
        final int JP = 3; // Judging / Perception.
        
        // symbols used to indicate type classifications.
        final char[][] SYMBOLS = { { 'I', 'E' }, 
                                   { 'S', 'N' },
                                   { 'T', 'F' },
                                   { 'J', 'P' } };
          
        while( input.hasNextLine() ) {
            String name = input.nextLine();        
            String answers = input.nextLine();
                
            // Clear entries for this person.
            for( int i = 0; i < dimensions.length; i++ ) {
                dimensions[ i ] = 0;
            }
            
            System.out.println( name + ":" );
                
            // Calculate the number of Bs in each dimension.            
            for( int i = 0; i < dimensions.length; i++ ){           	 
            	int numberA = 0;            	
            	int numberB = 0;            	
            	if( i == 0 ){           		
            		for( int v = 0; v <= answers.length() - NUM_IN_GROUP; v+=NUM_IN_GROUP ){            			
            			if( answers.charAt( v ) == B ){            				
            				numberB++;
            			}                    			
            		}            		
            		numberA = NUM_GROUPS - numberB;            		
            		System.out.print( "    " + ( 10 - numberB ) + A + "-" + numberB + B );            		
            		dimensions[i] = ( ( numberB * 100 )  / ( numberA + numberB ) );
            	}            	
            	else {            		
            		for( int v = i + ( i - 1 ); v < answers.length(); v+=NUM_IN_GROUP - 1 ){            			
            			if( answers.charAt( v ) == B ){            				
            				numberB++;            				
            			}            			
            			v++;            			
            			if( answers.charAt( v ) == B ){            				
            				numberB++;            				
            			}            			
            		}            		
            		numberA = ( NUM_GROUPS * 2 ) - numberB;            		
            		System.out.print( " " + ( numberA ) + A + "-" + numberB + B );        			
            		dimensions[i] = ( ( numberB * 100 )  / ( numberA + numberB ) );		// calculate the percent of B's in each dimension          
            	}  
            }                          
            System.out.println();
            System.out.print( "    [" + dimensions[0] + "%, " + dimensions[1] + "%, " + dimensions[2] + "%, " + dimensions[3] + "%] = " ); 
            printType( dimensions, SYMBOLS ); 
        }
    }
    
    public static void printType( int [] dimensions, char[][] SYMBOLS ){	// prints the resulting type SYMBOLS
    	int g = 0;
    	for( int i = 0; i < dimensions.length; i++){
    		if( dimensions[i] >= 50 ){
    			g = 1;
    		}
    	System.out.print( SYMBOLS[i][g] );
    	g = 0; 
    	}
    	System.out.println();
    }
}
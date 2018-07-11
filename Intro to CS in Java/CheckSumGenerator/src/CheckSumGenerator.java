import java.util.*;

// Nils Fenske
// 1/29/14
// CS 210
// Assignment #3
//
// This program will check the sum of an 8 digit number entered by the user.

public class CheckSumGenerator {

    // The largest value an int can hold is 2,147,483,647
    // That's only ten digits, and we can't even do all 
    // ten digit numbers, so we need to be sure
    // that the largest number we make is only nine digits.
    public static final int NUMBER_DIGITS = 8;    

    public static void main( String[] args ) {
    
        //***********************************
        // test the f method
        //***********************************
        System.out.println( "Testing f, the results should be:" );
        System.out.println( "0, 2, 4, 6, 8, 1, 3, 5, 7, 9," );
        System.out.println( "The results are: " );
        for( int i = 0; i < 10; i++ ) {
            System.out.print( f( i ) + ", " );
        }
        System.out.println();
        System.out.println();
    
    
        //***********************************
        // Now, let's apply our methods.
        //***********************************
        Scanner console = new Scanner( System.in );
        
        // get number from user on command line
        int numberBeforeChecksum = getNumber( console ); 
        
        // get the digit we need to set the validation
        int checkSumDigit = getCheckSumDigit( numberBeforeChecksum ); 
        
        // compute the checksummed number
        int numberAfterChecksum = 10 * numberBeforeChecksum + checkSumDigit;
        
        //***********************************
        // print all results
        //***********************************
        System.out.println( "numberBeforeChecksum = " + numberBeforeChecksum );
        System.out.println( "checkSumDigit = " + checkSumDigit );
        System.out.println( "numberAfterChecksum = " + numberAfterChecksum );
    }
    
    public static int getCheckSumDigit( int numberBeforeChecksum ) {
        int x = numberBeforeChecksum;
        	int d7 = x % 10;	//assigning the correct values from the user input to each d value
    		x = x / 10;			//
    		int d6 = x % 10;	//
    		x = x / 10;			//
    		int d5 = x % 10;	//
    		x = x / 10;			//
    		int d4 = x % 10;	//
    	    x = x / 10;			//
    		int d3 = x % 10;	//
        	x = x / 10;			//
        	int d2 = x % 10;	//
    		x = x / 10;			//
    		int d1 = x % 10;	//
    		x = x / 10;			//
    		int d0 = x % 10;	//
    		x = x / 10;
    		int p = 10 - (d0 + f( d1 ) + d2 + f(d3 ) + d4 + f( d5 ) + d6 + f( d7 ) ) % 10; // Finding remaining value ( p ) to add so its a multiple of 10
    		
        return ( p );  // p will now get added to the user input making it divisible by 10
    }
    
    public static int f( int x ) {	//formula for the function f()
    	x = 2 * x;
    	int a = x / 10;		//grabs the first digit
		int b = x % 10;		//grabs the second digit
        return ( a + b );   //adds the two digits together
    }
    
    /**
     * Get a number from the user via Scanner
     @ @param console is the input stream used to get data
     * @return the value read from the Scanner
     */
    public static int getNumber( Scanner console ) {
        System.out.print( "Input an " + NUMBER_DIGITS + "-digit number: " );
        int userInput = console.nextInt();
        console.nextLine(); // flush the input buffer completely.
        return userInput;
    }
}
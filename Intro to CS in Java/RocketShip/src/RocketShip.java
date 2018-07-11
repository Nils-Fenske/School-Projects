// Nils Fenske		
// 1/23/14
// CS 210
// Assignment #2
//
// This program will print a rocket ship made of symbols that can be scaled to different sizes.
public class RocketShip {
    // ROCKET_SIZE controls the size of the rocket ship,
    // in that the number of small diamonds in the 
    // middle of the rocket body is 
    // 2 * ( 2 * ROCKET_SIZE - 1 )
    public static final int ROCKET_SIZE = 4;  
    
    public static void main( String[] args ) {
        printRocket();
    }
    public static void printRocket() {
        printNoseCone(); // top of rocket ship
        printBody(); // middle of rocket ship
        printNozzle(); // bottom of rocket ship
    }
    public static void printNoseCone() {	//this is the top cone of / and *'s 
        for ( int a = 1; a <= 2 * ROCKET_SIZE - 1; a++) {
        	for ( int space = 2 * ROCKET_SIZE - 1; space >= a; space--) {
        		System.out.print( " " );
        	}
        	for ( int slash = 1; slash <= a; slash++) {
        		System.out.print( "/" );
        	}
        		System.out.print( "**" );
            for ( int slash = 1; slash <= a; slash++) {
            	System.out.print( "\\" );
            }
        	for ( int space = 5; space >= a; space--) {
        		System.out.print( " " );
        	}	
        	System.out.println();
        }		
    }
    public static void printBody() {
        System.out.print( "+" );	//this is the top border of the middle section
        for ( int b = 1; b <= ROCKET_SIZE * 2; b++ ) {
        	System.out.print( "=*" );
        }
        System.out.println( "+" );
        	for ( int c = 1; c <= ROCKET_SIZE; c++ ) {	//this is the top 1/4 of the body. Indented for no reason other than readability.
        		System.out.print( "|" );
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int tri = 1; tri <= c; tri++ ) {
        				System.out.print( "/\\" );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int tri = 1; tri <= c; tri++ ) {
        				System.out.print( "/\\" );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
    			System.out.println( "|" );
    			
        	}
        	for ( int c = 1; c <= ROCKET_SIZE; c++ ) {	// this is the bottom of the top half
        		System.out.print( "|" );
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int tri = ROCKET_SIZE; tri >= c; tri-- ) {
        			System.out.print( "\\/" );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int tri = ROCKET_SIZE; tri >= c; tri-- ) {
        			System.out.print( "\\/" );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		System.out.println( "|" );
        	}
        System.out.print( "+" );	//this is the border line going through the middle
        for ( int b = 1; b <= ROCKET_SIZE * 2; b++ ) {
            System.out.print( "=*" );
        }
        System.out.println( "+" );
        	for ( int c = 1; c <= ROCKET_SIZE; c++ ) {	//this is the same as the bottom of the top half
        		System.out.print( "|" );
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int tri = ROCKET_SIZE; tri >= c; tri-- ) {
        			System.out.print( "\\/" );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		for ( int tri = ROCKET_SIZE; tri >= c; tri-- ) {
        			System.out.print( "\\/" );
        		}
        		for ( int dot = 2; dot <= c; dot++ ) {
        			System.out.print( "." );
        		}
        		System.out.println( "|" );
        	}
        	for ( int c = 1; c <= ROCKET_SIZE; c++ ) {	//this code is the same as the top 1/4
        		System.out.print( "|" );
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int tri = 1; tri <= c; tri++ ) {
        				System.out.print( "/\\" );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
        		for ( int tri = 1; tri <= c; tri++ ) {
        				System.out.print( "/\\" );
        		}
        		for ( int dot = ROCKET_SIZE - 1; dot >= c; dot-- ) {
        			System.out.print( "." );
        		}
    			System.out.println( "|" );
        	}
        System.out.print( "+" );	//here is the bottom border of the body
        for ( int b = 1; b <= ROCKET_SIZE * 2; b++ ) {
            System.out.print( "=*" );
        }
        System.out.println( "+" );
    }
    public static void printNozzle() {	// This will print the rockets nozzle of / and *'s
    	for ( int a = 1; a <= 2 * ROCKET_SIZE - 1; a++) {	
        	for ( int space = 2 * ROCKET_SIZE - 1; space >= a; space--) {
        		System.out.print( " " );
        	}
        	for ( int slash = 1; slash <= a; slash++) {
        		System.out.print( "/" );
        	}
        		System.out.print( "**" );
            for ( int slash = 1; slash <= a; slash++) {
            	System.out.print( "\\" );
            }
        	for ( int space = 5; space >= a; space--) {
        		System.out.print( " " );
        	}	
        	System.out.println();
        }		
    }
}
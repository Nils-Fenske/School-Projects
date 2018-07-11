import java.util.*;

public class CircleMain{

	public static void  main( String[] args ){
		
		intro();
		
		double radius = inputRadius();
		
		while( radius != 0 ){
			
			while( radius < 0 ){
				System.out.println( "The radius must be a positive number; please try again." );
				System.out.println();
				inputRadius();				
			}
			
			printCircle( radius );
			
			System.out.println();
			
			inputRadius();						
		}
		
		exit();
	}
		
	public static void intro(){
		System.out.println( "This program will prompt for the radius of a circle" );
		System.out.println( "and disply the circle's diameter, cicumference, and area." );
		System.out.println( "The program will repeat until the user chooses to quit." );
		System.out.println();
	}

	public static void exit(){
		System.out.println();
		System.out.println( "Thanks for using the circle program." );
	}
	
	public static double inputRadius(){
		System.out.print( "Enter a radius ( 0 to quit ): " );
		Scanner input = new Scanner( System.in );

			while( !input.hasNextInt() ){
				System.out.println( "Not a number; try again." );
				System.out.println();
				System.out.print( "Enter a radius ( 0 to quit ): " );
				input = new Scanner( System.in );
			}		
				double radius = input.nextInt() * 1.0;
				return radius;
			
	}
	
	public static void printCircle( double x ){
		Circle c1 = new Circle( x );
	
		System.out.println( "Here is your new Circle:" );
		c1.toString();
		System.out.print( "Diameter: " ); 
		c1.getDiameter();
		System.out.print( ", Circumference: ");
		c1.getCircumference();
		System.out.print( ", Area: " );
		c1.getArea();
		System.out.println();
	}
}

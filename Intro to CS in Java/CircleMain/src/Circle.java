/**
 * @author Nils Fenske
 * A Circle object with radius from a user.
 */
public class Circle {
    private double radius;

    /**
     * Constructs a new circle with radius 1.
     */
    public Circle() {
        this( 1.0 );    
    }
    
    /**
     * Takes in new radius.
     * @param newRadius takes in a new radius
     */
	public Circle(double newRadius) {
		radius = newRadius;			
	}
	
	/**
	 * Calculates the diameter.
	 * @return returns the diameter from the given radius.
	 */
	public double getDiameter(){
		return 2 * radius;
	}
	
	/**
	 * Calculates the circumference.
	 * @return returns the circumference from the given radius.
	 */
	public double getCircumference(){
		return getDiameter() * 3.14;
	}
	
	/**
	 * Calculates the area.
	 * @return returns the area from the given radius.
	 */
	public double getArea(){
		return radius * radius * 3.14;
	}
	
	/**
	 * converts the radius into a string which prints a message saying what the radius is.
	 */
	public String toString(){
		return "Radius: " + radius;
	}
	
	/**
	 * Compares the circle to another circle with the same radius.
	 */
	public boolean equals( Object o ){
		if (o instanceof Circle) {
            Circle other = (Circle) o;
            return radius == other.radius;
        } else {
            return false;
        } 
	}
}

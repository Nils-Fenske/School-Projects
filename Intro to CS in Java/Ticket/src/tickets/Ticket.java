
//Nils Fenske
//CS211 Bill Iverson
//Ticket Class
package tickets;

public abstract class Ticket {
	private int price = 50;	//regular price is $50
	
	protected int number;	//ticket number
	
	public Ticket(){}
	
	public Ticket( int c ){						// Walkup Ticket
		number = c;
	}							
	
	public Ticket( int x , int days ){			// Advanced ticket
		number = x;								
		if ( days >= 10 ){
			price = 30; 
		} else {
			price = 40;
		}	
	}
	
	public int getPrice(){
		return price;
	}
	
	public String toString(){
		return "Number: " + number + ", Price: " + getPrice();
	}
}

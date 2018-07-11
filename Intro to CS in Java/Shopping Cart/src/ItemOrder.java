// Nils Fenske
// 4/27/14
// CS 211 Bill Iverson 11:30
// Assignment #6 
 
public class ItemOrder {
	
	private Item item;
	private int quantity;

	public ItemOrder( Item product, int number ) throws IllegalArgumentException {
		item = product;
		
		if ( number < 0 ) {
			throw new IllegalArgumentException();		//quantity cannot be less than 0
		}
		else {
			quantity= number;
		}
	}
	
	public double getPrice() {
		return item.priceFor( quantity );					//returns the price for the 
	}
	
	public Item getItem() {
		return item;										//returns the item selected
	}
}

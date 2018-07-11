// Nils Fenske
// 4/27/14
// CS 211 Bill Iverson 11:30
// Assignment #6 
// Item

import java.text.NumberFormat;


public class Item {
	
	private String name;
	private double price;
	private int bulkAmount;
	private double bulkPrice;

	public Item( String setName, double setPrice ) throws IllegalArgumentException {
		name = setName;
		
		if ( setPrice < 0 ) {						//price cannot be below 0
			throw new IllegalArgumentException(); 
		}
		price = setPrice;							//sets the price of the item
	}
	
	public Item( String setName, double setPrice, int setBulkAmount, double setBulkPrice ) throws IllegalArgumentException {
		name = setName;
		
		if ( setPrice < 0 ) {
			throw new IllegalArgumentException(); 
		}
		price = setPrice;
		
		if ( setBulkAmount <= 0 || setBulkPrice < 0 ) {		//bulk amounts and prices cannot be below zero
			throw new IllegalArgumentException();
		}
		bulkAmount = setBulkAmount;							//sets the amounts and prices for bulk purchases
		bulkPrice = setBulkPrice;
	}
	
	public double priceFor( int quantity ) {
		
		int bulkGroups = 0;
		int remainder = 0;
		double priceForBulk = 0;
		
		if ( quantity >= bulkAmount && bulkAmount > 0 ) {
			
			bulkGroups = quantity / bulkAmount;				//finds the number of items considered bulk
			remainder = quantity % bulkAmount;				//finds the number of remaining full price items
			priceForBulk = bulkGroups * bulkPrice;			//finds the price for groups of bulk items
		} 
		
		//total for all items
		return ( bulkAmount > 0 && quantity >= bulkAmount ) ? priceForBulk + remainder * price: quantity * price;
	}
	
	public String toString() {
		
		NumberFormat nf = NumberFormat.getCurrencyInstance();
		String printPrice = nf.format( price ); 
		String printBulkPrice = nf.format( bulkPrice );
		
		if ( bulkAmount > 0 ) {
			return name + ", " + printPrice + " (" + bulkAmount + " for " + printBulkPrice + ")";
		}
		else {
			return name + ", " + printPrice;
		}
	}
}

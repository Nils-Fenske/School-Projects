// Nils Fenske
// 4/27/14
// CS 211 Bill Iverson 11:30
// Assignment #6  

import java.util.ArrayList;


public class ShoppingCart {
	
	private ArrayList<ItemOrder> c = new ArrayList<ItemOrder>();
	 private boolean discountApplied;
	 
	 public ShoppingCart() {
	  c.clear(); 
	 }
	 
	public void setDiscount( boolean selected ) {
		discountApplied = selected;	
	}

	public double getTotal() {
		double total = 0;
		for ( ItemOrder n: c ) {
			total += n.getPrice();
		}
		if ( this.discountApplied ) {
			return total = total * 0.9;
		}
		else {
			return total;
		}
	}

	public void add( ItemOrder i ) {
		if ( this.ifExists( i ) ) {					//if this item has already been added
			c.set( getExisting( i ), i );			//replace it here
		}
		else {
			c.add( i );							//else just add it as a new one
		}
	}

	private boolean ifExists( ItemOrder i ){
		for(ItemOrder a: c)
		{
			if(a.getItem() == i.getItem())
			{
				return true;
			}
		}
		return false;
	}
	
	private int getExisting( ItemOrder i ) {
		for(ItemOrder a: c)
		{
			//if this is the object we are looking for
			if(a.getItem() == i.getItem())
			{
				//return the index of that object
				return c.indexOf(a);
			}
		}
		return 0;
	}

}

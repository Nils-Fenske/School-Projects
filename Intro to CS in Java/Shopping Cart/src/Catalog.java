// Nils Fenske
// 4/27/14
// CS 211 Bill Iverson 11:30
// Assignment #6 
// Catalog

import java.util.ArrayList;


public class Catalog {
	
	private String catName;
	private ArrayList <Item> catalog = new ArrayList <Item>();

	public Catalog( String name ) {
		this.catName = name;			//sets the catalogs name
	}

	public String getName() {
		return catName;					//returns the catalogs name
	}

	public int size() {
		return catalog.size();			//returns the catalogs size
	}

	public Item get( int i ) {
		return catalog.get( i );			//returns the index of an item in the catalog
	}

	public void add( Item item ) {	
		catalog.add( item );				//adds an item to the catalog
		
	}

}

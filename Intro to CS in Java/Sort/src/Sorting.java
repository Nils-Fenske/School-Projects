// Nils Fenske
// 5/14/14
// Assignment #9
// Bill Iverson CS 211

import java.io.*;
import java.util.*;

public class Sorting {

	public static void main(String[] args) throws FileNotFoundException {
		
		PrintStream output = new PrintStream("bigO.csv" );
 
		ArrayList<Integer> toSort = new ArrayList<Integer>();
		for ( int i = 1000; i <= 2000000; i+= 10000) {
			toSort.clear();

			for ( int n = 0; n < i; n++) {
				toSort.add((int) (1+n*Math.random()));
			}
			int start = (int) System.currentTimeMillis();
			Collections.sort(toSort);
			int finish = (int) System.currentTimeMillis();
			int time = finish - start;
			System.out.println(toSort.size() +", " + time);
			output.println(toSort.size() +", " + time);
		}
		output.close();
	}
}


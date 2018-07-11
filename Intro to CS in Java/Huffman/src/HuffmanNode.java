import java.io.*;
import java.util.*;
//Nils Fenske
//6/17/14
//Assignment # 14
//Bill Iverson CS 211

public class HuffmanNode implements Comparable<HuffmanNode> {
	public int frequency;
	public char character;
	public HuffmanNode left;
	public HuffmanNode right;
	
	public HuffmanNode(int frequency, char character,  HuffmanNode left, HuffmanNode right) {
			this.frequency = frequency;
			this.character = character;
			this.left = left;
			this.right = right;
	}
	
	public boolean isLeaf(HuffmanNode root) {
		return (root.right == null && root.left == null);
	}
	
	public static Map<Character, Integer> getCounts(FileInputStream input) {
		Map<Character, Integer> getCounts = new TreeMap<Character, Integer>();
		int i;
        try {
        	while ((i = input.read()) != -1) {
        		if ( i >= 65 && i <= 90 ) {
        			i += 32;
        		}
        		if (i >= 97 && i <= 122 || i == 32) {
        			if (getCounts.containsKey((char)i)) {
        				getCounts.put((char)i, getCounts.get((char)i) + 1);
        			}
        			else if (i == 256) {
        				System.out.println("EOF");
        			}
        			else {
        				getCounts.put((char)i,1);
        			}
        		}
        	}
        }
        catch (IOException e) {
        	e.printStackTrace();
       	}
        System.out.println("getCounts");
        System.out.println(getCounts);
       	return getCounts;
	}

	@Override
	public int compareTo(HuffmanNode arg0) {
		// TODO Auto-generated method stub
		return 0;
	}
}

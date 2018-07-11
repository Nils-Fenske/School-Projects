import java.io.FileInputStream;
import java.util.*;
//Nils Fenske
// 6/17/14
// Assignment # 14
// Bill Iverson CS 211

public class HuffmanTree {

	private HuffmanNode overallRoot;
	 

	public HuffmanTree(Map<Character, Integer> counts) {
		 
	}
	
	public String printSideways() {
        return printSideways(overallRoot, 0);
    }
	
	public String printSideways(HuffmanNode root, int level) {
        String result = null ;
		if (root != null) {
            printSideways(root.right, level + 1);
            for (int i = 0; i < level; i++) {
                System.out.print("    ");
            }
            result = root.frequency + printSideways(root.left, level + 1);
        }
		return result;
    }

	public StringBuilder compress(FileInputStream input) {
		return null;
	}

	public String decompress(StringBuilder huffResults) {
		// TODO Auto-generated method stub
		return null;
	}

}

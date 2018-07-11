import java.util.ArrayList;
// Nils Fenske
// Quiz #11 
// 5/30/14
// Bill Iverson CS 211

public class Utility{

		public static ArrayList<Integer> runningTotal (ArrayList<Integer> test){
			ArrayList<Integer> result = new ArrayList<Integer>();
	    	int total = 0;
	    	for (int i = 0; i < test.size(); i++) {
	    		total += test.get(i);
	    		result.add(total);
	    	}
	    	return result;
		}
}

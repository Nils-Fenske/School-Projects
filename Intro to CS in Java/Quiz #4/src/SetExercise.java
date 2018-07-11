import java.util.*;
/**
 * Nils Fenske
 * Quiz #4
 * BC CS211
 * Selected Chapter 11 Exercises
 * 
 * W.P. Iverson, programming exercise
 * April 2014
 */
public class SetExercise
{
    public static void main(String[] a) {
        // Build an array of Strings
        String[] arrayS = {"Jane","Logan","Whitaker","Alyssa","Stefanie","Jeff","Kim","Sylvia"};
        ArrayList<String> testListS = new ArrayList<String>();
        
        // Build the Set of Strings:
        for (String s: arrayS) testListS.add(s);
        Set<String> testSetS = new TreeSet<String>(testListS);
        
        // test programming exercise
        System.out.println(testSetS);
        removeOddLength(testSetS);
        removeOddLength(null);
        System.out.println(testSetS);
    }
    
    public static Set<String> removeOddLength( Set<String> a )  {
    	try {
    		Iterator<String> itr = a.iterator();
    		while( itr.hasNext() ) {
    			if(itr.next().length() % 2 != 0 ) {
    				itr.remove(); 
    			}
    		}
    		return a;
    	}
    	catch ( Exception e ){
    		return a;
    	}
    }
}
    
    
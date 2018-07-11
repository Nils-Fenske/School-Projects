import java.util.Iterator;


public class Test {
	public static void main( String[] args) {
		
		LinkedStack<String> test = new LinkedStack<String>();
		test.push("three"); 
		//System.out.println(test.pop());
		test.push("two"); 
		//System.out.println(test.pop());
		test.push("one");
		//System.out.println(test.pop());
		
		while (!test.empty()) {
			System.out.println(test.pop());
			//System.out.println(test);
		}
		
		
		Iterator<String> thing = test.iterator();
		
		while (thing.hasNext()) { 
			System.out.println(thing.next());
		}
	}
}

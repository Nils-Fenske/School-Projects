import java.util.ArrayList;

//import java.util.*;


public class Test {

// Testing for Exercises in back of Chapter 15
	
	public static void main(String[] args) {
		ArrayIntList test = new ArrayIntList();		// my data structure
		int[] a = {1,2,3,4,5,6,1,2,6,7,3,5,44,2,26,};			// sample data
		for (int i: a) test.add(i);					// use for each 
		

//		try {
//			ArrayIntList oops = new ArrayIntList(-9);	// maybe illegal, consider Exceptions
//			test.get(1);
//		} catch (IllegalArgumentException e) {
//			System.out.println("Caught  " ); //+ e.toString());
//		} catch (Exception d) {
//			System.out.println("the d exception");
//		} finally {
//			System.out.println("Always do this stuff");
//		}
		
		System.out.println(test);
		//test.replaceAll(3, 999);						// Exercise 15.2
		test.runningTotal();							// Exercise 15.4 (wrong use)
		//test = test.runningTotal();					// (correct use)
		//test = ArrayIntList.runningTotal(test);		// (static use)
		//test = Utility.runningTotal(test);			// (another static use)
		//System.out.println(test.isPairwiseSorted());	// Exercise 15.6
		System.out.println(test.longestSortedSequence());	// 15.8
		//test.removeAll(999);								// 15.10
		//test.mirror();									// 15.12
		//test.stretch(3);									// 15.14
		ArrayIntList test1 = test;
		test1.stutter();
		System.out.println("test1: " + test1);
//		ArrayIntList test2 = test.stutter2();
//		System.out.println("test2: " + test2);
//		ArrayIntList test3 = ArrayIntList.stutter2(test);
//		System.out.println("test3: " + test3);
//		System.out.println(test);
		
//		for (int i: test) System.out.println(i);	// nor Iterable nor Iterator??
//		ArrayIntListIterator itr = new ArrayIntListIterator(test);
//		while (itr.hasNext()) System.out.print(itr.next()+", ");
//		System.out.println();
		
//		// Programming Project #2
//		ArrayList<Integer> test2 = new ArrayList<Integer>();
//		for (int i: a) test2.add(i);
//		for (Integer I: test2) System.out.print(I+", "); // uses a generic Java API Iterator<E>
//		System.out.println();
//		ArrayListIterator<Integer> itr2 = new ArrayListIterator<Integer>(test2);
//		itr2.next();
//		itr2.next();
//		itr2.remove();
//		while (itr2.hasNext()) System.out.print(itr2.next()+", ");
//		
	}

}
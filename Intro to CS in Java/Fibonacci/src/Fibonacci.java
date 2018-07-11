// Nils Fenske
// 5/6/14
// CS 211
// Assignment #8
// Write a code that returns values from the Fiboancci sequence as fast as possible.

public class Fibonacci {
    public static void main(String[] args) {
    	int test = 45;
    	while (test > -1) {
        double time1 = System.currentTimeMillis();
        System.out.println(fibFast(test)); // a fast recursive version
        double time2 = System.currentTimeMillis();
        System.out.println("fibFast: " + (time2-time1)/1000 + " seconds");
        
        double time3 = System.currentTimeMillis();
        System.out.println(myVersion(test)); // a version I managed to figure out without recursion that is just as fast
        double time4 = System.currentTimeMillis();
        System.out.println("myVersion: " + (time4-time3)/1000 + " seconds");
        
        double time5 = System.currentTimeMillis();
        System.out.println(fibonacci(test)); // slow version in text 
        double time6 = System.currentTimeMillis();
        System.out.println("fibonacci: " + (time6-time5)/1000 + " seconds");
        System.out.println();
        test++;
    	}
    }
    
    public static int fibonacci(int n){
    	if (n<=2) {
    		return 1;
    	} else {
    		return fibonacci(n-1) + fibonacci(n-2);
    	}	
    }
    
    public static int fibFast(int e) {
    	return adding(e, 1, 0);
    }
    
    public static int adding(int n, int y, int x) {
    	if (n == 0) {
    		return x;
    	}
    	else {
    		return adding(n-1, x+y, y);
    	}
    }    
    
   public static int myVersion(int n) {
    	int i = 0;
    	int x = 1;
    	int y = 0;
    	int p;
    	while ( i != n ){
    		p = x;
    		x = x + y;
    		y = p;
    		i++;
    	}	
    	return y;
    }
}
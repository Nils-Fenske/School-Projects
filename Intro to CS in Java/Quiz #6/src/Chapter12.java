// Nils Fenske
// 5/8/14
// Chpater 12 Quiz #6
// CS 211 Bill Iverson

public class Chapter12 {
    public static void main(String[] args) {
        //System.out.println("Factorial="+factorial(7));
        System.out.println("Permut(5,1)=5  "+permut(5,1));
        System.out.println("Permut(7,3)=210  "+permut(7,3));
        System.out.println("Permut(52,5)=311875200  "+permut(52,5));
        System.out.println("Permut(55,5)=417451320  "+permut(55,5));
        System.out.println( exampleRecursion(3));
        System.out.println(func1(8));
    }
    
    
    public static int permut( int n, int r ) {
    	if ( r == 1 ) {
    		return n;
    	}
    	else {
    		return permut( n-1, r-1 ) * n;
    	}
    }
    
    public static int exampleRecursion (int n) 
    { 
        if (n == 0) 
                   return 0; 
        else 
                   return exampleRecursion(n - 1) + n * n * n; 
    }
    
    public static int func1( int m) {
    	if( m >= 10) {
    		return 10;
    	}
    	else {
    		return m * func1(m + 1);
    	}
    }
}
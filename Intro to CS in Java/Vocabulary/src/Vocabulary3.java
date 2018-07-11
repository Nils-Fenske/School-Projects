// Nils Fenske
// 4/30/14
// CS 211 Assignment #7
// This program reads two text files and compares the vocabulary used in each.
//  
// 1) The total run time for the original array list based code is 828 milliseconds.
//
// 2) It takes only 821 milliseconds to read the files and then about 7 more milliseconds to count the words in common.
//
// 3) Using Set's, it takes 650 milliseconds to read the files and then about 15 more milliseconds to count the words in common.
//
// 4) Moby = 'e'(115002), 't'(86488), and 's'(63053)
//    Hamlet =  'e'(17900), 't'(12098), and 'n'(8377)
//


import java.util.*;
import java.io.*;

public class Vocabulary3 {
	static int r = 0;

    public static void main(String[] q) throws FileNotFoundException {
        Scanner console = new Scanner(System.in);
        giveIntro();

        System.out.print("file #1 name? ");
        Scanner input1 = new Scanner(new File("moby.txt")); // moby.txt			// CAN CHANGE BACK TO console.nextLine()
        System.out.print("file #2 name? ");
        Scanner input2 = new Scanner(new File("hamlet.txt")); // hamlet.txt		// CAN CHANGE BACK TO console.nextLine()
        System.out.println();

        double time1 = System.currentTimeMillis();
        HashSet<String> list1 = getWords(input1);
        HashSet<String> list2 = getWords(input2);
        double time2 = System.currentTimeMillis();
        System.out.println("File read time=" + (time2-time1)/1000 + " seconds");
        time1 = System.currentTimeMillis();
        HashSet<String> overlap = getOverlap(list1, list2);
        reportResults(list1, list2, overlap);
        time2 = System.currentTimeMillis();
        System.out.println("Process time=" + (time2-time1) + " milliseconds");
        
        // This portion is similar to Addison and Alex Tan (previos CS11 student) we worked on it together
        FileInputStream moby = new FileInputStream( new File( "moby.txt" ) );		
        FileInputStream hamlet = new FileInputStream( new File( "hamlet.txt" ) );
        HashMap<Character, Integer> mobyChars = getCounts( moby );
        HashMap<Character, Integer> hamletChars = getCounts( hamlet );
        
        characterPrint( mobyChars );
        characterPrint( hamletChars);
    }
       
    public static HashMap<Character, Integer> getCounts(FileInputStream input) {
        // read all characters and sort
        HashMap<Character, Integer> chars = new HashMap<Character, Integer>();
        int i;
        try {
        	while ( ( i = input.read() ) != -1 ) {
        		if ( i >= 65 && i <= 90 ) {
        			i += 32;
        		}
        		// only alphabetical, lowercase characters in the character table
        		if ( i >= 97 && i <= 122 ) {
        			if ( chars.containsKey( ( char) i ) ) {
        				chars.put( ( char ) i, chars.get( ( char ) i ) + 1 );
        			}
        			else {
        				chars.put( ( char ) i, 1 );
        			}
        		}
        	}
        }
        catch (IOException e) {
        	e.printStackTrace();
       	}
       	return chars;  
        }
    
    public static void characterPrint( HashMap<Character, Integer> m ) {
    	 int char1 = 0;		//stores the top three characters
         int char2 = 0;
         int char3 = 0;
         
         int count1 = 0;	//stores the count for the top three characters
         int count2 = 0;
         int count3 = 0;
         
         for ( int c = 97; c <= 122; c++ ) {
         	if(m.get((char)c) > count1)
         	{
         		char1 = (char)c;
         		count1 = m.get((char)c);
         	}
         	else if(m.get((char)c) > count2)
         	{
         		char2 = (char)c;
         		count2 = m.get((char)c);
         	}
         	else if(m.get((char)c) > count3)
         	{
         		char3 = (char)c;
         		count3 = m.get((char)c);
         	}
         }
         if ( r == 0 ) {
        	 System.out.println();
        	 System.out.println( "Most Common Moby Characters: " + ( char ) char1 + " " + count1 + " " + ( char ) char2 + " " + count2 + " " + ( char ) char3 + " " + count3 );
        	 System.out.println();
        	 r++;
         }
         else {
             System.out.println( "Most Common Hamlet Characters: " + ( char ) char1 + " " + count1 + " " + ( char ) char2 + " " + count2 + " " + ( char ) char3 + " " + count3 );
             System.out.println();
         }
     }
    
    // post: reads all words from the given Scanner, turning them to lowercase
    //       and returning a sorted list of the vocabulary of the file
    public static HashSet<String> getWords(Scanner input) {
        // ignore all but alphabetic characters and apostrophes
        input.useDelimiter("[^a-zA-Z']");
        // read all words and sort
        HashSet<String> words = new HashSet<String>();
        while (input.hasNext()) {
            String next = input.next().toLowerCase();
            words.add(next);
        }
        return words;
    }

    // pre : list1 and list2 are sorted and contain no duplicates
    // post: constructs and returns an ArrayList containing the words 
    //       in common betweeen list1 and list2
    public static HashSet<String> getOverlap(HashSet<String> list1, HashSet<String> list2) {
        HashSet<String> result = new HashSet<String>();
        for ( String a : list1 ) {
        	if ( list2.contains(a ) ) {
                result.add( a );
        	}
        }
        return result;
    }

    // post: explains program to user
    public static void giveIntro() {
        System.out.println("This program compares the vocabulary of two");
        System.out.println("text files, reporting the number of words");
        System.out.println("in common and the percent of overlap.");
        System.out.println();
    }

    // pre : overlap contains the words in common between list1 and list2
    // post: reports statistics about two word lists and their overlap
    public static void reportResults(Set<String> list1, Set<String> list2, Set<String> overlap) {
        System.out.println("file #1 words = " + list1.size());
        System.out.println("file #2 words = " + list2.size());
        System.out.println("common words  = " + overlap.size());

        double percent1 = 100.0 * overlap.size() / list1.size();
        double percent2 = 100.0 * overlap.size() / list2.size();
        System.out.println("% of file 1 in overlap = " + percent1);
        System.out.println("% of file 2 in overlap = " + percent2);
    }
}

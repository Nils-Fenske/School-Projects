// Simple first version of LinkedIntList with just a constructor
// and methods for add and toString.
// from BuildingJavaPrograms.com
// with additions by W.P.I., BC 2014
import java.util.*;

// Nils Fenske
// 6/5/14
// Quiz #12
// Bill Iverson CS 211 

public class LinkedIntList {
    private ListNode front;  // first value in the list

    // post: constructs an empty list
    public LinkedIntList() {
        front = null;
    }

    // post: returns comma-separated, bracketed version of list
    public String toString() {
        if (front == null) {
            return "[]";
        } else {
            String result = "[" + front.data;
            ListNode current = front.next;
            while (current != null) {
                result += ", " + current.data;
                current = current.next;
            }
            result += "]";
            return result;
        }
    }

    // post: appends the given value to the end of the list
    public void add(int value) {
        if (front == null) {
            front = new ListNode(value);
        } else {
            ListNode current = front;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new ListNode(value);
        }
    }
    
    //Exercise 16.1: set 
    public void set(int index, int value) {
        ListNode current = front;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        current.data = value;
    }
    
    //Exercise 16.9: stutter 
    public void stutter() {
        ListNode current = front;
        while (current != null) {
            current.next = new ListNode(current.data, current.next);
            current = current.next.next;
        }
    }  
    
    public LinkedIntList removeEvens(LinkedIntList list) {
    	LinkedIntList result = new LinkedIntList();
    	ListNode current = list.front;
    	
    	if ( list.front == null ){
    		result = list;
    	}
    	else if ( list.front.next == null ) {
    		return result;
    	}
    	else if ( current != null ){
        	current = list.front;
    		list.front = list.front.next;
    		System.out.println(current.data);
			while ( current.next != null ){
				current.next = current.next.next;
				current = current.next;
			}
			result = list;
		}
    	return result;
    	
    }
    
}    
    
 
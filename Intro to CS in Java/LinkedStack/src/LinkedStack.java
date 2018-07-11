import java.util.EmptyStackException;
import java.util.Iterator;
import java.util.NoSuchElementException;

// Nils Fenske
// 6/4/14
// Assignment #12
// Bill Iverson CS 211 

// Class LinkedList<E> can be used to store a list of values of type E.

public class LinkedStack<E> implements Iterable<E> {
   
	private LinkedNode<E> top; 
	
    public LinkedStack() {				// Sets the value of the top node to null;
    	top = null; 
    }

    public boolean empty() {			// Returns true if the node is empty
        return top == null;
    }
    
    public E peek() {					// Returns the value on top of the stack without removing it
		if (this.empty()) {
			throw new EmptyStackException();
		}
		else {
			return top.data;
		}
	}
    
    public E pop() {					// Removes the top node and returns its value
    	if (top == null) {
			throw new EmptyStackException();
		}
		else {
			LinkedNode<E> newNode = top;
			E result = newNode.data;
			top = top.next;	    	
			return result;
		}
    	
    }
    
    public E push(E item) {				// Constructs a new node with the input value and places it on top of the existing ones
    	LinkedNode<E> oldNode = top;
    	top = new LinkedNode<E>(item);
		top.next = oldNode;
		return item;
	}
    
    public Iterator<E> iterator() {		// Constructs a new iterator
        return new LinkedIterator();
    }
  
    private class LinkedIterator implements Iterator<E> {
        private LinkedNode<E> current;  
        
        public LinkedIterator() {
            current = top;
        }

        public boolean hasNext() {
            return current != null;
        }

        public E next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            E result = current.data;
            current = current.next;
            return result;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
    
   class LinkedNode<E> {
        public E data;         
        public LinkedNode<E> next;  
        
        public LinkedNode(E data) {
            this(data, null);
        }

        public LinkedNode(E data, LinkedNode<E> next) {
            this.data = data;
            this.next = next;
        }
   }
}
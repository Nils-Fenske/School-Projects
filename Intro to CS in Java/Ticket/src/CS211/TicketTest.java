package CS211;

import tickets.*;
//CS211 BC, W.P. Iverson
//January 2014
public class TicketTest {
//testing code for Ticket Classes
//BJP text Exercises, Chapter 9
 public static void main(String[] args) {
     AdvanceTicket one = new AdvanceTicket(45,84);
     //one.setNumber(44); // not allowed, no method
     //one.number = 44;    // not allowed, wrong package
     
     WalkupTicket two = new WalkupTicket(2);
     two.setNumber(89);
     WalkupTicket three = new WalkupTicket(30);
     three.setNumber(44);// modifies protected field
     one.toString();
     two.toString();
     three.toString();
     System.out.println(one.toString());
     System.out.println(two.toString());
     System.out.println(three.toString());
 }
}

public class Test {

	public static void main(String[] args) {
		
		// Reference tree 1
		IntTreeNode two = new IntTreeNode(2, new IntTreeNode(4, null, null), new IntTreeNode(6, null, null));
		IntTreeNode five = new IntTreeNode(5, new IntTreeNode(1, null, null), null);
		
		IntTree tree1 = new IntTree(new IntTreeNode(3, five, two));
		
		tree1.printSideways();
        
        System.out.println(tree1.isFull());						//#7
        System.out.println(tree1.countEvenBranches());			//#4
        tree1.printLeaves();									//#6
        System.out.println(tree1.toString());					//#8
        tree1.removeLeaves(); tree1.printSideways();		//#12
        tree1.tighten(); tree1.printSideways();					//#16
		
        //Reference tree 2
		IntTreeNode six = new IntTreeNode(6,null,new IntTreeNode(9,null,null));
        IntTreeNode seven = new IntTreeNode(7,new IntTreeNode(4,null,null),null);
        IntTreeNode eight = new IntTreeNode(8,new IntTreeNode(0,null,null),null);
        
        IntTree tree2 = new IntTree(new IntTreeNode(2,eight,new IntTreeNode(1,seven,six)));
       
        tree2.printSideways();
        
        System.out.println(tree2.isFull());						//#7
        System.out.println(tree2.countEvenBranches());			//#4
        tree2.printLeaves();									//#6
        System.out.println(tree2.toString());					//#8
        tree2.removeLeaves(); tree2.printSideways();		//#12
        tree2.tighten(); tree2.printSideways();					//#16
        
        //Reference tree 3
        IntTreeNode one = new IntTreeNode(1, null, null);
		IntTreeNode three = new IntTreeNode(3, new IntTreeNode(8, null, null), new IntTreeNode(7, null, null));
		
		IntTree tree3 = new IntTree(new IntTreeNode(2, three, one));
		
		tree3.printSideways();
        
		System.out.println(tree3.isFull());						//#7
        System.out.println(tree3.countEvenBranches());			//#4
        tree3.printLeaves();									//#6
        System.out.println(tree3.toString());					//#8
        tree3.removeLeaves(); tree3.printSideways();		//#12
        tree3.tighten(); tree3.printSideways();					//#16
  	}
}

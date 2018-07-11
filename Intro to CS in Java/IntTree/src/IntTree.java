// Simple binary tree class that includes methods to construct a
// tree of ints, to print the structure, and to print the data
// using a preorder, inorder or postorder traversal.  The trees
// built have nodes numbered starting with 1 and numbered
// sequentially level by level with no gaps in the tree.  The
// documentation refers to these as "sequential trees."
//
// from buildingjavaprograms.com

// Nils Fenske
// Assignment #13
// 6/12/14
// Bill Iverson CS 211

import java.util.*;

public class IntTree {
    private IntTreeNode overallRoot;

    public IntTree(int max) {
        if (max <= 0) {
            throw new IllegalArgumentException("max: " + max);
        }
        overallRoot = buildTree(1, max);
    }
    
    public IntTree() {
        overallRoot = null;
    }
    
    // constructor added so we can build page 1029 reference trees
    public IntTree(IntTreeNode given) {
        overallRoot = given;
    }

    // Exercise #4 returns the number of even branches
    public int countEvenBranches() {
    	return countEvenBranches(overallRoot);
    }
    
    private int countEvenBranches(IntTreeNode root) {
    	if (root == null) {
    		return 0;
    	} else if (root.data % 2 == 1 || root.left == null && root.right == null) {
    		return countEvenBranches(root.left) + countEvenBranches(root.right); 
    	} else {
    		return 1 + countEvenBranches(root.left) + countEvenBranches(root.right); 
    	}
    }

    // Exercise #6 prints only the leaves of the tree
    public void printLeaves() {
    	printLeaves(overallRoot);
    }
    
    private void printLeaves(IntTreeNode root) {
    	if (root == null){
    		System.out.println("no leaves");
    	} else {
    		System.out.print("leaves: "); leaves(root);
    	}
    }

    private void leaves(IntTreeNode root) {
    	if (root == null){
    		return;
    	}
    	if (root.left == null && root.right == null) { 
    		System.out.print(root.data + " ");
    	} else {
    		leaves(root.right); 
    		leaves(root.left);
    	}		
	}

	//Exercise #7, Chapter 17
    public boolean isFull() {
    		return (overallRoot == null || isFull(overallRoot));
	}
    
    private boolean isFull(IntTreeNode root) {
		if(root.left == null && root.right == null) {
    		return true;
		} else {
    		return (root.left != null && root.right != null && isFull(root.left) && isFull(root.right));
		}
    }  
    
    // Exercise #8 converts the data of the tree into a string and returns that string
    public String toString() { 
   	 	return toString(overallRoot); 
   	}
   
    private String toString(IntTreeNode root) { 
    	if (root == null) {
    		return "empty"; 
   	 	}
   	 	else if (root.left == null && root.right == null){ 
   	 		return "" + root.data; 
   	 	}
   	 	else {
   	 		return "(" + root.data + ", " + toString(root.left) + ", " + toString(root.right) + ")"; 
   	 	}
   	}
    
    //Exercise #12 returns a tree with the leaves removed without changing the tree 
    public void removeLeaves() {
        overallRoot = removeLeaves(overallRoot);
    }
    
    private IntTreeNode removeLeaves(IntTreeNode root) {
        if (root != null) { 
	    if (root.left == null && root.right == null) {
	        root = null;
	    } else {
	        root.left = removeLeaves(root.left); 
	        root.right = removeLeaves(root.right);
	    }
	}

	return root; 
    }
    
    // Exercise #16 returns a tree that has ... without changing the tree 
    public void tighten(){
        overallRoot = tighten(overallRoot);
    }

    private IntTreeNode tighten(IntTreeNode root) {
        if (root != null) { 
	    if (root.left == null && root.right != null) { 
	        root = root.right; 
	    } if (root.right == null && root.left != null){ 
	    	root = root.left; 
	    } 
	        root.left = tighten(root.left); 
	        root.right = tighten(root.right);
	    }	        
    return root;
}


    private IntTreeNode buildTree(int n, int max) {
        if (n > max) {
            return null;
        } else {
            return new IntTreeNode(n, buildTree(2 * n, max),
                                   buildTree(2 * n + 1, max));
        }
    }

    public void printPreorder() {
        System.out.print("preorder:");
        printPreorder(overallRoot);
        System.out.println();
    }

    private void printPreorder(IntTreeNode root) {
        if (root != null) {
            System.out.print(" " + root.data);
            printPreorder(root.left);
            printPreorder(root.right);
        }
    }

    public void printInorder() {
        System.out.print("inorder:");
        printInorder(overallRoot);
        System.out.println();
    }

    private void printInorder(IntTreeNode root) {
        if (root != null) {
            printInorder(root.left);
            System.out.print(" " + root.data);
            printInorder(root.right);
        }
    }

    public void printPostorder() {
        System.out.print("postorder:");
        printPostorder(overallRoot);
        System.out.println();
    }

    private void printPostorder(IntTreeNode root) {
        if (root != null) {
            printPostorder(root.left);
            printPostorder(root.right);
            System.out.print(" " + root.data);
        }
    }

    public void printSideways() {
        printSideways(overallRoot, 0);
    }

    private void printSideways(IntTreeNode root, int level) {
        if (root != null) {
            printSideways(root.right, level + 1);
            for (int i = 0; i < level; i++) {
                System.out.print("    ");
            }
            System.out.println(root.data);
            printSideways(root.left, level + 1);
        }
    }
}
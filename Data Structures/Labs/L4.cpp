// Nils Fenske
// 10/23/2015
// Lab 4

#include <iostream>

using namespace std;

struct TNode{
  int data;
  TNode* left;
  TNode* right;
};
TNode* plantTree(int value);
void insert(TNode* &root, int value);
void preorder(TNode* trav);
void postorder(TNode* trav);
void inorder(TNode* trav);
  
int main (){
  
  TNode* root = plantTree(20);
  insert(root, 5);
  insert(root, 10);
  insert(root, 15);
  insert(root, 25);
  insert(root, 22);
  insert(root, 30);
  insert(root, 35);
  insert(root, 15);

  preorder(root);

  postorder(root);

  inorder(root);

  return 0;
}

TNode* plantTree(int value){
    TNode* root = new TNode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void insert(TNode* &root,int value) {
  TNode* prev = NULL;
  TNode* auxilary = root;
  while (auxilary){
	prev = auxilary;
	if (value > auxilary->data){
	  auxilary = auxilary->right;
	}else
      auxilary = auxilary->left;
  }
  if (!prev){
	root = new TNode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;
  }else if (value < prev->data){
	prev->left = new TNode;
	prev->left->data = value;
	prev->left->left = NULL;
	prev->left->right = NULL;
  }else if (value > prev->data){
	prev->right = new TNode;
	prev->right->data = value;
	prev->right->left = NULL;
	prev->right->right = NULL;
  }
}

void preorder(TNode* trav){
  if (!trav) return;
  cout << trav->data << endl;
  preorder(trav->left);
  preorder(trav->right);
  return;
}

void postorder(TNode* trav){
  if (!trav) return;
  postorder(trav->left);
  postorder(trav->right);
  cout << trav->data << endl;
  return;
}

void inorder(TNode* trav){
  if (!trav) return;
  inorder(trav->left);
  cout << trav->data << endl;
  inorder(trav->right);
  return;
}


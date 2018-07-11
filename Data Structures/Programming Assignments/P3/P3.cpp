// Nils Fenske
// 11-1-15
// Programming Assignment 3

#include "primeDupBST.cpp"

int main() {

	//srand(time(NULL));

	int quantity = 10;
	int x = 0;

	primeDupBST tree;

	//cout << "insert" << endl;
	tree.insert(5);
	tree.insert(10);
	tree.insert(15);
	tree.insert(25);
	tree.insert(17);
	tree.insert(17);
	tree.insert(35);
	tree.insert(15);

	//tree.remove(17);
	//tree.remove(10);
	
	//for (int i = 0; i < quantity; i++) {
	//	x = rand() % 100;
	//	tree.insert(x);
	//	cout << x << endl;
	//}

	//cout << "remove" << endl;
	//or (int i = 0; i < quantity / 2; i++) {
	//	x = rand() % 100;
	//	tree.remove(x);
	//	cout << x << endl;
	//}

	//tree.inorder();

	//tree.preorder();

	return 0;
}
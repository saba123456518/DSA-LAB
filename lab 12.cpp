//#include<iostream>
//#include <algorithm>
//using namespace std;
// struct Node{
// 	int key;
// 	Node* left;
// 	Node* right;
// 	Node (int val){
// 	key = val;
//	 left =  nullptr;
//	 right = nullptr;	
// 		
//	 }
// };
// 
// Node* insert(Node* root , int key ){
//  if(!root){
//  	return new Node(key);
//  }
//  if(key<root->key)
//  root->left = insert(root->left , key );
//  else 
//   root->right = insert(root->right , key );
//   return root;
//}
// void inorder(Node* root){
// 	if(root){
// 	inorder(root->left)	;
// 	cout<<root->key <<" ";
//	 	inorder(root->right)	;	
//	 }
// }
//
//int main() {
//    Node* Root = nullptr;
//    int arr[] = {30, 20, 40, 10, 25};
//    for (int val : arr)
//        Root = insert(Root, val);
//
//    cout << "BST Inorder: ";
//    inorder(Root);
//    cout << endl;
//    return 0;
//}
#include<iostream>
#include<algorithm>
using namespace std;

struct AVLNode {
    int key, height;
    AVLNode *left, *right;
    AVLNode(int val) {
        key = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getbalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* insertAVL(AVLNode* root, int key) {
    if (!root) return new AVLNode(key);

    if (key < root->key)
        root->left = insertAVL(root->left, key);
    else if (key > root->key)
        root->right = insertAVL(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getbalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

   
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderAVL(AVLNode* root) {
    if (root) {
        inorderAVL(root->left);
        cout << root->key << " ";
        inorderAVL(root->right);
    }
}

int main() {
    AVLNode* avlRoot = nullptr;
    int arr[] = {40, 20, 30, 50, 25};
    for (int val : arr)
        avlRoot = insertAVL(avlRoot, val);

    cout << "AVL Inorder: ";
    inorderAVL(avlRoot);
    cout << endl;
    return 0;
}




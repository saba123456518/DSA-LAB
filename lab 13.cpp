

//part(A)

//#include<iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//	Node (int val){
//		data = val;
//		left = right = nullptr;
//	}
//};
//void inorder(Node* root){
//	if(root){
//	inorder(root->left)	;
//	cout<< root->data<<" ";
//	inorder(root->right);
//		
//			}
//}
//
//void preorder(Node* root){
//	if(root){
//	cout<< root->data<<" ";
//	preorder(root->left)	;
//	preorder(root->right);
//		
//	}
//}
//void postorder(Node* root){
//	if(root){
//
//	postorder(root->left);
//	postorder(root->right);
//	cout<< root->data<<" ";	
//	}
//}
//
//
//int main() {
//    
//     Node* root = new Node(10);
//     root->left = new Node(5);
//     root->right= new Node(15);
//     root->left->left = new Node(2);
//     root->left->right = new Node(7);
//     root->right->right = new Node(20);
//
//    cout << "Inorder Traversal: ";
//    inorder(root);
//    cout << "\nPreorder Traversal: ";
//    preorder(root);
//    cout << "\nPostorder Traversal: ";
//    postorder(root);
//    cout << endl;
//
//    return 0;
//}

//part (b)
//
//#include <iostream>
//#include  <vector>
//using namespace std;
//
//void DFS_Graph(int node, vector<vector<int>> &adj, vector<bool> &visited){
//	visited[node] = true;
//	cout << node << " ";
//	
//	for(int neighbor : adj[node]){
//		if(!visited[neighbor])
//			DFS_Graph(neighbor, adj, visited);
//	}
//}
//
//int main(){
//
//	int V = 5;
//	vector<vector<int>> adj(V);
//	
//	adj[0] = {1,2};
//	adj[1] = {0,3};
//	adj[2] = {0,4};
//	adj[3] = {1};
//	adj[4] = {2};
//	
//	vector<bool> visited(V, false);
//	cout << " DFS in Graph: " ;
//	DFS_Graph(0, adj, visited);
//	cout <<  endl;
//	return 0;
//
//
//
//}

//part (c);

//BFS TRAVERSAL IN TREE
//
//#include<iostream>
//#include<queue>
//using namespace std;
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//	Node (int val){
//		data = val;
//		left = right = nullptr;
//	}
//};
//
//void bfs (Node* root){
//	if (!root) return ;
//	queue<Node*> q;
//	q.push(root);
//	while (!q.empty()){
//	Node* cur = q.front ();
//	q.pop();
//	cout<<cur->data<<" ";
//	if(cur->left)q.push(cur->left);	
//	if(cur->right)q.push(cur->right);		
//		
//	}
//}
//
//   
//
//int main() {
//	 Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right= new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//
//    cout << "BFS in Tree: ";
//    bfs(root);
//    return 0;
//}

//part(D)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS_Graph(int start, vector<vector<int>> &adj, vector<bool>  &visited){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
while(!q.empty()){
int node = q.front();
	q.pop();
	cout << node << " ";
		
	for (int neighbor : adj[node]) {
	if(!visited[neighbor]){
	visited[neighbor] = true;
	q.push(neighbor);
			}
		}
	}
}

int main (){
	int V = 5;
	vector<vector<int>> adj(V);
	adj[0] = {1, 2};
	adj[1] = {1, 3};
	adj[2] = {0, 4};
	adj[3] = {1};
	adj[4] = {2};
	
	 vector<bool> visited(V, false);
    cout << "BFS in Graph: ";
    BFS_Graph(0, adj, visited); 
    cout << endl;

}














#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;

	Node(int data) {
		val = data;
		left = right = nullptr;
	}
};

class Functions {
public:
	void insert(Node* root, int data) {
		if (root->val > data) {
			if (root->left == nullptr) {
				root->left = new Node(data);
				return;
			}
			else 
				insert(root->left, data);
		}
		else if (root->val < data) {
			if (root->right == nullptr) {
				root->right = new Node(data);
				return;
			}
			else 
				insert(root->right, data);
		}
	}

	bool search(Node* root, int data) {
		if (root == nullptr) 
			return false;
		if (root->val == data) 
			return true;
		if (root->val > data) 
			return search(root->left, data);
		else 
			return search(root->right, data);
	}

	Node* deleteValue(Node* root, int data) {
		if (root == nullptr) return root;
		else if (root->val > data)
			root->left = deleteValue(root->left, data);
		else if (root->val < data)
			root->right = deleteValue(root->right, data);
		else {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else {
				Node* temp = root->right;
				while (temp->left != nullptr)
					temp = temp->left;
				root->val = temp->val;
				root->right = deleteValue(root->right, temp->val);
			}
		}
		return root;
	}

	void minInBST(Node* root) {
		if (root == nullptr) return;
		if (root->left == nullptr) {
			cout << root->val;
			return;
		}
		minInBST(root->left);
	}

	void maxInBST(Node* root) {
		if (root == nullptr) return;
		if (root->right == nullptr) {
			cout << root->val;
			return;
		}
		maxInBST(root->right);
	}

	void levelOrderTraversal(Node* root) {
		if (root == nullptr) return;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> level;
			for (int i = 0; i < size; i++) {
				Node* node = q.front();
				q.pop();
				if (node->left != nullptr) q.push(node->left);
				if (node->right != nullptr) q.push(node->right);
				level.push_back(node->val);
			}
			for (int val : level)
				cout << val << " ";
		}
		cout << endl;
	}

	int height(Node* root) {
		if (root == nullptr)
			return 0; 
	
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
	
		return 1 + max(leftHeight, rightHeight);
	}
};

int main() {
	Node* root = new Node(4);
	Functions f;

	f.insert(root, 2);
	f.insert(root, 6);
	f.insert(root, 1);
	f.insert(root, 3);
	f.insert(root, 5);
	f.insert(root, 7);

	cout << "Level Order Traversal:\n";
	f.levelOrderTraversal(root);

	int n;
	cout << "\nSearch Input: ";
	cin >> n;
	if (f.search(root, n)) 
		cout << "Present\n";
	else 
		cout << "Absent\n";

	root = f.deleteValue(root, 4);

	cout << "Level Order Traversal After Deletion:\n";
	f.levelOrderTraversal(root);

	cout << "Minimum in BST: ";
	f.minInBST(root);
	cout << endl;

	cout << "Maximum in BST: ";
	f.maxInBST(root);
	cout << endl;

	cout << endl;

	cout<<f.height(root);

	return 0;
}

#include <algorithm>

using namespace std;
typedef int KeyType;
typedef pair<Node*, Node*> NodePair;

struct Node{
	KeyType key;
	Node * left, * right;
	int priority, size;
	Node(const KeyType _key) :key(_key), priority(rand()), size(1), left(NULL), right(NULL){};
	int calcSize(){
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
		return size;
	}
	void setLeft(Node *newLeft){ left = newLeft; calcSize(); }
	void setRight(Node *newRight){ right = newRight; calcSize(); }

};

NodePair split(Node * root, KeyType key){
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->
}
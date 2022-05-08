#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int value;
	int depth;

public:
	Node() {
		parent = nullptr;
		value = 0;
		depth = 0;
	}

	friend class Tree;
};

class Tree {

public:
	Node* root;
	vector<Node*> nodeList;

	Tree() {
		root = new Node();
		root->value = 1;
		root->depth = 0;
		nodeList.push_back(root);
	}


	Node* find(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == x) {
				return nodeList[i];
			}
		}

		return nullptr;
	}

	void insert(int x, int y) {
		//���� ���� ����ó��
		Node* p = find(x);
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == y) {
				return;
			}
		}

		Node* c = new Node();
		//�ڽ��� ���� = �θ� ���� +1
		c->depth = p->depth + 1;
		c->parent = p;
		c->value = y;
		p->child.push_back(c);
		nodeList.push_back(c);
		

	}


	void preOrder(Node* n) {
		Node* p = n;

		cout << p->depth << " ";

		for (Node* a : p->child) {
			preOrder(a);
		}

	}


};


int main() {
	int order_num;


	cin >> order_num;

	

	for (int i = 0; i < order_num; i++) {
		//Ʈ�� �� for�� �ȿ� �־ Ʈ�� �ʱ�ȭ ��Ű��
		Tree* t = new Tree();
		int tree_num;
		cin >> tree_num;
		//Ʈ�� �Է��� �� 10�� �Է��ص� 9���� �Է¹ޱ�
		//��Ʈ�� �̹� ����?
		for (int j = 1; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert(a, b);
		}
		t->preOrder(t->root);
		cout << endl;
	}
}
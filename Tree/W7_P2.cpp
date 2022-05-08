#include<iostream>
#include<vector>
using namespace std;

class Node {
	Node* parent;
	vector<Node*>child;
	int value;

	Node() {
		parent = nullptr;
		value = 0;
	}
	friend class Tree;
};

class Tree {
public:
	Node* root;
	vector<Node*>nodeList;

	Tree() {
		root = new Node();
		root->value = 1;
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
		Node* p = find(x);

		Node* c = new Node();
		c->value = y;
		c->parent = p;
		p->child.push_back(c);
		nodeList.push_back(c);
	}

	int preOrder(int x) {
		//���� �Է��ϸ� �ű⿡ �´� ��� ã��
		Node* p = find(x);

		int file = 0;

		//�� �ڽ��� ũ�Ⱑ 0 �̴� = external��� �ϱ� file 1�߰�
		if (p->child.size() == 0) {
			file++;
		}

		//���� ��ȸ�ϸ鼭 file�� �����ֱ�
		for (Node* a : p->child) {
			file += preOrder(a->value);
		}

		return file;

	}

};

int main() {
	int tree_num, order;
	Tree* t = new Tree();
	
	cin >> tree_num >> order;

	for (int i = 1; i < tree_num; i++) {
		int a, b;
		cin >> a >> b;
		t->insert(a, b);
	}

	for (int i = 0; i < order; i++) {
		int a;
		cin >> a;
		cout << t->preOrder(a) << endl;
	}






}
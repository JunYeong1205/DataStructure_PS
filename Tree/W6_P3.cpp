#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int value;

public:
	Node() {
		parent = nullptr;
		value = 0;
	}

	friend class Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;


public:
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

		if (x == y) {
			return;
		}

		Node* p = find(x);

		if (p == nullptr) {
			cout << "-1" << endl;
		}

		else {
			Node* c = new Node();
			c->parent = p;

			for (int i = 0; i < nodeList.size(); i++) {
				if (nodeList[i]->value == y) {
					cout << "-1" << endl;
					return;
				}
			}
			c->value = y;
			p->child.push_back(c);
			nodeList.push_back(c);
		}

	}


	void Delete(int x) {
		Node* d = find(x);

		if (d == nullptr) {
			cout << "-1" << endl;
			return;
		}
		else if (d == root) {
			return;
		}
		else {

			Node* parentNode = d->parent;

			//���� ����� �ϱ�
			for (int i = 0; i < d->child.size(); i++) {
				parentNode->child.push_back(d->child[i]);
				d->child[i]->parent = parentNode;
			}

			//���� ����� �ϱ�
			for (int i = 0; i < parentNode->child.size(); i++) {
				if (d == d->parent->child[i]) {
					//�θ��� �θ��� �ڽ� �߿��� �ڽ��� ����+ i��° ����
					d->parent->child.erase(d->parent->child.begin() + i);
					break;
				}
			}

			//���� ����� �ϱ�
			//nodeList������ �Ȱ��� �۾�
			for (int i = 0; i < nodeList.size(); i++) {
				if (d == nodeList[i]) {
					nodeList.erase(nodeList.begin() + i);
					break;
				}
			}

			delete d;

		}
	}

	void parent(int x) {
		Node* newNode = find(x);
		//�������͸� x�� ���°Ŵϱ� -1
		if (newNode == nullptr) {
			cout << "-1" << endl;
		}
		//��Ʈ�� �ƹ��͵� ������
		else if (newNode == root) {
			return;
		}
		else {
			cout << newNode->parent->value << endl;
		}

	}

	void child(int x) {
		Node* p = find(x);

		if (p == nullptr || p->child.size() == 0) {
			cout << "-1" << endl;
			return;
		}

		for (int i = 0; i < p->child.size(); i++) {
			cout << p->child[i]->value << " ";
		}
		cout << endl;


	}

	void minChild(int x) {
		Node* p = find(x);
		int min = 10001;

		if (p == nullptr || p->child.empty()) {
			cout << "-1" << endl;
			return;
		}

		for (int i = 0; i < p->child.size(); i++) {
			if (p->child[i]->value < min) {
				min = p->child[i]->value;
			}
		}
		cout << min << endl;

	}

};


int main() {
	int order_num;
	string order;

	cin >> order_num;
	Tree* t = new Tree();


	for (int i = 0; i < order_num; i++) {
		cin >> order;

		if (order == "insert") {
			int x, y;
			cin >> x >> y;
			t->insert(x, y);
		}
		else if (order == "child") {
			int x;
			cin >> x;
			t->child(x);
		}
		else if (order == "delete") {
			int x;
			cin >> x;
			t->Delete(x);
		}
		else if (order == "parent") {
			int x;
			cin >> x;
			t->parent(x);
		}
		else if (order == "minChild") {
			int x;
			cin >> x;
			t->minChild(x);
		}
	}
}
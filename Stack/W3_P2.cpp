#include <iostream>
using namespace std;

class arrayStack {
private:
	char* arr;
	int capacity; // ������ �ִ� ũ��
	int topIndex;

public:
	arrayStack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
	};

	bool empty() {
		return (topIndex == -1);
	};

	// ������ ũ�⸦ ��ȯ
	int size() {
		return topIndex + 1; // topIndex�� -1�̹Ƿ�
	};

	// ������ top�� ����� ���Ҹ� ��ȯ
	char top() {
		return arr[topIndex]; // topIndex�� ���� ��ȯ
	};

	// ���ÿ� ���ο� ���Ҹ� ����
	void push(char data) {
		arr[++topIndex] = data; // topIndex 1 ������Ű�� �� ��ġ�� ���� ����
	};

	// ������ top�� ����� ���Ҹ� ����
	void pop() {
		cout << arr[topIndex];
		topIndex--; // topIndex 1 ����
	};
};

int main() {
	int n;
	cin >> n;

	for (int k = 0; k < n; k++) {
		string data;
		cin >> data;
		arrayStack as(data.size());

		for (int i = 0; i < data.size(); i++) {
			if(data[i] >= '1' && data[i] <= '9') {
				cout << data[i];
			}
			else if (data[i] == '*' || data[i] == '/') {
				while (!(as.empty() || as.top() == '+' || as.top() == '-')) {
					as.pop();
				}
				as.push(data[i]);
			}
			else if (data[i] == '+' || data[i] == '-') {
				while (!as.empty()) {
					as.pop();
				}
				as.push(data[i]);
			}
		}
		while (!as.empty()) {
			as.pop();
		}
		cout << endl;

	}
}
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int prizes[9] = { 23, 6, 11, 73, 35, 62, 27, 33, 56 };
	int target = 3;			//����°�� ���� �� ã��

	int size = 9;
	int i = 0;
	int j = 1;
	int start = 0;
	while (target != i) {
		while (j < size) {
			if (prizes[j] <= prizes[size - 1]) {
				swap(&prizes[i], &prizes[j]);
				i++;
			}
			j++;
		}
		if (target < i) {		//ã������ ���� ���ʿ� ���� ��
			start = i - 1;
			i = start;
			j = start;
		}
		else if (target > i) {		//ã������ ���� �����ʿ� ���� ��
			start = i;
			i = start;
			j = start;
		}
	}
	

	return 0;
}
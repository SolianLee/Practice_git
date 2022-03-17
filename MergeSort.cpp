/*
#include <iostream>
using namespace std;

int sorted[8] = { 0, };
void merge(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {		//�� subarr ��. 
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid) {		//i�� mid���� Ŀ���� �Ҹ��� mid �����ʿ� ���� �����ִٴ� ��.
		for (int t = j; t <= right; t++) {
			sorted[k++] = arr[t];
		}
	}
	else {				//i�� mid���� �۰ų� ���ٴ� ���� mid ���ʿ� ���� �����ִٴ� ��.
		for (int t = i; t <= mid; t++) {
			sorted[k++] = arr[t];
		}
	}

	//���ĵ� ���� �ӽ÷� ������ sorted �迭���� arr�� �� ����
	for (int t = left; t <= right; t++) {
		arr[t] = sorted[t];
	}
}

void merge_sort(int arr[], int left, int right) {
	int mid = 0;

	if (left < right) {		//�Ѿ�� �迭�� left�� right���� ������ -> left==right�̸� ���Ұ� �ϳ���� ���̹Ƿ� ����X
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);			//������ �ڸ� �պκ� ����
		merge_sort(arr, mid + 1, right);	//������ �ڸ� �޺κ� ����
		merge(arr, left, mid, right);		//�ΰ��� subarr ����
	}
}

int main() {
	int arr[8] = { 21,10,12,20,25,13,15,22 };

	merge_sort(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
*/
// Learn: https://youtu.be/COk73cpQbFQ

#include<bits/stdc++.h>
using namespace std;

int Partition(vector<int> &v, int start, int end) {
	int pivot = v[end]; // let pivot is right most element
	int partitionIndex = start;

	for (int i = start; i < end; i++) {
		if (v[i] <= pivot) {
			swap(v[i], v[partitionIndex]);
			partitionIndex++;
		}
	}

	swap(v[partitionIndex], v[end]); // swap pivot with element at the partitionIndex
	return partitionIndex;
}

void QuickSort(vector<int> &v, int start, int end) {
	if (start < end) {
		int partitionIndex = Partition(v, start, end);
		QuickSort(v, start, partitionIndex - 1);
		QuickSort(v, partitionIndex + 1, end);
	}
}

int main() {
	vector<int> v{3, 7, 1, 5, 8, 4, 2, 6};

	QuickSort(v, 0, 7);

	for (int i = 0; i < 8; i++)
		cout <<  v[i] << ' ';
}

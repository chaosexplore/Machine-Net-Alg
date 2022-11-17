#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

int bSearch(vector<int>&vec, int left, int right, int key) {
	if (right <= left) {
		if (key != vec[left])	return -1;
		
		return left;
	}
	
	int mid = left + (right - left) / 2;
	
	if (key == vec[mid])
		// TODO
		return mid;
	if (key < vec[mid])
		return bSearch(vec, left, mid - 1, key);
	if (key > vec[mid])
		return bSearch(vec, mid + 1, right, key);
}

int binarySearch(vector<int>&vec, int left, int right, int key) {
	return bSearch(vec, left, right-1, key);
}

// ==
int bsearch1 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] < key) {
			low = mid + 1;
		}
		else if (vec[mid] > key) {
			high = mid - 1;
		}
		else
			return mid;
	}

	return -1;
}

// first ==
int bsearch1_1 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] < key) {
			low = mid + 1;
		}
		else if (vec[mid] > key) {
			high = mid - 1;
		}
		else {
			if (mid == 0 || vec[mid-1] != key)	return mid;
			high = mid -1;	
		}
	}

	return -1;
}

// last ==
int bsearch1_2 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] < key) {
			low = mid + 1;
		}
		else if (vec[mid] > key) {
			high = mid - 1;
		}
		else {
			if(mid == vec.size()-1 || vec[mid+1] != key)	return mid;
			low = mid + 1;
		}
	}

	return -1;
}

// firt >=
int bsearch2 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] >= key) {
			if (mid == 0 || vec[mid-1] < key)	return mid;
			high = mid-1;
		}	
		else
			low = mid + 1;
	}

	return -1;
}

// first >
int bsearch3 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] > key) {
			if (mid == 0 || vec[mid-1] <= key)	return mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return -1;
}

// last <=
int bsearch4 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] <= key) {
			if (mid == vec.size()-1 || vec[mid+1] > key)	return mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return -1;
}

// last <
int bsearch5 (vector<int>&vec, int key) {
	if (vec.size() == 0) return -1;

	int low = 0, high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] < key) {
			if (mid == vec.size()-1 || vec[mid+1] >= key)	return mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return -1;
}

int main() {
	vector<int> nums;
	for (int i = 0; i < 10000; i = i+2) {
		nums.push_back(i);
		nums.push_back(i);
	}
	int key = 7998;

	typedef int (*func)(vector<int>&, int);
	auto fn = [&](func f){
		auto ret = f(nums, key);
		if (ret != -1)
			cout << ret << " -> " << nums[ret] << endl;
		else
			cout << "NONE" << endl;
	 };

	fn(&bsearch1);	
	fn(&bsearch1_1);	
	fn(&bsearch1_2);	
	fn(&bsearch2);	
	fn(&bsearch3);	
	fn(&bsearch4);	
	fn(&bsearch5);

	return 0;
}
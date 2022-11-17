#include <iostream>
#include <vector>
#include "ctimer.h"

using namespace std;

class ISolution {
public:
    virtual ~ISolution() = default;
    virtual void method() = 0;
};

class SolutionsManager {
public:
	virtual ~SolutionsManager() {
		for (auto x : solutions_) {
			if (x)	delete x;
		}
	}
	void addSolution(ISolution* s) {
		solutions_.push_back(s);
	}

	void execute() {
		for (auto x : solutions_) {
			auto t1 = t_now();
			x->method();
			auto t2 = t_now();
			t_cal_echo(t1, t2);
		}

	}
private:
	vector<ISolution*> solutions_;	
};

#pragma pack(1)
class A {
	char a;
	void foo();
};

class A1 {

};

class A2 {
	void foo();
};

class B {
	int b;
	virtual void foo();
	virtual void bar();
};

class C : public B {
	static int c;
	int b;
	void foo() { int a = 1*2;}
	void bar(){ int a = 1*2;}
	int baar();
};

class D : virtual C {
	int b;
};


class Solution : public ISolution {
public:
	void method() {
		cout << sizeof(A) << endl;
		cout << sizeof(A1) << endl;
		cout << sizeof(A2) << endl;
		cout << sizeof(B) << endl;
		cout << sizeof(C) << endl;
		cout << sizeof(D) << endl;
	}
};


int bSearch(vector<int>&vec, int left, int right, int key) {
	if (right <= left) {
		if (key != vec[left])	return -1;
		
		return left;
	}
	
	int mid = left + (right - left) / 2;
	
	if (key == vec[mid])
		return mid;
	if (key < vec[mid])
		return bSearch(vec, left, mid - 1, key);
	if (key > vec[mid])
		return bSearch(vec, mid + 1, right, key);
}

int binarySearch(vector<int>&vec, int left, int right, int key) {
	return bSearch(vec, left, right-1, key);
}

int main()
{
	SolutionsManager s;
	s.addSolution(new Solution());
	s.execute();
	
	int key;
	cin >> key;
	vector<int> t;
	for (int i = 0; i < 10000; ++i) t.push_back(i);
	int ret = binarySearch(t, 0, t.size(), key);
	cout << ret << " -> ";
	if (ret == -1) cout << "none" << endl;
	else cout << t[ret] << endl;

    cin.get();

    return 0;
}

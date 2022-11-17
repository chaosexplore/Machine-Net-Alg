#include <iostream>
#include <vector>
#include <string>
#include <bitset>
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

class Solution : public ISolution{
public:
	void method() {
		unsigned int num;
		cout << "input hex: ";
		cin >> num;
		print_binary(num);
		cout << count(num) << endl;

		string bs;
		cout << "input binary :";
		cin >> bs;
		print_hex(bs);
	}

	// count 1
	int count(unsigned int num) {
		int sum = 0;
		while (num) {
			if (num % 2)	++sum;
			num /= 2;
		}

		return sum;
	}

	void print_binary(unsigned int num) {
		string s;
		while (num) {
			if (num % 2) s.push_back('1');
			else s.push_back('0');

			num /= 2;
		}

		for (int i = s.size()-1; i >= 0; --i) {
			cout << s[i];
		}
		cout << endl;
	}

	void print_hex(string& s) {
		int h = 0;
		for (auto t : s) {
			if (t == '1') {
				h = 2*h + 1;
			}
			else if (t == '0') {
				h = 2*h;
			}
			else {
				break;
				cout << "not a normal binary." << endl;
			}
		}

		cout << h << endl;
	}
};

class Solution2 : public ISolution{
public:
	void method() {
		unsigned int num;
		cin >> num;
		cout << bitset<32>(num) << endl;
		cout << count(num) << endl;
	}

	// count 1
	int count(unsigned int num) {
		int sum = 0;
		for(int i = 0; i < 32; ++i) {
			if (num >> i & 1) ++sum;
			//num = num >> 1;
		}

		return sum;
	}
};

int main()
{
	SolutionsManager s;
	s.addSolution(new Solution());
	s.addSolution(new Solution2());
	s.execute();
	
    cin.get();

    return 0;
}

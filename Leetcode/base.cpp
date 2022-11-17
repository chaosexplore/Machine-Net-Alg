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

class Solution : public ISolution{
public:
	void method() {
		
	}
};

int main()
{
    vector<int> in;
    int myint = 0;

    while(1) {
    	cin >> myint;
		if (myint == -99) break;
		in.push_back(myint);
    }     

	//generateVec(in, 1000000, 100000);

	// solution execute
	SolutionsManager s;
	s.addSolution(new Solution());
	s.execute();
	
    cin.get();

    return 0;
}

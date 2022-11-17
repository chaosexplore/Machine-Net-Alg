#include <iostream>
#include <vector>
#include <string>
#include "ctimer.h"

using namespace std;

class ISolution {
public:
    virtual ~ISolution() = default;
    virtual vector<vector<string>> method(int n) = 0;
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

	void execute(int n) {
		for (auto x : solutions_) {
			auto t1 = t_now();
			auto ret = x->method(n);
			auto t2 = t_now();
			t_cal_echo(t1, t2);
		}

	}
private:
	vector<ISolution*> solutions_;	
};


class Solution : public ISolution{
private:
    vector<int> cols;
    static constexpr char NOP = '.';
    static constexpr char ISP = 'Q';
public:
    vector<vector<string>> method(int n) {
        cols = vector<int>(n, -1);
        vector<vector<string>> ret;
        recuseCall(ret, 0, n);
        
        return ret;
    }

    bool isOK(int row) {
		for (int i = row - 1, j = 1; i >= 0; --i, ++j) {
			if (cols[row] == cols[i]) return false;
			if (cols[i] == cols[row] - j || cols[i] == cols[row] + j)	return false;
		}
        return true;
    }

    void recuseCall (vector<vector<string>>& ret, int row, int n) {
        if (row == n) {print(ret, n); return;}
        for (int i = 0; i < n; ++i) {
            cols[row] = i;
            if (isOK(row))
                recuseCall(ret, row+1, n);
        }
    }

    void print(vector<vector<string>>& ret, int n) {
		vector<string> vec;
		string s;
		for (int i = 0; i < n; ++i) {
			s.clear();
			for (int j = 0; j < n; ++j) {
				if (cols[i] != j)  s.push_back(NOP);
				else  s.push_back(ISP);
			}
			vec.emplace_back(s);
		}

		ret.emplace_back(vec);
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
	s.execute(4);
	
    cin.get();

    return 0;
}

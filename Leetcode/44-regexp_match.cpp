#include <iostream>
#include <vector>
#include <string>
#include "ctimer.h"

using namespace std;

class ISolution {
public:
    virtual ~ISolution() = default;
    virtual bool isMatch(string s, string p) = 0;
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

	void execute(string& s, string& p) {
		for (auto x : solutions_) {
			auto t1 = t_now();
			auto ret = x->isMatch(s, p);
			cout << ret << endl;
			auto t2 = t_now();
			t_cal_echo(t1, t2);
		}

	}
private:
	vector<ISolution*> solutions_;	
};

class Solution : public ISolution{
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> state (n+1, 0);

        int tik;
        state[0] = true;
        for (int i = 0; i < m; ++i) {
            tik = n;
            
            for (int j = n - 1; j >= 0; --j) {
                if (state[j] || 0 == i) {
                    if (p[i] == '*') {
                        for (int k = j; k <= tik; ++k)
                            state[k] = true;

                        tik = j;
                    }
                    else {
                        if (p[i] == '?' || p[i] == s[j]) {
                            state[j] = true;
                        }
                        else {
                            state[j] = false; 
                        }
                    }
                }
                else
                    state[j+1] = false;
            }
        }

        return state[n];
    }
};

int main()
{
    string str, p;

	cin >> str;
	cin >> p;

	// solution execute
	SolutionsManager s;
	s.addSolution(new Solution());
	s.execute(str, p);
	
    cin.get();

    return 0;
}

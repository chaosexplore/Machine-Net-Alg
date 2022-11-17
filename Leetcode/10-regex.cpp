#include <iostream>
#include <vector>
#include <string>
#include <map>
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
		cout << "result is : " << (isMatch("abcdddb", "abcf*d*.") ? "True" : "False") << endl;		
		cout << "result is : " << (isMatch("abcc", "abc.") ? "True" : "False") << endl;		
		cout << "result is : " << (isMatch("abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*") ? "True" : "False") << endl;		
		cout << "result is : " << (isMatch("aaa", "a*a") ? "True" : "False") << endl;		
	}

private:
    map<pair<int, int>, bool> memo;

public:
    
	bool isMatch(string s, string p) {
		return match_pos(s, 0, p, 0);
	}

	bool match_pos(string&s, int pos1, string& p, int pos2) {
        auto key = make_pair(pos1, pos2);
        if (memo.find(key) != memo.end())  return memo[key];

		bool isany = pos2 < p.size()-1 ? (p[pos2+1] == '*') : false;
		// reach the end
		if (pos1 == s.size() || pos2 == p.size()) {
			if (pos1 == s.size() && pos2 == p.size()) {
                memo[key] = true;
                return true;
            }
			else {
                if (isany)  return match_pos(s, pos1, p, pos2+2);
                else {
                        memo[key] = false;
                        return false;
                    }
            }
		}

		// recurse pair

        if (isany) {
            bool ret = match_pos(s, pos1, p, pos2+2); // skip
            
            if (!ret && (s[pos1] == p[pos2] || p[pos2] == '.')) {
                ret = ret || match_pos(s, pos1+1, p, pos2+2); // stop
                ret = ret || match_pos(s, pos1+1, p, pos2); // continue p
            }
            memo[key] = ret;
            return ret;
        }
        else {
            if (s[pos1] == p[pos2] || p[pos2] == '.')   return match_pos(s, pos1+1, p, pos2+1);
            else {
                memo[key] = false;   
                return false;
            }
        }
	}
};

int main()
{
	//generateVec(in, 1000000, 100000);

	// solution execute
	SolutionsManager s;
	s.addSolution(new Solution());
	s.execute();
	
    cin.get();

    return 0;
}

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

class Solution1 : public ISolution {
public:
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i);
            }
            return seed;
        }
    };

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<short, vector<vector<int>>> h;
        h[0] = {{}};

        short max = candidates[0];
        for (int i = 1; i <= target; ++i) {
            vector<vector<int>> tmp;
            for (auto t : candidates) {
                if (t > max) max = t;
                auto p = i - t;
                if (p >= 0) {
                    for (auto it : h[p]) {
                        it.push_back(t);
                        tmp.emplace_back(it);
                    }
                }
            }
            h.emplace(i, tmp);
        }

        // dedup
        unordered_set<vector<int>, VectorHash> note;
        for (auto& t : h[target]) {
            vector<int> tmp(204, 0);
            for (auto num : t) {
                ++tmp[num];
            }
            note.emplace(tmp);
        }
        
        vector<vector<int>> ret;
        for (auto& t : note) {
            vector<int> tmp;
            for (int i = 0; i < t.size(); ++i) {
                int tim = t[i];
                while (tim) {
                    tmp.push_back(i);
                    --tim;
                }
            }
            ret.emplace_back(tmp);
        }

        return ret;
    }
};

class Solution2 : public ISolution{
private:
    static const unsigned int bitsize = 204;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<short, unordered_set<bitset<bitsize>>> h;
        {
            bitset<bitsize> bt;
            h.emplace(0, unordered_set<bitset<bitsize>>{bt});
        }

        for (int i = 1; i <= target; ++i) {
            unordered_set<bitset<bitsize>> tmp;
            for (auto t : candidates) {
                auto p = i - t;
                if (p >= 0) {
                    for (auto it : h[p]) {
                        it.set(t);
                        tmp.emplace(it);
                    }
                }
            }
            h.emplace(i, tmp);
        }

        // dedup
        vector<vector<int>> vec;
        for (auto& t: h[target]) {
            vector<int> tmp;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i])   tmp.push_back(i);
            }
            vec.emplace_back(tmp);
        }

        return vec;
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
	s.addSolution(new Solution1());
	s.addSolution(new Solution2());
	s.execute();
	
    cin.get();

    return 0;
}

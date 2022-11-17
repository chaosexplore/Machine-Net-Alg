#include <iostream>
#include <vector>
#include <limits.h>
#include "ctimer.h"

using namespace std;

class ISolution {
public:
    virtual ~ISolution() = default;
    virtual int coinChange(vector<int>& coins, int amount) = 0;
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

	void execute(vector<int>& coins, int amount) {
		int ret = 0;

		for (auto x : solutions_) {
		    auto t1 = t_now();
			ret = x->coinChange(coins, amount);	
    		auto t2 = t_now();
    		t_cal_echo(t1, t2);
            cout << ret << endl;
	    }
	}
private:
	vector<ISolution*> solutions_;	
};

class Solution1 : public ISolution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (coins.size() < 1) return -1;
        if (amount <= 0) return 0;

        // states
        int** states = new int*[coins.size()];
        for (int i = 0; i < coins.size(); ++i) {
            *(states + i) = new int[amount+1]{0};
        }

        // initialize
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                states[i][j] = amount + 1;
            }
        }

        for (int i = 1; i <= amount; ++i) {
            if (i % coins[0] == 0)
                states[0][i] = i / coins[0];
        } 

        // caculae
        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                int t = j / coins[i];
                for (int h = 0; h <= t; ++h) {
                    int re = j - h*coins[i];
                    if (states[i-1][re] + h < states[i][j])
                        states[i][j] = states[i-1][re] + h;
                }
            }
        }

        // get min
        int ret = -1;
        if(states[coins.size()-1][amount] <= amount)
            ret = states[coins.size()-1][amount];
        
        for (int i = 0; i < coins.size(); ++i) {
            delete [] *(states + i);
        }
        return ret;
    }
};

class Solution2 : public ISolution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // states
        vector<int> states(amount+1, amount+1);
        // initialize
        states[0] = 0;
        
        // caculae
        for (int i = 1; i <= amount; ++i) {
            int min = states[i];
            for (auto t : coins) {
                if (i < t ) continue;

                if (min > states[i-t] + 1)
                    min = states[i-t] + 1;
            }
            states[i] = min;
        }

        // get min
        if(states[amount] <= amount)
            return states[amount];
        else
            return -1;
    }
};

class Solution3 : public ISolution {
public:
    vector<int> states_;
    int MAX;
    int coinChange(vector<int>& coins, int amount) {
        if (0 == amount) return 0;

        states_.resize(amount+1);
        MAX = amount + 1;
        states_ = vector<int>(amount+1, MAX);

        int ret = dp(coins, amount);
        return ret > amount ? -1 : states_[amount];
    }

    int dp(vector<int>& coins, int m) {

        if (0 == m) 
            return 0;
        if (states_[m] < MAX) 
            return states_[m];

        int min = states_[m], tmp = 0;
        for(auto t : coins) {
            if (t > m) continue;    
            tmp = dp(coins, m-t) + 1;
            if (min > tmp)
                min = tmp;
        }

        states_[m] = min == MAX ? -1 : min;
        return states_[m];
    }
};

int main()
{
    vector<int> in;
    int myint = 0;
    
    int amount = 0;
    cin >> amount;

    while(1) {
    	cin >> myint;
		if (myint == -99) break;
		in.push_back(myint);
    }     

	SolutionsManager s;
    s.addSolution(new Solution1());
    s.addSolution(new Solution2());
    s.addSolution(new Solution3());
    s.execute(in, amount);
	
    cin.get();

    return 0;
}

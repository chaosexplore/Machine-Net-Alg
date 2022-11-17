#ifndef __CTIMER_H_
#define __CTIMER_H_

#include<chrono>
#include<iostream>
#include<vector>
#include<cstdlib>

using std::cout;
using std::endl;
using std::vector;
using namespace std::chrono;

typedef high_resolution_clock::time_point t_type;

static inline t_type t_now()
{
	return high_resolution_clock::now();
}


static inline double t_cal(t_type& t1, t_type& t2)
{
	return duration<double, std::milli>(t2 - t1).count();
}

static inline void t_cal_echo(t_type& t1, t_type& t2)
{
	auto t = duration<double, std::milli>(t2 - t1);
	cout << "time cost : " << t.count() << "  ms" << endl;
}

static void generateVec(vector<int>& in, int n, int range)
{
	for (int i = 0; i < n; ++i) {
		in.emplace_back(rand() % range + 1);
	}
}

static void checkVecOrder(vector<int>& in)
{
	bool ret = true;
	
	if (in.size() > 2) {
		if (in[0] <= in[1])
			[&](){ for(int i = 1; i < in.size()-1; ++i) if(in[i] > in[i+1]) ret = false;};
	    else
			[&](){ for(int i = 1; i < in.size()-1; ++i) if(in[i] < in[i+1]) ret = false;};
	}
	
	if (ret)
		cout << endl << "Sorted !!" << endl;
	else
		cout << endl << "Not Sorted !!" << endl;
}


#endif   // __CTIMER_H_
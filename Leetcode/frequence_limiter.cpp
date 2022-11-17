class limiter {
private :
	queue <time_t> seqs;
	
public ：
	bool check(int k) {
		static int count = 0;
		
		// add counter
		++count;
		seqs.push (t);
		time_t t = now(), pre = t;
		
		// erase count 1s before
		if (!seqs.empty())	pre = seqs.front();
		while (t - pre > 1second){
			--count;
			seqs.pop();
			if (!seqs.empty())	pre = seqs.front();
		}
		
		// check frequnce
		if (count > k)
			return false;
		else
			return true;
	}
}
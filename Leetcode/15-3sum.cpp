class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if(nums.size() < 3) return ret;

        int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for(auto& t : nums) {
            if (t > max) max = t;
            if (t < min) min = t;
        }

        if (max < 0) return ret;
        int offset = abs(min);
        size_t n = max + offset + 1;
        
        char* bit = (char*)calloc(n,sizeof(char));
        //memset(bit, 0, sizeof(char)*n);
        //cout << n <<endl;
        //for(int i = 0; i < n; ++i) {
        //    bit[i]=1;
        //}
        for(auto& t : nums) {
            if (bit[t+offset] < 3)
                ++bit[t+offset];
        }

        int i, j, k, t1, t2;
        for(i = 0; i <= offset; ++i) {
            //if(i > offset) break;
            t1 = bit[i];
            if (t1 <= 0)
                continue;

            //cout << t1 <<endl;
            j = i + (t1 == 1 ? 1 : 0);
            for (; j < n; ++j) {
                if (i + j > 2*offset) break;

                t2 = bit[j];
                if (t2 <= 0) 
                    continue;
                    
                int k = 3*offset - i - j;
                int m = j - (t2 == 1 ? 0 : 1);
                if(j == i && t2 <= 2) m = j;
                //cout << i << j<< k<<endl;
                if (k > m && k < n && bit[k] > 0)
                    ret.push_back({i - offset, j - offset, k - offset});
            }
        }

        return ret;
    }
};

class BitMap
{
	public:
		BitMap(size_t n, int s=1) {
			ptr = new char[n*s/8 + 1];
            memset(ptr, 0, sizeof(char)*(n*s/8 + 1));
            bits_num = n;
            step = s;
		}
		
		~BitMap() {
			delete[] ptr;
		}
		
		int get(size_t k) {
			if (k > bits_num) return false;
            k *= step;
			int byteIndx = k / 8;
			int bitIndx = k % 8;
            
            int num = 0, i = 0;
            while(i < step) {

                if (ptr[byteIndx] & 1 << bitIndx)
                    ++num;
                else
                    break;

                ++i;
                ++bitIndx;
                byteIndx += bitIndx / 8;
                bitIndx %= 8;
            }
			return num;
		}
		
        // support set multiple times. consider char array or int array ...
		void set(size_t k) {
			if (k > bits_num) return;
            k *= step;
			int byteIndx = k / 8;
			int bitIndx = k % 8;

            int i = 0;
            while(i < step) {

                if (ptr[byteIndx] & 1 << bitIndx)
                    ++i;
                else {
                    ptr[byteIndx] |= 1 << bitIndx;
                    break;
                }

                ++bitIndx;
                byteIndx += bitIndx / 8;
                bitIndx %= 8;
            }
		}

        void reset(size_t k) {
			if (k > bits_num) return;
			int byteIndx = k / 8;
			int bitIndx = k % 8;
			ptr[byteIndx] &= ~(1 << bitIndx);
		}

	private:
		size_t bits_num;
        int step;   // step bits for one element
		char* ptr;
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if(nums.size() < 3) return ret;

        int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for(auto& t : nums) {
            if (t > max) max = t;
            if (t < min) min = t;
        }

        int offset = abs(min);
        size_t n = max + offset + 1;

        BitMap bit(n,3);

        for(auto& t : nums) {
            bit.set(t + offset);
        }

        int i, j, k, t1, t2;
        for(i = 0; i < n; ++i) {
            t1 = bit.get(i);
            if (t1 <= 0)
                continue;

            j = i + (t1 == 1 ? 1 : 0);
            for (; j < n; ++j) {
                t2 = bit.get(j);
                if (t2 <= 0) 
                    continue;
                    
                int k = 3*offset - i - j;
                int m = j - (t2 == 1 ? 0 : 1);
                if(j == i && t2 == 2) m = j;
                if (k > m && bit.get(k) > 0)
                    ret.emplace_back(vector<int>{i - offset, j - offset, k - offset});
            }
        }

        return ret;
    }
};


class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        std::sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i < nums.end(); ++i) {
            if (*i > 0) break;
            if (i > nums.begin() && *i == *(i-1))  continue;

            auto j = i+1;
            auto t = nums.end() - 1;
            while (j < t) {
                if (*i + *j > 0) break;
                int sum = *i + *j + *t;

                if (sum > 0)    --t;
                else if (sum < 0) ++j;
                else {
                    ret.emplace_back(vector<int>{*i, *j, *t});
                    //ret.push_back({*i, *j, *t});
                    while (j < t && *j == *(j+1)) ++j;  // mark
                    while (j < t && *t == *(t-1)) --t;

                    ++j;
                    --t;
                }
            }
        }

        return ret;
    }
};
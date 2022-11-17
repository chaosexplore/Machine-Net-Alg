#ifndef __BITMAP__
#define __BITMAP__

class BitMap
{
	public:
		BitMap(size_t n) {
			ptr = new char[n/8 + 1];
			memset(ptr, 0, sizeof(char)*(n/8 + 1));
            bits_num = n;
		}
		
		~BitMap() {
			delete[] ptr;
		}
		
		bool get(size_t k) {
			if (k > bits_num) return false;
			int byteIndx = k / 8;
			int bitIndx = k % 8;
			return (ptr[byteIndx] & 1 << bitIndx) != 0;
		}
		
		void set(size_t k) {
			if (k > bits_num) return;
			int byteIndx = k / 8;
			int bitIndx = k % 8;
			ptr[byteIndx] |= 1 << bitIndx;
		}

        void reset(size_t k) {
			if (k > bits_num) return;
			int byteIndx = k / 8;
			int bitIndx = k % 8;
			ptr[byteIndx] &= ~(1 << bitIndx);
		}

	private:
		size_t bits_num;
		char* ptr;
};


class StepBitMap
{
	public:
		StepBitMap(size_t n, int s=1) {
			ptr = new char[n*s/8 + 1];
            memset(ptr, 0, sizeof(char)*(n*s/8 + 1));
            bits_num = n;
            step = s;
		}
		
		~StepBitMap() {
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

#endif __BITMAP__
class Solution {
public:
	/*
	int hammingDistance(int x, int y) {
		int xor_x_y = x ^ y;
		int res = 0;
		for(int i = 0; i < 32 ; i++){
			if(xor_x_y & (1<<i)){
				res++;
			}
		}
		return res;
	}
	*/
	int hammingDistance(int x, int y) {
		int xor_x_y = x ^ y;
		int res = 0;
		while(xor_x_y){
			res++;
			xor_x_y &= (xor_x_y - 1);
		}
		return res;
	}
};
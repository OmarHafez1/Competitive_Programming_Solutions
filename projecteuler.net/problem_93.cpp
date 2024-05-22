#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll
#define EPS .000000001

set<int> st;
void go(vector<ld> nums) {
	if(nums.size() == 1) {
		ld tmp = nums[0];
		if(ceil(tmp) == floor(tmp) && tmp > 0)
			st.insert(tmp);
		else {
			tmp+=EPS;
			if(ceil(tmp) == floor(tmp) && tmp > 0) {
				st.insert(tmp);
			}
		}
		return;
	}
	for(int i = 0; i < nums.size(); i++) {
		for(int j = i+1; j < nums.size(); j++) {
			auto tmp = nums;
			ld x = nums[i];
			ld y = nums[j];
			tmp.erase(tmp.begin()+j);
			tmp.erase(tmp.begin()+i);
			tmp.push_back(x+y);
			go(tmp);
			tmp.back() = x-y;
			go(tmp);
			tmp.back() = y-x;
			go(tmp);
			tmp.back() = x*y;
			go(tmp);
			if(y) {
				tmp.back() = x/y;
				go(tmp);
			}
			if(x) {
				tmp.back() = y/x;
				go(tmp);
			}
		}
	}
}

signed main() {
	int mx = 1, ans = 1;
	for(ld a = 1; a <= 9; a++) {
		for(ld b = a+1; b <= 9; b++) {
			for(ld c = b+1; c <= 9; c++) {
				for(ld d = c+1; d <= 9; d++) {
					st.clear();
					vector<ld> tmp = {a, b, c, d};
					go(tmp);
					int ind = 1;
					for(auto &x : st) {
						if(x != ind) {
							if(x > mx) {
								ans = a*1000+b*100+c*10+d;
								mx = x;
							}
							break;
						}
						ind++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}

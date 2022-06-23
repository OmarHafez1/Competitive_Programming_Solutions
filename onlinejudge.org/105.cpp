/* 
**
**   author:  Omar_Hafez
**   created: 29 May 2022 (Sunday)  10:16:54 PM
**
*/
 
#include <bits/stdc++.h>
using namespace std;

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(NULL); 

	vector<int> a(50000);
	int l, r, h, start = INT_MAX, end = 0;
	while(cin >> l >> h >> r) {
		end = max(end, r);
		start = min(start, l);
		for(int i = l; i < r; i++) {
			a[i] = max(h, a[i]);
		}
	}
	cout << start << " " << a[start] << " ";
	for(int i = start+1; i < end; i++) {
		if(a[i] != a[i-1]) {
			cout << i << " " << a[i] << " ";
		}
	}

	cout << end << " 0\n";
	
}
	 
	 
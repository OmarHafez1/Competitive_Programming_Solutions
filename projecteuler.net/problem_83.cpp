//======================================================
// Author      : Omar_Hafez
// Created     : 12 December 2022 (Monday)  6:13:37 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define N 80
#define INF 2e9

vector<int> split(const string& str, const string& delim) {
  vector<int> tokens;
  size_t prev = 0, pos = 0;
  do {
      pos = str.find(delim, prev);
      if (pos == string::npos) pos = str.length();
      string token = str.substr(prev, pos-prev);
      if (!token.empty()) tokens.push_back(stoi(token));
      prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}


vector<vector<int>> a(N);
vector<vector<int>> paths;

int x[] = {1, 0, 0, -1};
int y[] = {0, 1, -1, 0};

void dik(int i, int j, int val) {
    if(i < 0 || j < 0 || i >= N || j >= N) return;
    if(val + a[i][j] < paths[i][j]) {
        paths[i][j] = val+a[i][j];
        for(int k = 0; k < 4; k++) {
            dik(i+x[k], j+y[k], paths[i][j]);
        }
    }
}

signed main() { 
    paths = vector<vector<int>> (N, vector<int>(N, INF));
    string tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        a[i] = split(tmp, ",");
    }
    dik(0, 0, 0);
    cout << paths.back().back();
}

/*
  ▐ ▌  ▐ ▌
 ▐▌ ▐▌▐▌ ▐▌
 █▄▀▄██▄▀▄█
  ▄  ██▌ ▄
▄▀ █▀██▀█ ▀▄
▐▌▐▌ ▐▌ ▐▌▐▌
 ▐ █    █ ▌
    ▌  ▐
*/


     
     
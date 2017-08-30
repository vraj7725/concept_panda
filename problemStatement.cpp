#include <bits/stdc++.h>
using namespace std;
int countt;
// this is stack for storing data pairwise 
stack<pair<int, int>> s;
//c1 - 5
//c2 - 3

int arr[6][4];

//bool function return always 1 ya 0 
bool getSol(int c1, int c2) {
	if(c1 + c2 == 4)
		return true;
	if(arr[c1][c2])
		return false;
	arr[c1][c2] = 1;
	// cout<<c1<<" "<<c2<<endl;
	if(c1 && !c2) {
		int t1 = 0, t2 = 0;
		t1 = c1;
		t2 = min(3,t1);
		t1 -= t2;
		if (getSol(t1,t2)) {
		 	s.push(make_pair(1,2));
			return true;
		}
	}
	if(c1 && !c2) {
		int t1 = 0, t2 = 0;
		t2 = c2;
		t1 = min(5,t2);
		t2 -= t1;
		if (getSol(t1,t2)) {
			s.push(make_pair(2,1));
			return true;
		}
	}
	if (c1 && c2) {
		int t1 = 0, t2 = 0;
		t1 = c1;
		t2 = c2;
		// cout<<"Here\n";
		int temp = min(t1, 3-t2);
		t2 += temp;
		t1 -= temp;
		if (getSol(t1,t2)) {
			s.push(make_pair(2,1));
			return true;
		}
		temp = min(t2,5-t1);
		t1 += temp;
		t2 -= temp;
		if (getSol(t1,t2)) {
			s.push(make_pair(1,2));
			return true;
		}	
	}
	if (c1!=5) {
		if (getSol(5,c2)) {
			s.push(make_pair(3,1));
			return true;
		}
	}
	if (c2!=3) {
		if (getSol(c1,3)) {
			s.push(make_pair(3,2));
			return true;
		}
	}
	
	if (c1) {   
		if (getSol(0,c2)) {
			s.push(make_pair(1,3));
			return true;
		}
	}
	if (c2) {   
		if (getSol(c1,0)) {
			s.push(make_pair(1,3));
			return true;
		}
	}
	return false;
}

int main() {
	/* this is basically 2d matrix for retrieving the values */
	int cup1 = 0, cup2 = 0;
	for(int i = 0; i < 6; i ++) { 
		for(int j = 0; j < 4; j ++)
			arr[i][j] = 0;
	}
	// string for printing 
	string sa[3];
	sa[0] = "Cup1";
	sa[1] = "Cup2";
	sa[2] = "Sink";

	bool f = getSol(0,0);
	// this is for result 
	while(!s.empty()) {
		cout<<sa[s.top().first-1]<<" "<<sa[s.top().second-1]<<endl;
		countt++;
		//pop for deleting  top most element from stack
		s.pop();
	}
	cout<<"finally water level is "<<countt-3<<endl;
	return 0;
}

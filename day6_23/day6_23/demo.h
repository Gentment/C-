#pragma once
#include<queue>
using namespace std;
void test() {
	priority_queue<int> q;
	priority_queue<int, vector<int>, less<int>> q1;
	priority_queue<int, vector<int>, greater<int> > q2;
}
#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
DFS
*/
// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& M) {
//         int n = M.size();

//         int res = 0;
//         vector<bool> visited(n,false);
//         for(int i=0;i<n;i++){
//             if(visited[i])
//                 continue;
//             findCircleNumDFS(M,visited,i);
//             ++res;
//         }
//         return res;
//     }

//     void findCircleNumDFS(vector<vector<int>>& M,vector<bool> &visited,int k){
//         visited[k] = true;
//         for(int i=0;i<M.size();++i){
//             if(!M[k][i] || visited[i])
//                 continue;
//             findCircleNumDFS(M,visited,i);
//         }      
//     }
// };


//BFS

//class Solution {
//public:
//	int findCircleNum(vector<vector<int>>& M) {
//		int n = M.size();
//		int res = 0;
//		queue<int> q;
//		vector<bool> visited(n, false);
//		for (int i = 0; i < n; ++i) {
//			if (visited[i])
//				continue;
//			q.push(i);
//			while (!q.empty()) {
//				int t = q.front();
//				q.pop();
//				visited[t] = true;
//				for (int j = 0; j < n; ++j)
//				{
//					if (!M[t][j] || visited[j])
//						continue;
//					q.push(j);
//				}
//			}
//			++res;
//		}
//		return res;
//	}
//
//};


/*
	²¢²é¼¯
*/

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		int res = n;
		vector<int> root(n, 0);
		for (int i = 0; i < n; i++)
			root[i] = i;
		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j) {
				if (M[i][j] == 1) {
					int p1 = getRoot(root, i);
					int p2 = getRoot(root, j);
					if (p1 != p2) {
						--res;
						root[p2] = p1;
					}
				}
			}
		}
	}
	int getRoot(vector<int> root, int i) {
		while (i != root[i]) {
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}
};
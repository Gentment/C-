#pragma once
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	 *  ����λ�϶�����������ż��λ�϶���ż��
	 *  ���룺����arr�����ȴ���2
	 *  len��arr�ĳ���
	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
	 */
	void oddInOddEvenInEven(vector<int>& vec, int len) {
		int first = 0;
		int last = vec.size() - 1;
		for (int first = 0; first < vec.size(); ++first) {
			if (first % 2 == 0 && vec[first] % 2 != 0) {
				int i = first + 1;
				for (; i < vec.size(); ++i) {
					if (vec[i] % 2 == 0) break;
				}
				if (i < vec.size()) {
					int tmp = vec[first];
					vec[first] = vec[i];
					vec[i] = tmp;
				}
			}
			else if (first % 2 != 0 && vec[first] == 0) {
				int i = first + 1;
				for (; i < vec.size(); ++i) {
					if (vec[i] % 2 != 0) break;
				}
				if (i < vec.size()) {
					int tmp = vec[first];
					vec[first] = vec[i];
					vec[i] = tmp;
				}
			}
		}
	}
};

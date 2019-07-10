#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void func(int &a){
  cout<<a<<" ";
}

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  for_each(v.begin(),v.end(),func);
  return 0;
}

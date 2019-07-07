#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef struct
{
	int id;
	string name;
}User;
int main()
{
	unordered_map<int,struct User> user;
   	User u={1,"lxk"};
	user.insert(1,u);
	cout<<user.size()<<endl;
	return 0;
}

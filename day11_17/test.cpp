#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v(10,1);
    for(size_t i=0;i<v.size();i++)
    {

        v[i]= i;
    }
    for(vector<int>::iterator it = v.begin();it != v.end();++it)
    {
        
        cout<<*it<<" ";
    }
    cout<<endl;
    // v.reserve(5);
    // v.resize(5);
    // v.rbegin();
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;

     cout<<"Size:"<<v.size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    return 0;
}

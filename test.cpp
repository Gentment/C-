#include "List.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	//3 5 7 2 9 1 8
	int temp =10;
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;

	List *list1 = new List(10);

	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);
	list1->ListInsert(3,&e4);
	list1->ListInsert(4,&e5);
	list1->ListInsert(5,&e6);
	list1->ListInsert(6,&e7);

	list1->ListTraverse();
	
	list1->GetElem(3,&temp);
	//list1->ListDelete(1,&temp);
	//list1->ListInsert(3,&temp);
	cout<<endl;
	cout<<"#"<<temp<<endl;
	//list1->ListTraverse();
	//list1->ClearList();
	//cout<<"ClearList"<<endl;
	//list1->ListTraverse();
	delete list1;
}
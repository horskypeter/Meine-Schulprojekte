#include <iostream>
#include "stack.h" 
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

mystack::mystack() 
{
	stack<string> mystack1; 
	stack<string> mystack2;
	stack<string> copy1;
	stack<string> copy2;
}

bool mystack::isEmpty()													//kontrola obsahu
{
	return mystack1.empty() && mystack2.empty();
}

void mystack::empty()													//vyprazdnenie
{
	while (!mystack1.empty())
	{
		mystack1.top();
		mystack1.pop();
	}
	while (!mystack2.empty())
	{
		mystack2.top();
		mystack2.pop();
	}
}

void mystack::add()													//pridanie
{
	getline(cin, str);
	original=str;
	str.erase(remove(str.begin(), str.end(), ','), str.end());                                         //odstranenie ciarok
	str.erase(remove(str.begin(), str.end(), ' '), str.end());                                         //odstranenie medzier 
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });        //upravy velke pismena na male
	clean = str;
	mystack1.push(str);
	copy1.push(str);
	reverse(str.begin(), str.end());																	//otoci
	turned = str;
	mystack2.push(str);
	copy2.push(str);
}

string mystack::transform1()
{
	return original;
}

string mystack::transform2()								
{
	return clean;
}

string mystack::transform3()
{
	return turned;
}

void mystack::print1()
{
	while (!mystack1.empty())
	{
		cout << mystack1.top() << endl;
		mystack1.pop();
	}
	mystack1=copy1;
}

void mystack::print2()
{
	while (!mystack2.empty())
	{
		cout << mystack2.top()<<endl;
		mystack2.pop();
	}
	mystack2 = copy2;
}

string mystack::palindrom()
{
	int i, length;
	int flag = 0;
	length = size(str);
	for (i = 0; i < length; i++)
	{
		if (str[i] != str[length - i - 1]) 
		{
			flag = 1;
		}
	}
	if (flag) 
	{
		retur = "Nie je palindrom";
	}
	else 
	{
		retur = "Zadany vyraz je palindrom";
	}
	return retur;
}
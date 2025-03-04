#include <string>
#include <iostream>
#include <stack>
using namespace std;

class mystack
{
private:
	stack<string> mystack1;
	stack<string> mystack2;
	stack<string> copy1;
	stack<string> copy2;
	string str,original,clean,turned,retur;


public:
	mystack();
	void empty();
	bool isEmpty();
	void add();
	void print1();
	void print2();
	string palindrom();
	string transform1();
	string transform2();
	string transform3();
};
#include "chartree.h"
#include <fstream>
#include <iostream>

TreeNode::TreeNode(string ch, NodePtr lPtr, NodePtr rPtr, NodePtr pPtr)
{
	data = ch; lLink = lPtr; rLink = rPtr; parent = pPtr;
}

CharTree::CharTree()																	//konstruktor
{
	rootPtr = NULL;
	Load("game.txt");
}
CharTree::~CharTree()																	//destruktor
{
	Save("game.txt");
	DeleteTree(rootPtr);
}

void CharTree::DeleteTree(NodePtr ptr)													//vymazanie stromu
{
	NodePtr tempPtr;
	if (ptr != NULL) {
		tempPtr = ptr;
		ptr = tempPtr->lLink;
		DeleteTree(ptr);
		ptr = tempPtr->rLink;
		DeleteTree(ptr);
		delete tempPtr;
	}
}

void CharTree::BuildRoot(string someChar)												//stavat koren
{
	rootPtr = new TreeNode(someChar, NULL, NULL, NULL);
}

NodePtr CharTree::Root() const { return rootPtr; }										//koren

void CharTree::AppendLeft(NodePtr ptr, string someChar)									//pridat vlavo
{
	ptr->lLink = new TreeNode(someChar, NULL, NULL, ptr);
}

void CharTree::AppendRight(NodePtr ptr, string someChar)								//pridat pvravo
{
	ptr->rLink = new TreeNode(someChar, NULL, NULL, ptr);
}

string CharTree::GetData(NodePtr ptr)													//ziskat udaje
{
	if (ptr != NULL)
		return ptr->data;
	else
		return "NULL";
}

void CharTree::SetData(string someChar, NodePtr ptr)									//nastavit udaje
{
	ptr->data = someChar;
}

NodePtr CharTree::LChild(NodePtr ptr)													//nastavenie na lave dieta
{
	return (ptr == NULL) ? NULL : ptr->lLink;
}

NodePtr CharTree::RChild(NodePtr ptr)													//nastavenie na prave dieta
{
	return (ptr == NULL) ? NULL : ptr->rLink;
}

bool CharTree::IsLeaf(NodePtr ptr)														//je list
{
	if (ptr == NULL)
		return true;
	else
		return (ptr->lLink == NULL && ptr->rLink == NULL);
}

NodePtr CharTree::GetParent(NodePtr ptr)												//zistit rodica
{
	if (ptr != NULL)
		return ptr->parent;
	else
		return NULL;
}

void CharTree::Save2(NodePtr ptr, ofstream& output)										//ukladanie
{
	if (ptr == NULL)
	{
		return;
	}
	if (IsLeaf(ptr))
	{
		output << "!";
	}
	output << GetData(ptr) + "\n";
	Save2(LChild(ptr), output);
	if (LChild(ptr) == NULL && !IsLeaf(ptr))
	{
		output << "\n";
	}
	Save2(RChild(ptr), output);
	if (RChild(ptr) == NULL && !IsLeaf(ptr))
	{
		output << "\n";
	}
}

void CharTree::Save(string path)														//ukladanie
{
	ofstream output;
	NodePtr current;

	output.open(path);
	Save2(Root(), output);
	output.close();
}

void CharTree::Load(string path)														//nacitavanie
{
	ifstream input;
	NodePtr current;

	input.open(path);
	if (!input)
	{
		cout << "Subor na nacitanie hry sa nenasiel" << endl;
	}
	else
	{
		BuildRoot("");
		Load2(Root(), input);
		if (GetData(Root()) == "")
		{
			DeleteTree(Root());
		}

		input.close();
	}
}
void CharTree::Load2(NodePtr ptr, ifstream& input)										//nacitavanie
{
	string nacitavam;
	getline(input, nacitavam);
	if (nacitavam == "" || input.eof())
		return;
	ptr->data = nacitavam;

	if (nacitavam.at(0) == '!')
	{
		ptr->data = nacitavam.substr(1);
		return;
	}
	ptr->lLink = new TreeNode("", NULL, NULL, ptr);
	Load2(LChild(ptr), input);
	if (GetData(LChild(ptr)) == "")
	{
		DeleteTree(LChild(ptr));
		ptr->lLink = NULL;
	}

	ptr->rLink = new TreeNode("", NULL, NULL, ptr);
	Load2(RChild(ptr), input);
	if (GetData(RChild(ptr)) == "")
	{
		DeleteTree(RChild(ptr));
		ptr->rLink = NULL;
	}
}
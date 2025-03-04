#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct TreeNode;
typedef TreeNode* NodePtr;
struct TreeNode {
	string data;
	NodePtr lLink;
	NodePtr rLink;
	NodePtr parent;
	TreeNode(string, NodePtr, NodePtr, NodePtr);
};
class CharTree {
private:
	NodePtr rootPtr;

public:

	CharTree();
	~CharTree();
	void BuildRoot(string someChar);
	NodePtr Root() const;
	void AppendLeft(NodePtr ptr, string someChar);
	void AppendRight(NodePtr ptr, string someChar);
	NodePtr LChild(NodePtr ptr);
	NodePtr RChild(NodePtr ptr);
	bool IsLeaf(NodePtr ptr);
	void SetData(string someChar, NodePtr ptr);
	string GetData(NodePtr ptr);
	NodePtr GetParent(NodePtr ptr);
	void DeleteTree(NodePtr ptr);

	void Save(string path);
	void Load(string path);
	void Save2(NodePtr ptr, ofstream& output);
	void Load2(NodePtr ptr, ifstream& output);
};
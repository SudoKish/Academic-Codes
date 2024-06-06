/*

5.Convert given binary tree into threaded binary tree. Analyze time and space complexity of the
algorithm.

*/
#include <iostream>
using namespace std;
class TBT;
class node
{
	node *left,*right;
	int data;
	bool rbit,lbit;
public:
	node()
{
		left=NULL;
		right=NULL;
		rbit=lbit=0;
}
	node(int d)
	{
		left=NULL;
		right=NULL;
		rbit=lbit=0;
		data=d;
	}
	friend class TBT;
};

class TBT
{
	node *root; //acts as a dummy node
public:
	TBT() //dummy node initialization
{
		root=new node(9999);
		root->left=root;
		root->rbit=1;
		root->lbit=0;
		root->right=root;
}
	void create();
	void insert(int data);
	node *inorder_suc(node *);
	void inorder_traversal();
	node * preorder_suc(node *c);
	void preorder_traversal();
};
//--------------------------------------------
void TBT::preorder_traversal()
{
	node *c=root->left;
	while(c!=root)
	{
		cout<<" "<<c->data;
		c=preorder_suc(c);
	}
}
void TBT::inorder_traversal()
{
	node *c=root->left;
	while(c->lbit==1)
		c=c->left;
	while(c!=root)
	{
		cout<<" "<<c->data;
		c=inorder_suc(c);
	}
}
node* TBT::inorder_suc(node *c)
{
	if(c->rbit==0)
		return c->right;
	else
		c=c->right;
	while(c->lbit==1)
	{
		c=c->left;
	}
	return c;
}
node *TBT::preorder_suc(node *c)
{
	if(c->lbit==1)
	{
		return c->left;
	}
	while(c->rbit==0)
	{
		c=c->right;
	}
	return c->right;
}
//-------- Create Method
void TBT::create()
{

	int n;
	if(root->left==root&&root->right==root)
	{
	cout<<"\nEnter number of nodes:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int info;
		cout<<"\nEnter data: ";
		cin>>info;
		this->insert(info);
	}
	}
	else
	{
		cout<<"\nTree is Already created.\n";
	}
}
void TBT::insert(int data)
{

	if(root->left==root&&root->right==root) //no node in tree
	{
		node *p=new node(data);
		p->left=root->left;
		p->lbit=root->lbit; //0
		p->rbit=0;
		p->right=root->right;
		root->left=p;
		root->lbit=1;
		cout<<"\nInserted start"<<data;
		return;
	}
	node *cur=new node;
	cur=root->left;
	while(1)
	{

		if(cur->data<data)   //insert right
		{
			node *p=new node(data);
			if(cur->rbit==0)
			{
				p->right=cur->right;
				p->rbit=cur->rbit;
				p->lbit=0;
				p->left=cur;
				cur->rbit=1;
				cur->right=p;
				cout<<"\nInserted right "<<data;
				return;
			}
			else
				cur=cur->right;
		}
		if(cur->data>data) //insert left
		{
			node *p=new node(data);
			if(cur->lbit==0)
			{
				p->left=cur->left;
				p->lbit=cur->lbit;
				p->rbit=0;
				p->right=cur; //successor
				cur->lbit=1;
				cur->left=p;
				cout<<"\nInserted left"<<data;
				return;
			}
			else
				cur=cur->left;
		}
	}

}



int main() {
	TBT t1;
	int value;
	int choice;
	do
	{
		cout<<"\n1.Create Tree\n2.Insert into tree\n3.Preorder\n4.Inorder\n0.Exit\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			t1.create();
			break;
		case 2:
			cout<<"\nEnter Number(data): ";
			cin>>value;
			t1.insert(value);
			break;
		case 3:
			cout<<"\nPreorder traversal of TBT\n";
			t1.preorder_traversal();
			break;
		case 4:
			cout<<"\nInoder Traversal of TBT\n";
			t1.inorder_traversal();
			break;
		default:
			cout<<"\nWrong choice";
		}

	}while(choice!=0);


	return 0;

    }

	/*
	
	Theory:
Threaded Binary Tree:
In a threaded binary tree, some nodes have additional pointers called "threads" that point to either the inorder predecessor or successor of the node.
Threads are added to nodes with null left or right child pointers, allowing for efficient traversal without recursion.
Types of Threads:
Inorder Thread: Points to the inorder successor of a node.
Preorder Thread: Points to the preorder successor of a node.
Postorder Thread: Points to the postorder successor of a node.
Construction Algorithm:
Start with an empty threaded binary tree.
Traverse the original binary tree in a specific order (inorder, preorder, or postorder).
For each node encountered during traversal, add threads as necessary based on the presence of null left or right child pointers.
Time and Space Complexity:
Construction:
Time Complexity: O(n), where n is the number of nodes in the original binary tree. Traversing the tree takes O(n) time, and adding threads takes constant time per node.
Space Complexity: O(n), where n is the number of nodes in the original binary tree. Additional space is required to store the threaded binary tree.
Real-World Considerations:
Traversal Order:
The efficiency of traversal may vary depending on the chosen traversal order (inorder, preorder, or postorder). In general, inorder threading is commonly used for efficient inorder traversal.
Balancing:
If the original binary tree is balanced, the resulting threaded binary tree may also maintain balance, leading to efficient operations.
Thread Maintenance:
Threaded binary trees require careful maintenance when performing operations like insertion, deletion, or balancing to ensure that thread pointers remain valid.
Use Cases:
Threaded binary trees are useful for applications where efficient traversal is critical, such as in-memory databases or expression evaluation.
Conclusion:
Converting a binary tree into a threaded binary tree offers advantages in terms of space and time efficiency for certain traversal operations. However, the construction algorithm involves traversing the entire original binary tree, resulting in linear time complexity. Additionally, extra space is required to store the threaded binary tree. Careful consideration of traversal order and maintenance of thread pointers are necessary for optimal performance in real-world scenarios.*/
/*

4. Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. 
After constructing a binary tree - 
i. Insert new node 
ii. Find number of nodes in longest path 
iii. Minimum data value found in the tree 
iv. Change a tree so that the roles of the left and right pointers are swapped at every node 
v.  Search a value

*/

#include <iostream>
using namespace std;

//Structre to create node
struct Node{
    int data;
    Node* right;
    Node* left;
};

//Function to create node
Node* create(int data){
    Node* temp=new Node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

//Function to insert node
void insert(Node* &root,int data){
    if(root==NULL){
        root=create(data);          //say 5 root
    }                               //Next element n
    else if(root->data > data){     //if (5 > n)
        insert(root->left,data);    //n will go to left side 
    }
    else{                           //else
    insert(root->right,data);       //n will go to right side
    }
}
//Preorder
void displayPre(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";      //PARENT
        displayPre(root->left);     //LEFT
        displayPre(root->right);    //RIGHT
    }

}

//Inorder
void displayIn(Node* root){
    if(root!=NULL){
        displayIn(root->left);      //LEFT
        cout<<root->data<<" ";      //PARENT
        displayIn(root->right);     //RIGHT
    }

}

//Postorder
void displayPost(Node* root){
    if(root!=NULL){
        displayPost(root->left);      //LEFT
        displayPost(root->right);     //RIGHT
        cout<<root->data<<" ";        //PARENT
    }

}

//Function to calculate Height
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int l_h=height(root->left);
        int r_h=height(root->right);
        if(l_h>=r_h){
            return l_h+1;
        }
        else{
            return r_h+1;
        }
    }
}

//Function to seach for value
void search(Node* root,int value){
    if(root!=NULL){
    if(root->data>value){
        search(root->left,value);

    }
    else if(root->data<value){
        search(root->right,value);
    }
    else if(root->data==value){
        cout<<"\nelement FOUND";
    }
    }
    else{
        cout<<"\nelement NOT found";
    }
}

//Function to find smallest element i.e display extreme left
void smallest(Node* root){
    if(root->left!=NULL){
        smallest(root->left);
    }
    else{
        cout<<"Smallest :: "<<root->data;
    }
}

//Function to display largest element i.e display extreme right
void largest(Node* root){
    if(root->right!=NULL){
        largest(root->right);
    }
    else{
        cout<<"\nlargest :: "<<root->data;
    }
}

//Function mirror the tree
void mirror(Node* root){
    if(root==NULL){
        return;
    }    
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}

int main(){
    bool loop=1;
    Node * root=NULL;
    int ch,n,num;
    while(loop==1){
    //Menu
    cout<<"\n-----MENU-----"<<endl
        <<"1. create BST"<<endl
        <<"2. preorder"<<endl
        <<"3. inorder"<<endl
        <<"4. postorder"<<endl
        <<"5. height"<<endl
        <<"6. search"<<endl
        <<"7. smallest"<<endl
        <<"8. largest"<<endl
        <<"9. mirror"<<endl
        <<"10. exit"<<endl
        <<"ENTER :: ";
    cin>>ch;
    switch (ch)
    {
        case 1:
        {
            cout<<"\nEnter the number of elements :: ";
            cin>>n;

            cout<<"Enter the numbers :: ";
            for(int i=0;i<n;i++){
                cin>>num;
                insert(root,num);
            }
            break;
        }
        case 2:
        {
            cout<<"\nPRE ORDER : ";
            displayPre(root);
            break;
        }
        case 3:
        {
            cout<<"\nIN ORDER : ";
            displayIn(root);
            break;
        }
        case 4:
        {
            cout<<"\nPOST ORDER : ";
            displayPost(root);
            break;
        }
        case 5:
        {
            int h=height(root);
            cout<<"\nHeight of BST :: "<<h;
            break;
        }
        case 6:
        {   
            int value;
            cout<<"Enter the element to search :: ";
            cin>>value;
            search(root, value);
            break;
        }
        case 7:
        {
            smallest(root);
            break;
        }
        case 8:
        {
            largest(root);
            break;
        }
        case 9:
        {   
            cout<<"\nBEFORE MIRROR"
                <<"\nInorder :: ";
            displayIn(root);
            mirror(root);
            cout<<"\nAFTER MIRROR"
                <<"\nInorder :: ";
            displayIn(root);
            break;
        }
        case 10:
        {
            loop=0;
            break;
        }
    }
}    
    return 0;
}

/*

Theory:
Binary Search Tree (BST):
A binary search tree is a binary tree where each node has at most two children, and the key (value) of each node is greater than the keys in its left subtree and less than the keys in its right subtree. This property allows for efficient searching, insertion, and deletion operations.
Standard BST Operations:
Insertion: Insert a new node into the BST while maintaining the BST property.
Search: Find a node with a specific value in the BST.
Traversal: Visit all nodes of the BST in a specific order (e.g., inorder, preorder, postorder).
Deletion: Remove a node from the BST while preserving the BST property.
Additional Operations:
Height Calculation: Determine the height of the BST, which represents the longest path from the root to a leaf node.
Minimum Value: Find the minimum value stored in the BST by traversing the left subtree recursively.
Pointer Swapping: Swap the left and right pointers of each node in the BST.
Insertion of a New Node: Insert a new node into the BST after construction.
Conclusion:
Efficiency of BST Operations:
Insertion, search, and deletion operations in a BST typically have time complexities of O(log n) on average, where n is the number of nodes in the tree. However, they can degrade to O(n) in the worst case for unbalanced trees.
Traversal of the tree can be done in O(n) time, where n is the number of nodes.
Operations like finding the height, minimum value, and pointer swapping also have time complexities of O(n) since they require traversing the entire tree.
Handling Unbalanced Trees:
Unbalanced trees can lead to inefficient operations, especially for search and insertion. Balancing techniques like AVL trees or Red-Black trees can help maintain balance and improve performance.
Space Complexity:
The space complexity of a BST is O(n) to store the nodes, where n is the number of nodes in the tree.
Real-World Considerations:
When implementing BST operations, it's essential to consider factors like maintaining balance, handling edge cases, and optimizing for the specific requirements of the application.*/


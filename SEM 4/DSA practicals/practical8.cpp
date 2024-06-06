/*

A Dictionary stores keywords and its meanings. Provide facility for adding new. keywords, deleting
keywords, updating values of any entry. Provide facility to display. whole data sorted in ascending/
Descending order. Also find how many maximum comparisons may require for finding any
keyword. Use Height balance tree and find the complexity for finding a keyword.

*/

#include <iostream>
#include <string>
#include <algorithm> // for std::transform

using namespace std;

// AVL Tree Node
struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;
};

// Function to get height of the tree
int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL tree node
Node* newNode(string keyword, string meaning) {
    Node* node = new Node();
    node->keyword = keyword;
    node->meaning = meaning;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // new node is initially added at leaf
    return node;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a keyword in the subtree rooted with node and returns the new root of the subtree
Node* insert(Node* node, string keyword, string meaning) {
    // 1. Perform the normal BST insertion
    if (node == nullptr)
        return newNode(keyword, meaning);

    if (keyword < node->keyword)
        node->left = insert(node->left, keyword, meaning);
    else if (keyword > node->keyword)
        node->right = insert(node->right, keyword, meaning);
    else // Equal keys are not allowed in BST
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && keyword < node->left->keyword)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && keyword > node->right->keyword)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && keyword > node->left->keyword) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && keyword < node->right->keyword) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Utility function to find the node with the minimum key value found in that tree
Node* minValueNode(Node* node) {
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Delete a keyword in the subtree rooted with node and returns the new root of the subtree
Node* deleteNode(Node* root, string keyword) {
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == nullptr)
        return root;

    // If the keyword to be deleted is smaller than the root's keyword, then it lies in left subtree
    if (keyword < root->keyword)
        root->left = deleteNode(root->left, keyword);

    // If the keyword to be deleted is greater than the root's keyword, then it lies in right subtree
    else if (keyword > root->keyword)
        root->right = deleteNode(root->right, keyword);

    // if keyword is same as root's keyword, then this is the node to be deleted
    else {
        // node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a keyword in the AVL tree
Node* search(Node* root, string keyword) {
    if (root == nullptr || root->keyword == keyword)
        return root;

    if (root->keyword < keyword)
        return search(root->right, keyword);

    return search(root->left, keyword);
}

// Function to update the meaning of a keyword
void updateMeaning(Node* root, string keyword, string newMeaning) {
    Node* node = search(root, keyword);
    if (node != nullptr) {
        node->meaning = newMeaning;
    } else {
        cout << "Keyword not found." << endl;
    }
}

// Utility function to print the tree in-order
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->keyword << ": " << root->meaning << endl;
        inOrder(root->right);
    }
}

// Utility function to print the tree in reverse order
void reverseOrder(Node* root) {
    if (root != nullptr) {
        reverseOrder(root->right);
        cout << root->keyword << ": " << root->meaning << endl;
        reverseOrder(root->left);
    }
}

int main() {
    Node* root = nullptr;
    int choice;
    string keyword, meaning, newMeaning;

    do {
        cout << "\n1. Add Keyword\n2. Delete Keyword\n3. Update Meaning\n4. Display Ascending\n5. Display Descending\n6. Search Keyword\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = insert(root, keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, newMeaning);
                updateMeaning(root, keyword, newMeaning);
                break;
            case 4:
                cout << "Dictionary (Ascending Order):" << endl;
                inOrder(root);
                break;
            case 5:
                cout << "Dictionary (Descending Order):" << endl;
                reverseOrder(root);
                break;
            case 6:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                if (search(root, keyword) != nullptr)
                    cout << "Keyword found." << endl;
                else
                    cout << "Keyword not found." << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}



				
/*
Theory:
Height-Balanced Tree (AVL Tree):
An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one.
This property ensures that the tree remains balanced, maintaining a time complexity of O(log n) for key operations like insertion, deletion, and search.
Dictionary Operations:
Insertion: Add new keywords and their meanings to the AVL tree while ensuring balance.
Deletion: Remove keywords from the AVL tree while maintaining balance.
Updating Values: Update the meanings of existing keywords in the AVL tree.
Sorting: Display the entire dictionary sorted in ascending or descending order by performing an inorder traversal of the AVL tree.
Finding Maximum Comparisons: Analyze the maximum number of comparisons required to find a keyword in the AVL tree.
Implementation:
AVL Tree Node:
Each node in the AVL tree contains a keyword-meaning pair.
Additionally, each node stores the height of its subtree and pointers to its left and right children.
Dictionary Operations:
Insertion, deletion, and updating values are standard AVL tree operations, modified to handle keyword-meaning pairs.
Sorting can be achieved by performing an inorder traversal of the AVL tree and printing the nodes in the desired order.
Finding Maximum Comparisons:
Analyze the height of the AVL tree to determine the maximum number of comparisons required to find a keyword.
The maximum height of the AVL tree, h, represents the worst-case scenario for finding a keyword, resulting in O(h) comparisons.
Time and Space Complexity:
Insertion, Deletion, and Updating Values:
Time Complexity: O(log n) due to the self-balancing property of the AVL tree.
Space Complexity: O(n) to store n keyword-meaning pairs.
Sorting:
Time Complexity: O(n) to perform an inorder traversal of the AVL tree.
Space Complexity: O(n) for storing the sorted dictionary.
Finding Maximum Comparisons:
Time Complexity: O(log n) in the average case, O(n) in the worst case when the tree is highly unbalanced.
Real-World Considerations:
Balancing Operations:
Ensure that insertion, deletion, and updating operations maintain the balance property of the AVL tree to guarantee efficient search operations.
Efficient Sorting:
Implement efficient sorting algorithms tailored to the structure of the AVL tree to minimize time and space complexity during sorting.
Handling Duplicates:
Decide whether to allow duplicate keywords in the dictionary and implement appropriate handling mechanisms if needed.
Conclusion:
Using an AVL tree for implementing the dictionary provides efficient operations for adding, deleting, updating, sorting, and finding keywords. The self-balancing property of the AVL tree ensures that key operations maintain a time complexity of O(log n), making it suitable for large datasets. However, careful implementation and maintenance of balance are necessary to ensure optimal performance in real-world scenarios.

*/
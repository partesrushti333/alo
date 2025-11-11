/*
------------------------------------------------------------
Algorithm: Dictionary using Binary Search Tree (BST)
------------------------------------------------------------
1. Start
2. Create a structure Node with fields: keyword, meaning, left, right.
3. Insert():
      a) If tree empty, create root node.
      b) Else compare keyword.
      c) If keyword < current → go to left subtree.
      d) Else go to right subtree.
4. Search():
      a) Compare keyword with current node.
      b) If found, return meaning.
      c) Else go to left or right subtree.
5. Delete():
      a) Find node to be deleted.
      b) If leaf → delete directly.
      c) If one child → connect parent to child.
      d) If two children → find inorder successor and replace.
6. Update():
      a) Search for the keyword.
      b) If found, modify meaning.
7. Display:
      a) Inorder traversal → ascending order.
      b) Reverse inorder → descending order.
8. Count maximum comparisons during search.
9. Stop
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword, meaning;
    Node *left, *right;
    Node(string k, string m) {
        keyword = k;
        meaning = m;
        left = right = NULL;
    }
};

class Dictionary {
    Node* root;
public:
    Dictionary() { root = NULL; }

    Node* insert(Node* root, string k, string m) {
        if (!root) return new Node(k, m);
        if (k < root->keyword) root->left = insert(root->left, k, m);
        else if (k > root->keyword) root->right = insert(root->right, k, m);
        return root;
    }

    void add(string k, string m) {
        root = insert(root, k, m);
    }

    Node* search(Node* root, string k, int& comp) {
        if (!root) return NULL;
        comp++;
        if (root->keyword == k) return root;
        if (k < root->keyword) return search(root->left, k, comp);
        else return search(root->right, k, comp);
    }

    void update(string k) {
        int comp = 0;
        Node* temp = search(root, k, comp);
        if (!temp) cout << "Keyword not found!\n";
        else {
            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, temp->meaning);
            cout << "Meaning updated successfully!\n";
        }
    }

    Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, string k) {
        if (!root) return root;
        if (k < root->keyword) root->left = deleteNode(root->left, k);
        else if (k > root->keyword) root->right = deleteNode(root->right, k);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMin(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }
        return root;
    }

    void del(string k) {
        root = deleteNode(root, k);
        cout << "Keyword deleted successfully!\n";
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }

    void revInorder(Node* root) {
        if (!root) return;
        revInorder(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        revInorder(root->left);
    }

    void displayAscending() {
        cout << "\nDictionary in Ascending Order:\n";
        inorder(root);
    }

    void displayDescending() {
        cout << "\nDictionary in Descending Order:\n";
        revInorder(root);
    }

    void findComparisons(string k) {
        int comp = 0;
        Node* temp = search(root, k, comp);
        if (temp) cout << "Keyword found! Comparisons made: " << comp << endl;
        else cout << "Keyword not found! Comparisons made: " << comp << endl;
    }
};

int main() {
    Dictionary dict;
    int choice;
    string key, meaning;

    do {
        cout << "\n---- Dictionary Operations ----\n";
        cout << "1. Add Keyword\n2. Delete Keyword\n3. Update Meaning\n4. Display Ascending\n5. Display Descending\n6. Find Comparisons\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cin.ignore();
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dict.add(key, meaning);
                cout << "Keyword added successfully!\n";
                break;

            case 2:
                cout << "Enter keyword to delete: ";
                cin >> key;
                dict.del(key);
                break;

            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                dict.update(key);
                break;

            case 4:
                dict.displayAscending();
                break;

            case 5:
                dict.displayDescending();
                break;

            case 6:
                cout << "Enter keyword to search: ";
                cin >> key;
                dict.findComparisons(key);
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 7);

    return 0;
}

/*
--------------------- Sample Output ---------------------
---- Dictionary Operations ----
1. Add Keyword
2. Delete Keyword
3. Update Meaning
4. Display Ascending
5. Display Descending
6. Find Comparisons
7. Exit
Enter your choice: 1
Enter keyword: apple
Enter meaning: A fruit
Keyword added successfully!

Enter your choice: 1
Enter keyword: ball
Enter meaning: A round object
Keyword added successfully!

Enter your choice: 4
Dictionary in Ascending Order:
apple : A fruit
ball : A round object

Enter your choice: 3
Enter keyword to update: apple
Enter new meaning: A sweet red fruit
Meaning updated successfully!

Enter your choice: 6
Enter keyword to search: ball
Keyword found! Comparisons made: 2

Enter your choice: 5
Dictionary in Descending Order:
ball : A round object
apple : A sweet red fruit

Enter your choice: 2
Enter keyword to delete: apple
Keyword deleted successfully!

Enter your choice: 7
Exiting...
---------------------------------------------------------
*/

/*
------------------------------------------------------------
Algorithm: Pinnacle Club Member Management using Singly Linked List
------------------------------------------------------------
1. Start
2. Define a structure Node with PRN, Name, and pointer next.
3. Create a class PinnacleClub to manage:
      - head pointer
      - Functions:
          a) addPresident(): Insert president at the start
          b) addSecretary(): Insert secretary at the end
          c) addMember(): Insert member in between
          d) deletePresident(): Delete first node
          e) deleteSecretary(): Delete last node
          f) deleteMember(): Delete member by PRN
          g) display(): Display all members
          h) count(): Count total members
4. Create two lists (Division A and Division B) and concatenate them.
5. Display the concatenated list.
6. Stop
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;
    Node(int p, string n) { prn = p; name = n; next = NULL; }
};

class PinnacleClub {
    Node* head;
public:
    PinnacleClub() { head = NULL; }

    void addPresident(int prn, string name) {
        Node* temp = new Node(prn, name);
        temp->next = head;
        head = temp;
    }

    void addSecretary(int prn, string name) {
        Node* temp = new Node(prn, name);
        if (!head) { head = temp; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = temp;
    }

    void addMember(int prn, string name) {
        Node* temp = new Node(prn, name);
        if (!head) { head = temp; return; }
        Node* t = head;
        while (t->next && t->next->next) t = t->next;
        temp->next = t->next;
        t->next = temp;
    }

    void deletePresident() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteSecretary() {
        if (!head || !head->next) { delete head; head = NULL; return; }
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = NULL;
    }

    void deleteMember(int prn) {
        if (!head) return;
        Node* t = head;
        while (t->next && t->next->prn != prn) t = t->next;
        if (t->next) {
            Node* del = t->next;
            t->next = t->next->next;
            delete del;
        }
    }

    void display() {
        Node* t = head;
        cout << "\nPinnacle Club Members:\n";
        while (t) {
            cout << "PRN: " << t->prn << " | Name: " << t->name << endl;
            t = t->next;
        }
    }

    int count() {
        int c = 0;
        Node* t = head;
        while (t) { c++; t = t->next; }
        return c;
    }

    Node* getHead() { return head; }

    void concatenate(PinnacleClub& other) {
        if (!head) { head = other.head; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = other.head;
    }
};

int main() {
    PinnacleClub divA, divB;

    divA.addPresident(101, "Riya");
    divA.addMember(102, "Aarav");
    divA.addMember(103, "Sia");
    divA.addSecretary(104, "Karan");

    divB.addPresident(201, "Nisha");
    divB.addMember(202, "Raj");
    divB.addSecretary(203, "Tina");

    cout << "\nDivision A Members:";
    divA.display();
    cout << "\nTotal Members in Division A: " << divA.count();

    cout << "\n\nDivision B Members:";
    divB.display();
    cout << "\nTotal Members in Division B: " << divB.count();

    divA.concatenate(divB);
    cout << "\n\nAfter Concatenation of Division A and B:";
    divA.display();
    cout << "\nTotal Members after concatenation: " << divA.count();

    divA.deletePresident();
    divA.deleteSecretary();
    divA.deleteMember(102);

    cout << "\n\nAfter Deletions:";
    divA.display();
    cout << "\nTotal Members after deletion: " << divA.count();
    return 0;
}

/*
--------------------- Sample Output ---------------------
Division A Members:
Pinnacle Club Members:
PRN: 101 | Name: Riya
PRN: 102 | Name: Aarav
PRN: 103 | Name: Sia
PRN: 104 | Name: Karan
Total Members in Division A: 4

Division B Members:
Pinnacle Club Members:
PRN: 201 | Name: Nisha
PRN: 202 | Name: Raj
PRN: 203 | Name: Tina
Total Members in Division B: 3

After Concatenation of Division A and B:
Pinnacle Club Members:
PRN: 101 | Name: Riya
PRN: 102 | Name: Aarav
PRN: 103 | Name: Sia
PRN: 104 | Name: Karan
PRN: 201 | Name: Nisha
PRN: 202 | Name: Raj
PRN: 203 | Name: Tina
Total Members after concatenation: 7

After Deletions:
Pinnacle Club Members:
PRN: 102 | Name: Aarav
PRN: 103 | Name: Sia
PRN: 104 | Name: Karan
PRN: 201 | Name: Nisha
PRN: 202 | Name: Raj
Total Members after deletion: 5
---------------------------------------------------------
*/

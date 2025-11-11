/*
------------------------------------------------------------
Algorithm: Appointment Booking System using Doubly Linked List
------------------------------------------------------------
1. Start
2. Define a structure Node with fields: name, time, and next/prev pointers.
3. Create a class AppointmentList with:
      a) insertSlot(): Insert a new available time slot in sorted order.
      b) displayFreeSlots(): Display all available (unbooked) slots.
      c) bookAppointment(): Mark a slot as booked by entering patient name.
      d) cancelAppointment(): Cancel an existing appointment after validating time.
      e) sortByTime(): Sort list by time using pointer manipulation.
      f) displayAll(): Display all booked and free slots.
4. In main():
      Create an object of AppointmentList
      Display menu for user actions:
         1. Display Free Slots
         2. Book Appointment
         3. Cancel Appointment
         4. Sort List
         5. Display All
         6. Exit
5. Perform user-selected operations
6. Stop
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int time;
    string name;
    bool booked;
    Node *prev, *next;
    Node(int t) {
        time = t;
        booked = false;
        name = "Free";
        prev = next = NULL;
    }
};

class AppointmentList {
    Node* head;
public:
    AppointmentList() { head = NULL; }

    void insertSlot(int t) {
        Node* temp = new Node(t);
        if (!head) { head = temp; return; }
        Node* curr = head;
        Node* prev = NULL;
        while (curr && curr->time < t) {
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        } else {
            temp->next = curr;
            temp->prev = prev;
            prev->next = temp;
            if (curr) curr->prev = temp;
        }
    }

    void displayFreeSlots() {
        Node* t = head;
        cout << "\nAvailable Time Slots:\n";
        while (t) {
            if (!t->booked)
                cout << t->time << ":00\n";
            t = t->next;
        }
    }

    void displayAll() {
        Node* t = head;
        cout << "\nAll Appointment Slots:\n";
        while (t) {
            cout << t->time << ":00  -  " << (t->booked ? t->name : "Free") << endl;
            t = t->next;
        }
    }

    void bookAppointment(string pname, int t) {
        Node* temp = head;
        while (temp) {
            if (temp->time == t) {
                if (temp->booked) {
                    cout << "Slot already booked!\n";
                    return;
                }
                temp->booked = true;
                temp->name = pname;
                cout << "Appointment booked successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid slot time!\n";
    }

    void cancelAppointment(int t) {
        Node* temp = head;
        while (temp) {
            if (temp->time == t) {
                if (!temp->booked) {
                    cout << "Slot is not booked yet!\n";
                    return;
                }
                temp->booked = false;
                temp->name = "Free";
                cout << "Appointment cancelled successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid slot time!\n";
    }

    void sortByTime() {
        if (!head || !head->next) return;
        Node* i = head;
        while (i->next) {
            Node* j = i->next;
            while (j) {
                if (i->time > j->time) {
                    swap(i->time, j->time);
                    swap(i->booked, j->booked);
                    swap(i->name, j->name);
                }
                j = j->next;
            }
            i = i->next;
        }
        cout << "List sorted by time successfully!\n";
    }
};

int main() {
    AppointmentList a;
    a.insertSlot(9);
    a.insertSlot(10);
    a.insertSlot(11);
    a.insertSlot(12);
    a.insertSlot(13);
    a.insertSlot(14);
    a.insertSlot(15);
    int choice, time;
    string name;

    do {
        cout << "\n------ Appointment Booking System ------\n";
        cout << "1. Display Free Slots\n2. Book Appointment\n3. Cancel Appointment\n4. Sort List by Time\n5. Display All Slots\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: a.displayFreeSlots(); break;
            case 2:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter slot time (e.g., 10 for 10:00): ";
                cin >> time;
                a.bookAppointment(name, time);
                break;
            case 3:
                cout << "Enter slot time to cancel: ";
                cin >> time;
                a.cancelAppointment(time);
                break;
            case 4:
                a.sortByTime();
                break;
            case 5:
                a.displayAll();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}

/*
-------------------- Sample Output --------------------
------ Appointment Booking System ------
1. Display Free Slots
2. Book Appointment
3. Cancel Appointment
4. Sort List by Time
5. Display All Slots
6. Exit
Enter your choice: 1

Available Time Slots:
9:00
10:00
11:00
12:00
13:00
14:00
15:00

Enter your choice: 2
Enter your name: Riya
Enter slot time (e.g., 10 for 10:00): 10
Appointment booked successfully!

Enter your choice: 5
All Appointment Slots:
9:00  -  Free
10:00 -  Riya
11:00 -  Free
12:00 -  Free
13:00 -  Free
14:00 -  Free
15:00 -  Free

Enter your choice: 3
Enter slot time to cancel: 10
Appointment cancelled successfully!

Enter your choice: 1
Available Time Slots:
9:00
10:00
11:00
12:00
13:00
14:00
15:00

Enter your choice: 6
Exiting...
-------------------------------------------------------
*/

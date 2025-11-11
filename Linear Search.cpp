/*
------------------------------------------------------------
1(a) Algorithm: Linear Search
------------------------------------------------------------
1. Start
2. Input total number of students (n)
3. Store roll numbers of students in an array
4. Input roll number to be searched
5. Traverse array from index 0 to n-1
6. If roll[i] == key → print "Found" and stop
7. If not found after traversal → print "Not Found"
8. Stop
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Student attended training program.\n";
            return;
        }
    }
    cout << "Student did not attend training program.\n";
}

int main() {
    int n, key;
    cout << "Enter number of students: ";
    cin >> n;
    int arr[n];
    cout << "Enter roll numbers in random order:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter roll number to search: ";
    cin >> key;
    linearSearch(arr, n, key);
    return 0;
}

/*
Sample Output:
Enter number of students: 5
Enter roll numbers in random order:
12 34 56 78 90
Enter roll number to search: 78
Student attended training program.
*/

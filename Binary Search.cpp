/*
------------------------------------------------------------
1(b) Algorithm: Binary Search
------------------------------------------------------------
1. Start
2. Input total number of students (n)
3. Store roll numbers in sorted order
4. Input roll number to search
5. Set low = 0, high = n-1
6. Repeat until low > high:
      mid = (low + high)/2
      If arr[mid] == key → print "Found" and stop
      If key < arr[mid] → high = mid - 1
      Else → low = mid + 1
7. If not found → print "Not Found"
8. Stop
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            cout << "Student attended training program.\n";
            return;
        } else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Student did not attend training program.\n";
}

int main() {
    int n, key;
    cout << "Enter number of students: ";
    cin >> n;
    int arr[n];
    cout << "Enter roll numbers in sorted order:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter roll number to search: ";
    cin >> key;
    binarySearch(arr, n, key);
    return 0;
}

/*
Sample Output:
Enter number of students: 5
Enter roll numbers in sorted order:
10 20 30 40 50
Enter roll number to search: 30
Student attended training program.
*/

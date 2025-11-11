/*
------------------------------------------------------------
2. Algorithm: Selection Sort and Bubble Sort (Top 5 Scores)
------------------------------------------------------------
1. Start
2. Input number of students (n)
3. Store their percentages in an array
4. Apply Selection Sort:
      For i = 0 to n-2
         Find minimum element from i to n-1
         Swap with arr[i]
5. Apply Bubble Sort (optional)
6. Display sorted percentages in ascending order
7. Display top 5 scores (from end of array)
8. Stop
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void selectionSort(float arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
    }
}

void bubbleSort(float arr[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    float arr[n];
    cout << "Enter percentage of students:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr, n);
    cout << "\nSorted Percentages (Ascending):\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nTop 5 Scores:\n";
    for(int i = n - 1; i >= max(0, n - 5); i--)
        cout << arr[i] << " ";
    return 0;
}

/*
Sample Output:
Enter number of students: 7
Enter percentage of students:
78.5 92.3 65.4 89.0 74.5 99.1 83.6

Sorted Percentages (Ascending):
65.4 74.5 78.5 83.6 89.0 92.3 99.1 
Top 5 Scores:
99.1 92.3 89.0 83.6 78.5
*/

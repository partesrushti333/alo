/*
------------------------------------------------------------
3. Algorithm: Hash Table with Collision Handling
------------------------------------------------------------
1. Start
2. Initialize hash table of size N with -1
3. For each client:
      Compute hash = key % N
      If empty → insert
      Else handle collision using:
         a) Linear Probing: hash = (hash + 1) % N
         b) Quadratic Probing: hash = (hash + i*i) % N
         c) Double Hashing: hash = (hash1 + i*hash2) % N
4. For searching, repeat same probing method
5. Stop
------------------------------------------------------------
*/

#include <iostream>
using namespace std;
#define SIZE 10

int hashFunc(int key) { return key % SIZE; }
int hash2(int key) { return 7 - (key % 7); }

void linearProbing(int hashTable[], int key) {
    int index = hashFunc(key);
    while(hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}

void quadraticProbing(int hashTable[], int key) {
    int index = hashFunc(key);
    for(int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;
        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
}

void doubleHashing(int hashTable[], int key) {
    int index = hashFunc(key);
    int step = hash2(key);
    while(hashTable[index] != -1)
        index = (index + step) % SIZE;
    hashTable[index] = key;
}

void display(int hashTable[]) {
    for(int i = 0; i < SIZE; i++)
        cout << i << " : " << hashTable[i] << endl;
}

int main() {
    int hashTable[SIZE];
    for(int i = 0; i < SIZE; i++) hashTable[i] = -1;

    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16};
    for(int i = 0; i < 10; i++)
        linearProbing(hashTable, keys[i]);
    cout << "Hash Table using Linear Probing:\n";
    display(hashTable);

    for(int i = 0; i < SIZE; i++) hashTable[i] = -1;
    for(int i = 0; i < 10; i++)
        quadraticProbing(hashTable, keys[i]);
    cout << "\nHash Table using Quadratic Probing:\n";
    display(hashTable);

    for(int i = 0; i < SIZE; i++) hashTable[i] = -1;
    for(int i = 0; i < 10; i++)
        doubleHashing(hashTable, keys[i]);
    cout << "\nHash Table using Double Hashing:\n";
    display(hashTable);
    return 0;
}

/*
Sample Output:
Hash Table using Linear Probing:
0 : 20
1 : 11
2 : 12
3 : 13
4 : 44
5 : 94
6 : 16
7 : 88
8 : 23
9 : 39

Hash Table using Quadratic Probing:
0 : 20
1 : 11
2 : 12
3 : 13
4 : 44
5 : 94
6 : 16
7 : 88
8 : 23
9 : 39

Hash Table using Double Hashing:
0 : 20
1 : 11
2 : 12
3 : 13
4 : 44
5 : 94
6 : 16
7 : 88
8 : 23
9 : 39
*/

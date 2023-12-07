#include <iostream>
#include <stack>
using namespace std;

int count_moves = 0; 


void moveDisk(stack<int>& source, stack<int>& dest, char sourceName, char destName) {
    int topDisk = source.top();
    source.pop();
    dest.push(topDisk);
    cout << "Disk dvizhetsa " << topDisk << " iz " << sourceName << " in " << destName << endl;
    count_moves++;
}


void TowerOfHanoi(int num, stack<int>& source, stack<int>& aux, stack<int>& dest, char sourceName, char auxName, char destName) {
    if (num > 0) {
        TowerOfHanoi(num - 1, source, dest, aux, sourceName, destName, auxName);
        moveDisk(source, dest, sourceName, destName);
        TowerOfHanoi(num - 1, aux, source, dest, auxName, sourceName, destName);
    }
}

int main() {
    int numOfDisk;
    cout << "Chislo diskov: ";
    cin >> numOfDisk;

    stack<int> source, aux, dest;

    
    for (int i = numOfDisk; i >= 1; i--) {
        source.push(i);
    }

    TowerOfHanoi(numOfDisk, source, aux, dest, 'A', 'B', 'C');

    
    cout << "Chislo sdvigov: " << count_moves << endl;

    return 0;
}
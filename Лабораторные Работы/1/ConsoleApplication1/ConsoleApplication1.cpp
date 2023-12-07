#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of characters in the vector: ";
    cin >> n;

    vector<char> vec(n);
    cout << "Enter " << n << " characters for the vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    vector<char>::iterator last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    int k;
    cout << "Enter the index of the element to be removed: ";
    cin >> k;
    vec.erase(vec.begin() + k);

    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
    for (int i = 0; i < vec.size(); i++) {
        vector<char>::iterator it = find(vowels.begin(), vowels.end(), vec[i]);
        if (it != vowels.end()) {
            vec.insert(vec.begin() + i + 1, 'A');
            i++;
        }
    }

    vector<char>::iterator max_it = max_element(vec.begin(), vec.end());
    iter_swap(vec.begin(), max_it);
    iter_swap(vec.begin(), vec.end() - 1);

    for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
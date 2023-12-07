#include <iostream>
#include <map>

using namespace std; 

int main() {
    setlocale(LC_ALL, "RUS");
    map<int, int> myMap;

    
    myMap[1] = 10;
    myMap[2] = 20;
    myMap[3] = 30;
    myMap[4] = 40;
    myMap[5] = 50;

    
    int keyToDelete = 3;
    map<int, int>::iterator it = myMap.find(keyToDelete); 
    if (it != myMap.end()) {
        myMap.erase(it);
        cout << "Элемент с ключом " << keyToDelete << " удален из контейнера." << endl;
    }
    else {
        cout << "Элемент с ключом " << keyToDelete << " не найден в контейнере." << endl;
    }

    
    if (!myMap.empty()) {
        map<int, int>::iterator maxElement = myMap.begin();
        for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
            if (it->second > maxElement->second) {
                maxElement = it;
            }
        }
        cout << "Максимальный элемент: ключ - " << maxElement->first << ", значение - " << maxElement->second << endl;
        myMap.erase(maxElement);
        cout << "Максимальный элемент удален из контейнера." << endl;
    }
    else {
        cout << "Контейнер пуст, нельзя удалить максимальный элемент." << endl;
    }

    
    double average = 0;
    for (map<int, int>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        average += it->second;
    }
    if (!myMap.empty()) {
        average /= myMap.size();
    }
    cout << "Среднее арифметическое элементов в контейнере: " << average << endl;

    
    for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        it->second += average;
    }

    
    cout << "Обновленный контейнер:" << endl;
    for (map<int, int>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "Ключ: " << it->first << ", Значение: " << it->second << endl;
    }

    return 0;
}






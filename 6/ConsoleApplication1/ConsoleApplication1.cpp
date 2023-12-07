class Person {
public:
    string FIO;
    int Age;
    char Gender;

    Person(string FIO, int Age, char Gender) : FIO(FIO), Age(Age), Gender(Gender) {}

    virtual int GetMedianIncome() const { return 0; }
    virtual int GetMedianExpenses() const { return 0; }
};

class HomeStudent : public Person {
public:
    string EducationLevel;

    HomeStudent() : Person("", 0, 'U'), EducationLevel("") {}

    HomeStudent(string FIO, int Age, char Gender, string EducationLevel) : Person(FIO, Age, Gender), EducationLevel(EducationLevel) {}

    int GetMedianIncome() const override { return 0; }
    int GetMedianExpenses() const override { return 0; }
};

class SchoolStudent : public Person {
public:
    string EducationLevel;
    int Grade;

    SchoolStudent() : Person("", 0, 'U'), EducationLevel(""), Grade(0) {}

    SchoolStudent(string FIO, int Age, char Gender, string EducationLevel, int Grade) : Person(FIO, Age, Gender), EducationLevel(EducationLevel), Grade(Grade) {}

    int GetMedianIncome() const override { return 0; }
    int GetMedianExpenses() const override { return 0; }
};

class Worker : public Person {
public:
    int Income;
    int Expenses;

    Worker(string FIO, int Age, char Gender, int Income, int Expenses) : Person(FIO, Age, Gender), Income(Income), Expenses(Expenses) {}

    int GetMedianIncome() const override { return 0; }
    int GetMedianExpenses() const override { return 0; }
};

int main() {
    int userChoice;
    cout << "Выберите тип объекта (1 - дошкольник, 2 - школьник, 3 - студент, 4 - работающий): ";
    cin >> userChoice;

    switch (userChoice) {
    case 1:
        HomeStudent homeStudent;
        cout << "Средний доход: " << homeStudent.GetMedianIncome() << endl;
        cout << "Средний расход: " << homeStudent.GetMedianExpenses() << endl;
        break;
    case 2:
        SchoolStudent schoolStudent;
        cout << "Средний доход: " << schoolStudent.GetMedianIncome() << endl;
        cout << "Средний расход: " << schoolStudent.GetMedianExpenses() << endl;
        break;
    case 3:
        Student student;
        cout << "Средний доход: " << student.GetMedianIncome() << endl;
        cout << "Средний расход: " << student.GetMedianExpenses() << endl;
        break;
    case 4:
        Worker worker;
        cout << "Средний доход: " << worker.GetMedianIncome() << endl;
        cout << "Средний расход: " << worker.GetMedianExpenses() << endl;
        break;
    default:
        cout << "Неправильный выбор. Пожалуйста, выберите один из предложенных типов объекта." << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

// Step 1: Create an abstract base class "Engine"
class Engine {
public:
    virtual void definePower() = 0;
    virtual void defineMaxRPM() = 0;
};

// Step 2: Create derived classes
class InternalCombustionEngine : public Engine {
public:
    // Step 3: Write constructors and overload input/output operators
    InternalCombustionEngine() {}
    InternalCombustionEngine(int cylinders) : cylinders(cylinders) {}
    friend ostream& operator<<(ostream& os, const InternalCombustionEngine& engine) {
        os << "Internal Combustion Engine with " << engine.cylinders << " cylinders";
        return os;
    }
    // Step 4: Override virtual methods
    void definePower() override {
        cout << "Defining power for Internal Combustion Engine" << endl;
    }
    void defineMaxRPM() override {
        cout << "Defining max RPM for Internal Combustion Engine" << endl;
    }
private:
    int cylinders;
};

// Similarly, create DieselEngine and TurbojetEngine classes following the same steps

int main() {
    InternalCombustionEngine ice1;
    InternalCombustionEngine ice2(8);
    cout << ice1 << endl;
    cout << ice2 << endl;
    ice1.definePower();
    ice2.defineMaxRPM();
    return 0;
}
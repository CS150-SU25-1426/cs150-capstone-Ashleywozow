#include "Storm.h"
#include <iostream>

using namespace std;

int main() {

    cout << "=== STORM TRACKING SYSTEM - PHASE 1 TEST ===" << endl << endl;
    
    Storm hurricane("Hurricane Katrina", "Hurricane", 5, 175.0, "Gulf Coast", "Active");
    Storm tornado("Moore Tornado", "Tornado", 5, 210.0, "Moore, Oklahoma", "Dissipated");
    
    cout << "Testing operator<< (display):" << endl;
    cout << hurricane << endl;
    cout << tornado << endl;
    
    Storm hurricane2("Hurricane Katrina", "Hurricane", 5, 175.0, "Gulf Coast", "Active");
    cout << "Testing operator== (equality):" << endl;
    cout << "Same hurricane data equal? " << (hurricane == hurricane2 ? "Yes" : "No") << endl;
    cout << "Hurricane equals tornado? " << (hurricane == tornado ? "Yes" : "No") << endl << endl;
    
    cout << "Testing getters/setters:" << endl;
    Storm testStorm;
    testStorm.setName("Test Storm");
    testStorm.setType("Thunderstorm");
    testStorm.setIntensity(3);
    testStorm.setWindSpeed(95.0);
    testStorm.setStatus("Active");
    
    cout << "Storm name: " << testStorm.getName() << endl;
    cout << "Storm type: " << testStorm.getType() << endl;
    cout << "Is active: " << (testStorm.isActive() ? "Yes" : "No") << endl << endl;
    
    cout << "=== PHASE 1 TESTING COMPLETE ===" << endl;




    return 0;
}
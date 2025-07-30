#include "StormList.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
StormList::StormList() {}

// Destructor
StormList::~StormList() {
    storms.clear();
}

// Copy constructor
StormList::StormList(const StormList& other) : storms(other.storms) {}

// Add a new storm to the list
bool StormList::addStorm(const Storm& storm) {
    try {
        storms.push_back(storm);
        return true;
    } catch (const exception& e) {
        cout << "Error adding storm: " << e.what() << endl;
        return false;
    }
}

// Edit a storm at specific index
bool StormList::editStorm(int index, const Storm& updatedStorm) {
    if (index >= 0 && index < static_cast<int>(storms.size())) {
        storms[index] = updatedStorm;
        return true;
    }
    return false;
}

// Delete a storm at specific index
bool StormList::deleteStorm(int index) {
    if (index >= 0 && index < static_cast<int>(storms.size())) {
        storms.erase(storms.begin() + index);
        return true;
    }
    return false;
}

// Find storm by name (returns pointer to storm or nullptr)
Storm* StormList::findStormByName(const string& name) {
    for (size_t i = 0; i < storms.size(); i++) {
        if (storms[i].getName() == name) {
            return &storms[i];
        }
    }
    return nullptr;
}

// Get storm at specific index
Storm* StormList::getStormAt(int index) {
    if (index >= 0 && index < static_cast<int>(storms.size())) {
        return &storms[index];
    }
    return nullptr;
}

// Find index of storm by name
int StormList::findStormIndex(const string& name) {
    for (size_t i = 0; i < storms.size(); i++) {
        if (storms[i].getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;  // Not found
}

// Get total number of storms
int StormList::getSize() const {
    return static_cast<int>(storms.size());
}

// Check if list is empty
bool StormList::isEmpty() const {
    return storms.empty();
}

// Clear all storms
void StormList::clearAll() {
    storms.clear();
}

// Overloaded stream insertion operator
ostream& operator<<(ostream& os, const StormList& s) {
	for (int i = 0; i < s.storms.size(); i++){
        os << i + 1 << ") " << "\n" <<s.storms[i] << endl;
    }
	return os;
}


// Overloaded equality operator
bool StormList::operator==(const StormList& other) const {
    if (storms.size() != other.storms.size()) {
        return false;
    }
    
    for (size_t i = 0; i < storms.size(); i++) {
        if (!(storms[i] == other.storms[i])) {
            return false;
        }
    }
    return true;
}
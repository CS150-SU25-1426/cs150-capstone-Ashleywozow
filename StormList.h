#ifndef STORMLIST_H
#define STORMLIST_H

#include "Storm.h"
#include <vector>
#include <iostream>

using namespace std;

class StormList {
private:
    vector<Storm> storms;

public:
    // Constructors
    StormList();
    ~StormList();
    
    // Copy constructor
    StormList(const StormList& other);
    
    // Core functionality - Add, Edit, Delete
    bool addStorm(const Storm& storm);
    bool editStorm(int index, const Storm& updatedStorm);
    bool deleteStorm(int index);
    
    // Search and access methods
    Storm* findStormByName(const string& name);
    Storm* getStormAt(int index);
    int findStormIndex(const string& name);
    
    // Utility methods
    int getSize() const;
    bool isEmpty() const;
    void clearAll();
    
    // Overloaded operators (required)
    friend ostream& operator<<(ostream& os, const StormList& stormList);
    bool operator==(const StormList& other) const;
};

#endif // STORMLIST_H
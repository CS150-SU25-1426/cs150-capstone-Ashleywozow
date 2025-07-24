#ifndef STORM_H
#define STORM_H

#include <string>
#include <iostream>

using namespace std;

class Storm {
private:
    string name;
    string type;        // Hurricane, Tornado, Thunderstorm, etc.
    int intensity;      // Scale of 1-5 (Category for hurricanes, EF scale for tornadoes, etc.)
    double windSpeed;   // Maximum sustained wind speed in mph
    string location;    // Current or forecasted location
    string status;      // Active, Dissipated, Forming, etc.

public:
    // Constructors
    Storm();
    Storm(const string& name, const string& type, int intensity, 
          double windSpeed, const string& location, const string& status);
    
    // Destructor - may be needed later
    ~Storm();
    
    // Copy constructor
    Storm(const Storm& other);
    
    // Assignment operator
    Storm& operator=(const Storm& other);
    
    // Getters
    string getName() const;
    string getType() const;
    int getIntensity() const;
    double getWindSpeed() const;
    string getLocation() const;
    string getStatus() const;
    
    // Setters
    void setName(const string& name);
    void setType(const string& type);
    void setIntensity(int intensity);
    void setWindSpeed(double windSpeed);
    void setLocation(const string& location);
    void setStatus(const string& status);
    
    // Overloaded operators 
    friend ostream& operator<<(ostream& os, const Storm& storm);
    bool operator==(const Storm& other) const;
    bool operator<(const Storm& other) const;  // for sorting by intensity 
    
    // Additional utility methods
    bool isActive() const;
    string getSeverityDescription() const;
};

#endif // STORM_H
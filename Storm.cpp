#include "Storm.h"
#include <iomanip>

using namespace std;

// Default constructor
Storm::Storm() : name(""), type(""), intensity(0), windSpeed(0.0), location(""), status("") {}

// Parameterized constructor
Storm::Storm(const string& name, const string& type, int intensity, 
             double windSpeed, const string& location, const string& status)
    : name(name), type(type), intensity(intensity), windSpeed(windSpeed), 
      location(location), status(status) {}

// Destructor
Storm::~Storm() {}

// Copy constructor
Storm::Storm(const Storm& other) 
    : name(other.name), type(other.type), intensity(other.intensity),
      windSpeed(other.windSpeed), location(other.location), status(other.status) {}

// Assignment operator
Storm& Storm::operator=(const Storm& other) {
    if (this != &other) {
        name = other.name;
        type = other.type;
        intensity = other.intensity;
        windSpeed = other.windSpeed;
        location = other.location;
        status = other.status;
    }
    return *this;
}

// Getters
string Storm::getName() const { return name; }
string Storm::getType() const { return type; }
int Storm::getIntensity() const { return intensity; }
double Storm::getWindSpeed() const { return windSpeed; }
string Storm::getLocation() const { return location; }
string Storm::getStatus() const { return status; }

// Setters
void Storm::setName(const string& name) { this->name = name; }
void Storm::setType(const string& type) { this->type = type; }
void Storm::setIntensity(int intensity) { 
    if (intensity >= 0 && intensity <= 5) {
        this->intensity = intensity; 
    }
}
void Storm::setWindSpeed(double windSpeed) { 
    if (windSpeed >= 0) {
        this->windSpeed = windSpeed; 
    }
}
void Storm::setLocation(const string& location) { this->location = location; }
void Storm::setStatus(const string& status) { this->status = status; }

// Overloaded stream insertion operator (operator<<)
ostream& operator<<(ostream& os, const Storm& storm) {
    os << "=== STORM DETAILS ===" << endl;
    os << "Name: " << storm.name << endl;
    os << "Type: " << storm.type << endl;
    os << "Intensity: " << storm.intensity << " (" << storm.getSeverityDescription() << ")" << endl;
    os << "Wind Speed: " << fixed << setprecision(1) << storm.windSpeed << " mph" << endl;
    os << "Location: " << storm.location << endl;
    os << "Status: " << storm.status << endl;
    os << "===================" << endl;
    return os;
}

// Overloaded equality operator (operator==)
bool Storm::operator==(const Storm& other) const {
    return (name == other.name && 
            type == other.type && 
            intensity == other.intensity &&
            windSpeed == other.windSpeed &&
            location == other.location &&
            status == other.status);
}

// Overloaded less-than operator for sorting by intensity
bool Storm::operator<(const Storm& other) const {
    if (intensity != other.intensity) {
        return intensity < other.intensity;
    }
    return windSpeed < other.windSpeed; // Secondary comparison by wind speed - if needed 
}

// Utility method to check if storm is active
bool Storm::isActive() const {
    return (status == "Active" || status == "Forming" || status == "Strengthening");
}

// Get severity description based on intensity and type (currently used for output)
string Storm::getSeverityDescription() const {
    if (type == "Hurricane") {
        switch (intensity) {
            case 1: return "Category 1 - Minimal";
            case 2: return "Category 2 - Moderate";
            case 3: return "Category 3 - Extensive";
            case 4: return "Category 4 - Extreme";
            case 5: return "Category 5 - Catastrophic";
            default: return "Tropical Depression/Storm";
        }
    } else if (type == "Tornado") {
        switch (intensity) {
            case 0: return "EF0 - Light";
            case 1: return "EF1 - Moderate";
            case 2: return "EF2 - Considerable";
            case 3: return "EF3 - Severe";
            case 4: return "EF4 - Devastating";
            case 5: return "EF5 - Incredible";
            default: return "Unrated";
        }
    } else {
        switch (intensity) {
            case 1: return "Weak";
            case 2: return "Moderate";
            case 3: return "Strong";
            case 4: return "Severe";
            case 5: return "Extreme";
            default: return "Minimal";
        }
    }
}
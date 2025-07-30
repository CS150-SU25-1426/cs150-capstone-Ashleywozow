#include "Storm.h"
#include "StormList.h"
#include <iostream>

using namespace std;

int main() {

    StormList stormTracker;
	Storm updatedStorm;
    string name;
    string type;        
    int intensity;      
    double windSpeed; 
    string location;    
    string status;

    int num;
	int choice = 0;

	do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO THE                            **\n";
		cout << "**                        STORM TRACKING SYSTEM                       **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "** 1)  Add a new Storm to the Storm Tracker                           **\n";
		cout << "** 2)  Remove a Storm from the Storm Tracker                          **\n";
		cout << "** 3)  Modify a Storm from the Storm Tracker                          **\n";
		cout << "** 4)  Display all Storms in the Storm Tracker                        **\n";
		cout << "** 5)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		cin >> choice;
    
		cin.ignore(); // To ignore the \n after choice (preventing name from being "\n")
        string hold;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter the name: ";
			getline(cin, name);
			cout << "Enter the type: ";
			getline(cin, type);
			cout << "Enter the intensity: ";
			cin >> intensity;
			cout << "Enter the wind speed: ";
			cin >> windSpeed;
            cin.ignore();
			cout << "Enter the location: ";
            getline(cin, location);
            cout << "Enter the status: ";
			getline(cin, status);

			Storm storm(name, type, intensity, windSpeed, location, status);
		
			if (stormTracker.addStorm(storm)){
				cout << "Storm added successfully!" << endl;
			}
			else {
				cout << "Storm could not be added :( " << endl;
			}


			cout << endl;
			break;
		}
		case 2:
			cout << stormTracker << endl;
			cout << "\nWhich storm would you like to remove? (by #) >> ";
			cin >> num;
			if (stormTracker.deleteStorm(num - 1)) {
		        	cout << "=== Storm #" << num << "  was removed successfully~~~\n\n";
			} else {
			        cout << "~~~Storm #" << num << " was not found\n\n";
			}
			
			break;
		case 3:
		{
			cout << stormTracker << endl;
			if (stormTracker.isEmpty()){
				cout << "No storms to edit!" << endl;
				break;
			}
			cout << "\nWhich storm would you like to modify? (by #) >> ";
			cin >> num;

			if (num > stormTracker.getSize() || num < 1){
				cout << "That is out of range please try again!" << endl;
				cout << "\nWhich storm would you like to modify? (by #) >> ";
				cin >> num;
			}

			int index = num - 1;
			Storm* currentStorm = stormTracker.getStormAt(index);
			if (currentStorm != nullptr) {
				cout << "\nCurrent storm details:" << endl;
				cout << *currentStorm << endl;
			}
			
			cout << "Enter new storm details:" << endl;
			cin.ignore();
			cout << "Enter the name: ";
			getline(cin, name);
			cout << "Enter the type: ";
			getline(cin, type);
			cout << "Enter the intensity: ";
			cin >> intensity;
			cout << "Enter the wind speed: ";
			cin >> windSpeed;
            cin.ignore();
			cout << "Enter the location: ";
            getline(cin, location);
            cout << "Enter the status: ";
			getline(cin, status);

			updatedStorm = Storm(name, type, intensity, windSpeed, location, status);
			if (stormTracker.editStorm(index, updatedStorm)) {
				cout << "Storm updated successfully!" << endl;
			} else {
				cout << "Failed to update storm!" << endl;
			}
			break;
		}		
		case 4:
			cout << stormTracker;
            cout << "\nPress Enter to Continue\n";
			getline(cin, hold);
			break;
		case 5:
			cout << "Thanks for stopping by! Remember to check your local forecast :)\n";
			break;
		}

	} while (choice != 5);
	

    return 0;
}
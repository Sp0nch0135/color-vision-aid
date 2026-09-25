

#include <iostream>

#include <string>

using namespace std;

int main()
{
    //var
    string colorBlindnessType;
    string color1;
    string color2;

    int blindnessChoice;
    int numberOfCombinations;
    int rating;

    bool difficultCombination;

    //I/O

    cout << "What type of color blindness would you like to test?" << endl;

    cout << "1. Protanopia" << endl;
    cout << "2. Deuteranopia" << endl;
    cout << "3. Tritanopia" << endl;

    cout << "Enter choice: ";
    cin >> blindnessChoice;

    //el switch
    switch (blindnessChoice)
    {
        case 1:
            colorBlindnessType = "protanopia";
            break;
        case 2:
            colorBlindnessType = "deuteranopia";
            break;
        case 3:
            colorBlindnessType = "tritanopia";
            break;
        default:
            cout << "Invalid choice." << endl;
            return 0;
    }

    cout << endl;
    
    cout << "You selected " << colorBlindnessType << endl;

    cout << "How many color combinations would you like to test? ";
    cin >> numberOfCombinations;

    cout << endl;

    // the for loopz
    for (int i = 1; i <= numberOfCombinations; i++) {
        cout << "Combination #" << i << endl;

        cout << "Enter the first color: ";
        cin >> color1;

        cout << "Enter the second color: ";
        cin >> color2;

        difficultCombination = false;
        rating = 3;

        //decisionss
        if (colorBlindnessType == "protanopia") {
            // Red and green combinations can be difficult
            if ((color1 == "red" && color2 == "green") || (color1 == "green" && color2 == "red")) {
                difficultCombination = true;
                rating = 1;
            } else if (color1 == "red" || color2 == "red" || color1 == "green" || color2 == "green") {
                rating = 2;
            }
        } else if (colorBlindnessType == "deuteranopia") {
            // Red and green combinations can also be difficult
            if ((color1 == "red" && color2 == "green") || (color1 == "green" && color2 == "red")) {
                difficultCombination = true;
                rating = 1;
            } else if (color1 == "red" || color2 == "red" || color1 == "green" || color2 == "green") {
                rating = 2;
            }
        } else if (colorBlindnessType == "tritanopia") {
            // Blue and yellow combinations can be difficult
            if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
                difficultCombination = true;
                rating = 1;
            } else if (color1 == "blue" || color2 == "blue" || color1 == "yellow" || color2 == "yellow") {
                rating = 2;
            }
        }

        cout << endl;

        //more decisions
        if (difficultCombination == true) {
            cout << color1 << " and " << color2 << " may be very difficult to differentiate for someone with " << colorBlindnessType << endl;
        } else {
            cout << color1 << " and " << color2 << " may be easier to differentiate for someone with " << colorBlindnessType << endl;
        }

        //otra decision
        if (rating == 1) { 
         cout << "Accessibility rating: POOR" << endl;
        } else if (rating == 2) {
            cout << "Accessibility rating: MODERATE" << endl;
        } else {
            cout << "Accessibility rating: GOOD" << endl;
        }
    }

    cout << endl;
    cout << "Finished evaluating the color palette." << endl;

    return 0;
}
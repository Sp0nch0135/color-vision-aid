#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

const int POOR_RATING = 1;
const int MODERATE_RATING = 2;
const int GOOD_RATING = 3;

struct Color
{
    // These values describe one color in the RGB color system.
    string name;
    int red;
    int green;
    int blue;
};

// Makes the list of color names and RGB values used by the program.
vector<Color> makeColorList();
// Changes the user's menu choice into a colorblindness type.
string getVisionType(int choice);
// Looks for the color name and copies its RGB values into selectedColor.
bool findColor(const vector<Color> &colorList, const string &colorName,
               Color &selectedColor);
// Compares two colors and returns a rating from 1 to 3.
int rateColors(const string &visionType, const Color &firstColor,
               const Color &secondColor, bool &warning);

// Runs the program and controls the user interaction.
int main()
{
    int visionChoice;
    int numberOfCombinations;
    int combinationNumber;
    string firstColorName;
    string secondColorName;
    string visionType;
    Color firstColor;
    Color secondColor;
    bool firstColorFound;
    bool secondColorFound;
    bool warning;
    int rating;
    // Stores the colors that the user can choose from.
    vector<Color> colorList;
    // Opens the report file where the results will be saved.
    ofstream report;

    colorList = makeColorList();

    cout << "RGB Color Vision Palette Advisor" << endl;
    cout << "Enter common color names such as blue, red, or green." << endl;
    cout << "1. Protanopia" << endl;
    cout << "2. Deuteranopia" << endl;
    cout << "3. Tritanopia" << endl;
    cout << "Type 1, 2, or 3 for the type you would like to test: ";
    cin >> visionChoice;

    visionType = getVisionType(visionChoice);
    if (visionType == "")
    {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "How many color combinations would you like to test? ";
    cin >> numberOfCombinations;
    if (numberOfCombinations <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    report.open("colorvision_report.txt");
    if (!report)
    {
        cout << "The report file could not be opened." << endl;
        return 1;
    }

    report << "RGB Color Vision Accessibility Report" << endl;
    report << "Vision type: " << visionType << endl;

    for (combinationNumber = 1;
         combinationNumber <= numberOfCombinations; ++combinationNumber)
    {
        cout << "Combination #" << combinationNumber << endl;
        cout << "Enter the first color: ";
        cin >> firstColorName;
        cout << "Enter the second color: ";
        cin >> secondColorName;

        firstColorFound = findColor(colorList, firstColorName, firstColor);
        secondColorFound = findColor(colorList, secondColorName, secondColor);

        if (!firstColorFound || !secondColorFound)
        {
            cout << "That color is not in the library." << endl;
            cout << "Use red, green, blue, yellow, purple, orange, pink, "
                    "brown, gray, black, or white." << endl;
            report.close();
            return 1;
        }

        cout << firstColor.name << " is RGB(" << firstColor.red << ", "
             << firstColor.green << ", " << firstColor.blue << ")." << endl;
        cout << secondColor.name << " is RGB(" << secondColor.red << ", "
             << secondColor.green << ", " << secondColor.blue << ")." << endl;

        rating = rateColors(visionType, firstColor, secondColor,
                            warning);

        if (warning)
        {
            cout << "These colors may be difficult to differentiate." << endl;
        }
        else
        {
            cout << "These colors may be easier to differentiate." << endl;
        }

        cout << "Accessibility rating: ";
        if (rating == POOR_RATING)
        {
            cout << "POOR" << endl;
        }
        else if (rating == MODERATE_RATING)
        {
            cout << "MODERATE" << endl;
        }
        else
        {
            cout << "GOOD" << endl;
        }

        report << firstColor.name << " and " << secondColor.name
               << " - rating " << rating << " out of " << GOOD_RATING
               << endl;
    }

    report.close();
    cout << "A report was saved to colorvision_report.txt." << endl;
    cout << "Finished evaluating the color palette." << endl;
    return 0;
}

// Creates and returns the small color library.
vector<Color> makeColorList()
{
    vector<Color> colorList;

    colorList.push_back({"red", 255, 0, 0});
    colorList.push_back({"green", 0, 128, 0});
    colorList.push_back({"blue", 0, 0, 255});
    colorList.push_back({"yellow", 255, 255, 0});
    colorList.push_back({"purple", 128, 0, 128});
    colorList.push_back({"orange", 255, 165, 0});
    colorList.push_back({"pink", 255, 192, 203});
    colorList.push_back({"brown", 165, 42, 42});
    colorList.push_back({"gray", 128, 128, 128});
    colorList.push_back({"black", 0, 0, 0});
    colorList.push_back({"white", 255, 255, 255});

    return colorList;
}

// Matches the user's menu choice to a colorblindness type.
string getVisionType(int choice)
{
    if (choice == 1)
    {
        return "protanopia";
    }
    if (choice == 2)
    {
        return "deuteranopia";
    }
    if (choice == 3)
    {
        return "tritanopia";
    }
    return "";
}

// Searches the vector and returns the matching RGB color.
bool findColor(const vector<Color> &colorList, const string &colorName,
               Color &selectedColor)
{
    size_t colorNumber;

    for (colorNumber = 0; colorNumber < colorList.size(); ++colorNumber)
    {
        if (colorList[colorNumber].name == colorName)
        {
            selectedColor = colorList[colorNumber];
            return true;
        }
    }
    return false;
}

// Compares RGB values and determines the accessibility rating.
int rateColors(const string &visionType, const Color &firstColor,
               const Color &secondColor, bool &warning)
{
    int totalDifference;
    bool redGreenPair;
    bool blueYellowPair;

    totalDifference = abs(firstColor.red - secondColor.red) +
                      abs(firstColor.green - secondColor.green) +
                      abs(firstColor.blue - secondColor.blue);
    redGreenPair = (firstColor.name == "red" && secondColor.name == "green") ||
                   (firstColor.name == "green" && secondColor.name == "red");
    blueYellowPair =
        (firstColor.name == "blue" && secondColor.name == "yellow") ||
        (firstColor.name == "yellow" && secondColor.name == "blue");

    warning = (visionType == "protanopia" ||
               visionType == "deuteranopia") && redGreenPair;
    warning = warning || (visionType == "tritanopia" && blueYellowPair);

    if (warning || totalDifference < 100)
    {
        return POOR_RATING;
    }
    if (totalDifference < 300)
    {
        return MODERATE_RATING;
    }
    return GOOD_RATING;
}


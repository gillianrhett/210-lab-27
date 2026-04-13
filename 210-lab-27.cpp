// COMSC 210 | Lab 27 | Gillian Rhett
#include <iostream>
#include <map>
#include <tuple>
#include <limits> // for input validation
using namespace std;

int menu();
void changeFriendship(map<string, tuple<int, string, string>>&, int);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;
    // friendship level (0-10), the villager's species (string), and the villager's catchphrase (string).

    // insert elements into the map
    villagerData["Audie"] = make_tuple(5, "Fox", "foxtrot");
    villagerData["Raymond"] = make_tuple(8, "Cat", "crisp");
    villagerData.insert({"Marshal", make_tuple(3, "Squirrel", "sulky")});
    villagerData.insert({"Hamlet", make_tuple(10, "Hamster", "hammy")});

    int choice = 0;
    while(!(1 <= choice && choice <= 4)) {
        choice = menu();
        if (choice == 1) {
        // Increase friendship

        }
        if (choice == 2) {
        // Decrease friendship

        }
        if (choice == 3) {
        // Search for vilager

        }
    }

    /*
    // access the map using a range-based for loop
    cout << "Villagers and their friendship level, species, and catchphrase (range-based for loop):" << endl;
    for (const auto& [name, data] : villagerData) {
        const auto& [friendship, species, catchphrase] = data;
        cout << "\t" << name << "'s friendship level is " << friendship 
        << ", species is " << species 
        << ", and catchphrase is " << catchphrase << "." << endl;
    }
    cout << endl;

    // access the map using iterators
    cout << "\nVillagers and their friendship level, species, and catchphrase (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
        it != villagerData.end(); ++it) 
    {
        cout << "\t" << it->first << "'s friendship level is " << get<0>(it->second) << ", species is " << get<1>(it->second) << ", and catchphrase is " << get<2>(it->second) << "." << endl;
    }
    cout << endl;

    // delete an element
    villagerData.erase("Raymond");
    // access the map using iterators
    cout << "\nNew list of villagers after deletion:" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
        it != villagerData.end(); ++it) 
    {
        cout << "\t" << it->first << endl;
    }
    cout << endl;

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s data: friendship level is " << get<0>(it->second) 
        << ", species is " << get<1>(it->second) << ", and catchphrase is " << get<2>(it->second) 
        << "." << endl;
    } 
    else
        cout << endl << searchKey << " not found." << endl;
    
    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;
    */
    return 0;
}

int menu() {
// display the menu and return the choice the user picked
    int choice = 0;
    cout << "1. Increase Friendship\n2. Decrease Friendship\n3. Search for Villager\n4. Exit" << endl;
    cout << "Enter your choice: ";
    while (!(choice >= 1 && choice <=4)) {
        try {
            cin >> choice;
            if (cin.fail() || !(choice >= 1 && choice <=4))
                throw invalid_argument("Invalid input. Enter a number 1, 2, 3, or 4.");
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

void changeFriendship(map<string, tuple<int, string, string>>& m, int amt) {
// change every villager's friendship by the given amount
    for (map<string, tuple<int, string, string>>::iterator it = m.begin(); 
        it != m.end(); ++it) 
    {
        get<0>(it->second) += amt;
    }
}
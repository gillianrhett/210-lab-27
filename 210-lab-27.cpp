// COMSC 210 | Lab 27 | Gillian Rhett
#include <iostream>
#include <map>
#include <tuple>
#include <limits> // for input validation
#include <string> // for getline
using namespace std;

int menu();
void changeFriendship(map<string, tuple<int, string, string>>&, string, int);
string searchForVillager(const map<string, tuple<int, string, string>>&);
void displayVillagerDetails(map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&, string);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;
    // friendship level (0-10), the villager's species (string), and the villager's catchphrase (string).

    // insert elements into the map
    villagerData["Audie"] = make_tuple(5, "Fox", "foxtrot");
    villagerData["Raymond"] = make_tuple(8, "Cat", "crisp");
    villagerData.insert({"Marshal", make_tuple(3, "Squirrel", "sulky")});

    int choice = 1;
    while((1 <= choice && choice < 6)) {
        choice = menu();
        if (choice == 1) {
        // Add a villager
            addVillager(villagerData);
        }
        if (choice == 2) {
        // Delete a villager
            string name = searchForVillager(villagerData);
            if (name != "")
                deleteVillager(villagerData, name);
        }
        if (choice == 3) {
        // Increase friendship for a given villager
            string name = searchForVillager(villagerData);
            if (name != "")
                changeFriendship(villagerData, name, 1);
        }
        if (choice == 4) {
        // Decrease friendship for a given villager
            string name = searchForVillager(villagerData);
            if (name != "")
                changeFriendship(villagerData, name, -1);
        }
        if (choice == 5) {
        // Search for vilager
            string name = searchForVillager(villagerData);
            if (name != "")
                cout << name << " found." << endl;
            else
                cout << name << "not found." << endl;
        }
        if (choice == 6)
            cout << "Goodbye." << endl;
        
        // display the map contents after each operation
        displayVillagerDetails(villagerData);
    }

    /* from milestone 2
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
    cout << "1. Add villager\n2. Delete villager\n3. Increase Friendship"
    << "\n4. Decrease Friendship\n5. Search for Villager\n6. Exit" << endl;
    cout << "Enter your choice: ";
    while (!(choice >= 1 && choice <=6)) {
        try {
            cin >> choice;
            if (cin.fail() || !(choice >= 1 && choice <=6))
                throw invalid_argument("Invalid input. Enter a number 1, 2, 3, 4, 5, or 6.");
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

void changeFriendship(map<string, tuple<int, string, string>>& m, string name, int amt) {
// change this villager's friendship by the given amount
    auto it = m.find(name);
    if (it != m.end()) { // Key exists, safe to use .at()
        if(get<0>(m.at(name)) + amt >= 0 || get<0>(m.at(name)) + amt > 10) // make sure this change won't make friendship negative
            get<0>(m.at(name)) += amt;
        else
            cout << "Error: friendship can only be 0 to 10." << endl;
    }
    else
    // name not found; this part is only necessary if we call this without first calling SearchForVillager
        cout << name << " not found." << endl;
}

string searchForVillager(const map<string, tuple<int,string,string>>& m) {
// take user input of name and return it if it's present in the map
    string searchKey;
    cout << "Enter the name of the villager: ";
    cin.ignore();
    getline(cin, searchKey);
    auto it = m.find(searchKey);
    if (it != m.end())
        return searchKey;
    else {
        cout << endl << searchKey << " not found." << endl;
        return "";
    }
}

void displayVillagerDetails(map<string, tuple<int, string, string>>& m) { // I wanted to make the parameter const but that caused an error
// output the data on every villager
    cout << "\nVillagers:" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = m.begin(); 
        it != m.end(); ++it) 
    {
        cout << "\t" << it->first << "'s friendship level is " << get<0>(it->second) << ", species is " << get<1>(it->second) << ", and catchphrase is " << get<2>(it->second) << "." << endl;
    }
    cout << endl;
}

void addVillager(map<string, tuple<int, string, string>>& m) {
// get user input to add a new villager to the map
    // get the user input
    string name;
    int friendship = -1;
    string species;
    string catchphrase;
    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    while (friendship < 0) {
        try {
            cin >> friendship;
            if (cin.fail() || friendship < 0)
                throw invalid_argument("Invalid input. Enter a number greater than or equal to zero: ");
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Species: ";
    cin >> species;
    cout << "Catchphrase: ";
    cin >> catchphrase;

    // add the new villager to the map
    m.insert({name, make_tuple(friendship, species, catchphrase)});
    cout << name << " added." << endl;
}

void deleteVillager(map<string, tuple<int, string, string>>& m, string name) {
// delete the villager with the name given
    auto it = m.find(name);
    if (it != m.end()) // Key exists, safe to use .at()
        m.erase(name);
    else
    // name not found; this part is only necessary if we call this without first calling SearchForVillager
        cout << name << " not found." << endl;
}
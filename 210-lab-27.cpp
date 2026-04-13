// COMSC 210 | Lab 27 | Gillian Rhett
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;
    // friendship level (0-10), the villager's species (string), and the villager's catchphrase (string).

    // insert elements into the map
    villagerData["Audie"] = {5, "Fox", "foxtrot"};
    villagerData["Raymond"] = {8, "Cat", "crisp"};
    villagerData.insert({"Marshal", {3, "Squirrel", "sulky"}});

    // access the map using a range-based for loop
    cout << "Villagers and their friendship level, species, and catchphrase (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": "; // this is the key, which is the villager's
        for (const auto& [name, data] : villagerData) {
            const auto& [friendship, species, catchphrase] = data;
            cout << name << "'s friendship level is " << friendship 
            << ", species is " << species 
            << ", and catchphrase is " << catchphrase << endl;
        }
        cout << endl;
    }
/* commenting out not-done-yet part to test the above parts
    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;
*/
    return 0;
}

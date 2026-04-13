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
    villagerData["Audie"] = make_tuple(5, "Fox", "foxtrot");
    villagerData["Raymond"] = make_tuple(8, "Cat", "crisp");
    villagerData.insert({"Marshal", make_tuple(3, "Squirrel", "sulky")});

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
        cout << "\nFound " << searchKey << "'s data: " << endl;
        cout << "Friendship level is " << get<0>(it->second) << endl;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;
    /* commenting out not-done-yet part to test the above parts
    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;
*/
    return 0;
}

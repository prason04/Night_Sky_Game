#ifndef ITEMBANK_H
#define ITEMBANK_H

#include <iostream>
using namespace std;
#include <vector>
#include <string>

class ItemBank {
private:
    vector<string> items;

public:

    ItemBank() {
        // Add the initial items to the vector
        items.push_back("Andromeda Galaxy (Messier 31)");
        items.push_back("Triangulum Galaxy (Messier 33)");

        /////
        loadItemsFromFile("ItemBank.txt");
    }

    // function: reads through the txt file full of items and finds a match to the items needed
    bool findItemInFile(string neededItem);
    // function: removes item from vector if player decides to use item
    bool removeItem(string item);
    // function: if player chooses to add galaxy to the vector, add to vector

    // function: outcome of random function is added to the vector/file if player decides to add it
    void addGalaxyName(const string& name);

    //////////

    // Function: display the items in the Item Bank
    void displayItems() const;

    private:
    // Function: load items from the file
    void loadItemsFromFile(const std::string& fileName);

    // Function: save items to the file
    void saveItemsToFile(const std::string& fileName) const;


    // void addGalaxyName(const name);
    // void displayGalaxyNames() const;
};

#endif 
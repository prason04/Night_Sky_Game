#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "ItemBank.h"

/*

bool ItemBank::findItemInFile(string neededItem) {
    std::ifstream inFile("ItemBank.txt"); // Open the file

    if (!inFile.is_open()) {
        cout << "Unable to open file." << endl;
        return false;
    }

    string item;
    while (getline(inFile, item)) {
        if (item == neededItem) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}

bool ItemBank::removeItem(string item) {
    // Remove from vector
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            break;
        }
    }

    // Rewrite the file without the removed item
    ofstream outFile("ItemBank.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open file for writing." << endl;
        return false;
    }

    for (const string& itemName : items) {
        outFile << itemName << endl;
    }

    outFile.close();
    return true;
}

void ItemBank::addGalaxyName(const string& name) {
    // Add the galaxy name to the vector
    items.push_back(name);

    // Optionally, you can save the updated items to the file as well
    ofstream outFile("ItemBank.txt", ios::app); // Open the file in append mode
    if (!outFile) {
        cerr << "Failed to open ItemBank.txt for writing" << endl;
        return;
    }

    outFile << name << endl; // Write the new galaxy name to the file
    outFile.close();
}

void ItemBank::loadItemsFromFile(const std::string& fileName) {
    items.clear(); // Clear the vector to reload items from the file

    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    std::string item;
    while (std::getline(inFile, item)) {
        items.push_back(item);
    }

    inFile.close();
}
*/
bool ItemBank::findItemInFile(string neededItem) {
    for (const std::string& item : items) {
        if (item == neededItem) {
            return true;
        }
    }
    return false;
}

bool ItemBank::removeItem(string item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        saveItemsToFile("ItemBank.txt"); // Save the updated items to the file
        return true;
    }
    return false;
}

void ItemBank::addGalaxyName(const std::string& name) {
    items.push_back(name);
    saveItemsToFile("ItemBank.txt"); // Save the updated items to the file
}

void ItemBank::loadItemsFromFile(const std::string& fileName) {
    items.clear(); // Clear the vector to reload items from the file

    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    std::string item;
    while (std::getline(inFile, item)) {
        items.push_back(item);
    }

    inFile.close();
}

void ItemBank::saveItemsToFile(const std::string& fileName) const {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    for (const std::string& item : items) {
        outFile << item << std::endl;
    }

    outFile.close();
}
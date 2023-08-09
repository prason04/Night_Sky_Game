#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GameMap.h"
#include "ItemBank.h"
#include "Games.h"
//#include "Games.cpp"
#include <algorithm> // For std::shuffle
#include <random> // For std::default_random_engine
using namespace std;

int main() {
    // Introduction
    cout << "Welcome fellow astronomer to (game's name)! In this game you will be creating your own night sky." << endl;
    cout << "As you do, you will also learn about what lies within the cosmos! Are you ready?" << endl;
    cout << "Please input Yes or No: " << endl;

    // Option: Yes / No
    string choice;
    cin >> choice;
    if (choice == "Yes") {
        // Instructions
        cout << " " << endl;
        cout << "Onwards then, fellow astronomer! Here is what awaits you: " << endl;
        cout << " " << endl;

        cout << "INSTRUCTIONS: " << endl;
        cout << " " << endl;

        cout << "MAPS" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "You will start off by selecting a map type of your choice, followed by selecting the level you'd like to play at." << endl;
        cout << "There are four map levels: easy, medium, hard, and timed." << endl;
        cout << "However for each map, it is up to you to win the items in that map to create your beautiful night sky!" << endl;
        cout << "To win these items, you can play some small astronomy-themed games." << endl;

        cout << " " << endl;

        cout << "PINS" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "With each map level that you complete, you also earn a pin!" << endl;
        cout << "There are four pins you can earn, one for each of the level." << endl;
        cout << "Once you have earned all the pins, you win the game!" << endl;

        cout << " " << endl;
        cout << "Good luck astronomer!" << endl;
        cout << " " << endl;

        // Fixed Map or Random Map?
        cout << "Time to choose a map! There are two types: " << endl;
        
        cout << "Fixed Map: the player can choose the format of their map from the ones shown to them." << endl;
        cout << "Random Map: items are scattered around the map at random by the game, though the level is still chosen by the player." << endl;

        cout << "Which map would you like to choose, a Fixed Map or a Random Map? Answer with F for Fixed Map and R for Random Map!" << endl;

        char mapChoice;
        cin >> mapChoice;
        cout << endl;

        // Fixed Map
        if (mapChoice == 'F') {
            cout << "Nothing wrong with seeing your options!" << endl;
            cout << "What difficulty level would you like to choose? Insert Easy, Medium, Hard, or Timed." << endl;
            string fixedLevel;
            cin >> fixedLevel;

            if (fixedLevel == "Easy") {

                cout << "Here are all the maps for the Easy level!" << endl;
                cout << " " << endl;
                // read maps from txt files
                string file1 = "FixedMaps.txt";
                ifstream inFile1;
                inFile1.open(file1);

                string line = "";
                if(inFile1.is_open()) {
                    // cout << endl;
                    while(getline(inFile1,line)) {
                        cout << line << endl;
                    }
                }
                inFile1.close();
                // ask which map the player would like to choose
                cout << " " << endl;
                cout << "Which one would you like to choose? Insert a number from 1 to 4: " << endl;
                int mapType;
                cin >> mapType;
                if (mapType == 1) {
                    cout << "You chose Map 1!" << endl;
                    GameMap map;
                    cout << " " << endl;

                    assert(map.addGalaxy(5, 7));
                    assert(map.addGalaxy(13, 12));

                    assert(map.addConstellation(2, 11));
                    assert(map.addConstellation(7, 3));
                    assert(map.addConstellation(14, 7));

                    assert(map.addStar(8, 13));
                    assert(map.addStar(13, 1));

                    assert(map.addPlanet(1, 3));
                    assert(map.addPlanet(10, 5));

                    map.displayMap();

                    cout << " " << endl;
                    cout << "In this map, you have to find these items: " << endl;
                    cout << " " << endl;
                    cout << "Galaxies: Andromeda Galaxy (Messier 31), Triangulum Galaxy (Messier 33)" << endl;
                    cout << "Constellations: Aquarius, Cancer, Gemini" << endl;
                    cout << "Stars: Sirius, Canopus" << endl;
                    cout << "Planets: Mercury, Venus" << endl;

                    // instructions for directions, repeatedly displays until g, c, s, p, or e is hit
                    cout << " " << endl;
                    cout << "Directions to move around the map:" << endl;
                    cout << "Up - Letter: w" << endl;
                    cout << "Down - Letter: s" << endl;
                    cout << "Right - Letter: d" << endl;
                    cout << "Left - Letter: a" << endl;
                    cout << "Exit - Letter: e" << endl;
                    cout << " " << endl;
                    char direction;
                    
                    while (true) {
                        // while (map.containsLowercaseLetters()) {}
                        map.displayMap();
                        cout << "Which direction would you like to go? Insert the letter (e for exit): " << endl;
                        cin >> direction;
                        switch (direction) {
                            case 'w':
                            case 's':
                            case 'd':
                            case 'a':
                                map.move(direction);
                                break;
                            case 'e':
                                // Exit the loop and end the game
                                cout << "Goodbye! Thank you for playing!" << endl;
                                return 0;
                            default:
                                cout << "Invalid input. Please enter w, s, d, a, or e." << endl;
                        }

                        ItemBank itemBank;
                        string neededItem;
                        string item;

                        // Galaxy (g)
                        if(map.isGalaxyLocation(map.getPlayerRow(),map.getPlayerCol())) {
                            cout << "You've stumbled upon a galaxy! Would you like to find this galaxy for your map?" << endl;
                            cout << "Insert Yes or No: ";
                            string galaxy1;
                            cin >> galaxy1;
                            if (galaxy1 == "Yes") {
                                // tell player what items (galaxies) they need
                                cout << "NOTE: For this map, you need to find the Andromeda Galaxy (Messier 31) and the Triangulum Galaxy (Messier 33)! Let's go!" << endl;

                                // check in Item Bank to see if galaxy has already been found

                                neededItem = "Andromeda Galaxy (Messier 31)";
                                bool foundItem1 = itemBank.findItemInFile(neededItem);

                                neededItem = "Triangulum Galaxy (Messier 33)";
                                bool foundItem2 = itemBank.findItemInFile(neededItem);

                                // Check if the Andromeda Galaxy (Messier 31) is in the Item Bank
                                if (foundItem1) {
                                    cout << "The Andromeda Galaxy (Messier 31) is in your Item Bank." << endl;
                                    cout << "Would you like to use it? (Yes/No): ";
                                    string use;
                                    cin >> use;
                                    if (use == "Yes") {
                                        use = "Andromeda Galaxy (Messier 31)";
                                        itemBank.removeItem("Andromeda Galaxy (Messier 31)");

                                        int playerRow = map.getPlayerRow();
                                        int playerCol = map.getPlayerCol();
                                        map.useAndromedaGalaxy(playerRow, playerCol);
                                    }
                                    else {
                                        cout << "This item will remain in your Item Bank." << endl;
                                    }
                                }
                                else {
                                    cout << "The Andromeda Galaxy (Messier 31) is not in your Item Bank." << endl;
                                    cout << "Would you like to play a game to win it? (Yes/No): ";
                                    string winItem;
                                    cin >> winItem;
                                    if (winItem == "Yes") {

                                        // Create a Game object to play the trivia game
                                        Game triviaGame;

                                        // Start the trivia game to win the Andromeda Galaxy (Messier 31)
                                        bool playerWon = triviaGame.startTriviaGame();

                                        if (playerWon) {
                                            // Add the Andromeda Galaxy (Messier 31) to the Item Bank
                                            itemBank.addGalaxyName("Andromeda Galaxy (Messier 31)");
                                            // Check again if the Andromeda Galaxy is found and ask to use

                                            // Check again if the Andromeda Galaxy is found in the Item Bank
                                            if (itemBank.findItemInFile("Andromeda Galaxy (Messier 31)")) {
                                                cout << "Andromeda Galaxy (Messier 31) is found in the Item Bank!" << std::endl;
                                                cout << "Do you want to use it? (Yes/No): ";
                                                string response;
                                                cin >> response;
                                                if (response == "Yes") {
                                                    response = "Andromeda Galaxy (Messier 31)";
                                                    itemBank.removeItem("Andromeda Galaxy (Messier 31)");
                                                    int playerRow = map.getPlayerRow();
                                                    int playerCol = map.getPlayerCol();
                                                    map.useAndromedaGalaxy(playerRow, playerCol);
                                                    
                                                } else {
                                                    cout << "This item shall remain in your Item Bank for later use!" << endl;
                                                }
                                            } else {
                                                cout << "Andromeda Galaxy (Messier 31) is not found in the Item Bank." << endl;
                                                // Continue with the game
                                            }
                                        }
                                        else {
                                            cout << "Better luck next time! The Andromeda Galaxy (Messier 31) remains unclaimed." << endl;
                                        }
                                    }
                                    else {
                                        cout << "Onwards, then!" << endl;
                                    }
                                }

                                // Check if the Triangulum Galaxy (Messier 33) is in the Item Bank
                                if (foundItem2) {
                                    cout << "The Triangulum Galaxy (Messier 33) is in your Item Bank." << endl;
                                    cout << "Would you like to use it? (Yes/No): ";
                                    string use2;
                                    cin >> use2;
                                    if (use2 == "Yes") {
                                        use2 = "Triangulum Galaxy (Messier 33)";
                                        itemBank.removeItem("Triangulum Galaxy (Messier 33)");
                                        if (foundItem1) {
                                            cout << "The Andromeda Galaxy (Messier 31) is in your Item Bank." << endl;
                                            cout << "Would you like to use it? (Yes/No): ";
                                            string use;
                                            cin >> use;
                                            if (use == "Yes") {
                                                use = "Andromeda Galaxy (Messier 31)";
                                                itemBank.removeItem("Andromeda Galaxy (Messier 31)");
                                            }
                                            else {
                                                cout << "This item will remain in your Item Bank." << endl;
                                            }
                                        }
                                    }
                                    else {
                                        cout << "This item will remain in your Item Bank." << endl;
                                    }
                                }
                                else {
                                    cout << "The Triangulum Galaxy (Messier 33) is not in your Item Bank." << endl;
                                    cout << "Would you like to play a game to win it? (Yes/No): ";
                                    string winItem;
                                    cin >> winItem;
                                    if (winItem == "Yes") {
                                        
                                    }
                                    else {
                                        cout << "Onwards, then!" << endl;
                                    }
                                }

                                // play game to win galaxy
                                // cout << "To win a galaxy, you have to play the following game: " << endl;
                                // Add game here
                                    // ISSUE: how to deal with a player's outcome, when to generate a random galaxy when player wins
                                    // ISSUE: how to keep adding items to item bank (vector? array?)

                            }
                            else if (galaxy1 == "No") {
                                // no need to put anything here
                            }
                            else {
                                cout << "Invalid input, please try again!" << endl;
                            }
                        }
                        // Constellation (c)
                        // Star (s)
                        // Planet (p)

                    }





                }
                if (mapType == 2) {
                    cout << "You chose Map 2!" << endl;
                    GameMap map;
                    cout << " " << endl;

                    assert(map.addGalaxy(1, 4));
                    assert(map.addGalaxy(9, 9));

                    assert(map.addConstellation(4, 6));
                    assert(map.addConstellation(11, 2));
                    assert(map.addConstellation(13, 12));

                    assert(map.addStar(3, 12));
                    assert(map.addStar(14, 6));

                    assert(map.addPlanet(6, 2));
                    assert(map.addPlanet(8, 14));

                    map.displayMap();
                }
                if (mapType == 3) {
                    cout << "You chose Map 3!" << endl;
                    GameMap map;
                    cout << " " << endl;

                    assert(map.addGalaxy(2, 13));
                    assert(map.addGalaxy(5, 5));
                    assert(map.addGalaxy(10, 13));

                    assert(map.addConstellation(1, 3));
                    assert(map.addConstellation(6, 14));
                    assert(map.addConstellation(12, 5));

                    assert(map.addStar(4, 1));
                    assert(map.addStar(8, 9));
                    assert(map.addStar(14, 13));

                    assert(map.addPlanet(4, 10));
                    assert(map.addPlanet(8, 2));

                    map.displayMap();
                }
                if (mapType == 4) {
                    cout << "You chose Map 4!" << endl;
                    GameMap map;
                    cout << " " << endl;

                    assert(map.addGalaxy(2, 8));
                    assert(map.addGalaxy(9, 5));
                    assert(map.addGalaxy(14, 13));

                    assert(map.addConstellation(1, 2));
                    assert(map.addConstellation(6, 10));
                    assert(map.addConstellation(13, 1));

                    assert(map.addStar(4, 13));
                    assert(map.addStar(6, 1));
                    assert(map.addStar(12, 11));

                    assert(map.addPlanet(9, 13));

                    map.displayMap();
                }
            }
            else if (fixedLevel == "Medium") {
                cout << "TBA" << endl;
            }
            else if (fixedLevel == "Hard") {
                cout << "TBA" << endl;
            }
            else if (fixedLevel == "Timed") {
                cout << "TBA" << endl;
            }
            else {
                cout << "Oops! That doesn't seem to be an option! Try again!" << endl;
            }
        }
        // Random Map
        else if (mapChoice == 'R') {
            cout << "TBA" << endl;
        }
        // Other Inputs (Invalid)
        else {
            cout << "Invalid choice: Input either F or R." << endl;
        }
    }
    else {
        cout << "Perhaps another day then!" << endl;
    }
}
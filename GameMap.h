#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>

using namespace std;

class GameMap
{
private:
    const char OPENSPACE = '-'; // marker for unexplored spaces
    const char GALAXIES = 'g'; // marker for galaxies
    const char CONSTELLATIONS = 'c'; // marker for constellations
    const char STARS = 's'; // marker for stars
    const char PLANETS = 'p'; // marker for planets
    const char COMETS = 'o'; // marker for comets
    const char ASTEROIDS = 'a'; // marker for asteroids
    const char SATELLITES = 't'; // marker for satellites
    const char STARCLUSTERS = 'l'; // marker for star clusters
    const char NEBULAE = 'n'; // marker for nebulae
    const char PARTY = 'X';      // marker for party position
    // const char EXPLORED = ' ';   // marker for explored spaces

    static const int num_rows_ = 16; // number of rows in map
    static const int num_cols_ = 16; // number of columns in map
    static const int max_galaxies_ = 3; // max galaxies
    static const int max_constellations_ = 3; // max constellations
    static const int max_stars_ = 3; // max stars
    static const int max_planets_ = 2; // max planets
    
    /*
    static const int max_npcs_ = 5;  // max non-player characters
    static const int max_monsters_ = 5; // max monsters
    static const int max_rooms_ = 5; // max number of rooms
    static const int max_spaces_ = 5; // max number of normal spaces
    */

    int player_position_[2];              // player position (row,col)
    int galaxies_positions_[max_galaxies_][3]; // stores the (row,col) positions of galaxies present on map and if they have been found
    int constellations_positions_[max_constellations_][3]; // stores the (row,col) positions of constellations present on map and if they have been found
    int stars_positions_[max_stars_][3]; // stores the (row,col) positions of stars present on map and if they have been found
    int planets_positions_[max_planets_][3]; // stores the (row,col) positions of planets present on map and if they have been found
    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

    /*
    int npc_positions_[max_npcs_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int monster_positions_[max_monsters_][3]; // stores the (row,col) positions of monsters present on map and if they have been found
    int room_positions_[max_rooms_][2];   // stores the (row,col) positions of rooms present on map
    int space_positions_[max_spaces_][2]; // stores the (row,col) positions of spaces present on map
    //int dungeon_exit_[2];                 // exit location of the dungeon
    */

    int galaxies_count_;  // stores number of galaxies currently on map
    int constellations_count_; // stores number of constellations currently on map
    int stars_count_; // stores number of stars currently on map
    int planets_count_; // stores the number of spaces currently on map

    bool andromedaGalaxyUsed_ = false;

public:
    GameMap();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    bool isOnMap(int row, int col);
    int getNumRows();
    int getNumCols();
    bool isGalaxyLocation(int row, int col);
    bool isConstellationLocation(int row, int col);
    bool isStarLocation(int row, int col);
    bool isPlanetLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);

    // other
    bool addGalaxy(int row, int col);
    bool addConstellation(int row, int col);
    bool addStar(int row, int col);
    bool addPlanet(int row, int col);
    void exploreSpace(int row, int col);
    bool move(char);
    void displayMap();

    void useAndromedaGalaxy(int playerRow, int playerCol);

    /*
    // int getDungeonExitRow();
    // int getDungeonExitCol();
    int getRoomCount();
    int getNPCCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isNPCLocation(int row, int col);
    bool isRoomLocation(int row, int col);
    bool isSpaceLocation(int row, int col); // added function
    bool isMonsterLocation(int row, int col); // added function
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);
    bool isDungeonExit(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);
    void setDungeonExit(int row, int col);

    // other
    void displayMap();
    bool move(char); //look
    bool addNPC(int row, int col);
    bool addRoom(int row, int col);
    bool addSpace(int row, int col); // added function
    bool addMonster(int row, int col); // added function
    bool removeNPC(int row, int col);
    bool removeRoom(int row, int col);
    void exploreSpace(int row, int col);
    */
};

#endif
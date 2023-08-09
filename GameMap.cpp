#include "GameMap.h"

using namespace std;

GameMap::GameMap()
{
    resetMap();
}

void GameMap::resetMap() {
    // Reset the map data to represent unexplored spaces ('-') initially
    for (int row = 0; row < num_rows_; ++row)
    {
        for (int col = 0; col < num_cols_; ++col)
        {
            map_data_[row][col] = OPENSPACE;
        }
    }

    // Reset the player position to a default location
    player_position_[0] = 0; // Set the player's row position to 0 (top row)
    player_position_[1] = 0; // Set the player's column position to 0 (first column)

    // Reset the celestial object positions and their found status
    galaxies_count_ = 0; // No galaxies initially
    constellations_count_ = 0; // No constellations initially
    stars_count_ = 0; // No stars initially
    planets_count_ = 0; // No planets initially

    // Clear the celestial object positions array and set the found status to false
    for (int i = 0; i < max_galaxies_; ++i)
    {
        galaxies_positions_[i][0] = -1; // Invalid row position
        galaxies_positions_[i][1] = -1; // Invalid column position
        galaxies_positions_[i][2] = false; // Not found yet
    }

    for (int i = 0; i < max_constellations_; ++i)
    {
        constellations_positions_[i][0] = -1; // Invalid row position
        constellations_positions_[i][1] = -1; // Invalid column position
        constellations_positions_[i][2] = false; // Not found yet
    }

    for (int i = 0; i < max_stars_; ++i)
    {
        stars_positions_[i][0] = -1; // Invalid row position
        stars_positions_[i][1] = -1; // Invalid column position
        stars_positions_[i][2] = false; // Not found yet
    }

    for (int i = 0; i < max_planets_; ++i)
    {
        planets_positions_[i][0] = -1; // Invalid row position
        planets_positions_[i][1] = -1; // Invalid column position
        planets_positions_[i][2] = false; // Not found yet
    }
}

// return player's row position
int GameMap::getPlayerRow()
{
    return player_position_[0];
}

// return player's column position
int GameMap::getPlayerCol()
{
    return player_position_[1];
}

// set player position, if in range
void GameMap::setPlayerPosition(int row, int col)
{
    if (isOnMap(row, col))
    {
        player_position_[0] = row;
        player_position_[1] = col;
    }
}

// returns member variable num_rows_
int GameMap::getNumRows()
{
    return num_rows_;
}

// returns member variable num_cols_
int GameMap::getNumCols()
{
    return num_cols_;
}

bool GameMap::isOnMap(int row, int col)
{
    if (0 <= row && row < num_rows_ && 0 <= col && col < num_cols_)
    {
        return true;
    }
    return false;
}

// if the player character lands on a Galaxy
bool GameMap::isGalaxyLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < galaxies_count_; i++)
    {
        if (row == galaxies_positions_[i][0] && col == galaxies_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

// if the player character lands on a Constellation
bool GameMap::isConstellationLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < constellations_count_; i++)
    {
        if (row == constellations_positions_[i][0] && col == constellations_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

// if the player character lands on a Star
bool GameMap::isStarLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < stars_count_; i++)
    {
        if (row == stars_positions_[i][0] && col == stars_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

// if the player character lands on a Planet
bool GameMap::isPlanetLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < planets_count_; i++)
    {
        if (row == planets_positions_[i][0] && col == planets_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

bool GameMap::isExplored(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }

    char positionCharacter = map_data_[row][col];

    // If the position character is lowercase, it means it has been explored
    if (positionCharacter >= 'a' && positionCharacter <= 'z')
    {
        return false;
    }

    // If the position character is uppercase, it means it is unexplored
    if (positionCharacter >= 'A' && positionCharacter <= 'Z')
    {
        return true;
    }

    // If the character is neither lowercase nor uppercase, it means it's neither explored nor unexplored
    // You can handle any other special characters or empty spaces here if needed.

    // For any other cases, assume the position is unexplored
    return false;
}

bool GameMap::isFreeSpace(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (isGalaxyLocation(row, col))
    {
        return false;
    }
    if (isConstellationLocation(row, col))
    {
        return false;
    }
    if (isStarLocation(row, col))
    {
        return false;
    }
    return true;
}

bool GameMap::addGalaxy(int row, int col)
{
    if (galaxies_count_ >= max_galaxies_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    galaxies_positions_[galaxies_count_][0] = row;
    galaxies_positions_[galaxies_count_][1] = col;
    galaxies_positions_[galaxies_count_][2] = false;
    galaxies_count_++;
    map_data_[row][col] = GALAXIES;
    return true;
}

bool GameMap::addConstellation(int row, int col)
{
    if (constellations_count_ >= max_constellations_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    constellations_positions_[constellations_count_][0] = row;
    constellations_positions_[constellations_count_][1] = col;
    constellations_positions_[constellations_count_][2] = false;
    constellations_count_++;
    map_data_[row][col] = CONSTELLATIONS;
    return true;
}

bool GameMap::addStar(int row, int col)
{
    if (stars_count_ >= max_stars_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    stars_positions_[stars_count_][0] = row;
    stars_positions_[stars_count_][1] = col;
    stars_positions_[stars_count_][2] = false;
    stars_count_++;
    map_data_[row][col] = STARS;
    return true;
}

bool GameMap::addPlanet(int row, int col)
{
    if (planets_count_ >= max_planets_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    planets_positions_[planets_count_][0] = row;
    planets_positions_[planets_count_][1] = col;
    planets_positions_[planets_count_][2] = false;
    planets_count_++;
    map_data_[row][col] = PLANETS;
    return true;
}

void GameMap::exploreSpace(int row, int col)
{
    // Check if it's already explored or if it's outside the map boundaries
    if (isExplored(row, col) || !isOnMap(row, col))
    {
        return;
    }

    if (andromedaGalaxyUsed_ && map_data_[row][col] == 'g')
    {
        map_data_[row][col] = 'G';
    }
    else
    {
        // If it's an unexplored position, mark it as explored by converting to lowercase
        map_data_[row][col] = tolower(map_data_[row][col]);
    }


    // If it's an unexplored position, mark it as explored by converting to lowercase
    // map_data_[row][col] = tolower(map_data_[row][col]);

    // If it's an unexplored position, mark it as explored by converting to lowercase
    // map_data_[row][col] = tolower(map_data_[row][col]);
}

bool GameMap::move(char direction)
{
    // check input char and move accordingly
    switch (tolower(direction))
    {
    case 'w': // if user inputs w, move up if it is an allowed move
        if (player_position_[0] > 0)
        {
            player_position_[0] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1)
        {
            player_position_[0] += 1;
        }
        else
        {
            return false;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0)
        {
            player_position_[1] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1)
        {
            player_position_[1] += 1;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }
    // if new location is an NPC location, mark as explored
    if (isGalaxyLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    if (isConstellationLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    if (isStarLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    if (isPlanetLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    return true;
}

void GameMap::displayMap()
{
    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            // Check if the current position is the player's position
            if (player_position_[0] == i && player_position_[1] == j)
            {
                cout << PARTY;
            }
            else
            {
                // Check if the position is explored
                if (map_data_[i][j] != OPENSPACE)
                {
                    // If explored, display the character in lowercase
                    cout << map_data_[i][j];
                }
                else
                {
                    // If unexplored, display the unexplored marker
                    cout << OPENSPACE;
                }
            }
        }
        cout << endl;
    }
}

void GameMap::useAndromedaGalaxy(int playerRow, int playerCol) {
    andromedaGalaxyUsed_ = true;
    exploreSpace(playerRow, playerCol);
}

/*
// Function to check if all characters on the map are uppercase
bool allCharactersAreUppercase(const GameMap& map) {
    for (int i = 0; i < map.getRowSize(); ++i) {
        for (int j = 0; j < map.getColSize(); ++j) {
            if (islower(map.getCharAt(i, j))) {
                return false;
            }
        }
    }
    return true;
}

in cpp: while (!allCharactersAreUppercase(map)) {}
*/

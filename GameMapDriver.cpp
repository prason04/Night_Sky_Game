#include "GameMap.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main1()
{
    GameMap map;
    // map.displayMap();
    // ADD MAP CHOICES HERE
    assert(map.addGalaxy(6, 8));
    assert(map.addGalaxy(14, 13));

    assert(map.addConstellation(3, 12));
    assert(map.addConstellation(8, 4));
    assert(map.addConstellation(15, 9));

    assert(map.addStar(9, 14));
    assert(map.addStar(14, 2));

    assert(map.addPlanet(2, 3));
    assert(map.addPlanet(11, 6));

    void displayMap();

    return 0;
}



// Easy: Map 1
/*
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
*/


// Easy: Map 2
/*
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
*/

// Easy: Map 3
/*
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
*/

// Easy: Map 4
/*
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
*/
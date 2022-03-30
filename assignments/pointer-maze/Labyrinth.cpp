#include "Labyrinth.h"
#include <unordered_set>

bool isPathToFreedom(MazeCell* start, const std::string& moves){
    std::unordered_set<Item> has;
    for(auto move : moves){
        if(move == 'N') start = start->north;
        else if(move == 'E') start = start->east;
        else if(move == 'S') start = start->south;
        else if(move == 'W') start = start->west;
        if(start == nullptr) return false;
        if(start->whatsHere != Item::NOTHING) has.insert(start->whatsHere);
    }
    return has.size() == 3;
}
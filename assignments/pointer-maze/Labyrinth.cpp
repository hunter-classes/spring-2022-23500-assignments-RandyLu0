#include "Labyrinth.h"
#include <set>

using std::set;

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    set<Item> has;
    for(auto move : moves){
        if(start->whatsHere != Item::NOTHING and !has.count(start->whatsHere)) has.insert(start->whatsHere);
        if(move == 'N' and start->north) start = start->north;
        else if(move == 'E' and start->east) start = start->east;
        else if(move == 'S' and start->south) start = start->south;
        else if(move == 'W' and start->west) start = start->west;
        else return false;
    }
    if(has.size() == 3) return true;
    return false;
}
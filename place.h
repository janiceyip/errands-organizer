//
//  place.h
//  
//
//  Created by James Chin on 2/14/15.
//
//

#ifndef ____place__
#define ____place__

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

typedef enum {RESTAURANT, STORE, SUPERMARKET} placeType;        // change enum to be __myMapPck_North

class Place {
private:
    int placeIndex;
    placeType place;
    string placeName;
    string address;
    struct node {
        int openHr;
        int closeHr;
        int open;
    };
    std::map<string, node> operatingHours;
public:
    Place();
    Place(int index, placeType placeTypeIn, string placeNameIn, string addressIn, map<string, node>* operatingHoursIn);
    ~Place();
    void toString();
};

#endif /* defined(____place__) */

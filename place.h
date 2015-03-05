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
#include "errands_org_globals.h"
using namespace std;
    struct node {
        int openHr;
        int closeHr;
        int open;
    };

class Place {
private:
    int placeIndex;
    placeType place;
    string placeName;
    string address;
    std::map<string, node> operatingHours;
public:
    Place();
    Place(int index, placeType placeTypeIn, string placeNameIn, string addressIn, map<string, node> operatingHoursIn);
    ~Place();
    void toString();
};

#endif /* defined(____place__) */

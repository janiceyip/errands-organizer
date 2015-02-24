//
//  place.cpp
//  
//
//  Created by James Chin on 2/14/15.
//
//

#include "place.h"
#include <iostream>
#include <map>

using namespace std;

Place::Place() {
    placeIndex = 0;
    place = RESTAURANT;
    placeName = "Lou's";
    address = "30 Main St, Hanover, NH 03755";
    
    node* dailyHours = new node;
    
    dailyHours->closeHr = 2200;
    dailyHours->openHr = 1100;
    dailyHours->open = 1;

    operatingHours["MON"] = *dailyHours;
    operatingHours["TUE"] = *dailyHours;
    operatingHours["WED"] = *dailyHours;
    operatingHours["THU"] = *dailyHours;
    operatingHours["FRI"] = *dailyHours;
    operatingHours["SAT"] = *dailyHours;
    operatingHours["SUN"] = *dailyHours;
}

Place::Place(int index, placeType placeTypeIn, string placeNameIn, string addressIn, std::map<string, node>* operatingHoursIn) {
    placeIndex = index;
    place = placeTypeIn;
    placeName = placeNameIn;
    address = addressIn;
    operatingHours = *operatingHoursIn;
}

Place::~Place(){    // destructor
    
}

void Place::toString(){
    cout << "name: "<<placeName <<endl;
    string tempPlace = "";
    if (place == 0) tempPlace = "RESTAURANT"; //{RESTAURANT, STORE, SUPERMARKET}
    else if (place == 1) tempPlace = "STORE"; //{RESTAURANT, STORE, SUPERMARKET}
    else if (place == 2) tempPlace = "SUPERMARKET"; //{RESTAURANT, STORE, SUPERMARKET}
    cout << "place type: "<< tempPlace <<endl;
    cout << "address: "<<address <<endl;
    cout << &operatingHours["MON"] << endl;
}

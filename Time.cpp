//
//  Time.cpp
//  errands-organizer-jc
//
//  Created by James Chin on 2/24/15.
//  Copyright (c) 2015 James Chin. All rights reserved.
//

#include "Time.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include "errands_org_globals.h"

Time::Time() {
// Diagonal
    travelTime[0] = 0;
    travelTime[2] = 0;
    travelTime[5] = 0;
    travelTime[9] = 0;
    travelTime[14] = 0;
    travelTime[20] = 0;
    
// distances
    travelTime[1] = 1;   // home & coop
    travelTime[3] = 2;    // home & boloco
    travelTime[4] = 3;    // boloco & coop
    travelTime[6] = 4;    // home & walmart
    travelTime[7] = 5;   // walmart & coop
    travelTime[8] = 6;    // walmart & boloco
    travelTime[10] = 1;  // baker & home
    travelTime[11] = 2;  // baker & coop
    travelTime[12] = 3;  // baker & boloco
    travelTime[13] = 5;  // baker & walmart
    travelTime[15] = 8;   // post office & home
    travelTime[16] = 8;   // post office & coop
    travelTime[17] = 9;   // post office & boloco
    travelTime[18] = 11;   // post office & walmart
    travelTime[19] = 12;  // post office & baker
}

Time::Time(const Time& a) {
    int i = 0;
    // while (i < (_errands_pl_size*_errands_pl_size)/2 -1) {
    while (i < 21) {
        travelTime[i] = a.travelTime[i];
        i++;
    }
}

void Time::printTime() {
    int i = 0; 
    while (i < 21) {
        cout << i << ": " << travelTime[i] << endl;
        i++;
    }
}

Time::~Time() {
    // do nothing
}

void Time::setTime (placeNames& a, placeNames& b, int time) {   // set distance
    if (a != _errands_pl_size && b!= _errands_pl_size) {       // check if valid place name entered by checking if bounds
        if (time > getTime(a, b)) {                             // check if new country road distance is less than existing travel time
            cout << " \"Country road\" should be shorter than existing route!"; //
        } else {
            int i = a;      // i becomes int of a
            int j = b;      // j becomes int of b
            
            if (j > i) {    // if index in upper triangular region of matrix, swap i and j
                int temp;   // temp int temp
                temp = i;   // set temp to i
                i = j;      // i to j
                j = temp;   // j to temp
            } else {}
            travelTime[i*(i+1)/2 + j] = time;     // return int
        }
    }
}


int Time::getTime(placeNames& a, placeNames& b){        //get distance
    if (a != _errands_pl_size && b!= _errands_pl_size) {      // check if valid place name entered by checking if bounds
        int i = a;              // set i to CityName a
        int j = b;              // set j to CityName b
        if (j > i) {    // if index in upper triangular region of matrix, swap i and j
            int temp;   // temp int temp
            temp = i;   // set temp to i
            i = j;      // i to j
            j = temp;   // j to temp
        } else {}
        return travelTime[i*(i+1)/2 + j];
    }
    else {
        return -1;
    }
}

int Time::numPlaces() {           // return # of cities
    return _errands_pl_size;
}

string Time::toString(placeNames& a) {       // convert PlaceName to string
    if (a == 0) {
        return "Home";
    } else if (a == 1){
        return "Coop";
    }else if (a == 2) {
        return "Boloco";
    }else if (a == 3) {
        return "Walmart";
    }else if (a == 4) {
        return "Baker";
    }else if (a == 5) {
        return "Hanover Post Office";
    } else {
        return "Invalid place";
    }
}

placeNames Time::setPlace(string select) {       // convert string to placeName
    if (select == "Home") {
        return _errands_pl_home;
    }else if (select == "Coop") {
        return _errands_pl_coop;
    }else if (select == "Boloco") {
        return _errands_pl_boloco;
    }else if (select == "Walmart") {
        return _errands_pl_walmart;
    }else if (select == "Baker") {
        return _errands_pl_baker;
    }else if (select == "Post Office"){
        return _errands_pl_hanover_post_office;
    }
    else {
        cout << "INVALID CITY ";
        return _errands_pl_size;             //
    }
}

// int main() {}

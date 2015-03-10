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
    // for loop to set dummy distances
    for (int i = 0;i < (_errands_pl_size *(_errands_pl_size+1))/2 ; i++) {
        travelTime[i] = i;
    }

    // Diagonal
    travelTime[0] = 0;  // home
    travelTime[2] = 0;  //coop
    travelTime[5] = 0;  // boloco
    travelTime[9] = 0;  // walmart
    travelTime[14] = 0; // baker
    travelTime[20] = 0; // hanover PO
    travelTime[27] = 0; // subway
    travelTime[35] = 0; // bjs
    travelTime[44] = 0; // bookstore
    travelTime[54] = 0; // orient
    travelTime[65] = 0; // laundromat
    travelTime[77] = 0; // pine
    travelTime[90] = 0; // mollys
    travelTime[104] = 0; // yamas
    travelTime[119] = 0; // starbucks
    travelTime[135] = 0;    // hospital
    
    
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
    while (i < (_errands_pl_size *(_errands_pl_size+1))/2) {
    //while (i < 21) {
        travelTime[i] = a.travelTime[i];
        i++;
    }
}

void Time::printTime() {
    int i = 0; 
     while (i < (_errands_pl_size*(_errands_pl_size+1))/2) {
    //while (i < 21) {
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
    if ((a != b) && (a != _errands_pl_size && b!= _errands_pl_size)) {      // check if valid place name entered by checking if bounds
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
        return "Post Office";
    }else if (a == 6) {
        return "Subway";
    }else if (a == 7) {
        return "BJs";
    }else if (a == 8) {
        return "Bookstore";
    }else if (a == 9) {
        return "Orient";
    }else if (a == 10) {
        return "Laundromat";
    }else if (a == 11) {
        return "Pine";
    }else if (a == 12) {
        return "Mollys";
    }else if (a == 13) {
        return "Yamas";
    }else if (a == 14) {
        return "Starbucks";
    }else if (a == 15) {
        return "Hospital";
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
        return _errands_pl_post_office;
    }else if (select == "Subway") {
        return _errands_pl_subway;
    }else if (select == "BJs") {
        return _errands_pl_bjs;
    }else if (select == "Bookstore") {
        return _errands_pl_bookstore;
    }else if (select == "Orient") {
        return _errands_pl_orient;
    }else if (select == "Laundromat") {
        return _errands_pl_laundromat;
    }else if (select == "Pine") {
        return _errands_pl_pine;
    }else if (select == "Mollys") {
        return _errands_pl_mollys;
    }else if (select == "Yamas") {
        return _errands_pl_yamas;
    }else if (select == "Starbucks") {
        return _errands_pl_starbucks;
    }else if (select == "Hospital") {
        return _errands_pl_hospital;
    }
    else {
        cout << "Invalid place name!";
        return _errands_pl_size;             //
    }
}

//int Time::operator[](const string[2] vectInput) {
int Time::operator[](const string vectInput[2]) {
    placeNames start;
    placeNames destination;
    
    start = setPlace( vectInput[0] );
    destination = setPlace(vectInput[1]);
    return getTime(start, destination);
}


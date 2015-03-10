//
//  Time.h
//  errands-organizer-jc
//
//  Created by James Chin on 2/24/15.
//  Copyright (c) 2015 James Chin. All rights reserved.
//
//  Adjacency matrix of travel time between indexed locations
//

#ifndef __errands_organizer_jc__Time__
#define __errands_organizer_jc__Time__

#include <stdio.h>
#include <iostream>
#include <map>
#include "errands_org_globals.h"
#include <vector>

class Time {
private:
    //int travelTime[()
    int travelTime[(_errands_pl_size*_errands_pl_size + _errands_pl_size)/2];   // linear array
public:
    Time();
    Time(const Time& a);
    ~Time();
    int getTime(placeNames& a, placeNames&b);
    void setTime(placeNames& i, placeNames& j, int time);     // set Time
    int numPlaces();            // return # places in adjacency matrix
    string toString(placeNames& a);
    placeNames setPlace(string a);
    void printTime();
    //int operator[](const vector<string>);
    int operator[](const string vectInput[2]);
};

#endif /* defined(__errands_organizer_jc__Time__) */

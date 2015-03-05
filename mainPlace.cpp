//
//  main.cpp
//  errands-organizer-jc
//
//  Created by James Chin on 2/14/15.
//  Copyright (c) 2015 James Chin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "place.h"
#include "Time.h"
#include "errands_org_globals.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    node dailyHours;
    dailyHours.closeHr = 2200;
    dailyHours.openHr = 1100;
    dailyHours.open = 1;
    
    std::map<string, node> opHrIn;
    // daily operating hours
    opHrIn["MON"] = dailyHours;
    opHrIn["TUE"] = dailyHours;
    opHrIn["WED"] = dailyHours;
    opHrIn["THU"] = dailyHours;
    opHrIn["FRI"] = dailyHours;
    opHrIn["SAT"] = dailyHours;
    opHrIn["SUN"] = dailyHours;
    
    // int index, placeType placeTypeIn, string placeNameIn, string addressIn, map<string, node> operatingHoursIn
    Place Lous(1, _errands_plType_restaurant, "Lous", "30 Main St, Hanover, NH 03755", opHrIn);
    Place Coop(1, _errands_plType_store, "Hanover Coop", "45 South Park Street Hanover, NH 03755", opHrIn);
    Place Walmart(1, _errands_plType_supermarket, "Walmart", "Valley Square Shopping Center, 285 Plainfield Road, West Lebanon, NH 03784", opHrIn);
    // print to check
    Lous.toString();
    Coop.toString();
    Walmart.toString();
    
    
    // test Adjacency matrix
    placeNames start = _errands_pl_coop;
    placeNames end = _errands_pl_home;
    int newTime;
    Time t;             // construct adjacency matrix t
    cout << "Travel time between" + t.toString(start)+ " and " + t.toString(end) + " : ";
    cout << t.getTime(start, end) << endl;
    
    return 0;
}
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
    cout << "start:";
    cout << start << endl;
    cout << "end:";
    cout << end  << endl;
    cout << "";
    

    cout << "Travel time between " + t.toString(start)+ " and " + t.toString(end) + " : ";

    cout << t.getTime(start, end) << endl;

    placeNames start1 = _errands_pl_walmart;
    placeNames end1 = _errands_pl_hanover_post_office;
    //Time t;             // construct adjacency matrix t
    
    
    cout << "Travel time between " + t.toString(start1)+ " and " + t.toString(end1) + " : ";
    cout << t.getTime(start1, end1) << endl;

    cout << "Travel time between " + t.toString(end1)+ " and " + t.toString(start1) + " : ";
    cout << t.getTime(end1, start1) << endl;
    
    placeNames start2 = _errands_pl_baker;
    placeNames end2 = _errands_pl_hanover_post_office;
    //Time t;             // construct adjacency matrix t
    
    cout << "start:";
    cout << start2 << endl;
    cout << "end:";
    cout << end2  << endl;
    cout << "";
    
    cout << "Travel time between " + t.toString(start2)+ " and " + t.toString(end2) + " : ";
    cout << t.getTime(start2, end2) << endl;
    

    cout << "Travel time between " + t.toString(end2)+ " and " + t.toString(start2) + " : ";
    cout << t.getTime(end2, start2) << endl;
    
    return 0;
}
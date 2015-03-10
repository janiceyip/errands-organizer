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
    placeNames coop = _errands_pl_coop;
    placeNames home = _errands_pl_home;
    placeNames boloco = _errands_pl_boloco;
    placeNames walmart = _errands_pl_walmart;
    placeNames hanoverPO = _errands_pl_post_office;
    placeNames baker = _errands_pl_baker;
    
    int newTime;
    Time t;             // construct adjacency matrix t
//    cout << "start:";
//    cout << coop << endl;
//    cout << "end:";
//    cout << home  << endl;
//    cout << "";
    
    cout << "DIAGONAL" << endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(home, home) << endl;

    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(coop, coop) << endl;
    
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(boloco, boloco) << endl;
    
    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(walmart, walmart) << endl;
    
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(baker, baker) << endl;
    
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(hanoverPO, hanoverPO) << endl;
    
    
    // OFF DIAGONAL
    
    cout << "OFF-DIAGONAL" << endl;
    cout << "COOP"<< endl;
    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(coop, home) << endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(home, coop) << endl;
    
    cout << "BOLOCO"<< endl;
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(boloco, home) << endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(home, boloco) << endl;
    
    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(coop, boloco) << endl;
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(boloco, coop) << endl;
    
    cout << "WALMART"<< endl;
    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(walmart, home) << endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(home, walmart) << endl;
    
    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(walmart, coop) << endl;
    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(coop, walmart) << endl;

    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(walmart, boloco) << endl;
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(boloco, walmart) << endl;
 
    cout << "BAKER"<< endl;
    cout << "Travel time between " + t.toString(baker)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(baker, home) << endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(baker) + " : ";
    cout << t.getTime(home, baker) << endl;
    
    cout << "Travel time between " + t.toString(baker)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(baker, coop) << endl;
    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(baker) + " : ";
    cout << t.getTime(coop, baker) << endl;
    
    cout << "Travel time between " + t.toString(baker)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(baker, boloco) << endl;
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(baker) + " : ";
    cout << t.getTime(boloco, baker) << endl;
    
    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(baker) + " : ";
    cout << t.getTime(walmart, baker) << endl;
    cout << "Travel time between " + t.toString(baker)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(baker, walmart) << endl;
    
    
    cout << "HANOVER PO"<< endl;
    cout << "Travel time between " + t.toString(home)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(home, hanoverPO) << endl;
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(home) + " : ";
    cout << t.getTime(hanoverPO, home) << endl;
    
    cout << "Travel time between " + t.toString(coop)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(coop, hanoverPO) << endl;
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(coop) + " : ";
    cout << t.getTime(hanoverPO, coop) << endl;
    
    cout << "Travel time between " + t.toString(boloco)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(boloco, hanoverPO) << endl;
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(boloco) + " : ";
    cout << t.getTime(hanoverPO, boloco) << endl;
    
    cout << "Travel time between " + t.toString(walmart)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(walmart, hanoverPO) << endl;
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(walmart) + " : ";
    cout << t.getTime(hanoverPO, walmart) << endl;

    cout << "Travel time between " + t.toString(baker)+ " and " + t.toString(hanoverPO) + " : ";
    cout << t.getTime(baker, hanoverPO) << endl;
    cout << "Travel time between " + t.toString(hanoverPO)+ " and " + t.toString(baker) + " : ";
    cout << t.getTime(hanoverPO, baker) << endl;
    
    cout << "";
    cout << "Print Time" << endl;
    t.printTime();
    
    
    cout << "";
    cout << "Test COPY CONSTRUCTOR" << endl;
    
    Time t2 = t;
    
    
    cout << "DIAGONAL" << endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(home, home) << endl;
    
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(coop, coop) << endl;
    
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(boloco, boloco) << endl;
    
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(walmart, walmart) << endl;
    
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(baker, baker) << endl;
    
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(hanoverPO, hanoverPO) << endl;
    
    
    // OFF DIAGONAL
    
    cout << "OFF-DIAGONAL" << endl;
    cout << "COOP"<< endl;
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(coop, home) << endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(home, coop) << endl;
    
    cout << "BOLOCO"<< endl;
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(boloco, home) << endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(home, boloco) << endl;
    
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(coop, boloco) << endl;
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(boloco, coop) << endl;
    
    cout << "WALMART"<< endl;
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(walmart, home) << endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(home, walmart) << endl;
    
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(walmart, coop) << endl;
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(coop, walmart) << endl;
    
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(walmart, boloco) << endl;
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(boloco, walmart) << endl;
    
    cout << "BAKER"<< endl;
    cout << "Travel time between " + t2.toString(baker)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(baker, home) << endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(baker) + " : ";
    cout << t2.getTime(home, baker) << endl;
    
    cout << "Travel time between " + t2.toString(baker)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(baker, coop) << endl;
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(baker) + " : ";
    cout << t2.getTime(coop, baker) << endl;
    
    cout << "Travel time between " + t2.toString(baker)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(baker, boloco) << endl;
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(baker) + " : ";
    cout << t2.getTime(boloco, baker) << endl;
    
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(baker) + " : ";
    cout << t2.getTime(walmart, baker) << endl;
    cout << "Travel time between " + t2.toString(baker)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(baker, walmart) << endl;
    
    cout << "HANOVER PO"<< endl;
    cout << "Travel time between " + t2.toString(home)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(home, hanoverPO) << endl;
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(home) + " : ";
    cout << t2.getTime(hanoverPO, home) << endl;
    
    cout << "Travel time between " + t2.toString(coop)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(coop, hanoverPO) << endl;
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(coop) + " : ";
    cout << t2.getTime(hanoverPO, coop) << endl;
    
    cout << "Travel time between " + t2.toString(boloco)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(boloco, hanoverPO) << endl;
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(boloco) + " : ";
    cout << t2.getTime(hanoverPO, boloco) << endl;
    
    cout << "Travel time between " + t2.toString(walmart)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(walmart, hanoverPO) << endl;
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(walmart) + " : ";
    cout << t2.getTime(hanoverPO, walmart) << endl;
    
    cout << "Travel time between " + t2.toString(baker)+ " and " + t2.toString(hanoverPO) + " : ";
    cout << t2.getTime(baker, hanoverPO) << endl;
    cout << "Travel time between " + t2.toString(hanoverPO)+ " and " + t2.toString(baker) + " : ";
    cout << t2.getTime(hanoverPO, baker) << endl;
    
    cout << "";
    cout << "Print Time t2" << endl;
    t2.printTime();
    
    cout << "random" << endl;
    
    cout << "" << endl;
    
    string tempVector[2] = {"Boloco", "Walmart"};
    cout << "random" << endl;
    cout << "TEST [] Overload: "<<t[tempVector] << endl;
    
    return 0;
    
}
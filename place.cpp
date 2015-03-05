//
//  place.cpp
//
//
//  Created by James Chin on 2/14/15.
//
//

#include "place.h"

Place::Place() {
    placeIndex = 0;
    place =  _errands_plType_restaurant;
    placeName = "Lou's";
    address = "30 Main St, Hanover, NH 03755";
    
    node dailyHours;
    
    dailyHours.closeHr = 2200;
    dailyHours.openHr = 1100;
    dailyHours.open = 1;
    
    operatingHours["MON"] = dailyHours;
    operatingHours["TUE"] = dailyHours;
    operatingHours["WED"] = dailyHours;
    operatingHours["THU"] = dailyHours;
    operatingHours["FRI"] = dailyHours;
    operatingHours["SAT"] = dailyHours;
    operatingHours["SUN"] = dailyHours;
}

Place::Place(int index, placeType placeTypeIn, string placeNameIn, string addressIn, std::map<string, node> operatingHoursIn) {
    
    placeIndex = index;
    place = placeTypeIn;
    placeName = placeNameIn;
    address = addressIn;
    operatingHours = operatingHoursIn;
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
    
    if (operatingHours["MON"].open == 1) {
        cout << "Monday Opening hours: " ;
        cout << operatingHours["MON"].openHr << endl;
        cout << "Monday Closing hours: ";
        cout << operatingHours["MON"].closeHr << endl;
    } else {
        cout << "Closed on Monday!";
    }
    
    if (operatingHours["TUE"].open == 1) {
        cout << "Tuesday Opening hours: " ;
        cout << operatingHours["TUE"].openHr << endl;
        cout << "Tuesday Closing hours: ";
        cout << operatingHours["TUE"].closeHr << endl;
    } else {
        cout << "Closed on Tuesday!";
    }
    
    if (operatingHours["WED"].open == 1) {
        cout << "Wednesday Opening hours: " ;
        cout << operatingHours["WED"].openHr << endl;
        cout << "Wednesday Closing hours: ";
        cout << operatingHours["WED"].closeHr << endl;
    }
    else {
        cout << "Closed on Wednesday!";
    }
    
    
    if (operatingHours["THU"].open == 1) {
        cout << "Thursday Opening hours: " ;
        cout << operatingHours["THU"].openHr << endl;
        cout << "Thursday Closing hours: ";
        cout << operatingHours["THU"].closeHr << endl;
    }
    else {
        cout << "Closed on Thursday!";
    }
    
    if (operatingHours["FRI"].open == 1) {
        cout << "Friday Opening hours: " ;
        cout << operatingHours["FRI"].openHr << endl;
        cout << "Friday Closing hours: ";
        cout << operatingHours["FRI"].closeHr << endl;
    }
    else {
        cout << "Closed on Friday!";
    }
    
    if (operatingHours["SAT"].open == 1) {
        cout << "Saturday Opening hours: " ;
        cout << operatingHours["SAT"].openHr << endl;
        cout << "Saturday Closing hours: ";
        cout << operatingHours["SAT"].closeHr << endl;
    }
    else {
        cout << "Closed on Saturday!";
    }
    
    if (operatingHours["SUN"].open == 1) {
        cout << "Sunday Opening hours: " ;
        cout << operatingHours["SUN"].openHr << endl;
        cout << "Sunday Closing hours: ";
        cout << operatingHours["SUN"].closeHr << endl;
    }
    else {
        cout << "Closed on Sunday!";
    }
    cout <<""<< endl;
}

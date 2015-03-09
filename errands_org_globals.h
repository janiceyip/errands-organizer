/*
 * Cards.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef ERRANDS_ORG_GLOBALS_H_
#define ERRANDS_ORG_GLOBALS_H_

using namespace std; 

enum errandType {
	_errands_org_groceries, 
	_errands_org_shopping, 
	_errands_org_restaurant_eating, 
	_errands_org_laundry, 
	_errands_org_dry_cleaning, 
	_errands_org_library, 
	_errands_org_post_office, 
	_errands_org_size
};

enum placeNames {
    _errands_pl_home,
    _errands_pl_coop,
    _errands_pl_boloco,
    _errands_pl_walmart,
    _errands_pl_baker,
    _errands_pl_post_office,
    _errands_pl_subway,
    _errands_pl_bjs,
    _errands_pl_bookstore,
    _errands_pl_orient,
    _errands_pl_laundromat,
    _errands_pl_pine,
    _errands_pl_mollys,
    _errands_pl_yamas,
    _errands_pl_starbucks,
    _errands_pl_hospital,
    _errands_pl_size,
};

enum placeType {
    _errands_plType_restaurant,
    _errands_plType_store,
    _errands_plType_supermarket
};

#endif /* ERRANDS_ORG_GLOBALS_H_ */
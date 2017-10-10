/***********************************************************
 CSCI 241 - Assignment 2 - Fall 2017
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: September 27, 2017
 
 Purpose: This cpp file allows the creation of provider
 instances.  It also allows providers to be printed.
 These two tasks are done with an instantiator method and
 print method.
 ************************************************************/

#include <iostream>
#include "Provider.h"

using std::cout;
using std::endl;

//Provider Constructor
Provider::Provider()
{
}

//Print
void Provider::print() const
{
    // print provider
    cout << "#" << number << endl;
    cout << name << endl;
    cout << specialty << endl;
    cout << address_1 << endl;
    cout << address_2 << endl;
    cout << city << ", " << state << " " << zip_code << endl;
    cout << phone_number << endl;
    cout << "\n";
}

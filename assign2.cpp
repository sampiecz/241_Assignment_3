/***********************************************************
 CSCI 241 - Assignment 2 - Fall 2017

 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: September 27, 2017

 Purpose: Takes all takes all the classes and their methods
 makes it possible to use them all in one place cleanly. It
 outputs an instance of the ProviderDB class and sorts and 
 prints it.
 ************************************************************/
#include <iostream>
#include "Provider.h"
#include "ProviderDB.h"
using std::cout;
using std::endl;

int main()
{
    // Prints out title to make it easy for the TA to read each section
    cout << "#######################################################################" << endl;
    cout << "Unsorted Print of all providers" << endl;
    cout << "#######################################################################" << endl;

    // Instantiates an object of the Providerdb class, loads the providerdb
    ProviderDB loadData("providerdb");

    //calls the print method on the object of the providerdb class
    loadData.print();

    // Prints out title to make it easy for the TA to read each section
    cout << "#######################################################################" << endl;
    cout << "Sorted by Provider Number" << endl;
    cout << "#######################################################################" << endl;

    // Takes the ProviderDB instance and calls the sort by number method
    loadData.sortByProviderNumber();
    // Once the object has been sorted it prints it out
    loadData.print();

    // Prints out title to make it easy for the TA to read each section
    cout << "#######################################################################" << endl;
    cout << "Sorted by Specialty" << endl;
    cout << "#######################################################################" << endl;

    // Takes the ProviderDB instance and sorts it by specialty
    loadData.sortBySpecialty();
    // Prints the object once it has been sorted
    loadData.print();

    // Prints out title to make it easy for the TA to read each section
    cout << "#######################################################################" << endl;
    cout << "Sorted by Name" << endl;
    cout << "#######################################################################" << endl;

    // Takes the ProviderDB instance and sorts it by name
    loadData.sortByName();
    // Prints the instance once it has been sorted by name
    loadData.print();

}

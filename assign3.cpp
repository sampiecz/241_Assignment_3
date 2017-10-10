/***********************************************************
 CSCI 241 - Assignment 3 - Fall 2017

 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: October 9, 2017

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
   // Loads providerDB object with data from file
    ProviderDB loadData("providerdb");

    loadData.sortByName();
    loadData.print();
    cout << "################################################################" << endl;
    loadData.sortByProviderNumber();
    loadData.print();
    cout << "################################################################" << endl;
    loadData.processTransactions("transactions.txt");
    return 0;
}

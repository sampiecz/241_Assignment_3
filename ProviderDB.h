#ifndef PROVIDERDB_H
#define PROVIDERDB_H

//*********************************************************************
// FILE:        ProviderDB.h
// AUTHOR:      Samuel Piecz
// LOGON ID:    Z1732715
// DUE DATE:    9/26/17
//
// PURPOSE:     Declaration for the ProviderDB class, which represents
// an array of providers. Also contains method prototypes for sorting.
//********************************************************************
#include "Provider.h"

// Declares the ProviderDB class
class ProviderDB
{
    private:
        //Data members
        Provider providerArray[40];
        int numberOfProviders;

    public:
        //Default constructor
        ProviderDB();

        //Alternate ProviderDB constructor
        ProviderDB(const char* filename);

        //Print function
        void print() const;

        //Sorting method 
        void sortByProviderNumber();

        //Sorting method
        void sortBySpecialty();

        //Sorthing method
        void sortByName();

        //Process Transactions
        void processTransactions(char* const transactionFile);

        //Search For Provider Number
        int searchForProviderNumber(char searchNumber);
};

#endif


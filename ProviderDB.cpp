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
#include <fstream>
#include <cstring>
#include <string>
#include "ProviderDB.h"
#include "Provider.h"

using std::ws;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ios;

/***************************************************************
 ProviderDB
 
 Use: Instiates an instance of the ProviderDB class
 
 Parameters: 1. No parameters
 ***************************************************************/
ProviderDB::ProviderDB()
{
}

/***************************************************************
 ProviderDB
 
 Use: Instiates an instance of the ProviderDB class, but allows
 a file to be taken as a parameter.
 
 Parameters: 1. const char* filename: A const char pointer called 
 filename. This allows a filename to be provided when the object
 is instianted.
 ***************************************************************/
ProviderDB::ProviderDB(const char* filename)
{
    // Creates inFile as an object of the ifstream class
    ifstream inFile;

    // Opens the file and puts it into infile - specifically binary data
    inFile.open(filename, ios::binary);

    // Output an error if no inFile exists.
    if (!inFile)
    {
        cerr << "File does not exist" << endl;
        exit(1);
    }

    // Reads the file and assigns it to the instance of the providerdb
    // that has been created.  Also assigns a size so we know how many
    // times to iterate.
    inFile.read((char *) this, sizeof(ProviderDB));
   
    // Closes the file
    inFile.close();
}

/***************************************************************
 print
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
void ProviderDB::print() const
{
    // loops through each item in provider array and prints it
    for (int i = 0; i < numberOfProviders; i++)
    {
        // prints each provider in the providerdb array
        providerArray[i].print();
    }
}

/***************************************************************
 sortByProviderNumber
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
void ProviderDB::sortByProviderNumber()
{
    int i, j;
    Provider bucket;

    for (i = 1; i < numberOfProviders; i++)
    {
        bucket = providerArray[i];

        for (j = i; (j > 0) && (strcmp(providerArray[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--)
            providerArray[j] = providerArray[j-1];

        providerArray[j] = bucket;
    }
}

/***************************************************************
 sortByProviderNumber
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
void ProviderDB::sortBySpecialty()
{
    int i, j;
    Provider bucket;

    for (i = 1; i < numberOfProviders; i++)
    {
        bucket = providerArray[i];

        for (j = i; (j > 0) && (strcmp(providerArray[j-1].getProviderSpecialty(), bucket.getProviderSpecialty()) < 0); j--)
            providerArray[j] = providerArray[j-1];

        providerArray[j] = bucket;
    }
}

/***************************************************************
 sortByProviderNumber
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
void ProviderDB::sortByName()
{
    int i, j;
    Provider bucket;

    for (i = 1; i < numberOfProviders; i++)
    {
        bucket = providerArray[i];

        for (j = i; (j > 0) && (strcmp(providerArray[j-1].getProviderName(), bucket.getProviderName()) > 0); j--)
            providerArray[j] = providerArray[j-1];

        providerArray[j] = bucket;
    }
}

/***************************************************************
 processTransactions
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
void ProviderDB::processTransactions(const char* transactionFile)
{
    string typeOfTransaction;
    string specialty; 
    string number;

    ifstream tranFile;

    tranFile.open(transactionFile);       

    if (!tranFile)
    {    
        cerr << "File does not exist." << endl;
        exit(1);
    }

    while (tranFile >> typeOfTransaction)
    {
       if (typeOfTransaction == "all")
       {
           cout << "#################################################" << endl;
           cout << "#                 All Providers                 #" << endl;
           cout << "#################################################" << endl;
           
           sortByName();
           print();
       }
       else if (typeOfTransaction == "specialty")
       {
           tranFile >> ws;
           getline(tranFile, specialty);
           sortBySpecialty();
           
           int counter = 0;

           cout << "#################################################" << endl;
           cout << "#               Provider Specialty              #" << endl;
           cout << "#################################################" << endl;

           for (int i = 0; i < numberOfProviders; i++)
           {
               
               if (providerArray[i].getProviderSpecialty() == specialty)
               {
                   providerArray[i].print(); 
                   counter++;
               }
           
           }

           cout << "\n=================================================" << endl;
           cout << "Amount of Providers objects printed out: " << counter << endl;
           cout << "=================================================\n" << endl;

       }
       else if (typeOfTransaction == "number")
       {
           tranFile >> ws;
           tranFile >> number;
           sortByProviderNumber();
           int mid = searchForProviderNumber(number.c_str());

           cout << "#################################################" << endl;
           cout << "#               Provider Number                 #" << endl;
           cout << "#################################################" << endl;

           if (searchForProviderNumber(number.c_str()) == -1)
           {
               cerr << "Number does not exist." << endl;
           }
           else
           {
               providerArray[mid].print();        
           }
    
        }
    }

    tranFile.close();
}

/***************************************************************
 searchForProviderNumber
 
 Use: Loops through ProviderDB array and prints each instance
 that is contained in the array.
 
 Parameters: No parameters.
 ***************************************************************/
int ProviderDB::searchForProviderNumber(const char* number)
{
    int low = 0;
    int high = numberOfProviders - 1;
    int mid;

    while (low <= high)
        {
            mid = (low + high) / 2;

            if (strcmp(providerArray[mid].getProviderNumber(), number) == 0)
            {    
                return mid;
            }
            else if (strcmp(providerArray[mid].getProviderNumber(), number) > 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }

        }

    return -1;
}

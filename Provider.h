#ifndef PROVIDER_H
#define PROVIDER_H

//*********************************************************************
// FILE:	Provider.h
// AUTHOR:	Samuel Piecz
// LOGON ID:	Z1732715
// DUE DATE:	9/27/17
//
// PURPOSE:	Declaration for the Provider class, which represents
//		information about a health care provider.
//********************************************************************

//Declaring the provider class
class Provider
{
    // Private is not necessary but it looks nice
    // Everything is private by default.
    private:
        //Data members
        char number[7] = {};
        char specialty[41] = {};
        char name[41] = {};
        char address_1[41] = {};
        char address_2[31] = {};
        char city[21] = {};
        char state[3] = {};
        char zip_code[6] = {};
        char phone_number[15] = {};

    // Declaring the public scope
    public:
        //Method prototypes

        //Default constructor
        Provider();

        //Print provider data
        void print() const;

        //Accessor method returns provider number data member
        const char* getProviderNumber() { return number; }

        //Accessor method that returns provider name data member
        const char*  getProviderName() { return name; }

        //Accessor method that returns provider specialty data member
        const char* getProviderSpecialty() { return specialty; }
};

#endif

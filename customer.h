///--------------------------customer.h-------------------------------------------
//Created by Chelsea Ip CSS343 Section B
//Created: 6/09/2019
//Last Modification: 6/09/2019
//------------------------------------------------------------------------------
//Purpose: This is the header file for a customer class,
//This class contains all the customer's information such as their names, ID, and 
//displays all their history including transaction history.
//------------------------------------------------------------------------------


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "movie.h"
#include <iostream>
#include "transaction.h"

using namespace std;

class Customer
{
public:
    
    //Default constructor
    Customer(); 
    //Default constructor, modifies customer data
    Customer(istream&)
    //Copy constructor
    Customer(const Customer&); 
    //Destructor
    ~Customer(); //destructor
    //Set the customer's information
    void setCustomer(istream&);
    //display customer info
    void display();
    //Retrieves history
    void getHistory();
    //Adds a transaction to customer
    void addTransaction(Transaction); 
    //Get function for first name
    string getFirstName()const;
    //Get function for last name
    string getLastName()const;
    virtual bool operator==(const Customer&) const;
    virtual bool operator!=(const Customer&) const;
    
private:
    string firstName, lastName;
    int customerID;
    vector<Transaction>transactionHistory;
};
#endif  /* CUSTOMER_H */



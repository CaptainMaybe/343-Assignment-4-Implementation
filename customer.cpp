#include "customer.h"
#include <iostream>
#include <vector>
#include <iostream>

// --------------------- Default Constructor -----------------------------------------
// Constructs the first name, last name and initializes value to a customer ID.
// Requests vector capacity able to contain 10 elements.
//
Customer::Customer() : customerID(0), firstName(""), lastName("")
{
    transactionHistory.reserve(10);
}

// --------------------- Default Constructor -----------------------------------------
// Reading in values from infile
//
Customer::Customer(istream& infile)
{
    setData(infile); 
}

// --------------------- Copy Constructor -----------------------------------------
// Copies the other customer's information to a newly created customer
//
Customer::Customer(const Customer& other)
{
    customerID = other.customerID;
    firstName = other.firstName;
    lastName = other.lastName;
}

// --------------------- Destructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Customer::~Customer()
{
    cout << "Destroyed" << endl;
}

// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
void Customer::setData(istream& infile)
{
    infile >> customerID;
    if(infile.eof()) return;
    infile.get();
    infile >> lastName;
    
    infile.get();
    infile >> firstName;
}

// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
void Customer::getHistory() const
{
    cout << " **** Customer: " << id << " " << lastName << ", " << firstName 
    << endl;
  int size = transactionHistory.size();
  if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
    transactionHistory[i].display();
    transactionHistory[i].getItem()->display();
            }//end for
            cout << endl;
  }
  else
  cout << "No Transactions for Customer" << endl;
  cout << endl;
}

void Customer::display()
{
    getHistory();
}
// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
void Customer::addTransaction(Transaction trans)
{
    transactionHistory.push_back(trans);
}

// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
string Customer::getFirstName() const
{
    return firstName;
}

// --------------------- getLastName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
string Customer::getLastName() const
{
    return lastName;
}

// ---------------------operator == -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
bool Customer::operator==(const Customer& other) const
{
    return(customerID == other.customerID);
}

// ---------------------operator!=-----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
bool Customer::operator!=(const Customer& other) const
{
    return(customerID != other.customerID);
}



/*
 * File:   business.h
 * Author: ipchelsea, guinek
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "movie.h"
//#include "transaction.h"
//#include "customer.h"
#include "bintree.h"
#include "moviefactory.h"

#ifndef BUSINESS_H
#define	BUSINESS_H

class Business
{
public:

    //default constructor
    Business();

    //destructor
    ~Business();

    //takes an array of BST holding movie pointers.
    //opens necessary file and process all the different movies.
    void buildMovies(string fileName);

    //takes a hash table containing all the customers by references
    //opens necessary file and process all the different customers.
    //void buildCustomers(HashTable<Customer>&);

    //processtrans method is missing
  private:
    BinTree movieStorage;
};

#endif	/* BUSINESS_H */

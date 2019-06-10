/*
 * File:   hashtable.h
 * Author: ipchelsea, guinek
 */
 #include <list>
#include "customer.h"

#ifndef HASHTABLE_H
#define	HASHTABLE_H

class Business
{
public:

    //default constructor
    HashTable();

    HashTable(int buckets);

    //destructor
    ///~HashTable();

    customer& find(&customer);

    void insert(&customer);

    void remove(&customer);

  private:
    struct Node
    {
      Customer* data;
      Node* next;
    };

    int hash(&customer);
    int bucketNum;
    list<customer> *table;

};

#endif	/* BUSINESS_H */

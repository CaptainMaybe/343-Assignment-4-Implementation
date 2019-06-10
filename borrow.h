/* 
 * File:   borrow.h
 * Author: ipchelsea
 */

#ifndef BORROW_H
#define BORROW_H

using namespace std;

class Borrow : Transaction
{
public:
    //default constructor. Initializes all values to NULL or zero.
    Borrow(int customerID, string mediaType);
    
     //default destructor. No memory allocated
    ~Borrow();
    
    //Overides the parent's print.  Prints this transaction (borrow)
    void display();
    
    //overrides the parent class, performs the transaction, which is, in this
  //case, decreasing the "stock" of a movie by 1.
    void doTransaction();
};


#endif  /* BORROW_H */


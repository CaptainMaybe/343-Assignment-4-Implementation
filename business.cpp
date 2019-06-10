#include "business.h"

// -----------------------------------------------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Business::Business()
{
  movieStorage.makeEmpty();
}

// ----------------------------------- -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Business::~Business()
{

}

// ---------------------buildCustomers() ---------------------------------------
// Creates a hashtable to store each customer.
//
// void Business::buildCustomers(HashTable<Customer>& customerList)
// {
//     fstream input;
//     input.open("data4customers.txt");
//     Customer* customer;
//     while(!input.eof())
//     {
//         string customerID, lastName, firstName;
//
//         input >> customerID;
//         input >> lastName;
//         input >> firstName;
//         customer = new Customer(firstName, lastName, customerID);
//         customerList.insert(customer);
//     }
// }

// ---------------------buildMovies() -----------------------------------------
//
//
void Business::buildMovies(string fileName)
{
  //cout<<"inside buildMovies"<<endl;
    fstream input;
    bool validLine = true;
    input.open(fileName);

    while(!input.eof())
    {
        //movie in this case is a single line from the txt file (which
        //all the information used to create a single movie to store in the
        //bin tree)
        string movie;
        getline(input, movie);

        //cout<<"the movie is: " <<movie<<endl;
        MovieFactory MF;
        //valid line is a boolean that is set to false if there is an invalid input
        //in the line that createMovie takes in.
        NodeData* newMovie = MF.createMovie(movie, validLine);
        if(validLine)
        {
          //if something is invalid about the line that createMovie took in,
          //then it will not insert that line and will simply skip to the next one. 
          movieStorage.insert(newMovie);
        }
    }
}

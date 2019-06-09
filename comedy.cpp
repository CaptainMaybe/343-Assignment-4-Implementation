#include "comedy.h"

// --------------------- Default Constructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Comedy::Comedy(int stock, string directorFirstName, string directorLastName,
  string title, int year) : Movie(stock, directorFirstName,directorLastName,
  title, year)
{

}

// --------------------- Empty Constructor -----------------------------------------
// Constructs an empty string for the first name, last name and month of actor.
//
 Comedy::Comedy() : Movie()
 {
 }

 // --------------------- getStock() -----------------------------------------
// Returns the current stock of each movie
//
 int Comedy::getStock()
 {
   return stock;
 }


// --------------------- operator== -----------------------------------------
// Returns true if movies are the same, else false.
//
bool Comedy::operator==(const NodeData & other) const
{
  if(typeid(*this)!= typeid(other))
  {
    return false;
  }
  return Movie::compare(other);
}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep cop[y of the binary search tree
//
bool Comedy::operator!=(const NodeData& other) const
{
  return !(*this==other);
}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep cop[y of the binary search tree
//
bool Comedy::operator<(const NodeData &other) const
{
  if(typeid(*this)!= typeid(other))
  {
    return true;
  }
    //cout<<"HERE"<<endl;
  const Comedy& otherMovie = dynamic_cast<const Comedy&>(other);

  if(this->title < otherMovie.title)
  {
    return true;
  }

  if(this->title == otherMovie.title)
  {
    if(this->year< otherMovie.year)
    {
      return true;
    }
  }
  return false;
}

// ---------------------operator> -----------------------------------------
// Returns true if movie year and month is greater, else false.
//
bool Comedy::operator>(const NodeData &other) const
{
  if(typeid(*this)!= typeid(other))
  {
    return false;
  }
    //cout<<"HERE"<<endl;
  const Comedy& otherMovie = dynamic_cast<const Comedy&>(other);

  if(this->title > otherMovie.title)
    {
      return true;
    }

    if(this->title == otherMovie.title)
    {
      if(this->year> otherMovie.year)
      {
        return true;
      }
    }
  return false;
}

// ---------------------Operator<=( -----------------------------------------
// Returns true if movie is <= than the other
//
bool Comedy::operator<=(const NodeData &other) const
{
  return !((*this) > other);
}

// ---------------------operator>= -----------------------------------------
// Returns true if movie is >= than the other
//
bool Comedy::operator>=(const NodeData &other) const
{
  return !(*this < other);
}

// ---------------------operator= -----------------------------------------
// Assignment operator, which compares the actor's first name and last.
//
NodeData& Comedy::operator=(const NodeData &other)
{

  if(typeid(*this)!= typeid(other))
  {
    cout<<"type mismatch"<<endl;
    return *this;
  }
  const Movie& otherMovie = dynamic_cast<const Movie&>(other);
  Movie::copyHelp(otherMovie);
  return *this;
}

// --------------------- display()-----------------------------------------
// Display function prints the stock, director and actor's information.
//
void Comedy::display()
{
  Movie::display();
}

// --------------------- serialize -----------------------------------------
// Outputs the stock, directorLastName, majorActorFirstName and month
//
void Comedy::serialize(ostream& output) const
{
  output << stock << " " << directorFirstName << " ";
  output << directorLastName << " " << title << " " << year;
}

// --------------------- Operator<< -----------------------------------------
// Prints movie's stock, first name, last name, title and date of movie
//
ostream& operator<<(ostream& output, const Comedy& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" "<< movie.year;
  	return output;
  }

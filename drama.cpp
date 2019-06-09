#include "drama.h"

Drama::Drama() : Movie()
{

}

Drama::Drama(int stock, string directorFirstName, string directorLastName,
  string title, int year) : Movie(stock, directorFirstName,directorLastName,
  title, year)
  {};

void Drama::display()
{
  Movie::display();
}

void Drama::serialize(ostream& output) const
{
  Movie::serialize(output);
}

NodeData& Drama::operator=(const NodeData &other)
{
  Movie::copyHelp(other);
  return *this;
}

bool Drama::operator==(const NodeData &other) const
{

  if(typeid(*this)!= typeid(other))
  {
    return false;
  }

  return Movie::compare(other);

}

bool Drama::operator!=(const NodeData &other) const
{
  return !(*this == other);
}

bool Drama::operator<(const NodeData &other) const
{
  if(typeid(*this)!= typeid(other))
  {
    string type1 = "7Classic";
    if(type1.compare(typeid(other).name()) == 0)
    {
      return true;
    }

    return false;
  }
  const Drama& otherMovie = dynamic_cast<const Drama&>(other);

  string thisDirector = (this->directorFirstName + " " + this->directorLastName);
  string otherDirector = otherMovie.directorFirstName + " "
    + otherMovie.directorLastName;

  if(thisDirector < otherDirector)
  {
    return true;
  }

  if(thisDirector == otherDirector)
  {
    //cout<<"got here"<<endl;
    if(this->title < otherMovie.title)
    {
      return true;
    }
  }
  return false;
}

bool Drama::operator>(const NodeData &other) const
{
  if(typeid(*this)!= typeid(other))
  {
    string type1 = "7Classic";
    if(type1.compare(typeid(other).name()) == 0)
    {
      return false;
    }
    return true;
  }
  
  const Drama& otherMovie = dynamic_cast<const Drama&>(other);

  string thisDirector = (directorFirstName + " " + directorLastName);
  string otherDirector = otherMovie.directorFirstName + " "
    + otherMovie.directorLastName;

  if(thisDirector > otherDirector)
  {
    return true;
  }

  if(thisDirector == otherDirector)
  {
    //cout<<"got here"<<endl;
    if(this->title > otherMovie.title)
    {
      return true;
    }
  }
  return false;
}

bool Drama::operator<=(const NodeData &other) const
{
  return !(*this > other);
}

bool Drama::operator>=(const NodeData &other) const
{
  return !(*this < other);
}

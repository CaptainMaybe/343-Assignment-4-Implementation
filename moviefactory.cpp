#include "moviefactory.h"

MovieFactory::MovieFactory()
{

}

Movie* MovieFactory::createMovie(string in, bool& valid)
{
  valid = true;
  string input = in;
  Movie* M;

  string movieType = "";
  string stock = "";
  stringstream temp;
  stringstream directorName;
  string directorFirstName = "";
  string directorLastName = "";
  string title = "";
  int year = 0;

  stringstream ss(input);
  getline(ss, movieType, ',');

  getline(ss, stock, ',');

  ss>>directorFirstName;
  ss>>directorLastName;
  directorLastName.pop_back();
  getline(ss, title, ',');

  if(movieType == "D")
  {
    ss>>year;
    M = new Drama(stoi(stock), directorFirstName, directorLastName, title, year);
    return M;
  }

  else if(movieType == "C")
  {
    string majorActorFirstName = "";
    string majorActorLastName = "";
    int month = 0;
    ss>>majorActorFirstName;
    ss>>majorActorLastName;
    ss>>month;
    ss>>year;

    M = new Classic( stoi(stock),  directorFirstName, directorLastName,
         majorActorFirstName, majorActorLastName, title, month, year);
  }

  else if(movieType == "F")
  {
    ss>>year;
    M = new Comedy(stoi(stock), directorFirstName, directorLastName, title, year);
    return M;
  }
  else
  {
    M = NULL;
    cout<<"Invalid input of movie type: "<<movieType<<". Ignoring line..." <<endl;
    valid = false;
  }
  return M;
}

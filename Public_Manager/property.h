#include <string>
using namespace std;


class Property
{

  public:
	  Property(){ price = 0, bedrooms = 0, gardens = 0, garages = 0, location = "", type = ""; }
	  int price;
	  
    int bedrooms;
    int gardens;
    int garages;
    string location;
	string type;

};

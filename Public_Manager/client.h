#include <string>
using namespace std;

class Client
{
public:
	Client() { name = "", id = 0; }
	void setID(int);
  int getID();
  void setName(string);
  string getName();

private:

	int id;
  string name;
};
  
string Client::getName()
{
	return name;
}
void Client::setName(string input)
{
	name = input;
}

int Client::getID()
{
	return id;
}

void Client::setID(int i)
{
	id = i;
}
#include <iostream>

#include "Item6.h"
#include "Item7.h"

using namespace std;

int main()
{
	unsigned int item;
	cout << "Type the number of the item: ";
	cin >> item;

	if (item == 6) 
	{
		testItem6();
	}
	else if (item == 7) 
	{
		testItem7();
	}

	cin.ignore();
	cin.get();
}
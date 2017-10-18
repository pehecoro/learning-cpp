#include <iostream>

#include "Item6.h"
#include "Item7.h"
#include "Item8.h"
#include "Item9.h"

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
	else if (item == 8)
	{
		testItem8();
	}
	else if (item == 9)
	{
		testItem9();
	}

	cin.ignore();
	cin.get();
}
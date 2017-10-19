#include <iostream>

#include "Item6.h"
#include "Item7.h"
#include "Item8.h"
#include "Item9.h"
#include "Item10.h"
#include "Item11.h"
#include "Item12.h"

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
	else if (item == 10)
	{
		testItem10();
	}
	else if (item == 11)
	{
		testItem11();
	}
	else if (item == 12)
	{
		testItem12();
	}

	cin.ignore();
	cin.get();
}
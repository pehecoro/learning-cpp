#ifndef _ITEM8_
#define _ITEM8_

#include <iostream>

class Machine {

public:
	Machine() : status(1), overload(0) {}
	~Machine() {
		try {
			turnOff();
		}
		catch (std::invalid_argument e) {
			std::cout << e.what() << '\n'; //glup
			//std::abort(); //end
		}
	}

	void workWork() {
		if (status == 1) {
			std::cout << "Working\n";
			overload++;
			if (overload == 3) status = 2;
		}
		else {
			std::cout << ". . . .\n";
		}
	}
	
	void turnOff() {
		if (status != 0) {
			std::cout << "Turning off..\n";
			if (status == 2) {
				throw std::invalid_argument("The Machine is broken");
			}
			status = 0;
		}
	}
private:
	unsigned int status;
	unsigned int overload;
};


void testItem8() {

	{
		Machine m;
		m.workWork();
		m.workWork();
		m.workWork();
		m.workWork();
		/* OR
		try {
			turnOff();
		}
		catch (std::invalid_argument e) {
			So... do X and Y
		}
		*/
	}


}


#endif
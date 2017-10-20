#ifndef _ITEM14_
#define _ITEM14_

#include "Item6.h"
#include <iostream>
#include <memory>

struct Mutex {
	int i = 25;
};

/*
class Lock : private Uncopyable{

private:
	Mutex* pMutex;

public:
	Lock(Mutex* m)
		: pMutex(m)
	{
		lock();
	}
	~Lock() {
		unlock();
	}

	void lock() 
	{ 
		std::cout << "Resource acquired\n"; 
	}
	void unlock()
	{
		std::cout << "Resource freed\n"; 
		delete pMutex;
	}

};
*/

void unlock(Mutex* pM)
{
	std::cout << "Resource freed\n";
	//refMutCount--;
	//if(refMutCount==0)
	delete pM;
}

class Lock {

private:
	std::shared_ptr<Mutex> pMutex;

public:
	Lock(Mutex* m)
		: pMutex(m, unlock)
	{
		lock();
	}

	void lock()
	{
		std::cout << "Resource acquired\n";
	}
	
};


void testItem14() {
	Mutex* m = new Mutex();
	std::cout << ">" << m->i << '\n';
	{
		
		Lock l(m);

		//Lock l2(new Mutex());
		// l = l2;
	}
	//std::cout << ">" << m->i << '\n';


}



#endif
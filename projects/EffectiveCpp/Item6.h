#ifndef _ITEM6_
#define _ITEM6_

class Uncopyable {

public:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);

};

class Boo : private Uncopyable {

public:
	Boo(){}
	~Boo(){}

};

void testItem6() {

	{
		Boo b;

		//Boo bp(b); // Uncopyable

		//Boo bp;
		//bp = b;    // Uncopyable

	}
}


#endif
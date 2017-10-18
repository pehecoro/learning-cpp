#ifndef _ITEM9_
#define _ITEM9_

#include <iostream>
#include <string>

class Box {

public:
	explicit Box(const std::string& content) 
	{ 
		std::cout << "Constructing Box\n"; 
		logBox(content);
	}
	//virtual void logBox() const = 0;
	void logBox(const std::string& content) const{
		std::cout << "Log process. . ." << content << '\n';
	}

};

class Boombox : public Box {

public:
	explicit Boombox(const std::string& content) 
		: Box(createContent(content))
	{
		std::cout << "Constructing BoomBox\n";
	}

	static std::string createContent(const std::string& cnt) {
		std::cout << "Creating. . . \n";
		return cnt;
	}
};

void testItem9() {

	{
		Boombox b(std::string("Phcr"));
	}


}

#endif
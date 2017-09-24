#include <iostream>
#include <string>

/*
	Variadic Template - A lot of coool things
*/

template <typename... Types>
struct TupleSize;

template <typename Head, typename... Tail>
struct TupleSize<Head, Tail...>
{
	static const size_t value = sizeof(Head) + TupleSize<Tail...>::value;
};

template <> struct TupleSize<>
{
	static const size_t value = 0;
};

template <typename... Strings>
void output_strings(const std::string s, Strings&... strings){
	std::cout << s << '\n';
	output_strings(strings...);
}

void output_strings(const std::string s) {
	std::cout << s << '\n';
}

//Multiple cool inheritance
template <typename... Bases>
class Player : public Bases...{

private:
	std::string name;

public:
	Player(std::string name, Bases... bs):name(name), Bases(bs)...{}
	std::string getName() const{ return name; }
};

class Character {

private:
	int life;
public:
	Character(int life) :life(life) {}
	int getLife() const { return life; }
};

class Monster {
private:
	int attack;
public:
	Monster(int attack) :attack(attack) {}
	int getAttack() const { return attack; }
};


int main() {

	std::cout << "TupleSize: " << TupleSize<long long int>::value << '\n';

	output_strings("Bread", "Apple", "Banana", "Lemon");

	Player<Character, Monster> p("Pedro",20,100);
	std::cout << "Name: " << p.getName() << '\n';
	std::cout << "Life: " << p.getLife() << '\n';
	std::cout << "Attack: " << p.getAttack() << '\n';


	std::cin.get();
}
#include <iostream>
#include <ctime>
#include <vector>

/*
	Exception, function pointer, auto, decltype, some vector optimizations 
*/

class Point{

		friend std::ostream& operator<<(std::ostream& os, const Point& p) {
			os << "X = " << p.x << " Y = " << p.y << " Z = " << p.z;
			return os;
		}
	private:
		float x, y, z;
	public:
		Point(float x, float y, float z) :x(x), y(y), z(z) {}
		~Point(){}
		Point(const Point& p):x(p.x),y(p.y),z(p.z) {
			std::cout << "Copying Point" << '\n';
		}
};

//Dangerous
void showNumber(void* thing) {
	int* x = (int*)thing;
	std::cout << *x << '\n';
}

void multiply(int a, int b) {
	std::cout << a << " * " << b << ": " << a*b << '\n';
}

void sum(int a, int b) {
	std::cout << a << " + " << b << ": " << a+b << '\n';
}

typedef void(*function) (int a, int b);

void whatDo(int a, int b) {
	function f;
	if (a > 5) {
		f = multiply;
	}
	else {
		f = sum;
	}

	f(a,b);
}

template <typename T>
void showMe(std::vector<T>& v, int pos){
	if (pos < 0) throw std::invalid_argument("must be greater than or equal to 0");
	v.at(pos);
}

int main() {

	srand(static_cast<unsigned int>(time(0)));

	int a = rand() % 10;
	int b = 10;

	showNumber(&a);

	whatDo(a, b);

	//Costs: Reallocate
	//       Copy constructor 6 times
	std::cout << "+-------Example1 Vector--------+" << '\n';
	std::vector<Point> points1;
	points1.push_back(Point(1.0f, 2.0f, 3.0f));
	points1.push_back(Point(1.0f, 2.0f, 3.0f));
	points1.push_back(Point(1.0f, 2.0f, 3.0f));

	for (auto it = points1.begin(); it != points1.end(); ++it) {
		std::cout << (*it) << '\n';
	}

	//Costs: ~~ ~~ ~~~
	//
	//->No reallocate and no copy constructor
	std::cout << "+-------Example2 Vector--------+" << '\n';
	decltype(points1) points2;
	points2.reserve(3);
	points2.emplace_back(2.0f,1.0f,4.0f);
	points2.emplace_back(2.0f, 1.0f, 4.0f);
	points2.emplace_back(2.0f, 1.0f, 4.0f);

	for(decltype(points2)::const_iterator it = points2.begin(); it != points2.end(); ++it){
		std::cout << (*it) << '\n';
	}

	try {
		std::cout << "+--Trying to show what doesn't exist--+\n";
		points1.at(10);
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << '\n';
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}

	try {
		std::cout << "+--Trying to access a invalid position--+\n";
		showMe(points2, -2);
	}
	catch (std::invalid_argument e) {
		std::cout << e.what() << '\n';
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}

	std::cin.get();
}
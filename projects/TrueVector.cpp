#include <iostream>

/*
	Simple Vector
*/

class TrueVector {

	friend std::ostream& operator<<(std::ostream& os, const TrueVector& tV);
	private:
		float x, y, z;
	public:
		TrueVector(float x, float y = 0, float z = 0):x(x),y(y),z(z) {}
		~TrueVector() {}

		TrueVector operator+(TrueVector& tV) {
			return TrueVector(x + tV.x, y + tV.y, z + tV.z);
		}

		void operator+=(TrueVector& tV) {
			x = x + tV.x;
			y = y + tV.y;
			z = z + tV.z ;
		}

		float operator*(TrueVector& tV) {
			return (x*tV.x) + (y*tV.y) + (z*tV.z);
		}

		float length() {
			return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		}
		
		TrueVector cross(TrueVector& tV) {
			return TrueVector(y*tV.z - z*tV.y,
							z*tV.x - x*tV.z,
							x*tV.y - y*tV.x);
		}

		TrueVector normalize() {
			float length = this->length();
			return TrueVector(x / length, y / length, z / length);
		}

};

std::ostream& operator<<(std::ostream& os, const TrueVector& tV) {
	os << "X = " << tV.x << ", Y = " << tV.y << ", Z = " << tV.z;
	return os;
}


int main() {

	TrueVector vector1(1.0f, 2.0f, 3.0f);
	TrueVector vector2(4.0f, 5.0f, 6.0f);

	std::cout << "TrueVector 1: " << vector1 << std::endl;

	std::cout << "TrueVector 2: " << vector2 << std::endl;

	vector2 += vector1;

	std::cout << "TrueVector 2 += TrueVector 1 = " << vector2 << std::endl;

	std::cout << "TrueVector 2 length: " << vector2.length() << std::endl;

	std::cout << "TrueVector 1 + TrueVector 2 = " << (vector1 + vector2) << std::endl;

	std::cout << "TrueVector 1 cross TrueVector 2: " << vector1.cross(vector2) << std::endl;

	TrueVector vector2Norm = vector2.normalize();

	std::cout << "TrueVector 2 normalized: " << vector2Norm << " | Length: " << vector2Norm.length() << std::endl;

	std::cin.get();

	return 0;
}
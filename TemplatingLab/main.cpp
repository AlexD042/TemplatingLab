#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <list>

// DECLARATIONS
template<typename T>
std::vector<T> vec_fill(T element);

template<typename T>
void order(T& a, T& b, T& c);

template<typename T>
T search(T begin, T end, int element);

void test_vec_fill();
void test_order();
void test_search();

// MAIN
int main() {
	test_vec_fill();
	test_order();
	test_search();
}

// DEFINITIONS

template<typename T>
std::vector<T> vec_fill(T element) {
	std::vector<T> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(element + i);
	}
	return vec;
}

template<typename T>
void order(T& a, T& b, T& c) {
	if (a < b) {
		T tempB = b;
		b = a;
		a = tempB;
	}
	if (a < c) {
		T tempC = c;
		c = a;
		a = tempC;
	}
	if (b < c) {
		T tempC = c;
		c = b;
		b = tempC;
	}

}

template<typename T>
T search(T begin, T end, int element) {
	for (T elementIterator = begin; elementIterator != end; ++elementIterator) {
		if (*elementIterator == element) {
			return elementIterator;
		}
	}
	return end;
}

void test_vec_fill() {
	std::vector<int> vectorInt = vec_fill<int>(5);
	assert(vectorInt.size() == 10);
	assert(vectorInt[0] == 5);
	assert(vectorInt[9] == 14);

	std::vector<double> vectorDouble = vec_fill<double>(1.5);
	assert(vectorDouble.size() == 10);
	assert(vectorDouble[0] == 1.5);
	assert(vectorDouble[9] == 10.5);

	std::vector<char> vectorChar = vec_fill<char>('a');
	assert(vectorChar.size() == 10);
	assert(vectorChar[0] == 'a');
	assert(vectorChar[9] == 'j');

	std::cout << "test_vec_fill PASSED\n";
}

void test_order() {
	int a1 = 10, b1 = 30, c1 = 20;
	order<int>(a1, b1, c1);
	assert(a1 == 30);
	assert(b1 == 20);
	assert(c1 == 10);

	double a2 = 2.5, b2 = 9.9, c2 = 5.1;
	order<double>(a2, b2, c2);
	assert(a2 == 9.9);
	assert(b2 == 5.1);
	assert(c2 == 2.5);

	std::string a3 = "apple", b3 = "cherry", c3 = "banana";
	order<std::string>(a3, b3, c3);
	assert(a3 == "cherry");
	assert(b3 == "banana");
	assert(c3 == "apple");

	std::cout << "test_order PASSED\n";
}

void test_search() {
	std::vector<int> vector = { 10, 20, 30, 40, 50 };
	auto vectorIterator = search(vector.begin(), vector.end(), 30);
	assert(vectorIterator != vector.end());
	assert(*vectorIterator == 30);
	assert(search(vector.begin(), vector.end(), 99) == vector.end());

	std::cout << "test_search PASSED\n";

	std::list<int> list = { 1, 2, 3, 4, 5 };
	auto listIterator = search(list.begin(), list.end(), 4);
	assert(listIterator != list.end());
	assert(*listIterator == 4);
	assert(search(list.begin(), list.end(), 99) == list.end());

	int array[4] = { 100, 200, 300, 400 };
	int* arrayBegin = array;
	int* arrayEnd = array + 4;
	int* arrayIterator = search(arrayBegin, arrayEnd, 200);
	assert(arrayIterator != arrayEnd);
	assert(*arrayIterator == 200);
	assert(search(arrayBegin, arrayEnd, 999) == arrayEnd);
}
#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
std::vector<T> vec_fill(T element);

template<typename T>
void order(T& a, T& b, T& c);

template<typename T>
T search(T begin, T end, int element);

void test_vec_fill();
void test_order();
void test_search();

int main() {
	test_vec_fill();
	test_order();
	test_search();
}

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
	for (T iter = begin; iter != end; ++iter) {
		if (*iter == element) {
			return iter;
		}
	}
	return end;
}

void test_vec_fill() {
	std::vector<int> v_int = vec_fill<int>(5);
	assert(v_int.size() == 10);
	assert(v_int[0] == 5);
	assert(v_int[9] == 14);

	std::vector<double> v_double = vec_fill<double>(1.5);
	assert(v_double.size() == 10);
	assert(v_double[0] == 1.5);
	assert(v_double[9] == 10.5);

	std::vector<char> v_char = vec_fill<char>('a');
	assert(v_char.size() == 10);
	assert(v_char[0] == 'a');
	assert(v_char[9] == 'j');

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
	std::vector<int> vec = { 10, 20, 30, 40, 50 };
	auto vec_it = search(vec.begin(), vec.end(), 30);
	assert(vec_it != vec.end());
	assert(*vec_it == 30);
	assert(search(vec.begin(), vec.end(), 99) == vec.end());

	std::cout << "test_search PASSED\n";
}
#ifndef FIXED_H
#define FIXED_H

#include <cmath>

template<typename T, size_t frac_bits>
class Q;

template<typename T, size_t frac_bits>
bool operator==(Q<T, frac_bits> &q1, Q<T, frac_bits> &q2);

template<typename T, size_t frac_bits>
class Q {
public:
	Q();
	Q(float val);

	float to_float();

	Q<T, frac_bits>& operator=(float val);
	Q<T, frac_bits> operator+(const Q<T, frac_bits> &q);
	Q<T, frac_bits> operator-(const Q<T, frac_bits> &q);
	Q<T, frac_bits> operator*(const Q<T, frac_bits> &q);
	Q<T, frac_bits> operator/(const Q<T, frac_bits> &q);

	friend bool operator==<>(Q<T, frac_bits> &q1, Q<T, frac_bits> &q2);

	T value;

private:
	const static T factor = 1 << frac_bits;
};

template<typename T, size_t frac_bits>
Q<T, frac_bits>::Q() {
	value = 0;
}

template<typename T, size_t frac_bits>
Q<T, frac_bits>::Q(float val) {
	*this = val;
}

template<typename T, size_t frac_bits>
float Q<T, frac_bits>::to_float() {
	float v = static_cast<float>(value);
	return v/factor;		
}

template<typename T, size_t frac_bits>
Q<T, frac_bits>& Q<T, frac_bits>::operator=(float val) {
	float rval = round(val*factor);
	value = static_cast<T>(rval);
	return *this;
}

template<typename T, size_t frac_bits>
Q<T, frac_bits> Q<T, frac_bits>::operator+(
	const Q<T, frac_bits> &q) {
	T result;
	result = value + q.value;
	
	Q<T, frac_bits> qresult;
	qresult.value = result;

	return qresult;
}

template<typename T, size_t frac_bits>
Q<T, frac_bits> Q<T, frac_bits>::operator-(
	const Q<T, frac_bits> &q) {
	T result;
	result = value - q.value;

	Q<T, frac_bits> qresult;
	qresult.value = result;

	return qresult;
}

template<typename T, size_t frac_bits>
Q<T, frac_bits> Q<T, frac_bits>::operator*(
	const Q<T, frac_bits> &q) {

}

template<typename T, size_t frac_bits>
Q<T, frac_bits> Q<T, frac_bits>::operator/(
	const Q<T, frac_bits> &q) {
	
}

template<typename T, size_t frac_bits>
bool operator==(Q<T, frac_bits> &q1, Q<T, frac_bits> &q2) {
	return q1.value == q2.value;
}

#endif
#pragma once

template<class T> class Vector_ref {
public:
	//...
	void push_back(T&); // add a named object
	void push_back(T*); // add an unnamed object

	T& operator[](int i); // subscripting: read and write access
	const T& operator[](int i) const;

	int size() const;
};
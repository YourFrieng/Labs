#pragma once
#include <iostream>



template <class T> 
class Array{
class Z {
public:
	T num;
};

private:
	Z* first;
	int size;

public:
	Array() {
		size = 0;
		Z* temp = new Z;
		first = temp;
	};
	Array(int siz) {
		size = siz;
		Z* temp = new Z[siz];
		first = temp;
		for (size_t i = 0; i < size; ++i) {
			(*this)[i] = 0;
		}
	};
	Array(const Array& p) {
		size = p.size;
		Z* temp = new Z[size];
		first = temp;
		for (int i = 0; i < size; ++i) {
			(*this)[i] = (p.first + i)->num;
		}
	};
	~Array() {
		delete[] first;
		first = nullptr;
	};

	T& operator [](int i) { return (this->first + i)->num; };
	Array operator +(const Array& B) {
		if (size == B.size) {
			Array newest(B);
			for (size_t i = 0; i < size; ++i) {
				newest[i] += (*this)[i];
			}
			return newest;

		}
		else if (size > B.size) {
			Array newest(size);
			for (size_t i = 0; i < B.size; ++i) {
				newest[i] = (*this)[i] + ((B.first + i)->num);
			}
			for (size_t i = B.size; i < size; ++i) {
				newest[i] = (*this)[i];
			}

			return newest;
		}
		else {
			Array newest(B.size);
			for (size_t i = 0; i < size; ++i) {
				newest[i] = (*this)[i] + ((B.first + i)->num);
			}
			for (size_t i = size; i < B.size; ++i) {
				newest[i] = (B.first + i)->num;
			}

			return newest;
		}
	};
	Array operator -(const Array& B) {
		if (size == B.size) {
			Array newest(*this);
			for (size_t i = 0; i < size; ++i) {
				newest[i] -= (B.first + i)->num;
			}
			return newest;

		}
		else if (size > B.size) {
			Array newest(size);
			for (size_t i = 0; i < B.size; ++i) {
				newest[i] = (*this)[i] - ((B.first + i)->num);
			}
			for (size_t i = B.size; i < size; ++i) {
				newest[i] = (*this)[i];
			}

			return newest;
		}
		else {
			Array newest(B.size);
			for (size_t i = 0; i < size; ++i) {
				newest[i] = (*this)[i] - ((B.first + i)->num);
			}
			for (size_t i = size; i < B.size; ++i) {
				newest[i] = (B.first + i)->num;
			}

			return newest;
		}
	};
	Array operator *(const Array& B) {
		if (size == B.size) {
			Array newest(B);
			for (size_t i = 0; i < size; ++i) {
				newest[i] *= (*this)[i];
			}
			return newest;

		}
		else if (size > B.size) {
			Array newest(size);
			for (size_t i = 0; i < B.size; ++i) {
				newest[i] = (*this)[i] * ((B.first + i)->num);
			}
			for (size_t i = B.size; i < size; ++i) {
				newest[i] = (*this)[i];
			}

			return newest;
		}
		else {
			Array newest(B.size);
			for (size_t i = 0; i < size; ++i) {
				newest[i] = (*this)[i] * ((B.first + i)->num);
			}
			for (size_t i = size; i < B.size; ++i) {
				newest[i] = (B.first + i)->num;
			}

			return newest;
		}
	};
	Array& operator =(const Array& A) {
		this->size = A.size;
		delete[] this->first;
		Z* newest = new Z[this->size];
		this->first = newest;
		for (size_t i = 0; i < this->size; ++i) {
			(*this)[i] = ((A.first + i)->num);
		}
		return *this;
	};
	friend std::ostream& operator<<(std::ostream& s, const Array& A) {
		s << "[ ";
		for (size_t i = 0; i < A.size; ++i) {
			s << (A.first + i)->num << ' ';
		}
		s << " ]";
		return s;
	};
	friend std::istream& operator>>(std::istream& s, Array& A) {
		for (size_t i = 0; i < A.getSize(); ++i) {
			s >> A[i];
		}
		return s;
	};
	void print() {
		Z* temp = first;
		while (temp < first + size)
		{
			std::cout << temp->num << std::endl;
			++temp;
		}
	};
		int getSize() { return size; };
		void print(int serial) {
			if (serial > size) {
				std::cout << "Error size of array = " << size << ". Please write correct number" << std::endl;
			}
			else {
				std::cout << (first + serial)->num << std::endl;
			}
		};
		void add(int item, T number) {
			if (item < size) {
				Z* temp = first + item;
				temp->num = number;
			}
		};
		void find(T number) {
			for (size_t i = 0; i < size; ++i) {
				if (((first + i)->num) == number) {
					std::cout << "Item number: " << i << std::endl;
				}
			}
		};
	};

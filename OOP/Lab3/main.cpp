#include <iostream>

class Z {
public:
	int num;
};

class Arr:Z {
public:
	Arr();
	Arr(int);
	Arr(const Arr& p);
	~Arr();

	int& operator [](int i);
	Arr operator +(const Arr& B);
	Arr operator -(const Arr& B);
	Arr operator *(const Arr& B);
	Arr& operator =(const Arr& A);
	void print();

	void print(int serial);
	void add(int item, int number);
	void find(int number);
	
private:
	int size;
	Z* first;
};


int main()
{
	int size1 = 4;
	int size2 = 5;
	Arr myarray(size1);
	for (int i = 0; i < size1; ++i) {
		myarray[i] = i;
	}
	Arr myarray1(size2);
	for (int i = 0; i < size2; ++i) {
		myarray1[i] = i;
	}

	
	
	myarray.print();
	myarray1.print();
	//myarray.print(3);
	myarray.find(5);
	std::cout << std::endl;
	Arr myarray3;
	myarray3 = (myarray + myarray1);
	myarray3.print();
	std::cout << std::endl;
	myarray3 = (myarray - myarray1);
	myarray3.print();
	std::cout << std::endl;
	myarray3 = (myarray * myarray1);
	myarray3.print();
	return 0;
}

Arr::Arr() {
	size = 0;
	Z* temp = new Z;
	first = temp;
}

Arr::Arr(int siz)
{
	size = siz;
	Z* temp = new Z[ siz ];
	first = temp;
	for (int i = 0; i < size; ++i) {
		(*this)[i] = 0;
	}

}

Arr::Arr(const Arr& p)
{
	size = p.size;
	Z* temp = new Z[size];
	first = temp;
	for (int i = 0; i < size; ++i) {
		(*this)[i] = (p.first + i)->num;
	}
}

Arr::~Arr()
{
	delete[] first;
	first = nullptr;
}




int& Arr::operator[](int i)
{

	return (first + i)->num;
	
}

Arr Arr::operator+(const Arr& B)
{
	if (size == B.size) {
		Arr newest(B);
		for (size_t i = 0; i < size; ++i) {
			newest[i] += (*this)[i];
		}
		return newest;

	}
	else if (size > B.size) {
		Arr newest(size);
		for (size_t i = 0; i < B.size; ++i) {
			newest[i] = (*this)[i] + ((B.first + i)->num);
		}
		for (size_t i = B.size; i < size; ++i) {
			newest[i] = (*this)[i];
		}

		return newest;
	}
	else {
		Arr newest(B.size);
		for (size_t i = 0; i < size; ++i) {
			newest[i] = (*this)[i] + ((B.first + i)->num);
		}
		for (size_t i = size; i < B.size; ++i) {
			newest[i] = (B.first + i)->num;
		}

		return newest;
	}
}

Arr Arr::operator-(const Arr& B)
{
	if (size == B.size) {
		Arr newest(*this);
		for (size_t i = 0; i < size; ++i) {
			newest[i] -= (B.first + i)->num;
		}
		return newest;

	}
	else if(size > B.size){
		Arr newest(size);
		for (size_t i = 0; i < B.size; ++i) {
			newest[i] = (*this)[i] - ((B.first + i)->num);
		}
		for (size_t i = B.size; i < size; ++i) {
			newest[i] = (*this)[i];
		}

		return newest;
	}
	else {
		Arr newest(B.size);
		for (size_t i = 0; i < size; ++i) {
			newest[i] = (*this)[i] - ((B.first + i)->num);
		}
		for (size_t i = size; i < B.size; ++i) {
			newest[i] = (B.first +i)->num;
		}

		return newest;
	}

	
}

Arr Arr::operator*(const Arr& B)
{

	if (size == B.size) {
		Arr newest(B);
		for (size_t i = 0; i < size; ++i) {
			newest[i] *= (*this)[i];
		}
		return newest;

	}
	else if (size > B.size) {
		Arr newest(size);
		for (size_t i = 0; i < B.size; ++i) {
			newest[i] = (*this)[i] * ((B.first + i)->num);
		}
		for (size_t i = B.size; i < size; ++i) {
			newest[i] = (*this)[i];
		}

		return newest;
	}
	else {
		Arr newest(B.size);
		for (size_t i = 0; i < size; ++i) {
			newest[i] = (*this)[i] * ((B.first + i)->num);
		}
		for (size_t i = size; i < B.size; ++i) {
			newest[i] = (B.first + i)->num;
		}

		return newest;
	}
}

Arr& Arr::operator=(const Arr& A)
{
	this->size = A.size;
	delete[] this->first;
	Z* newest = new Z[this->size];
	this->first = newest;
	for (size_t i = 0; i < this->size; ++i) {
		(*this)[i] = ((A.first + i)->num);
	}
	return *this;
}

void Arr::print()
{
	Z* temp = first;
	while (temp < first + size)
	{
		std::cout << temp->num << std::endl;
		++temp;
	}
}



void Arr::print(int serial)
{
	if (serial > size) {
		std::cout << "Error size of array = " << size << ". Please write correct number" << std::endl;
	}
	else {
	std::cout << (first + serial)->num << std::endl;
}

}

void Arr::add(int item, int number)
{
	if (item < size) {
		Z* temp = first + item;
		temp->num = number;
	}
}

void Arr::find(int number)
{
	Z* temp = first;
	for (size_t i = 0; (temp + i) < (first + size); ++i) {
		if (temp->num == number) {
			std::cout << "Item number: " << i << std::endl;
		}
	}
}

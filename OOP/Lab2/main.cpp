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
	int size = 4;
	Arr myarray(size);
	for (int i = 0; i < size; ++i) {
		myarray.add(i, i);
	}

	myarray.print();
	myarray.print(3);
	myarray.find(5);
	myarray.~Arr();
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
}

Arr::Arr(const Arr& p)
{
	size = p.size;
	first = p.first;
}

Arr::~Arr()
{
	delete[] first;
	first = nullptr;
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

#include "array.h"



int main()
{
	int size1 = 4;
	int size2 = 5;
	Array<int> myarray(size1);
	for (int i = 0; i < size1; ++i) {
		myarray[i] = i;
	}
	Array<int> myarray1(size2);
	for (int i = 0; i < size2; ++i) {
		myarray1[i] = i;
	}

	
	
	myarray.print();
	myarray1.print();
	myarray.print(3);
	myarray.find(5);
	std::cout << std::endl;
	Array<int> myarray3;
	myarray3 = (myarray + myarray1);
	myarray3.print();
	std::cout << std::endl;
	myarray3 = (myarray - myarray1);
	myarray3.print();
	std::cout << std::endl;
	myarray3 = (myarray * myarray1);
	myarray3.print();
	std::cout << myarray << std::endl;
	std::cout << std::endl;
	Array<int> myarray4(5);
	std::cin >> myarray4;
	std::cout << myarray4;
	return 0;
}

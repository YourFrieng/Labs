#include"list.h"

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	List lst; //Объявляем переменную, тип которой есть список
	ifstream read_file("input.txt");
	TE a;
	while (read_file >> a) {

		lst.Add(a);	//добавление елемента

	}
	read_file.close();

	lst.If_NULL(); //Отображаем пуст ли список
	cout << endl;
	lst.Show();//Отображает список
	lst.WriteInFile();//Записывает список в файл
	cout << endl;
	lst.ShowASCII();//Показывает ASCII код последнего и предпоследнего елементов списка
	cout << endl;
	lst.Sort();
	cout << "After sorting" << endl;
	lst.Show();
	lst.WriteInFile();
	return 0;
}

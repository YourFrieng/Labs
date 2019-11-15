#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

typedef char TE;

struct list                             //Структура, являющаяся звеном списка
{
	TE x;                             //Значение x будет передаваться в список
	list* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class List                              //Создаем тип данных Список
{
	list* Head, * Tail;                 //Указатели на адреса начала списка и его конца
public:
	List() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
	void Show();                       //Прототип функции отображения списка на экране
	void Add(char x);                   //Прототип функции добавления элементов в список
	void If_NULL();
	void WriteInFile();
	void ShowASCII();
	void Sort();
};
void Show();                       //Прототип функции отображения списка на экране
void Add(char x);                   //Прототип функции добавления элементов в список
void If_NULL();
void WriteInFile();
void ShowASCII();
void Sort();
void Make_by_File(List list);

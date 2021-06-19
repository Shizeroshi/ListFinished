#include "List.h"
#include "Element.cpp"
#include "BaseIterator.cpp"
#include "Iterator.cpp"
#include "ReverseIterator.cpp"
#include "ConstIterator.cpp"
#include "ListClass.cpp"
#include "Methods.cpp"

//#define BaseCheck
//#define SizeConstructor
//#define IteratorsCheck
//#define IteratorsCheck2
//#define IteratorsCheck3
//#define IteratorsCheck4


int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	int n;
	cout << "Введите размер списка: "; cin >> n;

#ifdef SizeConstructor
	List list(n);
	for (size_t i = 0; i < list.getSize(); i++)list[i] = rand() % 100;
	for (size_t i = 0; i < list.getSize(); i++)cout << list[i] << tab;
	cout << endl;
	list.print();
#endif // SizeConstructor


#ifdef BaseCheck
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	cout << endl << endl;
	list.pop_front();
	list.print();
	cout << endl << endl;
	list.pop_back();
	list.print();
	cout << endl << endl;
	int index;
	int value;
	cout << "Индекс: "; cin >> index;
	cout << "Добавить: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.print_reverse();
	cout << "Индекс удаляемого: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BaseCheck

#ifdef IteratorsCheck
	List list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
		cout << i << tab;
	cout << endl;

	for (List::Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << "\n-------------------------------------------------------------\n";
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // IteratorsCheck


#ifdef IteratorsCheck2
	List list1 = { 3, 5, 8, 13, 21 };
	//list1.print();
	for (int i : list1)
	{
		cout << i << tab;
	}
	List list2 = list1; //CopyConstructor
	list2.print();
#endif // IteratorsCheck2


#ifdef IteratorsCheck3
	List list1 = { 3, 5, 8, 13, 21 };
	list1.print();
	List list2 = { 34, 55, 89 };
	list2.print();
	List list3 = list2 + list1;
	list3.print();
	list2.print();
#endif // IteratorsCheck3

#ifdef IteratorsCheck4
	List<int> list1 = { 1,3,5 };
	List<int> list2 = { 2,4,6 };
	cout << delimiter << endl;
	List<int> list3;
	list3 = list1 + list2;
	cout << delimiter << endl;
	list3.print();
#endif // IteratorsCheck4

	List<int> i_list = { 3, 5, 6, 12, 21 };
	i_list.print();
	List<double> d_list = { 2.5, 3.14, 5.2, 8.3 };
	d_list.print();
	List<string> s_list = { "What", "The", "Fuck" };
	for (string i : s_list)cout << i << tab; cout << endl;

	for (List<string>::Iterator it = s_list.begin(); it != s_list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (List<string>::ReverseIterator it = s_list.rend(); it != s_list.rbegin(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

#include "List.h"

template <typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
#ifdef DEBUG
	cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

}
template <typename T>List<T>::List(int size) :List()
{
	while (size--)push_back(0);
}
template <typename T>List<T>::List(const initializer_list<T>& il) : List()
{
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
		push_back(*it);
}
template <typename T>List<T>::List(const List<T>& other) :List()
{
	//for (T i : other.begin())push_back(i);
	for (Iterator it = other.begin(); it != other.end(); it++)
	{
		push_back(*it);
	}
}
template <typename T>List<T>::List(List<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;
	other.Head = other.Tail = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
template <typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
#ifdef DEBUG
	cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

}
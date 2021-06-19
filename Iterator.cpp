#include "List.h"

template<typename T>List<T>::Iterator::Iterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "ITConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "ITDestructor:\t" << this << endl;
#endif // DEBUG

}

template<typename T>typename List<T>::Iterator& List<T>::Iterator::operator++() // Prefix increment
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::Iterator List<T>::Iterator::operator--(int)
{
	Iterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
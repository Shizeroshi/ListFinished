#include "List.h"

template<typename T>List<T>::ReverseIterator::ReverseIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RITConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::ReverseIterator::~ReverseIterator()
{
#ifdef DEBUG
	cout << "RITConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ReverseIterator List<T>::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator--()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ReverseIterator List<T>::ReverseIterator::operator--(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pNext;
	return old;
}
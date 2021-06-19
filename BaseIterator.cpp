#include "List.h"

template<typename T>List<T>::BaseIterator::BaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "BITConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::BaseIterator::~BaseIterator()
{
#ifdef DEBUG
	cout << "BITDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>const T&List<T>::BaseIterator:: operator*()const
{
	return Temp->Data;
}
template<typename T>T& List<T>::BaseIterator::operator*()
{
	return Temp->Data;
}
template<typename T>bool List<T>::BaseIterator::operator==(const BaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::BaseIterator::operator!=(const BaseIterator& other)const
{
	return this->Temp != other.Temp;
}
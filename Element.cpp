#include "List.h"

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) // :Data(Data), pNext(pNext), pPrev(pPrev)
{
	this->Data = Data;
	this->pNext = pNext;
	this->pPrev = pPrev;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}
#pragma once
#include <iostream>
#include <string>

using namespace std;

#define tab "\t"
#define delimiter "\n---------------------------------------------------------\n"
//#define DEBUG

template<typename T>
class List
{
	class Element
	{
		T Data; // Значение элемента
		Element* pNext; // Указатель на некст элемент
		Element* pPrev; // Указатель на пред элемент
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	};
	Element* Head; // Указатель на начальный элем списка
	Element* Tail; // На конечный
	unsigned int size; // Размер списка

	class BaseIterator
	{
	protected:
		Element* Temp;
	public:
		BaseIterator(Element* Temp = nullptr);
		~BaseIterator();
		const T& operator*()const;
		T& operator*();
		bool operator==(const BaseIterator& other)const;
		bool operator!=(const BaseIterator& other)const;
		/*friend class Iterator;
		friend class ReverseIterator;*/
	};
public:
	class Iterator : public BaseIterator
	{
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();

		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
	};
	class ConstIterator :public Iterator
	{
	public:
		ConstIterator(Element* Temp) :Iterator(Temp)
		{

		}
		~ConstIterator()
		{

		}
		const int& operator*()
		{
			return Iterator::operator*();
		}
	};
	class ReverseIterator : public BaseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr);
		~ReverseIterator();
		ReverseIterator& operator++();
		ReverseIterator operator++(int);
		ReverseIterator& operator--();
		ReverseIterator operator--(int);

	};
	size_t getSize()const;
	ConstIterator begin()const;
	Iterator begin();
	ConstIterator end()const;
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();

	List();
	explicit List(int size);
	List(const initializer_list<T>& il);
	List(const List<T>& other);
	List(List<T>&& other);
	~List();

	//			Operators

	List<T>& operator=(const List<T>& other);


	T& operator[](size_t index);

	//			Adding elements

	void push_front(T Data);

	void push_back(T Data);

	void insert(unsigned int Index, T Data);

	//			Erasing elements

	void pop_front();

	void pop_back();

	void erase(int index);

	//			methods

	void print();

	void print_reverse();
};
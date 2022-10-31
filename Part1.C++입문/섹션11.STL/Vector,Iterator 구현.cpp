#include <iostream>
using namespace std;
#include <vector>

// vector 중 기능 몇가지만 만들어보자.
template<typename T> class Iterator;

template<typename T>
class Vector //우리가 만든거니 Vector라고 대문자를 쓰자
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}
	~Vector()
	{
		if (_data)
			delete[] _data; //배열형태로 만들어줄것이니, 여러개를 넣을때를 대비해 delete[]
	}

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			//증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);

			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity); //증설 후 기존데이터 옮기는 작업을 2번 코딩하지 않게 그냥 reserve에 만들고 호출.
		}

		_data[_size] = val;
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		T* newData = new T[_capacity];
		
		//데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		if (_data) //기존에 있던 데이터 날린다.
			delete[] _data;
		
		_data = newData;
	}

	T& operator[] (const int pos) //실제값을 다루기에 T&로 레퍼런스로 다뤄줘야함.
	{
		return _data[pos];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin()
	{
		return iterator(&_data[0]);
	}
	iterator end()
	{
		return begin() + _size;
	}
	iterator clear()
	{
		_size = 0;
	}


private:
	T* _data;
	int _size;
	int _capacity;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{
	}
	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}
	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}
	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}
	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
	//소속 컨테이너는 귀찮으니 생략
};


int main()
{
	Vector<int> v;

	v.reserve(10);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "------------" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}

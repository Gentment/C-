#include<iostream>

using namespace  std;

namespace myfun
{	

	template<class T>
	class vector
	{
	typedef T* iterator;
	typedef T* reverse_iterator;
	public:

		vector() :_start(nullptr), _end(nullptr), _capacity(0){}
		vector(size_t n,const T& data = T()):_start(new T[n]),_end(_start+n),_capacity(_end)
		{
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = data;
			}
		}

		vector(T* last, T* end)
		{
			size_t size = *end - *last;
			_start = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				_start[i] = last[i];
			}

			_end = _start + size;
			_capacity = _end;
		}

		vector(const vector<T> &data)
		{
			reverse(data._capacity);
			size_t size = data.size();
			for (size_t i = 0; i < data.size(); ++i)
			{
				_start[i] = data[i];
			}

			_start = data;
			
			_capacity = data._end;

		}


		void reverse(size_t n)
		{
			if (n> Capacity())
			{
				size_t size = size();

				T* temp = new T[n];

				if (_start)
				{
					for (size_t i=0;i<size;++i)
					{
						temp[i] = _start[i];
					}
				}

				_start = temp;
				_end = _start + size;
				_capacity = _start + n;
			}
		}

		size_t size()
		{
			return *_end - *_start;
		}
		size_t Capacity()
		{
			return *_capacity;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _end = nullptr;
			}
		}

		iterator Begin()
		{
			return _start;
		}
		iterator End()
		{
			return _end;
		}

		const iterator Begin() const
		{
			return _start;
		}
		const iterator End() const
		{
			return _end;
		}

		T& operator[](size_t index)
		{
			return _start[index];
		}

		const T& operator[](size_t index) const
		{
			return _start[index];
		}
	private:
		iterator  _start;
		iterator  _end;
		iterator  _capacity;
	};
}

using namespace myfun;
int main()
{
	vector<int> v(10,1);
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	v[i] = i;
	//}

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
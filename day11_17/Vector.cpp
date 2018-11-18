#include<iostream>

using namespace std;

namespace myfun{

    template<class T>
    class vector
    {   
        public:
            typedef T* iterator;
            typedef T* reverse;
        public:
            vector(): _start(nullptr),_last(nullptr),_endOfStroage(nullptr){}

            vector(size_t n,const T& data): _start(new T[n]),_last(_start+n),_endOfStroage(_last)
            {                
                for(size_t i = 0; i < n; ++i)
                {
                    _start[i] = data;
                }                
            }


            // vector(const vector<T>& v):_start(nullptr),_last(nullptr),_endOfStroage(nullptr)
            // {
            //     // reserver(v.capacity());
                
            //     for(iterator it=v.Begin();it != v.End();++it)
            //     {
            //         *it++ = *v++ ;
            //     }
               
            //     _last = v._last;
            //     _endOfStroage = v._endOfStroage;
            // }

            ~vector()
            {
                if(_start)
                {
                    delete[] _start;
                }
                _start = nullptr;
                _last = nullptr;
                _endOfStroage = nullptr;
            }

            vector<T>& operator=(const vector<T>& v)
            {

            }

            iterator Begin()
            {
                return _start;
            }

            iterator End()
            {
                return _last;
            }  

            // reverse_iterator rbegin()
            // {   
            //     return _last;
            // }
            // reverse_iterator rend()
            // {
            //     return _start;
            // }

            size_t Size() const
            {
                return _last-_start;
            }

            size_t capacity()const
            {
                return _endOfStroage - _start;
            }

            bool empty()const
            {
                return _start == _last;
            }

            void resize(size_t newSize,const T& data=T())
            {
                if(newSize <= Size())
                {
                    _last = _start+newSize;
                }
                if(newSize > capacity())
                {
                    reserver(newSize);
                }

                iterator  it = _last;
                iterator _last = _start + newSize;  //大小+
                
                //把申请到的预留空间放一个int占着
                while(it != _last){
                    *it = data;
                    ++it;
                }
                
            }

            // //预留空间
            void reserver(size_t newCapacity)
            {
                if(newCapacity > capacity())
                {
                    size_t size = Size();
                    T* temp = new T[newCapacity];

                    if (_start) {
                        
                        for(size_t i = 0; i < size; ++i)
                        {
                            temp[i] = _start[i];
                        }
                        /*
                        *   _endOfStroage = newCapacity ;失败，左值修改错误  ？
                        */
                        _start = temp;
                        _last = _start+size;
                        _endOfStroage = _start +newCapacity;
                    }
                    
                }
              
                
            }

            T& operator[](size_t index)
            {
                return _start[index];
            }

            const T& operator[](size_t index)const
            {
                return _start[index];
            }

            T& front()
            {
                return *_start;
            }

            const T& front()const
            {
                return *_start;
            }


            T& back()
            {
                return *(_last-1);
            }

            const T& back()const
            {
                return *(_last-1);
            }


            void push_back(const T& data){

                
                if (size() == capacity()) {
                    reverse(capaccity()*2);
                }
                
                size_t len = capacity()*2;
                T *temp = T(len);
                
                for(size_t i = 0; i < len; i++)
                {
                    temp[i] = _start[i];
                }
                temp[]
                
            }

            void pop_back()
            {
                
                if (size() > 0) {
                    --size();
                }
                
            }
            iterator insert(iterator pos,const T& data)
            {

            }

            // iterator earse(){}
            // void swap()
            // {

            // }
            // void clear()
            // {


            // }
            friend ostream& operator<<(ostream& _cout,vector& v)
            {
                _cout<<v.capacity()<<v.Size()<<v.back()<<v.front();
                return _cout;
            }

            friend istream& operator>>(istream& _cin,vector& v)
            {

            }
        private:
            iterator _start;
            iterator _last;
            iterator _endOfStroage;
    };


}

using namespace myfun;

void vectorTest()
{
    vector<int> v(4,4);
    
    for(size_t i = 0; i < 4; i++)
    {
        /* code */
        v[i]=i;
    }
    
    for(size_t i = 0; i < v.Size(); i++)
    {
        /* code */
        cout<<v[i]<<" ";
    }
    cout <<endl;
    
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;

    // v.reserver(10);
    v.resize(3);
    cout<<"Size"<<v.Size()<<endl;
    cout<<"capacity"<<v.capacity()<<endl;
    
   
}

int main()
{
    vectorTest();
    return 0;

}
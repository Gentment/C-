#include<iostream>

using namespace std;

class String
{
public:

// default (1) string();
// copy (2)	 string (const string& str);
// substring (3)	 string (const string& str, size_t pos, size_t len = npos);
// from c-string (4)	 string (const char* s);
// from buffer (5) string (const char* s, size_t n);
// fill (6)	 string (size_t n, char c);
// range (7)	 template <class InputIterator>   string  (InputIterator first, InputIterator last);
// initializer list (8)	string (initializer_list<char> il);
// move (9)	 string (string&& str) noexcept;
    
    String(const char* ret=""){}
    
    String(const String& str)
    {
        _str = str._str;
        _size = str._size;
        _capcity = str._capcity;
        
    }

    String& operator=(String s)
    {
        swap(_str,s._str);
        return *this;
    }

    friend ostream& operator<<(ostream& _cout,const String& s)
    {
        _cout<<s._str;
        returnnn _cout;
    }
    friend ostream& operator>>(istream& _cin, String& s)
    {
        _cin>>s._str;
        return _cin;
    }
private:
    char *_str;
    size_t _capcity;
    size_t _size;
};


int main()
{
    String s("123");
    
}
#include<iostream>
#include<string.h>
using namespace std;
// #if 0
// class myString
// {
//     public:
//         myString(){};
//         ~myString(){};
//         myString(const char* str)
//         {
//             if(!str)
//             {
//                 data=new char[1];
//                 *data='\0';
//             }else{
//                 int len = strlen(str)+1;
//                 data = new char[len];
//                 strcpy(data,str);
//             }
//         }
//         myString(const myString& str)
//         {
//             int len = strlen(str.data)+1;
//             data = new char[len];
//             strcpy(data,str.data);
//         }
//         myString& operator=(const myString& str)
//         {
//             if(this==&str)return *this;
//             int len = strlen(str.data)+1;
//             data = new char[len];
//             strcpy(data,str.data);
//             return *this;
//         }
//         friend ostream& operator<<(ostream& os,myString& str);
//     private:
//         char* data;
//         int length;
// };
// class test
// {
//     public:
//         test()
//         {
//             a=1;
//             b=2;
//             cout<<"2"<<endl;
//         }
//         test(int a,int b=2)
//         {
//             cout<<"1"<<endl;
//         }
//     private:
//         int a;
//         int b;
// };
// ostream& operator<<(ostream& os,myString& str)
// {
//     os << str.data;
// 	return os;
// }
// int main()
// {
//     char c[] = "hello world";
//     myString str(c);
//     cout<<str<<endl;
//     myString str1(str);
//     cout<<str1<<endl;
//     myString str2;
//     str2=str1;
//     cout<<str2<<endl;
//     test t;
//     test t1(1);
//     return 0;
// }
// #else
// class String
// {
//     private:
//         char* data;
//         int length;
//     public:
//         String(const char* str);
//         String(const String& str);
//         ~String();
//         size_t size() const;
//         String& operator=(const String& str);
//         String& operator+=(const String& str);

//         friend ostream& operator<<(ostream& os,const String& str);
// };

// String::String(const char* str)
// {
//     if(!str)
//     {
//         length = 0;
//         data = new char[1];
//         data[0] = '\0';
//     }else{
//         length = strlen(str);
//         data = new char[length+1];
//         strcpy(data,str);
//     }
// }

// size_t String::size() const
// {
//     return length;
// }

// String::String(const String& str)
// {
//     length = str.size();
//     data = new char[length+1];
//     strcpy(data,str.data);
// }

// String::~String()
// {
//     if(data)
//         delete[] data;
//     length = 0; 
// }

// String& String::operator=(const String& str)
// {
//     if(this==&str) return *this;
//     delete[] data;
//     int len = str.size();
//     data = new char[len+1];
//     strcpy(data,str.data);
//     return *this;
// }

// ostream& operator<<(ostream& os,const String& str)
// {
//     os<<str.data;
//     return os;
// }

// int main()
// {
//     String str("hello world");
//     String str1(str);
//     String str2 = str1;
//     cout<<str2<<endl;
//     return 0;
// }
// #endif

class String
{
    private:
        char* data;
        int length;
    public:
        String(const char* str);
        String(const String& str);
        ~String();

        String& operator=(const String& str);
        String& operator+=(const String& str);

        friend  ostream& operator<<(ostream& os,String& str);
};

String::String(const char* str)
{
    if(!str)
    {
        length = 0;
        data = new char[1];
        *data = '\0';
    }else{
        length = strlen(str);
        data = new char[length+1];
        strcpy(data,str);
    }
}
String::String(const String& str)
{
    length = str.length;
    data = new char[length+1];
    strcpy(data,str.data);
}

String::~String()
{
    if(data)
        delete[] data;
    length = 0;
}

String& String::operator=(const String& str)
{
    if(this==&str)return *this;
    delete[] data;
    length = str.length;
    data = new char[length+1];
    strcpy(data,str.data);
    return *this;
}

String& String::operator+=(const String& str)
{
    length = strlen(data)+strlen(str.data);
    char* _data = new char[length+1];
    strcpy(_data,data);
    strcpy(_data+strlen(data),str.data);
    _data[length] = '\0';
    delete[] data;
    data = _data;
    return *this;
}

ostream& operator<<(ostream& os,String& str)
{
    os<<str.data;
    return os;
}

class demo
{
public:
	demo():m_str("hello wolrd") {}
	string getStr()
	{
		return m_str;
	}
private:
	string m_str;
};

void fun(char*& p)
{
    demo d;
	p = &d.getStr()[0];
}

void *mymemcpy(void *__dest, __const void *__src, size_t __n)
{
	int i = 0;
	unsigned char *d = (unsigned char *)__dest, *s = (unsigned char *)__src;

	for (i = __n >> 3; i > 0; i--) {
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1 << 2) {
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1 << 1) {
		*d++ = *s++;
		*d++ = *s++;
	}

	if (__n & 1)
		*d++ = *s++;

	return __dest;
}

char *mystrstr(const char *s1, const char *s2)
{
    size_t l1,l2;
    l2 = strlen(s2);
    if(!l2)
        return (char *)s1;
    l1 = strlen(l1);
    while (l1>=l2)
    {
        l1--;
        if(!memcmp(s1,s2,l1))
            return (char *)s1;
        s1++;
    }
    return NULL;
    
}

int main()
{
    String str("how are you");
    String str1(str);
    String str2(str1);
    //cout<<str2<<endl;
    //str2 += str1;
    //cout<<str2<<endl;

    char *s1 = "hello";
    char *s2 = "ll";
    char *ret = mystrstr(s1, s2);
    cout<<ret<<endl;

    char *p = NULL;
	fun(p);
	printf("%s \n",p);
    return 0;
}
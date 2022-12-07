#include <iostream>
using namespace std;

class A
{
    public:
        inline A():a(0),b(0){};
        A(int al, int ba):a(al),b(ba){};
        A operator+ (A const &other) const;
        A operator- (A const &other) const;
        A operator* (A const &other) const;
        A operator% (A const &other) const;
        bool operator&& (const A &other) const;
        bool operator|| (const A &other) const;
        bool operator== (const A &other) const;
        bool operator!= (const A &other) const;
        void *operatornew (int size);
        void operator++ (void);
        void operator++ (int);
        void operator= (A const &other);
        A operator- (void) const;
        friend ostream & operator << (ostream &output, const A &obj);
        friend istream & operator >> (istream &input, A &obj);
        A(A &other);
        int a;
        int b;
};

ostream & operator << (ostream &output, const A &obj)
{
    output << obj.a << endl << obj.b;
    return (output);
}

istream & operator >> (istream &input, A &obj)
{
    input >> obj.a;
    input >> obj.b;
    return (input);
}

A::A(A &other)
{
    a = other.a;
    b = other.b;
}

A A::operator+ (A const &other) const
{
    A obj;
    obj.a = a + other.a;
    obj.b = b + other.b;
    return (obj);
}

A A::operator- (A const &other) const
{
    A obj;
    obj.a = a - other.a;
    obj.b = b - other.b;
    return (obj);
}

A A::operator* (A const &other) const
{
    A obj;
    obj.a = a * other.a;
    obj.b = b * other.b;
    return (obj);
}

A A::operator% (A const &other) const
{
    A obj;
    obj.a = a % other.a;
    obj.b = b % other.b;
    return (obj);
}

void A::operator++(void)
{
    ++a;
    ++b;
} 

void A::operator++(int)
{
    a++;
    b++;
}

A A::operator-(void) const
{
    A temp;
    temp.a = -a;
    temp.b = -b;

    return (temp);
}

bool A::operator&& (const A &other) const
{
    return ((a && b) && (other.a && other.b));
}

bool A::operator|| (const A &other) const
{
    return ((a && b) || (other.a && other.b));
}

bool A::operator== (const A &other) const
{
    return ((a == other.a) && (b == other.b));
}

bool A::operator!= (const A &other) const
{
    return ((a != other.a) || (b != other.b));
}

void A::operator= (const A &other)
{
    a = other.a;
    b = other.b;
}

void * A::operatornew (int size)
{
    void * p = ::operator new (size);
    return (p);
}

int main()
{
    // A obj1(3,5), obj2(3, 5);
    // A obj3;
    // A obj4;

    // obj3 = obj1 + obj2;
    // cout << obj3.a << " " << obj3.b << endl;
    // obj3 = obj1 - obj2;
    // cout << obj3.a << " " << obj3.b << endl;
    // obj3 = obj1 * obj2;
    // cout << obj3.a << " " << obj3.b << endl;
    // obj3 = obj1 % obj2;
    // cout << obj3.a << " " << obj3.b << endl;
    // ++obj3;
    // cout << obj3.a << " " << obj3.b << endl;
    // obj3++;
    // cout << obj3.a << " " << obj3.b << endl;
    // if (obj1 == obj2)
    //     cout << "hiho";
    // cin >> obj4;
    // cout << obj4;
    // cout << -obj4;
    int *p1, *p2, v1, v2;
    p1 = &v1;
    cout *p1;
}

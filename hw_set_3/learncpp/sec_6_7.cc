#include <iostream> 
#include <typeinfo>

using namespace std; 

int main() { 
    int x = 5; 
    cout << x << endl; 
    cout << &x << endl; 
    cout << *&x << endl; 

    int * y = &x; 
    cout << y << endl; 
    cout << &y << endl; 
    cout << *y << endl; 

    int array[] = { 9, 7, 1, 1, 1, 1, 1 }; 
    for ( auto i = 0; i != 6; i ++ ) {
        cout << & array[ i ] << endl; 
    }

    int * ptr = new int { 7 }; 
    cout << typeid( ptr ).name() << endl; 

    cout << ptr << endl; 
    cout << *ptr << endl; 
    cout << &ptr << endl; 

    // 
    return 0; 
}

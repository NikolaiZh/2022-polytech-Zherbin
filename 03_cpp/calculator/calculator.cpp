#include <iostream>
using namespace std;

int main()
{
double a, b, o;
char c;
while (true)
	{
	cin >> a;
	cin >> c;
	cin >> b;
	    if (c == '+'){
        cout << a << "+" <<  b << "=" << a + b;
	    }
	    if (c == '-'){
      cout << a << "-" <<  b << "=" <<  a - b;
	    }
	    if (c == '*'){
      cout << a << "*" <<  b << "=" <<  a * b;
	    }
	    if (c == '/'){
	        if (b == 0){
      cout << "undefined";
	        }
	        else {
      cout << a << "/" <<  b << "=" <<  a / b;    
      }
	  }
	    o = 1;
	    if (c == '^'){
	        for (double i = b; i > 0; i--) {
	            o = o * a;
	        }  
      cout << a << "^" <<  b << "=" << o;
    }
}
	
}

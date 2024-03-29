#include <iostream>
using namespace std;

class myclass {
    int *p;
public:
    int size;
    double x, y, z;

    myclass(int sz) {
        size = sz;
        p = new int[sz];
        if (!p) exit(1);

        for (int i = 0; i < size; i++) 
            p[i] = 2 * i;
        
    }
      // Copy constructor
    myclass(const myclass &other) {
        size = other.size;
        p = new int[size];
        if (!p) exit(1);
        for (int i = 0; i < size; i++)
            p[i] = other.p[i];
        x = other.x;
        y = other.y;
        z = other.z;
    }


    ~myclass() { 
        delete [] p; 
    }

    int get(int i) { 
        return p[i]; 
    }
};

void show(myclass a) {
    cout << "x= " << a.x << endl;
    cout << "y= " << a.y << endl;
    cout << "z= " << a.z << endl;
    cout << "array: ";
    for (int i = 0; i < a.size; i++) {
        cout << a.get(i) << " ";
    }
    cout << endl;
}

int main() {
    myclass ob1(10);
    show(ob1);
    
    myclass ob2 = ob1;
    show(ob2);
    return 0;
}

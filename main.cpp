#include <iostream>

#include <string.h>
using namespace std;

class Monitor {

private:
    int width;
    int height;
    string name;

public:
    Monitor(int width, int height, string name) {
        this->width = width;
        this->height = height;
        this->name = name;
    }
    ~Monitor(){}

    int getWidth() {return this->width;}
    int getHeight() {return this->height;}
    string getName() {return this->name;}

    void setWidth(int width) {this->width = width;}
    void setHeight(int height) {this->height = height;}
    string setName(string name) {this->name = name;}

};

int main() {
    /*
    char name[256];
	cout<<"Zmiana";
    cin.getline(name, 256);
    cout.write("\"", 1);
    cout.write(name, strlen(name));
    cout.write("\"", 1);
    */

    Monitor monitor(1920, 1080, "Dell");
    cout << monitor.getName();
}

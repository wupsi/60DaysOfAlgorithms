#include <iostream>
using namespace std;

struct queue{

private:
    int start, finish;
    string arr[100000];

public:
    queue(){
        start = 0;
        finish = 0;
    }

    void push(string s){
        arr[finish++] = s;
    }

    void pop(){
        if(!empty())
            start++;
        else 
            cout << "ERROR\n";
    }

    string front(){
        if(!empty())
            return arr[start];
        else
            return "error";
    }

    string back(){
        if(!empty())
            return arr[finish - 1];
        else
            return "error";
    }

    int size(){
        return finish - start;
    }

    bool empty(){
        return finish - start <= 0;
    }

};

int main(){

    queue ten, eleven;
    int classNumber;
    string name;

    while(cin >> classNumber >> name){
        
        if(classNumber == 9) cout << classNumber << " " << name << endl;
        if(classNumber == 10) ten.push(name);
        if(classNumber == 11) eleven.push(name);
    }

    while(!ten.empty()){
        cout << "10 " << ten.front() << endl;
        ten.pop();
    }

    while(!eleven.empty()){
        cout << "11 " << eleven.front() << endl;
        eleven.pop();
    }

}
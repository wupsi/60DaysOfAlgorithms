// Применение public, private

struct stack{

private:
    int pos;
    int arr[100000];

public:
    stack(){
        pos = 0;
    }

    void push(int x){
        arr[pos++] = x;
    }

    void pop(){
        if(!empty())
            pos--;
        else 
            cout << "ERROR\n";
    }

    int top(){
        if(!empty())
            return arr[pos - 1];
        else
            return -9999999;
    }

    bool empty(){
        return pos == 0;
    }

    int size(){
        return pos;
    }
};

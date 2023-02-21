#include <stdio.h>

struct Stack{
    int ara[1005];
    int sz=0;

    void push(int x){
        ara[sz]=x;
        sz++;
    }

    void pop(){
        ara[sz]=0;
        sz--;
    }

    int size(){
        return sz;
    }

    int top(){
        return ara[sz-1];
    }

};

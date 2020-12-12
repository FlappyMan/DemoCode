#include<iostream>
#include"state.h"
using namespace std;


int main()
{
    State* pState = new StateA();
    Context* pContext = new Context(pState);

    pContext->Request();
    pContext->Request();
    pContext->Request();
    pContext->Request();
    pContext->Request();


    return 0;
}


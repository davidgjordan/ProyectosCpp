#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <stdexcept>
# define GET_ABS(n)  (n<0)?-n:n
# define  LESS_THAT =
# define  FLOAT int
# define  END;
# undef true  // desdeinimos true le quitamos el valor
#define true 0
#define FOR_EACH(__i , arr,n)\
        for(int __x=0;__x<n;__x++){\
            auto __i =  arr[__x];\
            __i =  GET_ABS(arr[__x]);
#define END_FOR_EACH }
            
            // GET_ABS(arr[__x])\

using namespace std;
//macros caractesursctica del preprocesador de c mas lineas de codigo se puede?
int getAbs(int n){
    return n<0 ? -n:n;
}

int  main(){

        // int x = getAbs(-15);
        // int x = GET_ABS(-15);
        // cout<<x<<endl;
        // FLOAT Y LESS_THAT 5 END

        // bool z = true;
        // cout<<z<<endl;

        int x []={1,-2,3};
        FOR_EACH(i,x,3)

            cout<<i<<endl;

        END_FOR_EACH
        

    return 0;
}
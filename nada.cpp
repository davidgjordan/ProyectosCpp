#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
        const char* ops[] = {
                "a = 1",
                "b = 25",
                "c = \"Hello world\"",
                "d = a + b",
                "e = d + c",
                "f = 3.141592653",
                "g = true",
                "h = !g",
                "i = treu",
                "variable_1 = e",
                "variable_2 =",
                "= 256",
                "",
                "variable_3=a         ",
                "variable_4 =f",
                "variable_5= c + \" of c++ programmers\"",
                "variable_5 = variable_5 + \" using c++17\"",
                "variable_5 = 4",
                "="
        };

        variable_evaluator ve;

        char msg[256];
        for (auto& op : ops)
        {
                if (ve.add(op, msg))
                {
                        printf("[OK] [%s]\n", op);
                }
                else
                {
                        printf("[ERROR] [%s] Msg: [%s]\n", op, msg);
                }
        }
        puts("********");
        ve.iterate_variables(show_variable);
}

/*

//OUTPUT:
[OK] [a = 1]
[OK] [b = 25]
[OK] [c = "Hello world"]
[OK] [d = a + b]
[ERROR] [e = d + c] Msg: [Cannot apply operator+ on variables of different type]
[OK] [f = 3.141592653]
[OK] [g = true]
[OK] [h = !g]
[ERROR] [i = treu] Msg: [Unknown variable 'treu']
[ERROR] [variable_1 = e] Msg: [Unknown variable 'e']
[ERROR] [variable_2 =] Msg: [Syntax error]
[ERROR] [= 256] Msg: [Syntax error]
[ERROR] [] Msg: [Unsupported empty expression]
[OK] [variable_3=a      ]
[OK] [variable_4 =f]
[OK] [variable_5= c + " of c++ programmers"]
[OK] [variable_5 = variable_5 + " using c++17"]
[ERROR] [variable_5 = 4] Msg: [variable_5 defined previously as 'string']
[ERROR] [=] Msg: [Syntax error]
********
a: [1]
b: [25]
c: [Hello world]
d: [26]
f: [3.141592653]
g: [true]
h: [false]
variable_3: [1]
variable_4: [3.141592653]
variable_5: [Hello world of c++ programmers using c++17]

*/
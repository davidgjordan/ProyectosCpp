#include <iostream>
#include <PythonByHand.h>
#include <json.hpp> 

using Json = nlohmann::json;
using namespace std;


int main(){
    // create an empty structure (null)
json j;

// add a number that is stored as double (note the implicit conversion of j to an object)
j["pi"] = 3.141;


    cout<<"hello"<<endl;
    // cout<<js.dump();<<endl;


    return 0;
}
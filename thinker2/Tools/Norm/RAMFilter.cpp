# include <stdio.h>
# include <fstream>
# include "json.hpp"
# include <string.h>

# define BYTE_DIRECTION 56
# define NUMBER_DIRECTION 4.00
# define DIRECTION_UP 0.00
# define DIRECTION_RIGHT 1.00
# define DIRECTION_DOWN 2.00
# define DIRECTION_LEFT 3.00
# define FIRST_BYTE_FILTER 6
# define FINAL_BYTE_FILTER 17


using namespace std;

using json = nlohmann::json;

void RamFilter()
{
    string fileName;
    printf("Intro the name of the file.json: \n");
    getline(cin,fileName);

    std::ifstream intro(fileName);
    json fileRead;
    intro >> fileRead;

    int numberSteps=fileRead["steps"].size();           
    
    string fileNameOut;
    printf("Intro the name of the new file.json: \n");
    getline(cin,fileNameOut);
    ofstream out(fileNameOut);
    
    out <<"{\n\"intro\":\n[\n";

    for (float k=0.00;k<NUMBER_DIRECTION;++k)
    {   
        
        for (int step = 1; step <= numberSteps; step++)
        {
            if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==k)
            {
                out <<"[";
            }

            for (int byte = FIRST_BYTE_FILTER; byte < FINAL_BYTE_FILTER; ++byte)
            {
                if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==k)
                {
                    if(byte!=11)
                    {
                        out << fileRead["steps"][to_string(step)][byte]; 
                                                
                        if(byte!=FINAL_BYTE_FILTER-1)
                        {
                            out << ",";
                        }else
                        {
                            out << "],\n";
                        }
                    }
                }
            }
        }
        out<<"\n";
    }

    out << "],\n\n";

    out <<"\"out\":\n[\n";
    
    for (float k=0.00;k<NUMBER_DIRECTION;++k)
    {   
        int index=0;
        for (int step = 1; step <= numberSteps; step++)
        {
            if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==k)
            { 
                if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==DIRECTION_UP) out<<"[1,0,0,0],";
                if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==DIRECTION_RIGHT) out<<"[0,1,0,0],";
                if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==DIRECTION_DOWN) out<<"[0,0,1,0],";
                if (fileRead["steps"][to_string(step)][BYTE_DIRECTION]==DIRECTION_LEFT) out<<"[0,0,0,1],";
            
                if (index==4) {out<<"\n"; index=0;}
                else {index++;}  
            }
        }
        out <<"\n";
    }
    out <<"]\n}";

   out.close(); 
}

int main() 
{
    
   RamFilter();

   return 0;

}

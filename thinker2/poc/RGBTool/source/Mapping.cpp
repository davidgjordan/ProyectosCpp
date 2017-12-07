#include <Mapping.h>

#pragma region Functions
Mapping::Mapping(Json& jsonRgb)
{
    _jsonRgb = &jsonRgb;
    LoadJson();
}

void Mapping::LoadJson()
{
    _pathX = (*_jsonRgb)[PATH_X].get<vector<int>>();
    _pathY = (*_jsonRgb)[PATH_Y].get<vector<int>>();
}

string Mapping::ReplaceExceptions(string mapArray)
{
    for (auto it = (*_jsonRgb)[REPLACE_EXCEPTION].begin(); it != (*_jsonRgb)[REPLACE_EXCEPTION].end(); ++it)
    {
          string x = it.key();
          string y = it.value();
          regex factorMatch (x);
          mapArray = regex_replace (mapArray,factorMatch,y);
    }

    return mapArray;
}

void Mapping::SaveStringExceptions()
{
  int sizeReplaceExc;
  cout << "Enter the quantity of Patterns to Replace: "<<endl;
  cin >> sizeReplaceExc;
  string input;
  string inputChar;
  for(int i = 0; i < sizeReplaceExc; i++) 
  {
    cout << "Pattern Exception :";
    cin >> input;
    cout << "Caracter Replace";
    cin >> inputChar;
    _exceptionReplace[input] = inputChar;
  }
  (*_jsonRgb)[REPLACE_EXCEPTION] = _exceptionReplace;
}

void Mapping::SavePathX()
{
  
  int sizeOfVectorX;
  int input;
  vector<int> x;
  cout << "Enter the quantity of the Path's rows: "<<endl;
  cin >> sizeOfVectorX;
  while(!cin)
  {
        cout << "Not a valid value!!! \n Enter the quantity of the Path's rows: ";
        cin.clear();
        cin.ignore();
        cin >> sizeOfVectorX;
  }      
  
  for(int i = 0; i < sizeOfVectorX; i++) 
  {
    cout << "Row: ";
    cin >> input;

    while(!cin)
    {
        cout << "Not a valid value!!! \n Row: ";
        cin.clear();
        cin.ignore();
        cin >> input;
    }    
    x.push_back(input);
  }
  _pathX = x;
  (*_jsonRgb)[PATH_X] = _pathX;
}


void Mapping::SavePathY()
{
  
  int sizeOfVectorY;
  int input;
  vector<int> y;
  cout << "Enter the quantity of the Path's columns: "<<endl;
  cin >> sizeOfVectorY;
  while(!cin)
  {
        
        cout << "Not a valid value!!! \n Enter the quantity of the Path's columns: ";
        cin.clear();
        cin.ignore();
        cin >> sizeOfVectorY;
  }
    
  for(int i = 0; i < sizeOfVectorY; i++) 
  {
    cout << "Column :";
    cin >> input;
    while(!cin)
    {
        cout << "Not a valid value!!!  \n Column :";
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    
    y.push_back(input);
  }
  _pathY = y;
  (*_jsonRgb)[PATH_Y] = _pathY;
}

void Mapping::ToHtml()
{
    FILE* html = fopen("matrixGenerated.html","w");
    fprintf(html, "%s", "<html>\n<body>\n<table>");
    for(int y = 0; y < _pathY.size(); y++)
    {
        fprintf(html, "%s", "<tr>\n");
        for(int x = 0; x<_pathX.size();x++)
        {
            switch(_array2D[y][x])
            {
                case MAP_CHAR_WALL: fprintf(html, "%s \n", "<td style='background-color:red' width='10px' height='10px'></td>");
                    break;
                case MAP_CHAR_WAY: fprintf(html, "%s \n", "<td style='background-color:blue' width='10px' height='10px'></td>");
                    break;
                case MAP_CHAR_PILL: fprintf(html, "%s \n", "<td style='background-color:white' width='10px' height='10px'></td>");
                    break;
                default: fprintf(html, "%s \n", "<td style='background-color:black' width='10px' height='10px'></td>");
            }
        }
        fprintf(html, "%s \n", "</tr>");
    }
    fprintf(html, "%s", "</table>\n</body>\n</html>");
    fclose(html); 
}

vector<vector<char>> Mapping::GenerateMatrix(string mapArray)
{
    int xCount = 0; 
    int yCount = 0;
    int lineCount = 0;
    int cont = 1;
    SetArraySize();
    mapArray = ReplaceExceptions(mapArray);

    istringstream ss(mapArray);
    string row;

    while(getline(ss, row)) {
        if (find(_pathY.begin(), _pathY.end(), lineCount) != _pathY.end() )
        {
            for(int x : _pathX)
            {
                _array2D[yCount][xCount] = row[x];
                xCount++;
            }
            xCount = 0;
            yCount++;
        }      
        lineCount++;
    }

    return _array2D;
}


int Mapping::ValidateArray(int array[],int sizeMax,int sizeArray)
{
     int result = 1;
     for(int i = 0; i < sizeArray; i++)
     {
          if(sizeMax <= array[i])
          {
               result = -1;
               break;
          }
     }
     return result;
}

int Mapping::Compare(int array[],int size,int value)
{
    int result = 0;
    for(int i = 0;i < size; i++)
    {
         if(array[i] == value)
         {
              result = 1;
              break;
         }

    }
    return result;
   
}

Mapping::~Mapping()
{
    //dtor
}


string Mapping::CharRepresentation(string render)
{   
    string auxRender;
    auxRender += render;
    string map;
    int cRGB = 1;
    int axisY = 0;
    int axisX = 0;
    int red;
    int green;
    int blue;
    char caracter;

    char* token;
    token = strtok((char*)(auxRender).c_str()," ,[]");
    while(token!=NULL) 
    {
        if(axisX==(int)(*_jsonRgb)[WIDTH])
        {
            axisY++;
            axisX = 0;
            map += '\n';
        }
        switch(cRGB)
        {
            case 1:
                red = atoi(token);
                cRGB++;
                break;
            case 2:
                green = atoi(token);
                cRGB++;
                break;
            case 3:
                blue = atoi(token);
                cRGB = 1;
                axisX++;
                caracter = GetCharRgb(blue, green, red);
                map += caracter;
                break;
        }
        token = strtok(NULL," ,[]");
    }
    return map;
}


#pragma endregion Functions


#pragma region Mutators

vector<vector<char>> Mapping::GetMatrix()
{
    return _array2D;
}

char Mapping::GetCharRgb(const int blue, const int green, const int red)
{
    char caracter;

    vector<int> rgbSpace = (*_jsonRgb)[COLOR_SPACE].get<vector<int>>();
    vector<int> rgbWall = (*_jsonRgb)[COLOR_WALL].get<vector<int>>();
    vector<int> rgbWay = (*_jsonRgb)[COLOR_WAY].get<vector<int>>();
    vector<int> rgbPacmanScore = (*_jsonRgb)[COLOR_PACMAN_SCORE].get<vector<int>>();
    vector<int> rgbPacman = (*_jsonRgb)[COLOR_PACMAN].get<vector<int>>();
    vector<int> rgbScore = (*_jsonRgb)[COLOR_SCORE].get<vector<int>>();
    vector<int> rgbFruit = (*_jsonRgb)[COLOR_FRUIT].get<vector<int>>();
    vector<int> rgbGhost1 = (*_jsonRgb)[COLOR_GHOST1].get<vector<int>>();
    vector<int> rgbGhost2 = (*_jsonRgb)[COLOR_GHOST2].get<vector<int>>();
    vector<int> rgbGhost3 = (*_jsonRgb)[COLOR_GHOST3].get<vector<int>>();
    vector<int> rgbGhost4 = (*_jsonRgb)[COLOR_GHOST4].get<vector<int>>();
    vector<int> rgbGhostEat = (*_jsonRgb)[COLOR_GHOST_EAT].get<vector<int>>();
    vector<int> rgbGhostTimeOut = (*_jsonRgb)[COLOR_GHOST_TIME_OUT].get<vector<int>>();

    if (red == rgbSpace[COLOR_RED] && green == rgbSpace[COLOR_GREEN] && blue == rgbSpace[COLOR_BLUE]) 
    {
        caracter = MAP_CHAR_SPACE;
    }
    else if (red == rgbWall[COLOR_RED] && green == rgbWall[COLOR_GREEN] && blue == rgbWall[COLOR_BLUE])  
    {        
        caracter = MAP_CHAR_WALL;
    }
    else if (red == rgbWay[COLOR_RED] && green == rgbWay[COLOR_GREEN] && blue == rgbWay[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_WAY;
    }
    else if (red == rgbPacmanScore[COLOR_RED] && green == rgbPacmanScore[COLOR_GREEN] && blue == rgbPacmanScore[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_PACMAN_SCORE;
    }
    else if (red == rgbPacman[COLOR_RED] && green == rgbPacman[COLOR_GREEN] && blue == rgbPacman[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_PACMAN;
    }
    else if (red == rgbScore[COLOR_RED] && green == rgbScore[COLOR_GREEN] && blue == rgbScore[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_SCORE;  
    }
    else if (red == rgbFruit[COLOR_RED] && green == rgbFruit[COLOR_GREEN] && blue == rgbFruit[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_FRUIT;  
    }
    else if (red == rgbGhost1[COLOR_RED] && green == rgbGhost1[COLOR_GREEN] && blue == rgbGhost1[COLOR_BLUE]) 
    {
        caracter = MAP_CHAR_GHOST1;
    }
    else if (red == rgbGhost2[COLOR_RED] && green == rgbGhost2[COLOR_GREEN] && blue == rgbGhost2[COLOR_BLUE]) 
    {
        caracter = MAP_CHAR_GHOST2;
    }
    else if (red == rgbGhost3[COLOR_RED] && green == rgbGhost3[COLOR_GREEN] && blue == rgbGhost3[COLOR_BLUE]) 
    {
        caracter = MAP_CHAR_GHOST3;
    }
    else if (red == rgbGhost4[COLOR_RED] && green == rgbGhost4[COLOR_GREEN] && blue == rgbGhost4[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_GHOST4;
    }
    else if (red == rgbGhostEat[COLOR_RED] && green == rgbGhostEat[COLOR_GREEN] && blue == rgbGhostEat[COLOR_BLUE])  
    {  
        caracter = MAP_CHAR_GHOST_EAT;
    }
    else if (red == rgbGhostTimeOut[COLOR_RED] && green == rgbGhostTimeOut[COLOR_GREEN] && blue == rgbGhostTimeOut[COLOR_BLUE])  
    {
        caracter = MAP_CHAR_GHOST_TIME_OUT_EAT;
    }
    else 
    {
        caracter = MAP_CHAR_DEFAULT;
    }

    return caracter;
}

vector<int> Mapping::GetPathX()
{
  return _pathX;
}

vector<int> Mapping::GetPathY()
{
  return _pathY;
}

void Mapping::SetArraySize()
{
    _array2D.resize(_pathY.size());
    for (int i = 0; i < _pathY.size(); ++i)
      _array2D[i].resize(_pathX.size());
}
  
vector<vector<char>> Mapping::SetObjectMatrix(char object, int x, int y)
{
    _array2D[x][y] = object;

    return _array2D;
}

#pragma endregion Mutators
#include <Evaluate.h>

Evaluate::Evaluate(Json jsonRgb)
{
    _jsonRgb = jsonRgb;
}

Evaluate::~Evaluate()
{

}

map<char, double> Evaluate::GetObjectPosition (char objectMatch, string auxRenderRGB)
{
    int count = 0;
    int xMax = 0, yMax = 0;

    int xResize = 0, yResize = 0;
    
    int xMaxFor = 0;
    int yMaxFor = 0;

    int posMinX = 0, poxMaxX = 0;
    int posMinY = 0, posMaxY = 0;
    int flagFirst = 0;

    int posCentralX = 0;
    int posCentralY = 0;

    int divisionX = 0, divisionY = 0;

    map<char,double> position;

    xResize = (int)_jsonRgb[RESIZE_X];
    yResize = (int)_jsonRgb[RESIZE_Y];

    xMaxFor = (int)_jsonRgb[MAP_WIDTH];
    yMaxFor = (int)_jsonRgb[MAP_HEIGTH];

    xMax = xMaxFor / xResize;
    yMax = yMaxFor / yResize;
    
    vector<int> pathX = {};
    vector<int> pathY = {};

    pathX = (_jsonRgb)[PATH_X].get<vector<int>>();
    pathY = (_jsonRgb)[PATH_Y].get<vector<int>>();
    
    for(int y = 0; y < yMaxFor; y++)
    {
        for(int x = 0; x <= xMaxFor; x++)
        {
            if (auxRenderRGB[count] == objectMatch)
            {
                if (flagFirst == 0)
                {
                    poxMaxX = x;
                    posMinX = x;
                    posMaxY = y;
                    posMinY = y;
                    
                    flagFirst = 1;
                }
                else
                {
                    if (x > poxMaxX)
                    {
                        poxMaxX = x;
                    }
                    if (y > posMaxY)
                    {
                        posMaxY = y;
                    }
                    if (x < posMinX)
                    {
                        posMinX = x;
                    }
                    if (y < posMinY)
                    {
                        posMinY = y;
                    }
                }
            }
            count++;
        }
        
    }
        
    posCentralX = (posMinX + poxMaxX + (poxMaxX - posMinX) + 2) / (2 * xResize);
    posCentralY = (posMinY + posMaxY + (posMaxY - posMinY) + 2) / (2 * yResize);

    if (pathX.size() > 0)
    {
        divisionX = xMax;
        position['X'] = round(posCentralX * pathX.size() / (divisionX*1.00));
    }

    if (pathY.size() > 0)
    {
        divisionY = yMax;
        position['Y'] = round(posCentralY * pathY.size() / (divisionY*1.00));
    }
    return position;
}
map<string, double> Evaluate::GetObjectAllPosition (string objectMatch, string auxRenderRGB)
{
    int count = 0;
    int xMax = 0, yMax = 0;

    int xResize = 0, yResize = 0;
    
    int xMaxFor = 0;
    int yMaxFor = 0;

    int posMinX = 0, poxMaxX = 0;
    int posMinY = 0, posMaxY = 0;

    int posCentralX = 0;
    int posCentralY = 0;

    int divisionX = 0, divisionY = 0;

    int lenString;

    map<string,double> position;

    lenString = strlen(objectMatch.c_str());

    double posicionesChar[lenString * INDENTATION];

    for (int i = 0; i < lenString * INDENTATION; i = i + 2)
    {
        posicionesChar[i] = DEFAULT_MAX;
        posicionesChar[i+MOVE_ONE_POSITION] = DEFAULT_MIN;
    }

    xResize = (int)_jsonRgb[RESIZE_X];
    yResize = (int)_jsonRgb[RESIZE_Y];

    xMaxFor = (int)_jsonRgb[MAP_WIDTH];
    yMaxFor = (int)_jsonRgb[MAP_HEIGTH];

    xMax = xMaxFor / xResize;
    yMax = yMaxFor / yResize;
    
    vector<int> pathX = {};
    vector<int> pathY = {};

    pathX = (_jsonRgb)[PATH_X].get<vector<int>>();
    pathY = (_jsonRgb)[PATH_Y].get<vector<int>>();
    
    for(int y = 0; y < yMaxFor; y++)
    {
        for(int x = 0; x <= xMaxFor; x++)
        {
            for(int q = 0; q < lenString; q++)
            {
                if (auxRenderRGB[count] == objectMatch[q])
                {
                    if (x > posicionesChar[q*INDENTATION])
                    {
                        posicionesChar[q*INDENTATION] = x;
                    }
                    if (x < posicionesChar[q*INDENTATION+MOVE_ONE_POSITION])
                    {
                        posicionesChar[q*INDENTATION+MOVE_ONE_POSITION] = x;
                    }
                    if (y > posicionesChar[q*INDENTATION+MOVE_TWO_POSITION])
                    {
                        posicionesChar[q*INDENTATION+MOVE_TWO_POSITION] = y;
                    }
                    if (y < posicionesChar[q*INDENTATION+MOVE_THREE_POSITION])
                    {
                        posicionesChar[q*INDENTATION+MOVE_THREE_POSITION] = y;
                    }
                }
            }
            count++;
        }
    }

    for (int i = 0; i < lenString; i++)
    {
        if (posicionesChar[i*INDENTATION+MOVE_ONE_POSITION] == DEFAULT_MIN && posicionesChar[i*INDENTATION+MOVE_THREE_POSITION] == DEFAULT_MIN)
        {
            posicionesChar[i*INDENTATION+MOVE_ONE_POSITION] = 0;
            posicionesChar[i*INDENTATION+MOVE_THREE_POSITION] = 0;
        }

        posCentralX = (posicionesChar[i*INDENTATION] + posicionesChar[i*INDENTATION+MOVE_ONE_POSITION] + (posicionesChar[i*INDENTATION] - posicionesChar[i*INDENTATION+MOVE_ONE_POSITION]) + 2) / (2 * xResize);
        posCentralY = (posicionesChar[i*INDENTATION+MOVE_TWO_POSITION] + posicionesChar[i*INDENTATION+MOVE_THREE_POSITION] + (posicionesChar[i*INDENTATION+MOVE_TWO_POSITION] - posicionesChar[i*INDENTATION+MOVE_THREE_POSITION]) + 2) / (2 * yResize);
    
        if (pathX.size() > 0)
        {
            string nameX;

            nameX = objectMatch[i];
            nameX = nameX + DEFAULT_POSITION_X;
            
            divisionX = xMax;
            position[nameX.c_str()] = round(posCentralX * pathX.size() / (divisionX*1.00));
        }

        if (pathY.size() > 0)
        {
            string nameY;

            nameY = objectMatch[i];
            nameY = nameY + DEFAULT_POSITION_Y;

            divisionY = yMax;
            position[nameY.c_str()] = round(posCentralY * pathY.size() / (divisionY*1.00));
        }
    }
    return position;
}
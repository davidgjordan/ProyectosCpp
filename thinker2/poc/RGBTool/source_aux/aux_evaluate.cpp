#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <map>

#include "json.hpp"

using JSON = nlohmann::json;
using namespace std;

#define NAME_JSON "rgb.json"
#define WIDTH "Width"
#define HEIGHT "Height"
#define RESIZE_X "Resize_x"
#define RESIZE_Y "Resize_y"


void lectura_json(int& width, int& height, int& resize_x, int& resize_y);
std::map<char,int> find(char pat, int x_max, int y_max, int resize_x, int resize_y);

int main() 
{
	int resize_x= 0, resize_y = 0;
	int MAXX = 0, MAXY= 0;
	
	std::map<char,int> position;

	lectura_json(MAXX, MAXY, resize_x, resize_y);
	
	puts("\nPOSICION PACMAN: ");
    position = find('P',MAXX, MAXY, resize_x, resize_y);
	/*puts("\n\nPOSICION FANTASMA 1: ");
	find('1',MAXX, MAXY, resize_x, resize_y);
	puts("\n\nPOSICION FANTASMA 2: ");
	find('2',MAXX, MAXY, resize_x, resize_y);
	puts("\n\nPOSICION FANTASMA 3: ");
	find('3',MAXX, MAXY, resize_x, resize_y);
	puts("\n\nPOSICION FANTASMA 4: ");
	find('4',MAXX, MAXY, resize_x, resize_y);
	puts("\n\n");*/

    printf("\n[%d,", position['X']);
    printf("%d]\n\n", position['Y']);
    return 0;
}

std::map<char,int> find(char pat, int x_max, int y_max, int x_resize, int y_resize)
{
	std::map<char,int> position;

	int pos_min_x = 0, pos_max_x = 0;
	int pos_min_y = 0, pos_max_y = 0;
	int pos_central_x = 0, pos_central_y = 0;
	int flag_first = 0;
	FILE *fp;
 
	char scenary[x_max][y_max] = {};
	
	char character;
	
    fp = fopen("matrix.txt","r");
    if(fp==NULL)
	{
		printf("error");
	}
    else
	{
		for(int y=0; y<y_max; y++)
		{
			for(int x=0; x<x_max; x++)
			{
				character = fgetc(fp);
				scenary[x][y] = character;
				if (scenary[x][y] == pat)
				{
					if (flag_first == 0)
					{
						pos_max_x = x;
						pos_min_x = x;
						pos_max_y = y;
						pos_min_y = y;
						
						flag_first = 1;
					}
					else
					{
						if (x > pos_max_x)
						{
							pos_max_x = x;
						}
						if (y > pos_max_y)
						{
							pos_max_y = y;
						}
						if (x < pos_min_x)
						{
							pos_min_x = x;
						}
						if (y < pos_min_y)
						{
							pos_min_y = y;
						}
					}
				}
			}
		}
		
		printf("\n Posicion Minima: [%d , %d]", (pos_min_x+1/x_resize), (pos_min_y+1/y_resize));
		printf("\n Posicion Maxima: [%d , %d]", (pos_max_x+1/x_resize), (pos_max_y+1/y_resize));

		pos_central_x = (pos_min_x + pos_max_x + 2) / 2;
		pos_central_y = (pos_min_y + pos_max_y + 2) / 2;

		printf("\n Posicion Central X: [%d]", pos_central_x);
		printf("\n Posicion Central Y: [%d] \n\n", pos_central_y);

		position['X'] = pos_central_x;
		position['Y'] = pos_central_y;

		return position;


	}
    fclose(fp);
}

void lectura_json(int& width, int& height, int& resize_x, int& resize_y)
{
    JSON json;
    ifstream archivo_json(NAME_JSON);
    
    if (archivo_json.peek() == EOF)
    {
        printf("THIS FILE IS EMPTY <%s>\n", NAME_JSON);
    }    
    else
    {
        if(archivo_json.good())
		{
			archivo_json >> json;

			if(json.empty())
			{
				printf("THIS FILE <%s> IS EMPTY!\n", NAME_JSON);
			}
			else
			{
				width = json[WIDTH];
				height = json[HEIGHT];
				resize_x = json[RESIZE_X];
				resize_y = json[RESIZE_Y];
			}
		}
		else
		{
			printf("SOME THING ABOUT THIS FILE <%s> IS WRONG!\n", NAME_JSON);
		}
    }
}
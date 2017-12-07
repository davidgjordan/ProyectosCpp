
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <iterator>
#include <string>

#include "json.hpp"

using JSON = nlohmann::json;
using namespace std;

#define NOMBRE_JSON "resize.json"
#define RESIZE_X "resize_x"
#define RESIZE_Y "resize_y"

typedef struct bmpFileHeader
{
  /* 2 bytes de identificación */
  uint32_t size;        /* Tamaño del archivo */
  uint16_t resv1;       /* Reservado */
  uint16_t resv2;       /* Reservado */
  uint32_t offset;      /* Offset hasta hasta los datos de imagen */
} bmpFileHeader;

typedef struct bmpInfoHeader
{
  uint32_t headersize;      /* Tamaño de la cabecera */
  uint32_t width;       /* Ancho */
  uint32_t height;      /* Alto */
  uint16_t planes;          /* Planos de color (Siempre 1) */
  uint16_t bpp;             /* bits por pixel */
  uint32_t compress;        /* compresión */
  uint32_t imgsize;     /* tamaño de los datos de imagen */
  uint32_t bpmx;        /* Resolución X en bits por metro */
  uint32_t bpmy;        /* Resolución Y en bits por metro */
  uint32_t colors;      /* colors used en la paleta */
  uint32_t imxtcolors;      /* Colores importantes. 0 si son todos */
} bmpInfoHeader;

unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader);
void TextDisplayResize(bmpInfoHeader *info, unsigned char *img, const int, const int);
void TextDisplayOrigen(bmpInfoHeader *info, unsigned char *img);
void to_Image();
void convert_to_2dArray();
char get_char_rgb(const int b, const int g, const int r);
void lectura_json(int& resize_x, int& resize_y);
    
int main()
{
    int resize_x = 0;
    int resize_y = 0;
    
    bmpInfoHeader info;
    unsigned char *img;
    
    img=LoadBMP((char*)"pacman2.bmp", &info);
    lectura_json(resize_x, resize_y);
    TextDisplayResize(&info, img, resize_x, resize_y);
    TextDisplayOrigen(&info, img);
    
    return 0;
}

void to_Image()
{
    ifstream myReadFile;
    myReadFile.open("matrix3.txt");
    FILE* file= fopen("matrix4.html","w");
    fprintf(file, "%s", "<html><body><table>");
    string output="";
    while (!myReadFile.eof()) 
    {
        getline(myReadFile,output);
        fprintf(file, "%s", "<tr>");
        for(int i = 0; i<output.length();i++)
        {
            switch(output.at(i))
            {
				case 'M': fprintf(file, "%s", "<td style='background-color:red' width='10px' height='10px'></td>");
                    break;
				case 'L': fprintf(file, "%s", "<td style='background-color:blue' width='10px' height='10px'></td>");
                    break;
				case 'U': fprintf(file, "%s", "<td style='background-color:white' width='10px' height='10px'></td>");
                    break;
            }
        }
        fprintf(file, "%s", "</tr>");
    }
    fprintf(file, "%s", "</table></body></html>"); 
    myReadFile.close();
    fclose(file); 
}

void convert_to_2dArray()
{
	ifstream myReadFile;
    myReadFile.open("matrix2.txt");
    FILE* file= fopen("matrix3.txt","w");

    string output;
    int count = 1; //2
    int rowcount = 1;
    string aux= "";
    while (!myReadFile.eof()) 
    {
    	getline(myReadFile,output);         
        if( count == rowcount)
        {
			aux = output;

			regex e0 ("C");
			regex e1 ("MLML");
			regex e2 ("1");
			regex e3 ("2");
			regex e4 ("3");
			regex e5 ("4");
			regex e6 ("P");
			
		

			aux = std::regex_replace (aux,e0,"L");
			aux = std::regex_replace (aux,e1,"MLUL");
			aux = std::regex_replace (aux,e2,"L");
			aux = std::regex_replace (aux,e3,"L");
			aux = std::regex_replace (aux,e4,"L");
			aux = std::regex_replace (aux,e5,"L");
			aux = std::regex_replace (aux,e6,"L");

			if(aux.length()>=10)
			{
				if(aux.at(10)=='C')
				{
					aux.erase (10,1); 
				}
			}

			fprintf(file, "%s", aux.c_str());
			fprintf(file, "%s","\n");
			count = count + 4; //3
        }

        rowcount = rowcount + 1;
    }
    myReadFile.close();
    fclose(file);
    to_Image();
}
char get_char_rgb(const int b, const int g, const int r)
{
	char caracter;
	if (b == 0 && g == 0 && r == 0)
	{
		caracter = ' ';
	}
	else if (b == 111 && g == 111 && r == 228)
	{
		caracter = 'M';
	}
	else if (b == 136 && g == 28 && r == 0)
	{
		caracter = 'C';
	}
	else if (b == 53 && g == 187 && r == 187)
	{
		caracter = 'V';
	}
	else if (b == 74 && g == 164 && r == 210) //P
	{
		caracter = 'P';
	}
	else if (b == 61 && g == 144 && r == 195)
	{
		caracter = 'S';  
	}
	else if (b == 50 && g == 50 && r == 184)
	{
		caracter = 'O';  
	}
	else if(b == 48 && g == 122 && r == 180) // 1
	{
		caracter = '1';
	}
	else if(b == 72 && g == 72 && r == 200) // 2
	{
		caracter = '2';
	}
	else if(b == 153 && g == 184 && r == 84) // 3
	{
		caracter = '3';
	}
	else 
	{  
		caracter = '4'; // 4
	}

	return caracter;
}

void TextDisplayResize(bmpInfoHeader *info, unsigned char *img, const int reduccionX, const int reduccionY)
{
	FILE* file= fopen("matrix2.txt","w");
	int x, y;
	int r,g,b;
	char caracter;
	
	/* Reducimos la resolución vertical y horizontal para que la imagen entre en pantalla */
	//static const int reduccionX=x, reduccionY=y;
	  
	/* Dibujamos la imagen */
	if(file==NULL)
		exit(-1);
	
	for (y=210; y>39; y-=reduccionY)
	{
		for (x=0; x<info->width; x+=reduccionX)
		{
			b=(img[3*(x+y*info->width)]);
			g=(img[3*(x+y*info->width)+1]);
			r=(img[3*(x+y*info->width)+2]);

			caracter = get_char_rgb(b, g, r);
			fprintf(file, "%c", caracter); 
		}
		fprintf(file, "%s","\n");	  
	}
	fclose(file);

	convert_to_2dArray();
}

void TextDisplayOrigen(bmpInfoHeader *info, unsigned char *img)
{
	FILE* file= fopen("matrix.txt","w");
	int x, y;
	int r,g,b;
	char caracter;
	
	/* Reducimos la resolución vertical y horizontal para que la imagen entre en pantalla */
	//static const int reduccionX=x, reduccionY=y;
	  
	/* Dibujamos la imagen */
	if(file==NULL)
		exit(-1);
	
	for (y=210; y>0; y = y - 1)
	{
		for (x=0; x<info->width; x = x + 1)
		{
			b=(img[3*(x+y*info->width)]);
			g=(img[3*(x+y*info->width)+1]);
			r=(img[3*(x+y*info->width)+2]);

			caracter = get_char_rgb(b, g, r);
			fprintf(file, "%c", caracter); 
		}
		fprintf(file, "%s","\n");	  
	}
	fclose(file);

	convert_to_2dArray();
}

unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader)
{

	FILE *f;
	bmpFileHeader header;     /* cabecera */
	unsigned char *imgdata;   /* datos de imagen */
	uint16_t type;        /* 2 bytes identificativos */

	f=fopen (filename, "r");
	if (!f)
		return NULL;        /* Si no podemos leer, no hay imagen*/

	/* Leemos los dos primeros bytes */
	fread(&type, sizeof(uint16_t), 1, f);

	/* Leemos la cabecera de fichero completa */
	fread(&header, sizeof(bmpFileHeader), 1, f);

	/* Leemos la cabecera de información completa */
	fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);

	/* Reservamos memoria para la imagen, ¿cuánta? Tanto como indique imgsize */
	imgdata=(unsigned char*)malloc(bInfoHeader->imgsize);

	/* Nos situamos en el sitio donde empiezan los datos de imagen,
	nos lo indica el offset de la cabecera de fichero*/
	fseek(f, header.offset, SEEK_SET);

	/* Leemos los datos de imagen, tantos bytes como imgsize */
	fread(imgdata, bInfoHeader->imgsize,1, f);

	/* Cerramos */
	fclose(f);

	/* Devolvemos la imagen */
	return imgdata;
}
void lectura_json(int& resize_x, int& resize_y)
{
    JSON json;
    ifstream archivo_json(NOMBRE_JSON);
    
    if (archivo_json.peek() == EOF)
    {
        printf("THIS FILE IS EMPTY <%s>\n", NOMBRE_JSON);
    }    
    else
    {
        if(archivo_json.good())
		{
			archivo_json >> json;

			if(json.empty())
			{
				printf("THIS FILE <%s> IS EMPTY!\n", NOMBRE_JSON);
			}
			else
			{
				resize_x = json[RESIZE_X];
				resize_y = json[RESIZE_Y];
			}
		}
		else
		{
			printf("SOME THING ABOUT THIS FILE <%s> IS WRONG!\n", NOMBRE_JSON);
		}
    }
}
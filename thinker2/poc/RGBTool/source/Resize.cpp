#include <Resize.h>

Resize::Resize(Json& jsonRgb)
{
    _jsonRgb = &jsonRgb;
    LoadJsonRgb();
}

Resize::~Resize()
{}

void Resize::SetImageMap(string imageMap)
{
    _imageMap = imageMap;
}

void Resize::LoadJsonRgb()
{
    _resizeX = (*_jsonRgb)[RESIZE_X];
    _resizeY = (*_jsonRgb)[RESIZE_Y];
    _width = (*_jsonRgb)[WIDTH];
    _height = (*_jsonRgb)[HEIGTH];
    _mapWidth = (*_jsonRgb)[MAP_WIDTH];
    _mapHeight = (*_jsonRgb)[MAP_HEIGTH];
}

void Resize::UpdateJsonRGB()
{
    (*_jsonRgb)[RESIZE_X] = _resizeX;
    (*_jsonRgb)[RESIZE_Y] = _resizeY;
    (*_jsonRgb)[MAP_WIDTH] = _mapWidth;
    (*_jsonRgb)[MAP_HEIGTH] = _mapHeight;
}

string Resize::ResizeImageMap(int resizeX, int resizeY)
{
    SetResizeX(resizeX);
    SetResizeY(resizeY); 
    return ResizeImageMap();
}

string Resize::ResizeImageMap()
{   

    int axisX = 0;
    int axisY = 0;
    string mapImageResize = "";
    string lineMapImage;
    std::istringstream buffer_map_image(_imageMap);

    while(std::getline(buffer_map_image, lineMapImage, '\n')) 
    {
        if(axisY < _height)
        {
            if(axisY % _resizeY == 0)
            {
                for (axisX = 0; axisX < _width; axisX++)
                {
                    if(axisX % _resizeX == 0)
                    {
                        mapImageResize = mapImageResize + lineMapImage[axisX];
                    }
                }
                mapImageResize.append("\n");
            }
            axisY++;
        }
        else
        {
            break;
        }
    }
    _resizeImage = mapImageResize;
    return mapImageResize;
}

string Resize::CropImageMap(int mapWidth, int mapHeight)
{
    string cropImage = "";
    if(mapWidth < _width && mapHeight < _height)
    {
        SetMapWidth(mapWidth);
        SetMapHeigth(mapHeight);
        CropImageMap();
    }
    return cropImage;
}

string Resize::CropImageMap()
{
    string cropImage = "";
    string lineResizeImage;
    int axisY = 0;
    std::istringstream buffer_resize_image(_resizeImage);
    while(std::getline(buffer_resize_image,lineResizeImage, '\n'))
    {
        if(axisY  < _mapHeight)
        {
            cropImage = cropImage + lineResizeImage.substr(0,_mapWidth) + "\n";
        }
        axisY++;
    }
    return cropImage;
}

void Resize::ShowResizeImage()
{
    string mapImageResize;
    int axisY = 0;
    
    int len_x = _mapWidth/_resizeX;
    string lineMapImage;
    ResizeImageMap();
    std::istringstream buffer_map_image(_resizeImage);
    while(std::getline(buffer_map_image, lineMapImage, '\n')) 
    {
        mapImageResize = mapImageResize + lineMapImage;
        mapImageResize = mapImageResize + " " + to_string(axisY);
        mapImageResize.append("\n");
        axisY++;
    }

    cout<<mapImageResize<<endl;
}

void Resize::ShowCropImage()
{
    string mapImageCrop = CropImageMap();
    cout<<mapImageCrop<<endl;
}

void Resize::SetResizeX(int resize_x)
{
    _resizeX = resize_x;
    (*_jsonRgb)[RESIZE_X] = _resizeX;
}

void Resize::SetResizeY(int resize_y)
{
    _resizeY = resize_y;
    (*_jsonRgb)[RESIZE_Y] = _resizeY;
}

void Resize::SetMapWidth(int mapWidth)
{
    _mapWidth = mapWidth;
    (*_jsonRgb)[MAP_WIDTH] = _mapWidth;
}

void Resize::SetMapHeigth(int mapHeight)
{
    _mapHeight = mapHeight;
    (*_jsonRgb)[MAP_HEIGTH] = _mapHeight;
}
void Resize::SetWidth(int width)
{
    _width = width;
    (*_jsonRgb)[WIDTH] = _width;
}

void Resize::SetHeigth(int height)
{
    _height = height;
    (*_jsonRgb)[HEIGTH] = _height;
}
int Resize::GetResizeX()
{
    return _resizeX;
}

int Resize::GetResizeY()
{
    return _resizeY;
}

int Resize::GetWidth()
{
    return _width;
}

int Resize::GetHeight()
{
    return _height;
}

int Resize::GetMapWidth()
{
    return _mapWidth;
}

int Resize::GetMapHeight()
{
    return _mapHeight;
}
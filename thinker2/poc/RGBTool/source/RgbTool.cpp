#include <RgbTool.h>

RgbTool::RgbTool(string gameName)
{
	_gameName = gameName;
	ReadJson();
	_mapping = new Mapping(_jsonRgb);
	_evaluate = new Evaluate(_jsonRgb);
	_resize = new Resize(_jsonRgb);
}

RgbTool::~RgbTool()
{
	delete(_mapping);
	delete(_evaluate);
	delete(_resize);
} 
void RgbTool::CreateJsonDefault()
{
	vector<int> vector;
	map<string, string> map;
    ofstream opf {_gameName+".json"};
	Json json_rgb;
	json_rgb[WIDTH] = DEFAULT_WIDTH;
	json_rgb[HEIGTH] = DEFAULT_HEIGTH;
	json_rgb[MAP_WIDTH] = DEFAULT_WIDTH;
	json_rgb[MAP_HEIGTH] = DEFAULT_HEIGTH;
	json_rgb[RESIZE_X] = DEFAULT_RESIZE;
	json_rgb[RESIZE_Y] = DEFAULT_RESIZE;
	json_rgb[PATH_X] = vector;
	json_rgb[PATH_Y] = vector;
	json_rgb[REPLACE_EXCEPTION] = map;
	opf<<setw(INDENTATION)<<json_rgb<<"\n";
    opf.close();

    _jsonRgb = json_rgb;
}

void RgbTool::ReadJson()
{
	Json json;
    ifstream fileJson ((_gameName + ".json").c_str());

    if (fileJson.peek() == EOF)
    {
        CreateJsonDefault();
    }    
    else
    {
        if(fileJson.good())
		{
			fileJson >> json;

			if(json.empty())
			{
				CreateJsonDefault();
			}
			else
			{
				_jsonRgb = json;
			}
		}
		else
		{
			printf("SOME THING ABOUT THIS FILE <%s.json> IS WRONG!\n", _gameName.c_str());
		}
    }

    fileJson.close();
}

void RgbTool::CharRepresent(string auxRenderRgb)
{
	_charRepresentation = _mapping->CharRepresentation(auxRenderRgb);
}

void RgbTool::CharRepresent()
{
	_charRepresentation = _mapping->CharRepresentation(_renderRGB);
}

void RgbTool::ShowCropImage()
{
	int cropX, cropY;
    int len_x = GetWidth() /GetResizeX();
    int len_y = GetHeigth() /GetResizeY();
    cout<<"El tamano de la imagen recortada es en x y es: ";
    cout<<len_x<<"X"<<len_y<<"\n";
   
    cout<<"Ingrese un numero para cortar la imagen en X menor a "<< len_x<< ": ";
    cin>>cropX;
    cout<<"Ingrese un numero para cortar la imagen en Y menor a "<< len_y<< ": ";
    cin>>cropY;

    SetWidth(cropX);
    SetHeight(cropY); 
    _resize->ShowCropImage();
}

void RgbTool::ShowResizeImage()
{
	int resizeX, resizeY;
    cout<<"Ingrese un numero para reducir imagen en X: ";
    cin>>resizeX;
    cout<<"Ingrese un numero para reducir imagen en Y: ";
    cin>>resizeY;

    SetResizeX(resizeX);
    SetResizeY(resizeY);

    _resize->ShowResizeImage();
}


void RgbTool::SetRenderRgb(const string arrayRgb)
{
	_renderRGB = arrayRgb;
}

void RgbTool::PrintMapHtml()
{
	_mapping->ToHtml();
}

string RgbTool::GetRenderRgb()
{
	return _renderRGB;
}

map<char, double> RgbTool::GetObjectPosition(char objectMatch)
{
	return _evaluate->GetObjectPosition(objectMatch, _charRepresentation);
}

map<string, double> RgbTool::GetObjectAllPosition(string objectMatch)
{
	return _evaluate->GetObjectAllPosition(objectMatch, _charRepresentation);
}

void RgbTool::SavePathX()
{
	_mapping->SavePathX();
	SaveJson();
}

void RgbTool::SavePathY()
{
	_mapping->SavePathY();
	SaveJson();
}

void RgbTool::SaveJson()
{
	ofstream fileJson {(_gameName+".json").c_str()};

	fileJson<<setw(INDENTATION) << _jsonRgb;

	fileJson.close();
}

string RgbTool::CropImage(int width, int heigth)
{
	_resize->SetImageMap(_charRepresentation);
	string result = _resize->CropImageMap(width,heigth);
	SaveJson();
	return result;
}

string RgbTool::CropImage()
{
	_resize->SetImageMap(_charRepresentation);
	string result = _resize->CropImageMap();
	SaveJson();
	return result;
}

string RgbTool::GetResizedRender()
{
	_resize->SetImageMap(_charRepresentation);
	string result = _resize->ResizeImageMap();
	return result;
}

string RgbTool::GetResizedRender(int resizeX, int resizeY)
{
	_resize->SetImageMap(_charRepresentation);

	string result = _resize->ResizeImageMap(resizeX, resizeY);
	SaveJson();
	return result;
}

vector<vector<char>> RgbTool::GetMap()
{
	_resize->SetImageMap(_charRepresentation);
	return _mapping->GetMatrix();
}

vector<vector<char>> RgbTool::MappingRgb(string Resized_Map)
{
	_resize->SetImageMap(_charRepresentation);
	return _mapping->GenerateMatrix(Resized_Map);
}

void RgbTool::SaveStringExceptions()
{
	_mapping->SaveStringExceptions();	
	SaveJson();
}
string RgbTool::GetCharRepresentation()
{
		return _charRepresentation;
}

int RgbTool::GetWidth()
{
	return _resize->GetWidth();
}

int RgbTool::GetHeigth()
{
	return _resize->GetHeight();
}

int RgbTool::GetResizeX()
{
	return _resize->GetResizeX();
}

int RgbTool::GetResizeY()
{
	return _resize->GetResizeY();
}

void RgbTool::SetResizeX(int x)
{
	return _resize->SetResizeX(x);
}

void RgbTool::SetResizeY(int y)
{
	return _resize->SetResizeY(y);
}

void RgbTool::SetWidth(int resizeX)
{
	_resize->SetMapWidth(resizeX);
}
void RgbTool::SetHeight(int resizeY)
{
	_resize->SetMapHeigth(resizeY);
}
void RgbTool::SetWidthGlobal(int resizeX)
{
    _resize->SetWidth(resizeX);
    SaveJson();
}
void RgbTool::SetHeightGlobal(int resizeY)
{
    _resize->SetHeigth(resizeY);
    SaveJson();
}
vector<vector<char>> RgbTool::MappingRgb()
{
	CharRepresent(_renderRGB);
	
	return _mapping->GenerateMatrix(GetResizedRender());
}
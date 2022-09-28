bool Image::operator << (std::string filename)=0{
	const char * fn=filename.c_str();
	holder = ReadPPM(fn);
	delete [] fn;
	return (holder==nullptr) ? 0 : 1;
}

bool Image::operator >> (std::string filename)=0;{
	const char * fn =filename.c_str();	
	return WritePPM(this , fn);
}

Vec3<float> Image::getPixel(unsigned int x , unsigned int y){
	return Array::this(x, y);
	
}

void Image::setPixel(unsigned int x , unsigned int y, Vec3<float>& source){
	Array::this(x,y)=source;
}

void Image::setData(const Vec3<float> * & data_ptr){
	if(data_ptr==nullptr){
		if (buffer!=nullptr){
			delete[] buffer;			
		}
		buffer=nullptr;
	}else{
		memcpy(buffer, data_ptr,width*height);
	}	
}

Image::Image(){
	height = width = 0;
	buffer=nullptr;
}

Image::Image(unsigned int width, unsigned int height){
	this->width=width;
	this->height=height;
	buffer=new Vec3<float>[width*height];
}

Image::Image (unsigned int width, unsigned int height, Vec3<float>* data_ptr){
	this->width=width;
	this->height=height;
	buffer=nullptr;
	setData(data_ptr);
}

Image::Image(const Image& src){
	this->width=src.width;
	this->height=src.height;
	buffer=nullptr;
	const Vec3<float>* tmp = src.buffer;
	setData(tmp);
	delete [] tmp;
}

Image::~Image(){
	delete [] buffer;
}		


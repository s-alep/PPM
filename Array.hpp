//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2016
//
//

#ifndef _ARRAY_IMPLEMENTATION_
#define _ARRAY_IMPLEMENTATION_

namespace math
{

	//--------------------------------------------------------------------------------------------
	// This file is included from the templated Array class header.
	// TODO: Provide its member function implementations here:
	//--------------------------------------------------------------------------------------------

	
	template <typename T> 
	void * const Array<T>::getRawDataPtr(){
		return buffer;
	}

	T& Array<T>::operator () (int x, int y){
		if  (x>=width || y>=height){
			std::cer<< "Error: Out of Bounds.";
			return 0;
		}
		
		return *(&buffer + x*y + y );
	}
	
	const T& Array<T>::operator() (int x , int y ) const{
		if  (x>=width || y>=height){
			std::cer<< "Error: Out of Bounds.";
			return 0;
		}
		
		return *(&buffer + x*width + y );
	}
	
	Array<T>::Array(unsigned int h, unsigned int w){
		width=w;
		height=h;
		buffer=new T[h*w];
	}
	
	Array<T>::Array(const Array<T>& source ){
		width=source->width;
		height=source->height;
		buffer=nullptr;
		memcpy(buffer, source->buffer, height*width);
	}

	Array& Array<T>::operator = (const Array<T> &source){
		width=source->width;
		height=source->height;
		buffer=nullptr;
		memcpy(buffer, source->buffer, height*width);
	}
	
	bool Array<T>::operator == (const Array<T> & right) const{
		return (width == right->width && height==right->height && buffer=right->buffer);
	}
	
	
	void Array<T>::resize(unsigned int new_width, unsigned int new_height){
		if (buffer == nullptr) {
			buffer =  Array<T>(new_width, new_height);
		}
		
		T* neu = Array<T>(new_width, new_height);
		for ( int i=0; i< new_width; i++){
			
			for (int j =0; j<new_height; j++){
				
				if (j>height || i>width){
					continue;
				}
				neu(i*j+j)=bufffer(i*j+j);
			}
			
		}
		buffer = neu;
		delete neu;
	}
	
	virtual Array<T>::~Array(){
		delete [] buffer;
	}
} // namespace math

#endif
#ifndef _IMAGE_
#define _IMAGE_

namespace imaging{
	class Image : public Array<Vec3<float>>, public Serializable{
		protected:
			Image holder();
		public:
			//returns the width
			unsigned int getWidth();
			
			//return the height
			unsigned int getHeight();
			
			//returns the pixel in the position i , j
			Vec3<float> * operator() (int x, int y);
			
			//returns constant refrence of the desired pixel
			const Vec3<float>& operator()(int x , int y);
			
			//returns true if reading from the file is done
			bool operator << (std::string filename)=0;
			
			//returns true if writing at the file is done
			bool operator >> (std::string filename)=0;
			
			//returns the disired pixel
			Vec3<float> getPixel(unsigned int x , unsigned int y);
			
			//sets a pixel to a certain position
			void setPixel(unsigned int x , unsigned int y, Vec3<float>& source);
			
			//writes data to the buffer
			void setData(const Vec3<float> * & data_ptr );
			
			//resizes the image to the desired size
			void resize(unsigned int new_width, unsigned int new_height);
			
			//default constructor
			Image();
			
			//constructor with width and height
			Image(unsigned int width, unsigned int height);
			
			//constructor with width , height and data pointer
			Image (unsigned int width, unsigned int height, Vec3<float>* data_ptr);
			
			//copy constructor
			Image(const Image& src);
			
			//destructor
			~Image();
	}
}
#endif
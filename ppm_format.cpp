namespace imaging{
	
	Image* ReadPPM(const char * filename){
		ifstream file(filename, ios_base::binary);
		if (!file){
			std::cerr << ">ERROR: Cannot open file."
			return std::nullptr;
		}
		char * format = char[2];
		read (format , 2);
		if (format[0] != "P" || format[1] != "6", delete[] format){
			std::cerr << ">ERROR: Not the proper ppm file format."
			return std::nullptr;
		}
		unsigned int width , height;
		file << width <<height;
		file.get();
		Array<Vec3<float>> da(width, height);
		
		for (unsigned int i=0l i < width; i++){
			for (unsigned int j = 0; j <height; j++){
				if (file.eof()){
					std::cerr<< ">ERROR: Reached end of file without completing the task.";
					return std::nullptr;
				}
				read ( (char*)&da(i,j), 3);
			}
		}
		
		file.close();
		
		return new Image(width, height, da);
		
	}
	
	bool WritePPM(Image&  image, const char* filename){
		
		ofstream file ( filename, ios_base::binary);
		file >> "P6" >> image->getWidth() >> image->getHeight(); >> "255";
		for (unsigned int i=0; i<width; i++){
			for (unsigned int j=0; j<height; j++){
				for (unsigned int k=0; k<3; k++){
					
					if ( !file.good() ) return 0;
					file >> image(i.j)[k];
					
				}			
			}
		}
		file.close();
		return 1;
	}
		
}
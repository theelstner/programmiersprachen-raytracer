#include "sdfloader.hpp"

Scene* loadSDF(std::string const& file)
{
	Scene* out = new Scene;
	std::ifstream sdf; //sdf datei, die geöffnet wird und in stream objekt gespeichert wird
	std::vector<std::string> lines; //vec in dem einzelne zeilen d datei gespeichert
	sdf.open(file);
	if(sdf.is_open())
	{
		std::string line;
		while(getline(sdf, line))
		{
			lines.push_back(line);
		}
		sdf.close(); //dateisystem weiß sonst nicht, dass die wieder freigegeben ist, die datei
	}
	else
	{
		std::cout << "ERROR! File could not be opened. ERROR!" << std::endl;
		return out;
	}
	
	for (auto line : lines)
	{
		std::stringstream stream(line);
		std::string word;
		std::vector<std::string> words;
		while(stream.good()) //solange d stream offen ist und zeichen beinhaltet (fehler beim einlesen?steam zuende? lese oder schreibfehler?)
		{
			stream >> word; // operator trennt nach leerzeichen
			words.push_back(word);
		}

		if(words[0] == "#")
		{}

	    if(words[0] == "define")
	    {
	    	if(words[1] == "material")
	    	{
	    		std::string name = words[2];
	    		Color ka{std::stof(words[3]), std::stof(words[4]), std::stof(words[5])};
	    		Color kd{std::stof(words[6]), std::stof(words[7]), std::stof(words[8])};
	    		Color ks{std::stof(words[9]), std::stof(words[10]), std::stof(words[11])};
	    		float m = std::stof(words[12]);
	    		out->materials.push_back(Material{name, ka, kd, ks, m});
	    	}
	    	if(words[1] == "shape")
	    	{
	    		if(words[2] == "sphere")
	    		{
	    			std::string name = words[3];
	    			glm::vec3 center{std::stof(words[4]), std::stof(words[5]), std::stof(words[6])};
	    			double radius = std::stof(words[7]);
	    			Material material{words[8]}; // ATTENTION: Material{usrname} = black!
	    			out->sphere.push_back(Sphere{name, center, radius, material});
	    		}
	    		if(words[2] == "box")
	    		{
	    			std::string name = words[3];
	    			glm::vec3 min{std::stof(words[4]), std::stof(words[5]), std::stof(words[6])};
	    			glm::vec3 max{std::stof(words[7]), std::stof(words[8]), std::stof(words[9])};
	    			Material material{words[10]}; //Attention: Material material{usrname} = black!
	    			out->box.push_back(Box{name, min, max, material});
	    		}
	    	}
	    	if(words[1] == "light")
	    	{
	    		std::string name = words[2];
	    		glm::vec3 position{std::stof(words[3]), std::stof(words[4]), std::stof(words[5])};
	    		Color la{std::stof(words[6]), std::stof(words[7]), std::stof(words[8])};
	    		Color ld{std::stof(words[9]), std::stof(words[10]), std::stof(words[11])};
	    		out->lights.push_back(Light{name, position, la, ld});
	    	}
	    	if(words[1] == "camera")
	    	{
	    		std::string name = words[2];
	    		double fov_x = std::stof(words[3]);
	    		out->camera = Camera{name, fov_x};
	    	}
	    }

	    if(words[0] == "camera")
	    {
	    	std::string name = words[2];
	    	double fov_x = std::stof(words[3]);
	    	out->camera = Camera{name, fov_x};
	    }
	}
	return out;
}


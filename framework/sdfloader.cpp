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
	    }
	}
	return out;
}

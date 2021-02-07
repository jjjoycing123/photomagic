#include "LFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	//command line arguments
	string input_file = argv[1];
	string output_file = argv[2];
	string LFSR_seed = argv[3];
	string tap_string = argv[4];
	unsigned int tap = stoi(tap_string);
	unsigned LFSR_string_size = LFSR_seed.size();

	//Catch unwanted user input that prevents encryption
	if(tap > LFSR_string_size && LFSR_string_size > 1){
		tap = 0;
	}

	if(LFSR_string_size < 8){
		LFSR_seed = "01101000010100010000";
		tap = 16;
	}



	LFSR l(LFSR_seed, tap);
	vector<bool> vec = l.get_lfsr_vec();
	unsigned int num_generated = 0;


	//Image input and out declarations
	sf::Image image_in;
	sf::Image image_out;

	//Input image open
	if (!image_in.loadFromFile(input_file))
		return -1;

	//Assign input image to output image for encryption/decryption
	image_out = image_in;

	// p is a pixel
	sf::Color p;
	sf::Vector2u size = image_out.getSize();


	// Encrypt/Decrypt photo with LFSR
	for (unsigned x = 0; x<size.x; x++) {
		for (unsigned y = 0; y< size.y; y++) {
			p = image_out.getPixel(x, y);
			
			//Red.
			for(unsigned int i = l.get_size_of_resgister() - 8; i < l.get_size_of_resgister(); i++){
			num_generated*=2;
			num_generated+=vec.at(i);
			}
			p.r = p.r ^ num_generated;
			l.generate(15);
			vec = l.get_lfsr_vec();
			num_generated = 0;

			//Green
			for(unsigned int i = l.get_size_of_resgister() - 8; i < l.get_size_of_resgister(); i++){
			num_generated*=2;
			num_generated+=vec.at(i);
			}
			p.g = p.g ^ num_generated;
			l.generate(15);
			vec = l.get_lfsr_vec();
			num_generated = 0;
	
			//Blue
			for(unsigned int i = l.get_size_of_resgister() - 8; i < l.get_size_of_resgister(); i++){
			num_generated*=2;
			num_generated+=vec.at(i);
			}
			p.b = p.b ^ num_generated;
			l.generate(15);
			vec = l.get_lfsr_vec();
			num_generated = 0;

			image_out.setPixel(x, y, p);
		}
	}

	//Create windows for the two images that are going to be displayed.
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input File");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output File");

	sf::Texture texture1;
	texture1.loadFromImage(image_in);

	sf::Sprite sprite1;
	sprite1.setTexture(texture1);

	sf::Texture texture2;
	texture2.loadFromImage(image_out);

	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	//Event to draw the images on the page. 
	while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}

		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		window1.clear(sf::Color::White);
		window1.draw(sprite1);
		window1.display();
		window2.clear(sf::Color::White);
		window2.draw(sprite2);
		window2.display();
	}

	//   write the file
	if (!image_out.saveToFile(output_file))
		return -1;
	


	return 0;
}
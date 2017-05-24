/*
Creator:
	zzDeagle545zz
		Deagle Corp Productions

*/

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//System Libraries
#include <iostream>

//User Libraries
#include "Engine.h"

//Global Constants

//Function Prototypes


//******************************************************************************
//******************************************************************************
//                                   Main
//Function- Execution Begins Here
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
//Declare Variables
	//Event
	sf::Event Event;
	//Context Settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	//Timer for frames
	sf::Clock time;
	FTIME T;
	//Create Render Window
	sf::RenderWindow* MainWin=new sf::RenderWindow
		(sf::VideoMode(1280, 720), "Algorithm Sort", sf::Style::Default, settings);
	//Create the Game
	Engine engine(MainWin);
//Game Loop
	while (MainWin->isOpen()) {
	//Track the time between frames
		T.fTime = time.restart().asSeconds();
	//Run Game
		engine.run();
	}
//Deallocate Resources by the Window
	delete MainWin;
//Exit Stage Right
	return 0;
}
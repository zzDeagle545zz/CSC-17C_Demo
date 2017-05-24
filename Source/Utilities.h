/*
* File:   MenuStates.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: Create Functions and Classes for Utility Purposes.
*	Takes care of Simple tasks.
*/

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries

//Guard Block
#ifndef UTILITIES_H
#define UTILITIES_H

//******************************************************************************
//******************************************************************************
//								 Constants
//  
////////////////////////////////////////////////////////////////////////////////
//Define Constants
const float SQ3 = 1.7320508f;
//******************************************************************************
//******************************************************************************
//                            Function Prototypes
//  
////////////////////////////////////////////////////////////////////////////////
void cOrigin(sf::RectangleShape*);
void cOrigin(sf::Text*);
//Left Aligin Origin
void lOrigin(sf::RectangleShape*);
void lOrigin(sf::Text*);
//Right Aligin Origin
void rOrigin(sf::RectangleShape*);
void rOrigin(sf::Text*);
//******************************************************************************
//******************************************************************************
//                            Time Between Frames
//  
////////////////////////////////////////////////////////////////////////////////
class FTIME {
public:
//The time between Frames
 static float fTime;
};
//******************************************************************************
//******************************************************************************
//                                  Hexagon
//  
////////////////////////////////////////////////////////////////////////////////
class Hexagon :public sf::ConvexShape {
private:
//Attributes
	int size;

protected:

public:
//Member Functions
	Hexagon(int);						//Constructor
	Hexagon();							//Constructor
	~Hexagon();							//Destructor
//Hexagon Animate
	bool inside(sf::Vector2f);			
//SetSize Function
	void setSize(float);
	int getL() { return size; }
};
//******************************************************************************
//******************************************************************************
//                                 Hexagon Text Box
//  
////////////////////////////////////////////////////////////////////////////////
class HexBox{
private:
//Data
	int length;						//Length of text Box in Pixels
	int width;						//Width of txet Box in Pixels
	int S;							//Hex Width
//Elements of the HexBox
	sf::ConvexShape body;					//Shape of the Body
	sf::ConvexShape rFill;					//Rectangle Fill color
	Hexagon* tag;							//Hexagon tag
	Hexagon* hFill;							//Fill color for the Body
	sf::Text* bText;						//Text for body
	sf::Text* tText;						//Text for the tag
	sf::Font* font;							//Text Font
protected:

public:
	HexBox(int,int);					//Constructor
	~HexBox();							//Destructor
//Draw to the Window
	void draw(sf::RenderWindow*);
//Configure Functions
	void setOutlineColor(sf::Color);		//Sets the Outline Color
	void setOutlineThickness(int);			//Sets the Outline Thickness
	void setFillColor(sf::Color);			//Sets the Shape's Fill Color
	void setTagText(sf::String);			//Sets Tag String
	void setText(sf::String);				//Sets the String for the Box
	void setPosition(float,float);			//Sets the Position of the Shape
	void setScale(float,float);				//Sets the Scale of the Shape
	bool contains(sf::Vector2f);			//Test if Mouse is inside Shape
	void move(sf::Vector2f);				//Moves hexBox in x,y offset
//Accessor Functions
	Hexagon* getTag(){ return tag; }
	sf::Text* getBtext() { return bText; }
	sf::Vector2f getPosition() { return tag->getPosition(); }
};
//******************************************************************************
//******************************************************************************
//                          Hexagon Load Bar
//  
////////////////////////////////////////////////////////////////////////////////
class HexBar {
private:
//Data
	int length;
	int width;
	float pGress;					//Loading bar Progress
	//Time between Frames
	FTIME T;
	//Text
	sf::Text* lbP;					//Left Bound Parentheses 
	sf::Text* rbP;					//Right Bound Parentheses
	//Font
	sf::Font* font;					//Hex Bar Font
	//Hexagon
	Hexagon* lHex;					//Hexagon for Loading Bar
	//Rectangles
	sf::RectangleShape* lTrack;		//Track for Loading Bar
protected:
	//Orgin Settings
	void oRight() { rOrigin(lTrack); }			//Right
	void oCenter() { cOrigin(lTrack); }			//Center
	void oLeft() { lOrigin(lTrack); }			//Left
public:
	HexBar(int, int);					//Constructor
	~HexBar();							//Destructor
//Draw to the Window
	void draw(sf::RenderWindow*);
//Configure Functions
	void setPosition(float, float);		//Sets the Position of the Shape
	void setOrigin(int);				//Sets the Origin to Left, right, middle	
	void update(float);					//Moves hexBox in x,y offset
//Accessor Functions
	int getLength() { return length; }
	int getWidth() { return width; }
	sf::RectangleShape* getTrack() { return lTrack; }
	Hexagon* getHex() { return lHex; }
//Manipulator Functions
	void setpGress(float p) { pGress = p; }
};

#endif	//UTILITIES_H
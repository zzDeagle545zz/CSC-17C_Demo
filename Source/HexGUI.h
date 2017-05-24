/*
* File:   HexGUI.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: To Create a series of classes to handle user Input and
*	the Graphical Interface.
*/

//Guard Block
#ifndef HEXGUI_H
#define HEXGUI_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//System Library

//User Libraries
#include "Utilities.h"

//******************************************************************************
//******************************************************************************
//								 Constants
//  
////////////////////////////////////////////////////////////////////////////////
//Define Constants
//const float SQ3 = 1.7320508f;
//******************************************************************************
//******************************************************************************
//								 Color Scheme
//  
////////////////////////////////////////////////////////////////////////////////
struct HexStyle {
//Colors
	sf::Color cFill;			//Fill Color
	sf::Color cOutline;			//Outline Color
	sf::Color cText;			//Text Color
	sf::Color cHover;			//Color for Hover Affects
	sf::Color cFaded;			//Color of Inactive or faded Affects
//Fonts
	sf::Font* fTitle;			//Font for Title
	sf::Font* fBody;			//Font for Body
//Char Sizes
	int chTitle;				//Title Text
	int chBody;					//Body Text
//Outline Thickness
	int oThick;					//Outline Thickness
};
//******************************************************************************
//******************************************************************************
//                              Hex Button
//  
////////////////////////////////////////////////////////////////////////////////
class HexButton :public sf::ConvexShape {
private:
//Utility Members
	//Primatives
	int size;							//Hexagon Side Length
//GUI Elements
	//Style
	HexStyle* style;					//Style
	//Text
	sf::Text* text;						//Button Text
	//Font
	sf::Font* font;						//Text Font
protected:

public:
//Constructors
	HexButton();								//Default
	HexButton(int);								//Set Size of Hex
	HexButton(int, sf::String, HexStyle*);		//Sets Size/String/Style
//Destructors
	~HexButton();
//Member Functions
	bool inside(sf::Vector2f);				//Checks to see if Mouse is in Shape
	void SetPosition(float, float);			//Sets Position of GUI Element
	void draw(sf::RenderWindow*);			//Draws Items to Window
	void configure(HexStyle*);				//Configures all the Data
//Manipulator Functions

//Accessors Functions
	int getL() { return size; }				//Gets Hex Length
	sf::Text* getText() { return text; }	//Gets Hext Text
};
//******************************************************************************
//******************************************************************************
//                              Hex Label
//  
////////////////////////////////////////////////////////////////////////////////
class HexLabel {
private:
//Utility Members

//GUI Elements
	//Style
	HexStyle* style;
	//HexButton
	HexButton* hex;						//Emblem
	//Line
	sf::RectangleShape* uLine;			//UnderLine
	sf::RectangleShape* hitBox;			//Hit Box
	//Text
	sf::Text* label;					//Label Data
	//Font
	sf::Font* font;						//Font for Label
protected:

public:
//Constructor
	HexLabel(sf::Vector2f,sf::String, HexStyle*);	//Sets Size/String/Style
//Destructor
	~HexLabel();									
//Member Functions
	void setPosition(float,float);			//Sets the Position of the Label
	void draw(sf::RenderWindow*);			//Draws Items to Window
	void configure(HexStyle*);				//Configures Data Elements
	bool isIn(sf::Vector2f);				//Checks if point is in Label
//Accessor Functions
	HexButton* getHex() { return hex; }
	sf::RectangleShape* getLine() { return uLine; }
	sf::FloatRect getSize() { return hitBox->getLocalBounds(); }
	sf::Text* getText() { return label; }
//Manipulation Functions

};
//******************************************************************************
//******************************************************************************
//                              Hex Selector
//  
////////////////////////////////////////////////////////////////////////////////
class HexSelect {
private:
//Utility Members
	//Primative Data
	bool left;				//True Spins Left
	bool right;				//True Spins Right
	bool spinning;			//If it is Spinning
	float rotate;			//End Rotation Point
	//Frame Time
	FTIME T;
//GUI Elements
	//Style
	HexStyle* style;			//Menu Style
	//HexButton
	HexButton* hex;				//Hex Spin Selector
	//Triangles
	sf::ConvexShape* lTri;		//Left Triangle
	sf::ConvexShape* rTri;		//Right Triangle
	//Text
	sf::Text* descrip;			//Description
	//Font
	sf::Font* font;				//Text Font
protected:

public:
//Enumerator for Left and Right
	enum LoR { LEFT, RIGHT };
//Constructors
	HexSelect(int,sf::String,sf::String,HexStyle*);	//Sets Size/Strings/Style
//Destructor
	~HexSelect();
//Public Member Functions
	void setPosition(float, float);			//Sets Position of Selector
	void configure(HexStyle*);				//Configures GUI Data
	void draw(sf::RenderWindow*);			//Draws Elements to window
	void update();							//Updates the Selector
	bool isLeft(sf::Vector2f);				//Checks Mouse Pos for left arrow
	bool isRight(sf::Vector2f);				//Checks Mouse Pos for right arrow
	void spin(int,int);						//Spins hex
//Accessor Functions
	sf::Text* getText() { return descrip; }
	HexButton* getHex() { return hex; }
//Manipulation Functions
};

#endif //HEXGUI_H
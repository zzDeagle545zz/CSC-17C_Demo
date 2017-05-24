/*
Description
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
#include "Utilities.h"

//Global Constants

//Function Prototypes

//******************************************************************************
//******************************************************************************
//									 FTIME
//  
////////////////////////////////////////////////////////////////////////////////
//Static Variable Declaration
float FTIME::fTime;
//******************************************************************************
//******************************************************************************
//                                 Hexagon
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//                         Hexagon Constructor(Side Length)
//Function- Creates Standard hexagon Shape
//Inputs
//      -->>Side Length Away from the Origin
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
Hexagon::Hexagon(int sLgth) {
//Declare Variables
	size = sLgth;
//Creates the Hexagon Shape
	this->setPointCount(6);				
//Set Points of the Hexagon
	this->setPoint(0,sf::Vector2f		//Point 1
		(this->getOrigin().x - .5*sLgth, this->getOrigin().y - .866*sLgth));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5*sLgth, this->getOrigin().y - .866*sLgth));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + sLgth, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5*sLgth, this->getOrigin().y + .866*sLgth));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5*sLgth, this->getOrigin().y + .866*sLgth));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - sLgth, this->getOrigin().y));
//Set the Origin
	this->setOrigin(this->getPoint(5).x+sLgth, getPoint(0).y+sLgth*.866);
}
//******************************************************************************
//                         Hexagon Constructor(Side Length)
//Function- Creates Standard hexagon Shape
//Inputs
//      -->>Side Length Away from the Origin
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
Hexagon::Hexagon() {
	//Declare Variables
	int sLgth = 25;
	size = 25;
	//Creates the Hexagon Shape
	this->setPointCount(6);
	//Set Points of the Hexagon
	this->setPoint(0, sf::Vector2f		//Point 1
		(this->getOrigin().x - .5*sLgth, this->getOrigin().y - .866*sLgth));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5*sLgth, this->getOrigin().y - .866*sLgth));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + sLgth, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5*sLgth, this->getOrigin().y + .866*sLgth));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5*sLgth, this->getOrigin().y + .866*sLgth));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - sLgth, this->getOrigin().y));
	//Set the Origin
	this->setOrigin(this->getPoint(5).x + sLgth, getPoint(0).y + sLgth*.866);
}
//******************************************************************************
//                         Hexagon Destructor
//Function- Creates Standard hexagon Shape
//Inputs
//      -->>Side Length Away from the Origin
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
Hexagon::~Hexagon() {
//Declare Variables

}
//******************************************************************************
//******************************************************************************
//									Inside
//Function- Check to see if a X,Y Cordinate is in a shape
//Inputs
//      -->> Vector with X,Y cordinates
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
bool Hexagon::inside(sf::Vector2f cord) {
//Check point in entire Float Rect
	if (!this->getGlobalBounds().contains(cord))
		return false;
//Check Top left Triangle
	else if ((cord.y < -1.732*(cord.x - (this->getPosition().x - 
		(this->size*this->getScale().x))) + this->getPosition().y)) 
		return false;
//Check Top Right Triangle
	else if ((cord.y < 1.732*(cord.x - (this->getPosition().x + 
		(this->size*this->getScale().x))) + this->getPosition().y))
		return false;
//Check Bot left Triangle
	else if ((cord.y > -1.732*(cord.x - (this->getPosition().x + 
		(this->size*this->getScale().x))) + this->getPosition().y))
		return false;
//Check Top Right Triangle
	else if ((cord.y > 1.732*(cord.x - (this->getPosition().x - 
		(this->size*this->getScale().x))) + this->getPosition().y))
		return false;
//Its in!
	else
		return true;
}
//******************************************************************************
//******************************************************************************
//									Set Size
//Function- Changes the size of the Hexagon
//Inputs
//      -->>Float Ratio for the size
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void Hexagon::setSize(float rat) {
//Set Attribute
	size *= rat;
//Set New points with size
	this->setPoint(0, sf::Vector2f		//Point 1
		(this->getOrigin().x - .5*size, this->getOrigin().y - .866*size));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5*size, this->getOrigin().y - .866*size));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + size, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5*size, this->getOrigin().y + .866*size));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5*size, this->getOrigin().y + .866*size));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - size, this->getOrigin().y));
	//Set the Origin
	this->setOrigin(this->getPoint(5).x + size, getPoint(0).y + size*.866);
}
//******************************************************************************
//******************************************************************************
//							    Center Rectangle
//Function- Center Origin of  a text Box
//Inputs
//      -->>Rectangle
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void cOrigin(sf::RectangleShape* rect) {
	//Set Origin to Center
	rect->setOrigin
	(rect->getLocalBounds().left + rect->getLocalBounds().width / 2.0f,
		rect->getLocalBounds().top + rect->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//							  Left Aligin Rectangle
//Function- Center Origin of  a text Box
//Inputs
//      -->>Rectangle
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void lOrigin(sf::RectangleShape* rect) {
	//Set Origin to Left side
	rect->setOrigin
	(0,
		rect->getLocalBounds().top + rect->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//								  Right Aligin Text
//Function-Right aligin the Origin of a text Box
//Inputs
//      -->>Text
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void rOrigin(sf::RectangleShape* rect) {
	//Set Origin to Right
	rect->setOrigin
	(rect->getLocalBounds().left + rect->getLocalBounds().width,
		rect->getLocalBounds().top + rect->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//								  Center Text
//Function- Center Origin of a text Box
//Inputs
//      -->>Text
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void cOrigin(sf::Text* text) {
	//Set Origin to Center
	text->setOrigin
	(text->getLocalBounds().left + text->getLocalBounds().width / 2.0f,
		text->getLocalBounds().top + text->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//								  Left Aligin Text
//Function-Left aligin the Origin of a text Box
//Inputs
//      -->>Text
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void lOrigin(sf::Text* text) {
	//Set Origin to Left
	text->setOrigin
	(0,
		text->getLocalBounds().top + text->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//								  Right Aligin Text
//Function-Right aligin the Origin of a text Box
//Inputs
//      -->>Text
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void rOrigin(sf::Text* text) {
	//Set Origin to Right
	text->setOrigin
	(text->getLocalBounds().left + text->getLocalBounds().width,
		text->getLocalBounds().top + text->getLocalBounds().height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//                              Hexagon Text Box
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//                      HexBox Constructor(TextBox Length)
//Function- Creates Standard hexagon Shape
//Inputs
//      -->>Length of the Text Box in Pixels
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
HexBox::HexBox(int L,int W) {
//Set Data Values
	length = L;
	width = W;
	S = 2.0f * W / SQ3;				//Side Length of the Hexagon
//Create the Custom Shape Body
	//Set the Amount of Points
	body.setPointCount(10);
	//Set Origin
	sf::Vector2f O = body.getOrigin();
	//Set Point One
	body.setPoint(0,sf::Vector2f(O.x-.5f*S,O.y-S*SQ3/2));
	//Set Point Two
	body.setPoint(1, sf::Vector2f(O.x + .5f*S,O.y-S*SQ3/2));
	//Set Point Three
	body.setPoint(2, sf::Vector2f(O.x + .75f*S,O.y-S*SQ3/4));
	//Set Point Four
	body.setPoint(3, sf::Vector2f(O.x+.75f*S+L,O.y-S*SQ3/4));
	//Set Point Five
	body.setPoint(4, sf::Vector2f(O.x+.75*S+L+W/2*SQ3,O.y));
	//Set Point Six
	body.setPoint(5, sf::Vector2f(O.x + .75f*S + L, O.y + S*SQ3 / 4));
	//Set Point Seven
	body.setPoint(6, sf::Vector2f(O.x + .75f*S, O.y + S*SQ3 / 4));
	//Set Point Eight
	body.setPoint(7, sf::Vector2f(O.x + .5f*S, O.y + S*SQ3 / 2));
	//Set Point Nine
	body.setPoint(8, sf::Vector2f(O.x - .5f*S, O.y + S*SQ3 / 2));
	//Set Point Ten
	body.setPoint(9, sf::Vector2f(O.x - S, O.y));
//Create thhe fill Shapes
	//Hexagon for fill color
	hFill = new Hexagon(S);
	//Hexagon Tag
	tag = new Hexagon(S*.7f);
	//Retangle Part
	rFill.setPointCount(5);
	//Set Point One
	rFill.setPoint(0, sf::Vector2f(O.x, O.y-W/2));
	//Set Point Two
	rFill.setPoint(1, sf::Vector2f(O.x + L, O.y-W/2));
	//Set Point Three
	rFill.setPoint(2, sf::Vector2f(O.x + L+W / 2 * SQ3, O.y));
	//Set Point Four
	rFill.setPoint(3, sf::Vector2f(O.x + L, O.y+W/2));
	//Set Point Five
	rFill.setPoint(4, sf::Vector2f(O.x, O.y+W/2));
//Configure Shapes Data
	body.setFillColor(sf::Color(255, 255, 255, 0));
//Create Font
	font = new sf::Font;
	//Load Font
	try{
		if (!font->loadFromFile("Resources/Fonts/Xolonium-R.otf"))
			throw "Fail to Load";
		} catch (char* msg) {
		//Handle Error
	}
//Creat the Texts
	bText = new sf::Text("", *font, 20);
	tText = new sf::Text("", *font, 20);
	tag->setFillColor(sf::Color::Black);
	tag->setOutlineThickness(2);
	tag->setOutlineColor(sf::Color::Red);
}
//******************************************************************************
//******************************************************************************
//                      HexBox Constructor(TextBox Length)
//Function- Creates Standard hexagon Shape
//Inputs
//      -->>Length of the Text Box in Pixels
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
HexBox::~HexBox() {
//Delete Hexagons
	delete tag; delete hFill;
//Delete Texts
	delete bText; delete tText;
}
//******************************************************************************
//******************************************************************************
//							Draw
//Function- Draws the Hex Box to the window
//Inputs
//      -->>Pointer to the Window
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::draw(sf::RenderWindow* win) {
//Draw the Elements of the hex Box
	win->draw(body);
	win->draw(*hFill);
	win->draw(rFill);
	win->draw(*tag);
	win->draw(*bText);
	win->draw(*tText);
}
//******************************************************************************
//******************************************************************************
//                      Set Outline Color
//Function- Sets the outline color of the ConvexShape
//Inputs
//      -->>The Color
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setOutlineColor(sf::Color C) {
//Set the Color
	body.setOutlineColor(C);
}
//******************************************************************************
//******************************************************************************
//                      Set Outline Thickness
//Function- Sets the outline Thickness of the ConvexShape
//Inputs
//      -->>The Width in Pixels
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setOutlineThickness(int P) {
//Set the Color
	body.setOutlineThickness(P);
//Do the Slight Ajustment
	sf::Vector2f O = body.getOrigin();
	//Set Point Two
	body.setPoint(1, sf::Vector2f(O.x + .5f*S+P, O.y - S*SQ3 / 2));
	//Set Point Three
	body.setPoint(2, sf::Vector2f(O.x + .75f*S + P, O.y - S*SQ3 / 4));
	//Set Point Seven
	body.setPoint(6, sf::Vector2f(O.x + .75f*S + P, O.y + S*SQ3 / 4));
	//Set Point Eight
	body.setPoint(7, sf::Vector2f(O.x + .5f*S + P, O.y + S*SQ3 / 2));
}
//******************************************************************************
//******************************************************************************
//                      Set Fill Color
//Function- Sets the fill color of the ConvexShape
//Inputs
//      -->>The Color
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setFillColor(sf::Color C) {
//Set the Color
	rFill.setFillColor(C);
	hFill->setFillColor(C);
}
//******************************************************************************
//******************************************************************************
//							 Set Tag Text
//Function- Sets the Text for the Tag
//Inputs
//      -->>The String
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setTagText(sf::String T) {
//Set the text
	tText->setString(T);
//Reset Origin
	cOrigin(tText);
}
//******************************************************************************
//******************************************************************************
//							 Set Text
//Function- Sets the fill color of the ConvexShape
//Inputs
//      -->>The Color
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setText(sf::String T) {
//Set the text
	bText->setString(T);
//Reset Origin
	lOrigin(bText);
}
//******************************************************************************
//******************************************************************************
//							 Set Position
//Function- Sets the Position of the ConvexShape and its Elements
//Inputs
//      -->> X and Y Coordinates
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setPosition(float x, float y) {
//Set the Shapes Position
	rFill.setPosition(x + S*.75f, y);
	hFill->setPosition(x, y);
	body.setPosition(x, y);
	tag->setPosition(x, y);
//Set the Position of the  Texts
	tText->setPosition(x, y);
	if (body.getScale().x > 0) {
		bText->setPosition(x + S, y);
		rFill.setPosition(x + S*.75f, y);
	}
	else {
		bText->setPosition(x - S, y);
		rFill.setPosition(x - S*.75f, y);
	}
}
//******************************************************************************
//******************************************************************************
//							 Set Scale
//Function- Sets the scale of the ConvexShape and its Elements
//Inputs
//      -->> Scale Factor
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::setScale(float x,float y) {
//Set the Shapes Scale
	rFill.setScale(x, y);
	hFill->setScale(x, y);
	body.setScale(x, y);
	tag->setScale(x, y);
//For Negative Scale
	if (x < 0) {
		rOrigin(bText);
	}
}
//******************************************************************************
//******************************************************************************
//								Contains
//Function- Sets the scale of the ConvexShape and its Elements
//Inputs
//      -->> Scale Factor
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
bool HexBox::contains(sf::Vector2f X) {
	return true;
}
//******************************************************************************
//******************************************************************************
//							 Set Scale
//Function- Sets the scale of the ConvexShape and its Elements
//Inputs
//      -->> Scale Factor
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBox::move(sf::Vector2f X) {
//Set the Shapes Position
	rFill.setPosition(rFill.getPosition().x+X.x, rFill.getPosition().y + X.y);
	hFill->setPosition(hFill->getPosition().x + X.x, hFill->getPosition().y + X.y);
	body.setPosition(body.getPosition().x + X.x, body.getPosition().y + X.y);
	tag->setPosition(tag->getPosition().x+X.x,tag->getPosition().y+X.y);
//Set the Position of the  Texts
	tText->setPosition(tText->getPosition().x+X.x,tText->getPosition().y+X.y);
	bText->setPosition(bText->getPosition().x+X.x,bText->getPosition().y+X.y);
}
//******************************************************************************
//******************************************************************************
//                         Hexagon Loading Bar
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//            HexBar Constructor(TextBar Length,TextBar width)
//Function- Creates a Loading bar with Spinning hexagon
//Inputs
//      -->>Length of the Text Box in Pixels
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
HexBar::HexBar(int l,int w) {
//Intailze Variables
	length = l;
	width = w;
	float pGress = 0;
//Create the Objects
	//Recatangle
	lTrack = new sf::RectangleShape(sf::Vector2f(l, w));
	//Hexagon
	lHex = new Hexagon(w/SQ3);
	//Font
	font = new sf::Font;
	try {
		if (!font->loadFromFile("Resources/Fonts/Xolonium-R.otf"))
			throw "Could not load Font.";
	}
	catch (char msg[]) { std::cout << msg << std::endl; }
	//Texts
	lbP = new sf::Text("(", *font, 70);
	rbP = new sf::Text(")", *font, 70);
//Configure Data
	//Text
	rOrigin(lbP);							//Loading Bar Bound left
	lbP->setColor(sf::Color(100, 100, 100, 255));
	lOrigin(rbP);							//Loading Bar Bound right
	rbP->setColor(sf::Color(100, 100, 100, 255));
	//Rectangle
	cOrigin(lTrack);
	lTrack->setFillColor(sf::Color(0, 0, 0, 0));
	//Hexagon
	lHex->setOutlineColor(sf::Color::Cyan);
	lHex->setFillColor(sf::Color(100, 100, 100, 255));
	lHex->setOutlineThickness(2);

	//Set Default Position
	setPosition(0, 0);
}
//******************************************************************************
//******************************************************************************
//							HexBar Destructor
//Function- Releeases Resources
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
HexBar::~HexBar(){
//Free up Memory
	//Texts
	delete lbP; delete rbP;
	//Hexagon
	delete lHex;
	//Rectangles
	delete lTrack;
}
//******************************************************************************
//******************************************************************************
//								Draw
//Function- Draws the loading bar to the screen
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBar::draw(sf::RenderWindow* win) {
//Draw Loading Bar to the window
	win->draw(*lbP);
	win->draw(*rbP);
	win->draw(*lHex);
}
//******************************************************************************
//******************************************************************************
//								Set Position
//Function- Places the Loading bar
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBar::setPosition(float x, float y) {
//Set the Position of all the Objects
	//Loading Track
	lTrack->setPosition(x, y);
	//Loading Hexagon
	lHex->setPosition(lTrack->getGlobalBounds().left, y);
	//Bounding Paraenthesis 
	lbP->setPosition(lTrack->getGlobalBounds().left-width/SQ3,y);
	rbP->setPosition(lTrack->getGlobalBounds().left+length+width/SQ3,y);
}
//******************************************************************************
//******************************************************************************
//						Set Origin
//Function- 
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBar::setOrigin(int a) {
//Choose Left, Right, else middle
	//One Equals Origin Left
	if (a == 1)
		lOrigin(lTrack);
	else if (a == 2)
		rOrigin(lTrack);
	else
		cOrigin(lTrack);
}
//******************************************************************************
//******************************************************************************
//									Update
//Function- Load the Menu data while the splash screen is displayed
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HexBar::update(float p) {
	//Rotate the Hexagon
	pGress = p;
	lHex->setRotation(lHex->getRotation() + 360 * T.fTime);
	lHex->setPosition(lTrack->getGlobalBounds().left +
		lTrack->getLocalBounds().width*pGress, lTrack->getGlobalBounds().top+width/2);
}
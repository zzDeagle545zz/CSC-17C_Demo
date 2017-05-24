/*
Description
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "Menu.h"


/*

*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "Menu.h"

////******************************************************************************
////******************************************************************************
////******************************************************************************
////								TreeTraversal
////  
//////////////////////////////////////////////////////////////////////////////////
////******************************************************************************
////******************************************************************************
////								Constructor
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//TreeTrav::TreeTrav(sf::RenderWindow* window, HexStyle* s) {
//	//Set Style
//	style = s;
//	//Render Window
//	win = window;
//	//Create GUI Elements
//	//HexLabel
//	title = new HexLabel(sf::Vector2f(300, 50), "Tree Traversal", style);
//	//Configure Data
//
//	//Place Objects on the Screen
//	place();
//}
////******************************************************************************
////								Destructor
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//TreeTrav::~TreeTrav() {
//	//Release Resources
//	//HexLabel
//	delete title;
//
//}
////******************************************************************************
////								Listen
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//short TreeTrav::listen() {
//
//
//
//}
////******************************************************************************
////								Update
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//void TreeTrav::update() {
//
//
//
//}
////******************************************************************************
////								Display
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//void TreeTrav::display() {
//
//
//
//}
////******************************************************************************
////								Resize
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//void TreeTrav::resize(int x, int y) {
//
//
//
//}
////******************************************************************************
////								Place
////Function- 
////Inputs
////      
////Outputs
////      
//////////////////////////////////////////////////////////////////////////////////
//void TreeTrav::place() {
//
//
//
//}
//
//******************************************************************************
//******************************************************************************
//                           Sort Comparison
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//                   Constructor(Render Window) 
//Function- 
//Inputs
//      -->>Render Window
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
//SortComp::SortComp(sf::RenderWindow* window,HexStyle* s) {
//	//Create Menu Elements
//	//Menu Font
//	win = window;
//	style = s;
//	//Data
//	show = false;
//
//	//Rectangle Shapes
//
//	//Alg Bars
//	sSort = new AlgBar("Selection Sort",style->fBody , sf::Vector2f(500, 50));
//	bSort = new AlgBar("Bubble Sort", style->fBody, sf::Vector2f(500, 50));
//	maSort = new AlgBar("Mark Sort", style->fBody, sf::Vector2f(500, 50));
//	meSort = new AlgBar("Merge Sort", style->fBody, sf::Vector2f(500, 50));
//	qSort = new AlgBar("Quick Sort", style->fBody, sf::Vector2f(500, 50));
//	hSort = new AlgBar("Heap Sort", style->fBody, sf::Vector2f(500, 50));
//	//Texts
//
//	//Configure Data
//
//
//	//AlgBar
//	sSort->setPosition(75, 125);
//	bSort->setPosition(75, 225);
//	maSort->setPosition(75, 325);
//	meSort->setPosition(75, 425);
//	qSort->setPosition(75, 525);
//	hSort->setPosition(75, 625);
//
//}
////******************************************************************************
////								Destructor
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//SortComp::~SortComp() {
//	//Deallocate Memory
//	//AlgBars
//	delete sSort; delete bSort; delete maSort; delete meSort; delete qSort;
//	//Data
//	delete[] data;
//}
////******************************************************************************
////								Listen
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//short SortComp::listen() {
//	//Window Management
//	while (win->pollEvent(event)) {
//		if (event.type == sf::Event::Closed)	//Exit
//			win->close();
//		if (event.type == sf::Event::Resized) {	//Resize the Window
//												//resize(win, Event.size.width, Event.size.height);
//		}
//
//	}
//
//	return MAIN;
//}
////******************************************************************************
////								Update
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void SortComp::update() {
//	//Update load bars
//	if (show) {
//		//Update Position
//		sSort->addPercent(1000.f / data[SELSORT].tTime*T.fTime);
//		sSort->update();
//		bSort->addPercent(1000.f / data[BUBSORT].tTime*T.fTime);
//		bSort->update();
//		maSort->addPercent(1000.f / data[MRKSORT].tTime*T.fTime);
//		maSort->update();
//		meSort->addPercent(1000.f / data[MRGSORT].tTime*T.fTime);
//		meSort->update();
//		qSort->addPercent(1000.f / data[QUKSORT].tTime*T.fTime);
//		qSort->update();
//		hSort->addPercent(1000.f / data[HEPSORT].tTime*T.fTime);
//		hSort->update();
//	}
//	else {
//		sSort->update();
//		bSort->update();
//		maSort->update();
//		meSort->update();
//		qSort->update();
//		hSort->update();
//	}
//	if (bSort->getPercent() >= 1) {
//		show = false;
//		sSort->setPercent(0);
//		bSort->setPercent(0);
//		maSort->setPercent(0);
//		meSort->setPercent(0);
//		qSort->setPercent(0);
//		hSort->setPercent(0);
//	}
//}
////******************************************************************************
////								Display
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void SortComp::display() {
//	//Draw the Elements
//	win->clear();
//
//	sSort->draw(win);
//	bSort->draw(win);
//	maSort->draw(win);
//	meSort->draw(win);
//	qSort->draw(win);
//	hSort->draw(win);
//
//
//	win->display();
//}
/*
Description
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "Menu.h"


//******************************************************************************
//******************************************************************************
//                             Menu Abstract  Class
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//                         Default Constructor(Menu)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
Menu::Menu() {



}
//******************************************************************************
//******************************************************************************
//                         Default Constructor(Menu)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
Menu::~Menu() {


}
////******************************************************************************
////******************************************************************************
////								 Splash Screen
////  
//////////////////////////////////////////////////////////////////////////////////
////******************************************************************************
////******************************************************************************
////                      Splash Constructor(Render Window) 
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//Splash::Splash(sf::RenderWindow* window) {
////Set the Render Window to the Pointer
//	win = window;
////Loading Status
//	ready = false;
////Test Array
//	test = new tArray(10);
//	working = new tArray(10);
////Data 
//	data = new SortData[6];
////Set Ratio Value
//	resRat.x = win->getSize().x / 1280.0f;
//	resRat.y = win->getSize().y / 720.0f;
////Set Load Progress
//	pGress = 0;
////Create all the data
//	//HexBar
//	lBar = new HexBar(500, 50);
//	//Font
//	font = new sf::Font;
//	try {
//		if (!font->loadFromFile("Resources/Fonts/Xolonium-R.otf"))
//			throw "Could not load Font.";
//	} catch (char msg[]) { std::cout << msg << std::endl; }
//	//Texts
//	dCorp = new sf::Text("Loading...", *font, 40);
//	cRight = new sf::Text("...Running Algorithms", *font, 24);
////Configure Data
//	//Texts
//	cOrigin(dCorp);							//Deagle Corp
//	dCorp->setColor(sf::Color::Cyan);
//	dCorp->setPosition(640, 360);
//	lOrigin(cRight);						//Copyright
//	cRight->setPosition(10, 700);
//	cRight->setColor(sf::Color::Cyan);
//	//HexBar
//	lBar->setPosition(640, 450);
////Create the Menu Elements
//	//Load Thread
//	lThread=new sf::Thread(&Splash::loadMenu,this);
//	lThread->launch();
//}
////******************************************************************************
////******************************************************************************
////                      Splash Constructor(Render Window) 
////Function- 
////Inputs
////      -->>Render Window
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//Splash::~Splash() {
////Deallocate Memory
//	//Texts
//	delete dCorp;delete cRight;
//	//Fonts
//	delete font;
//	//Hexbar
//	delete lBar;
//	//Data
//	delete test;
//	delete working;
////Stops the thread
//	lThread->terminate();
////Delete Thread
//	delete lThread;
//}
////******************************************************************************
////******************************************************************************
////								Load Menu
////Function- Load the Menu data while the splash screen is displayed
////Inputs
////      -->>
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void Splash::loadMenu() {
////Create Main Screen
//	pGress = 0;
//	menu = new SortComp(win);
////Run the Algorithms
//	pGress = .166;
//	//Selection Sort
//	clock.restart();
//	SelSort(*working);
//	data[SELSORT].tTime = clock.getElapsedTime().asMilliseconds();
//	//Reset
//	copyArry();
//	pGress = .332;
//	//Bubble Sort
//	clock.restart();
//	BubSort(*working);
//	data[BUBSORT].tTime = clock.getElapsedTime().asMilliseconds();
//	//Reset
//	copyArry();
//	pGress = .498;
//	//Mark Sort
//	clock.restart();
//	MarkSort(*working);
//	data[MRKSORT].tTime = clock.getElapsedTime().asMilliseconds();
//	//Reset
//	copyArry();
//	pGress = .664;
//	//Merge Sort
//	clock.restart();
//	MergeSort(*working,0,working->getSize());
//	data[MRGSORT].tTime = clock.getElapsedTime().asMilliseconds();
//	//Reset
//	copyArry();
//	pGress = .830;
//	//Quick Sort
//	clock.restart();
//	QuickSort(working->getA(),0,working->getSize()-1);
//	data[QUKSORT].tTime = clock.getElapsedTime().asMilliseconds();
//	//Reset
//	copyArry();
//	pGress = .996;
//	//Heap Sort
//	clock.restart();
//	build_maxheap(working->getA(), working->getSize());
//	HeapSort(working->getA(), working->getSize());
//	data[HEPSORT].tTime = clock.getElapsedTime().asMilliseconds();
//
//	std::cout << "Sort Time in Milliseconds " << std::endl;
//	std::cout << "SelectionSort: " << data[SELSORT].tTime<<std::endl;
//	std::cout << "BubbleSort: " << data[BUBSORT].tTime << std::endl;
//	std::cout << "MarkSort: " << data[MRKSORT].tTime << std::endl;
//	std::cout << "MergeSort: " << data[MRGSORT].tTime << std::endl;
//	std::cout << "QuickSort: " << data[QUKSORT].tTime << std::endl;
//	std::cout << "HeapSort: " << data[HEPSORT].tTime << std::endl;
////Done Loading
//	menu->setData(data);
//	ready = true;
//	pGress = 1;
//}
////******************************************************************************
////******************************************************************************
////									Listen
////Function- Waits for User input and Responds to it
////Inputs
////      -->>
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//short Splash::listen() {
//	//Window Management
//	while(win->pollEvent(event)) {
//		if (event.type == sf::Event::Closed)	//Exit
//			win->close();
//		if (event.type == sf::Event::Resized) {	//Resize the Window
//			//resize(win, Event.size.width, Event.size.height);
//		}
//	}
////For Menu Selection
//	if (pGress == 1)
//		return MAIN;
//	return SPLASH;
//}
////******************************************************************************
////******************************************************************************
////								Update
////Function- Update the Loading Progress
////Inputs
////      -->> Percentage
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void Splash::update() {
////Manage the loading Bar
//	lBar->update(pGress);
//}
////******************************************************************************
////******************************************************************************
////								Display
////Function- Display the Splash Screen
////Inputs
////      -->> Window to Draw to
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void Splash::display() {
////Draw the Elements
//	win->clear();
//
//	lBar->draw(win);
//	win->draw(*cRight);
//	win->draw(*dCorp);
//
//	win->display();
//}
////******************************************************************************
////******************************************************************************
////								Copy Array
////Function- 
////Inputs
////      -->>
////Outputs
////      <<--
//////////////////////////////////////////////////////////////////////////////////
//void Splash::copyArry() {
////Copy Array Elements
//	for (int c = 0;c < test->getSize();c++) {
//		working->getA()[c]= test->getA()[c];
//	}
//}

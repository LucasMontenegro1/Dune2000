#include <iostream>
#include <string>
#include <fstream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <cstring>
#include <typeinfo>
#include <tuple>
#include <map>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "common_build.h"
#include "common_windtrap.h"

using namespace sf;


WindTrap::WindTrap(std::map <int, Vector2f> &frames, float x, float y, int team, int hp): BuildClient(x,y,team, hp), frames(frames) {
	this->largeBitsX = 65;
	this->largeBitsY = 75;
	this->is_constructed = false;
	this->frameWindow = 2;
	this->frameConstruction = 1;
	textBuild.loadFromFile("resources/builds/windtrap.png");
	spriteBuild.setTexture(textBuild);
	windows.setTexture(textBuild);
	Vector2f &posicionBuild = frames[frameBuild];
	spriteBuild.setTextureRect(IntRect(posicionBuild.x, posicionBuild.y,65,75));
	spriteBuild.setPosition(x,y);
	Vector2f &posicionWindow = frames[frameWindow];
	windows.setTextureRect(IntRect(posicionWindow.x, posicionWindow.y,40,55));
	windows.setPosition(x + 15,y + 7);		
}
	
void WindTrap::draw(RenderTarget &target, RenderStates states) const {
	if(is_selected){
		target.draw(lifeMax,states);
		target.draw(lifeRest,states);
	}
	if(is_constructed){
		target.draw(spriteBuild, states);
		target.draw(windows, states);
	} 
	if(frameConstruction > 1 && frameConstruction < 22){
		target.draw(spriteConstruction, states);
	}
}
	
void WindTrap::construct(){
	std::string f = "resources/builds/windtrap/" + std::to_string(frameConstruction) + ".bmp";
	Image image;
	image.loadFromFile(f);
	image.createMaskFromColor(sf::Color::Black);	
	textConstruction.loadFromImage(image);
	spriteConstruction.setTexture(textConstruction);
	spriteConstruction.setPosition(posX,posY);
	spriteConstruction.setTextureRect(IntRect(0,0,70,70));
	frameConstruction++;
	if(frameConstruction == 14) is_constructed = true;
	if(frameConstruction == 22) frameConstruction = 0;
}
	
void WindTrap::animateBuild(){
	if(cont % 10 == 0 && frameConstruction != 0) construct();
	if(cont % 50 == 0){
		if(frameWindow < 6) frameWindow++;
		else frameWindow = 2;
	}
	Vector2f &posicionBuild = frames[frameBuild];
	spriteBuild.setTextureRect(IntRect(posicionBuild.x, posicionBuild.y,65,75));
	Vector2f &posicionWindow = frames[frameWindow];
	windows.setTextureRect(IntRect(posicionWindow.x, posicionWindow.y,40,55));
	cont++;
}

WindTrap::~WindTrap(){}

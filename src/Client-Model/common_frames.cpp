#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <tuple>

using namespace sf;

struct Skins{
	std::map <int, Vector2f> tank;
	std::map <int, Vector2f> trike;
	std::map <int, Vector2f> windTrapH;
	std::map <int, Vector2f> windTrapO;
	std::map <int, Vector2f> windTrapA;
	
	Skins(){
		llenarFramesTank();
		llenarFramesTrike();
		llenarFrameswindTrapH();
		llenarFrameswindTrapO();
		llenarFrameswindTrapA();
	}
	
    private:
	void llenarFramesTank(){
		tank.insert(std::pair<int,Vector2f>(1, Vector2f(4,2)));
		tank.insert(std::pair<int,Vector2f>(2, Vector2f(38,2)));
		tank.insert(std::pair<int,Vector2f>(3, Vector2f(71,2)));
		tank.insert(std::pair<int,Vector2f>(4, Vector2f(103,2)));
		tank.insert(std::pair<int,Vector2f>(5, Vector2f(135,2)));
		tank.insert(std::pair<int,Vector2f>(6, Vector2f(167,2)));
		tank.insert(std::pair<int,Vector2f>(7, Vector2f(201,2)));
		tank.insert(std::pair<int,Vector2f>(8, Vector2f(234,2)));	
		tank.insert(std::pair<int,Vector2f>(9, Vector2f(4,31)));
		tank.insert(std::pair<int,Vector2f>(10, Vector2f(36,31)));
		tank.insert(std::pair<int,Vector2f>(11, Vector2f(69,31)));
		tank.insert(std::pair<int,Vector2f>(12, Vector2f(102,31)));
		tank.insert(std::pair<int,Vector2f>(13, Vector2f(135,31)));
		tank.insert(std::pair<int,Vector2f>(14, Vector2f(169,31)));
		tank.insert(std::pair<int,Vector2f>(15, Vector2f(203,31)));
		tank.insert(std::pair<int,Vector2f>(16, Vector2f(236,31)));
		tank.insert(std::pair<int,Vector2f>(17, Vector2f(4,56)));
		tank.insert(std::pair<int,Vector2f>(18, Vector2f(39,56)));
		tank.insert(std::pair<int,Vector2f>(19, Vector2f(71,56)));
		tank.insert(std::pair<int,Vector2f>(20, Vector2f(104,56)));
		tank.insert(std::pair<int,Vector2f>(21, Vector2f(136,56)));
		tank.insert(std::pair<int,Vector2f>(22, Vector2f(168,56)));
		tank.insert(std::pair<int,Vector2f>(23, Vector2f(201,56)));
		tank.insert(std::pair<int,Vector2f>(24, Vector2f(233,56)));
		tank.insert(std::pair<int,Vector2f>(25, Vector2f(4,83)));
		tank.insert(std::pair<int,Vector2f>(26, Vector2f(36,83)));
		tank.insert(std::pair<int,Vector2f>(27, Vector2f(68,83)));
		tank.insert(std::pair<int,Vector2f>(28, Vector2f(101,83)));
		tank.insert(std::pair<int,Vector2f>(29, Vector2f(135,83)));
		tank.insert(std::pair<int,Vector2f>(30, Vector2f(169,83)));
		tank.insert(std::pair<int,Vector2f>(31, Vector2f(202,83)));
		tank.insert(std::pair<int,Vector2f>(32, Vector2f(236,83)));
		tank.insert(std::pair<int,Vector2f>(33, Vector2f(2,109)));
		tank.insert(std::pair<int,Vector2f>(34, Vector2f(25,109)));
		tank.insert(std::pair<int,Vector2f>(35, Vector2f(48,109)));
		tank.insert(std::pair<int,Vector2f>(36, Vector2f(73,112)));
		tank.insert(std::pair<int,Vector2f>(37, Vector2f(99,112)));
		tank.insert(std::pair<int,Vector2f>(38, Vector2f(124,112)));
		tank.insert(std::pair<int,Vector2f>(39, Vector2f(147,109)));
		tank.insert(std::pair<int,Vector2f>(40, Vector2f(170,109)));	
		tank.insert(std::pair<int,Vector2f>(41, Vector2f(195,112)));
		tank.insert(std::pair<int,Vector2f>(42, Vector2f(219,109)));
		tank.insert(std::pair<int,Vector2f>(43, Vector2f(243,109)));
		tank.insert(std::pair<int,Vector2f>(44, Vector2f(2,129)));
		tank.insert(std::pair<int,Vector2f>(45, Vector2f(25,129)));
		tank.insert(std::pair<int,Vector2f>(46, Vector2f(48,129)));
		tank.insert(std::pair<int,Vector2f>(47, Vector2f(73,129)));
		tank.insert(std::pair<int,Vector2f>(48, Vector2f(99,129)));
		tank.insert(std::pair<int,Vector2f>(49, Vector2f(124,129)));
		tank.insert(std::pair<int,Vector2f>(50, Vector2f(147,129)));
		tank.insert(std::pair<int,Vector2f>(51, Vector2f(170,129)));	
		tank.insert(std::pair<int,Vector2f>(52, Vector2f(195,129)));
		tank.insert(std::pair<int,Vector2f>(53, Vector2f(219,129)));
		tank.insert(std::pair<int,Vector2f>(54, Vector2f(243,129)));
		tank.insert(std::pair<int,Vector2f>(55, Vector2f(2,149)));
		tank.insert(std::pair<int,Vector2f>(56, Vector2f(25,149)));
		tank.insert(std::pair<int,Vector2f>(57, Vector2f(48,149)));
		tank.insert(std::pair<int,Vector2f>(58, Vector2f(73,149)));
		tank.insert(std::pair<int,Vector2f>(59, Vector2f(99,149)));
		tank.insert(std::pair<int,Vector2f>(60, Vector2f(124,149)));
		tank.insert(std::pair<int,Vector2f>(61, Vector2f(147,149)));
		tank.insert(std::pair<int,Vector2f>(62, Vector2f(170,149)));	
		tank.insert(std::pair<int,Vector2f>(63, Vector2f(195,149)));
		tank.insert(std::pair<int,Vector2f>(64, Vector2f(219,149)));
	}
	
	void llenarFramesTrike(){
		trike.insert(std::pair<int,Vector2f>(1, Vector2f(5,5)));
		trike.insert(std::pair<int,Vector2f>(2, Vector2f(40,5)));
		trike.insert(std::pair<int,Vector2f>(3, Vector2f(75,5)));
		trike.insert(std::pair<int,Vector2f>(4, Vector2f(110,5)));
		trike.insert(std::pair<int,Vector2f>(5, Vector2f(140,5)));
		trike.insert(std::pair<int,Vector2f>(6, Vector2f(175,5)));
		trike.insert(std::pair<int,Vector2f>(7, Vector2f(200,5)));
		trike.insert(std::pair<int,Vector2f>(8, Vector2f(235,5)));	
		trike.insert(std::pair<int,Vector2f>(9, Vector2f(5,35)));
		trike.insert(std::pair<int,Vector2f>(10, Vector2f(40,35)));
		trike.insert(std::pair<int,Vector2f>(11, Vector2f(75,35)));
		trike.insert(std::pair<int,Vector2f>(12, Vector2f(110,35)));
		trike.insert(std::pair<int,Vector2f>(13, Vector2f(140,35)));
		trike.insert(std::pair<int,Vector2f>(14, Vector2f(175,35)));
		trike.insert(std::pair<int,Vector2f>(15, Vector2f(200,35)));
		trike.insert(std::pair<int,Vector2f>(16, Vector2f(235,35)));
		trike.insert(std::pair<int,Vector2f>(17, Vector2f(5,60)));
		trike.insert(std::pair<int,Vector2f>(18, Vector2f(40,60)));
		trike.insert(std::pair<int,Vector2f>(19, Vector2f(75,60)));
		trike.insert(std::pair<int,Vector2f>(20, Vector2f(105,60)));
		trike.insert(std::pair<int,Vector2f>(21, Vector2f(135,60)));
		trike.insert(std::pair<int,Vector2f>(22, Vector2f(165,60)));
		trike.insert(std::pair<int,Vector2f>(23, Vector2f(200,60)));
		trike.insert(std::pair<int,Vector2f>(24, Vector2f(235,60)));
		trike.insert(std::pair<int,Vector2f>(25, Vector2f(5,85)));
		trike.insert(std::pair<int,Vector2f>(26, Vector2f(40,60)));
		trike.insert(std::pair<int,Vector2f>(27, Vector2f(75,60)));
		trike.insert(std::pair<int,Vector2f>(28, Vector2f(110,60)));
		trike.insert(std::pair<int,Vector2f>(29, Vector2f(140,85)));
		trike.insert(std::pair<int,Vector2f>(30, Vector2f(175,85)));
		trike.insert(std::pair<int,Vector2f>(31, Vector2f(200,85)));
		trike.insert(std::pair<int,Vector2f>(32, Vector2f(235,85)));
	}
	
	void llenarFrameswindTrapH(){
		windTrapH.insert(std::pair<int,Vector2f>(0, Vector2f(70,135)));
		windTrapH.insert(std::pair<int,Vector2f>(1, Vector2f(0,135)));
		windTrapH.insert(std::pair<int,Vector2f>(2, Vector2f(0,213)));
		windTrapH.insert(std::pair<int,Vector2f>(3, Vector2f(40,213)));
		windTrapH.insert(std::pair<int,Vector2f>(4, Vector2f(80,213)));
		windTrapH.insert(std::pair<int,Vector2f>(5, Vector2f(120,213)));
		windTrapH.insert(std::pair<int,Vector2f>(6, Vector2f(160,213)));
	}

	void llenarFrameswindTrapA(){
		windTrapA.insert(std::pair<int,Vector2f>(0, Vector2f(65,0)));
		windTrapA.insert(std::pair<int,Vector2f>(1, Vector2f(0,0)));
		windTrapA.insert(std::pair<int,Vector2f>(2, Vector2f(0,75)));
		windTrapA.insert(std::pair<int,Vector2f>(3, Vector2f(44,75)));
		windTrapA.insert(std::pair<int,Vector2f>(4, Vector2f(44,75)));
		windTrapA.insert(std::pair<int,Vector2f>(5, Vector2f(125,75)));
		windTrapA.insert(std::pair<int,Vector2f>(6, Vector2f(165,75)));
	}
	
	void llenarFrameswindTrapO(){
		windTrapO.insert(std::pair<int,Vector2f>(0, Vector2f(70,270)));
		windTrapO.insert(std::pair<int,Vector2f>(1, Vector2f(0,270)));
		windTrapO.insert(std::pair<int,Vector2f>(2, Vector2f(0,340)));
		windTrapO.insert(std::pair<int,Vector2f>(3, Vector2f(40,340)));
		windTrapO.insert(std::pair<int,Vector2f>(4, Vector2f(79,340)));
		windTrapO.insert(std::pair<int,Vector2f>(5, Vector2f(120,340)));
		windTrapO.insert(std::pair<int,Vector2f>(6, Vector2f(160,340)));
	}
	
};
//
// Created by ignat on 15/06/22.
//

#ifndef DUNE2000_CONFIGURATIONS_H
#define DUNE2000_CONFIGURATIONS_H

struct Configurations {
	// Infantry
	unsigned int INFANTRY_CLASS_ID;

	unsigned int L_INFANTRY_ID;
	unsigned int L_INFANTRY_HP;
	unsigned int L_INFANTRY_CREATION_TIME;
	unsigned int L_INFANTRY_RANGE;
	unsigned int L_INFANTRY_TRAVERSE_TIME;

	// Vehicles
	unsigned int VEHICLE_CLASS_ID;

	unsigned int TANK_ID;
	unsigned int TANK_HP;
	unsigned int TANK_CREATION_TIME;
	unsigned int TANK_RANGE;
	unsigned int TANK_TRAVERSE_TIME;

	// Weapons
	unsigned int ASSAULT_RIFLE_ID;
	unsigned int ASSAULT_RIFLE_DMG;
	unsigned int ASSAULT_RIFLE_BONUS;
	unsigned int ASSAULT_RIFLE_RECHARGE_TIME;

	unsigned int CANNON_ID;
	unsigned int CANNON_DMG;
	unsigned int CANNON_BONUS;
	unsigned int CANNON_RECHARGE_TIME;
};

extern const struct Configurations CONFIGS;

#endif //DUNE2000_CONFIGURATIONS_H

========================================================================
    CONSOLE APPLICATION : Starfighter RnD Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up the Starfighter RnD application.


Starfighter RnD.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Starfighter RnD.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
File Summary:

Player(.cpp .h)
	Class containing all information about the player character including ship
	upgrades etc.

baseEnemy(.cpp .h)
	Base class from which all enemies (excluding bosses) are inherited

EnemyFactory(.cpp .h)
	Singleton class who's only purpose is to create the various types of enemies
	both singluarly and waves (as applicable)

CollisionMgr(.cpp .h)
	Class for checking and handling collisions between the game's objects

Missile(.cpp .h)
	Class for the firable missile for both player and Enemy's, ownership is set
	during construction


////////////////////////////////////////////////////////////////////////////
Other notes:

///////////////////////////////////////////////////////////////////////////

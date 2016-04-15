/*
* FILE : PioneerWorld.h
* PROJECT : PROG1385 - Assignment #4
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION : This file hold's the class of the PioneerWorld.h
*/



#include "PioneerAM.h"
#pragma once

#define kWorldMin 531
#define kWorldMax 1602
#define kWorldUp 9
#define kWorldDown -9

/*
* NAME : PioneerWorld
* PURPOSE : The pioneer world class inherits from the PioneerAM. Again because toggle frequency is overridded, it does nothing within this
* radio as well. The diffrence is within this class the scan up and down are overridden, changing the value of the frequecy.
*/
class PioneerWorld : public PioneerAM
{
public:
	/*
	* METHOD : PioneerWorld constructor
	* DESCRIPTION : this is the constructor for the PioneerWorld object. It set's the name of the radio and set's the current station
	* PARAMETERS : bool on : to determine weather or not the radio is to be turned on or not
	* RETURNS : void
	*/
	PioneerWorld(bool on) : PioneerAM(on)
	{
		SetRadioName("Pioneer XS440-WRLD");
		SetCurrentStation(kWorldMin);
		for (int i = 0; i < kNumberOfButtons; ++i)
		{
			SetButton(i);
		}
	}
	/*
	* METHOD : ScanUp()
	* DESCRIPTION : overridden function of AmFmRadio. It is used to scan the station's up by 9 instead of 10
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual void ScanUp()
	{
		if (GetPower())
		{
			//if current_station is 1602, the current_station becomes 531
			if (GetCurrent_station() >= kWorldMax)
			{
				SetCurrentStation(kWorldMin);
			}
			else
			{
				SetCurrentStation((GetCurrent_station() + kWorldUp));
			}
		}
	}
	/*
	* METHOD : ScanDown()
	* DESCRIPTION : overridden function of AmFmRadio. It is used to scan the station's down by 9 instead of 10
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual void ScanDown()
	{
		if (GetPower())
		{
			//if current_station is 531, the current_station becomes 1602
			if (GetCurrent_station() <= kWorldMin)
			{
				SetCurrentStation(kWorldMax);
			}
			else
			{
				SetCurrentStation((GetCurrent_station() + kWorldDown));
			}
		}
	}
	/*
	* METHOD : ~PioneerWorld()
	* DESCRIPTION : Destructor used to destroy the PioneerWorld object
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual ~PioneerWorld()
	{
		printf("\nDestroying Pioneer XS440-WRLD Radio");
	}
};


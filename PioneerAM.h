/*
* FILE : PioneerAM.h
* PROJECT : PROG1385 - Assignment #4
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION : This file hold's the class of the PioneerAM.h
*/

#include "PioneerCarRadio.h"
#pragma once

/*
* NAME : PioneerAM
* PURPOSE : The PioneerAM class mimics the functionality of the pioneerCarRadio, but instead only uses the AM freaquency instead of the
* FM as well. This is done by overriding the toggleFrequency method by not doing anything.
*/
class PioneerAM : public PioneerCarRadio
{
public:
	/*
	* METHOD : PioneerAm() consturctor
	* DESCRIPTION : The constructor for the PioneerAm object. It sets the radio's name to the appropriate name
	* PARAMETERS : bool on : used to set weather or not the radio is turned on or off
	* RETURNS : void
	*/
	PioneerAM(bool on) : PioneerCarRadio(on)
	{
		SetRadioName("Pioneer XS440-AM");
	}
	/*
	* METHOD : ~PioneerAM()
	* DESCRIPTION : used to destroy the PioneerAM radio
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual ~PioneerAM()
	{
		printf("\nDestroying Pioneer XS440-AM Radio");
	}
	/*
	* METHOD : ToggleFrequency()
	* DESCRIPTION : Overridden function that does nothing, that way there is no option to switch to the fm frequency. 
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual void ToggleFrequency(void)
	{

	}
	/*
	* METHOD : Overridded function from PioneerCarRadio used to only display the AM frequecny
	* DESCRIPTION :  void
	* PARAMETERS : void
	* RETURNS : void
	*/
	virtual void ShowCurrentSettings(void)
	{
		while (1)
		{
			printf("%s\n", GetRadioName().c_str());
			if (GetPower())
			{
				printf("Radio is on \n");
				printf("Volume: %d\n", GetVolume());
				printf("Frequency: %s\n", GetFrequency());
				printf("Current Station: %.1f %s\n", GetCurrent_station(), GetFrequency());

				printf("AM Buttons:\n");
				for (int i = 0; i < 5; ++i)
				{

					printf("%d) %6d ", i + 1, GetButton(i)->AMFreqs);
				}
			}
			else if (!GetPower())
			{
				printf("Radio is off. \n");
			}
			KeyPress();

			if (GetTerminateRadio())
			{
				break;
			}
			system("cls");
		}
	}
};




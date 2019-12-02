/*
* FILE : PioneerCarRadio.cpp
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION :
* The Method's within this file are created to help replicate the use of a car radio. The data members are all inherited from AmFmRadio.
*/


#include "PioneerCarRadio.h"
#pragma once

/*
* METHOD : PioneerCarRadio(bool on)
* DESCRIPTION : This is the constuctor for the PioneerCarRadio object. It inherits from the AmFmRadio. It's name is set with the SetRadioName method.
* PARAMETERS : bool on : this determins weather or not the radio is turned on or off
* RETURNS : void
*/
PioneerCarRadio::PioneerCarRadio(bool on) : AmFmRadio(on)
{
	SetRadioName("Pioneer XS440");
	TerminateRadio = false;
}
/*
* METHOD : GetTerminateRadio
* DESCRIPTION : This get the status of the radio, to determine weather or not the radio object is to be destroyed
* PARAMETERS : void
* RETURNS : bool : the radio is either to be terminated (true) or not (false)
*/
bool PioneerCarRadio::GetTerminateRadio(void)
{
	return TerminateRadio;
}
/*
* METHOD : SetTerminateRadio
* DESCRIPTION : This is to set wheater or not the radio is to be terminated
* PARAMETERS : bool newTerminateRadio : the new status for the radio to be destroyed or not
* RETURNS : void
*/
void PioneerCarRadio::SetTerminateRadio(bool newTerminateRadio)
{
	TerminateRadio = newTerminateRadio;
}
/*
* METHOD : KeyPress
* DESCRIPTION : This is what allows the user to interact with the radio in "real time". It uses getch() to figure out what key
* was pressed from the user, then passed through a switch case it then determines what to do.
* PARAMETERS : void
* RETURNS : void
*/
void PioneerCarRadio::KeyPress(void)
 {
	int buttonPress =	0;
	buttonPress		=	getch();
	if (GetPower())
	{
		if ((buttonPress == '1') || (buttonPress == '2') || (buttonPress == '3') || (buttonPress == '4') || (buttonPress == '5'))
		{
			SelectCurrentStation(buttonPress - kAsciiNegative);
		}
		if ((buttonPress == '!') || (buttonPress == '@') || (buttonPress == '#') || (buttonPress == '$') || (buttonPress == '%'))
		{
			if (buttonPress == '!')
			{
				SetButton(0); // button 1
			}
			else if (buttonPress == '@')
			{
				SetButton(1); // button 2
			}
			else if (buttonPress == '#')
			{
				SetButton(2); // button 3
			}
			else if (buttonPress == '$')
			{
				SetButton(3); // button 4
			}
			else if (buttonPress == '%')
			{
				SetButton(4); // button 5
			}

		}
	}
	switch (buttonPress)
	{
	case kPower:
		PowerToggle(); 
		break;
	case kVolUp:
		if (GetPower())
		{
			SetVolume(kVolPus);
		}
			
		break;
	case kVolDown:
		if (GetPower())
		{
			SetVolume(kVolSub);
		}
		break;

	case kScanUp:
		if (GetPower())
		{
			ScanUp();
		}
		break;

	case kScanDown:
		if (GetPower())
		{
			ScanDown();
		}
		break;

	case kSwitchBand:
		if (GetPower())
		{
			ToggleFrequency();
		}
		break;

	case kExit:
		SetTerminateRadio(true); //kill radio
		break;
	}
}
/*
* METHOD : GetRadioName
* DESCRIPTION : a accessor to get the radio name
* PARAMETERS : void
* RETURNS : string : returns the radio's name
*/
string PioneerCarRadio::GetRadioName(void)
{
	return radioName;
}

/*
* METHOD : ScanDown
* DESCRIPTION : scan the station down either by 10 for am or .2 of fm
* PARAMETERS : void
* RETURNS : void
*/
void PioneerCarRadio::SetRadioName(string newRadioName)
{
	radioName = newRadioName;
}

/*
* METHOD : ShowCurrentSettings()
* DESCRIPTION : This is an overloaded function of the parent class. This show's the settings of the radio, but also allows
* interaction with the radio with the KeyPress() function.
* PARAMETERS : void
* RETURNS : void
*/
void PioneerCarRadio::ShowCurrentSettings(void)
{
	while (1)
	{
		printf("%s\n", GetRadioName().c_str());
		if (GetPower())
		{
			printf("Radio is on \n");
			printf("Volume: %d\n",GetVolume());
			printf("Frequency: %s\n", GetFrequency());
			printf("Current Station: %.1f %s\n", GetCurrent_station(), GetFrequency());

			printf("AM Buttons:\n");
			for (int i = 0; i < 5; ++i)
			{
				
				printf("%d) %6d ", i + 1, GetButton(i)->AMFreqs);
			}
			printf("\nFM Button:\n");
			for (int j = 0; j < 5; ++j)
			{
			printf("%d) %6.1f ", j + 1, GetButton(j)->FMFreqs);
			}
		}
		else if (!GetPower())
		{
			printf("Radio is off. \n");
		}
		KeyPress(); //get the user input

		if (TerminateRadio)
		{
			break; //kill the radio
		}
		system("cls");
	}
}


/*
* METHOD : ~PioneerCarRadio()
* DESCRIPTION : the destructor for pioneer car radio
* PARAMETERS : void
* RETURNS : void
*/
PioneerCarRadio::~PioneerCarRadio()
{
	printf("\n\nDestroying Pioneer XS440");
}

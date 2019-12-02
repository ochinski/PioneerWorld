/*
* FILE : PioneerCarRadio.cpp
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION :
* The Method's within this file are created to help replicate the use of a car radio. The data members are all inherited from AmFmRadio.
*/

#include "AmfmRadio.h"
#pragma once

/*
* METHOD : AmFmRadio
* DESCRIPTION :  the constructor for the AmFmRadio. It set's all the private data members
* PARAMETERS : bool power : to determine weather or not the radio is to be set on or not
* RETURNS : void
*/
AmFmRadio::AmFmRadio(bool power)
{
	// defaulting variables
	prevStation = 0;
	savedVolume = kMinVol;
	savedSettings.AMFreqs = kMinAM;
	savedSettings.FMFreqs = kMinFM;
	displayOutput = false;
	on = power;
	//setting all button numbers to minimum
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreqs = kMinAM;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreqs = kMinFM;
	}
	//setting the stations as well as time, and starting the radio turned off
	current_station = kMinAM;
	strcpy(frequency, "AM");
	volume = kMinVol;
	}

/*
* METHOD : AmFmRadio
* DESCRIPTION :  the constructor for the AmFmRadio. It set's all the private data members
* PARAMETERS :  bool power : to determine weather or not the radio is to be set on or not
				Freqs newButton[kNumberOfButtons] : an array of structs of type freqs
* RETURNS : void
*/
AmFmRadio::AmFmRadio(bool on, Freqs newButton[kNumberOfButtons])
{
	// defaulting variables
	prevStation = 0;
	savedVolume = kMinVol;
	savedSettings.AMFreqs = kMinAM;
	savedSettings.FMFreqs = kMinFM;
	displayOutput = false;

	//setting all button numbers to minimum
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreqs = kMinAM;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreqs = kMinFM;
	}
	//setting the stations as well as time, and starting the radio turned off
	current_station = kMinAM;
	strcpy(frequency, "AM");
	volume = kMinVol;

	on = false;
}
/*
* METHOD : PowerToggle
* DESCRIPTION : This function is used to turn the power on or off for the radio. It also stores 
the values of volume and the current stations so when the power is toggled on, it will return to 
the same last station
* PARAMETERS : Void
* RETURNS : void
*/
void AmFmRadio::PowerToggle()
{
	//	save the current station to "prevStation" to retrieve it later 
	prevStation = current_station; 

	//	if radio is off turn in ON
	//	set the volume to the value stored within "savedvolume".
	//	get the station to set it to from prevStation
	if(!GetPower())
	{
		on = true;
		volume = savedVolume; 
		current_station = prevStation;
	}
	// is it is on turn it OFF
	// save the volume setting
	// set the new volume to lowest possible (0) then save the current station
	else if (GetPower())
	{
		on = false;
		savedVolume = volume;
		volume = kMinVol;
		prevStation = current_station;
	}
}

/*
* METHOD : SerCurrentStation
* DESCRIPTION : This mutator method is used to set the current station to the new desired station
* PARAMETERS : Void
* RETURNS : 0 if it didnt change, 1 if it did change
*/
int AmFmRadio::SetCurrentStation(double newStation)
{
	int retCode = 0;
	if (strcmp("AM", frequency) == 0)
	{
		if (newStation > kMinAM && newStation < kMaxAM )
		{
			current_station = newStation;
			retCode = 1;
		}
	}
	else 
	{
		if (newStation > kMinFM && newStation < kMaxFM)
		{
			current_station = newStation;
			retCode = 1;
		}
	}		
	return retCode;
}


/*
* METHOD : SetVolume
* DESCRIPTION : Set the volume of the amfm radio from the user. Check to make sure valid entery was inputed.
* PARAMETERS : Void
* RETURNS :  0 if it didnt change, 1 if it did change
*/
int AmFmRadio::SetVolume(void)
{
	char buf[20] = "";
	int retCode = 0;
	if (GetPower())
	{
		//display output if display is true
		if (displayOutput == true)
		{
			printf("\nEnter the volume level (0 - 100). ");
		}

		//get user input, store in buffer
		//then convert it into a int
		fgets(buf, sizeof buf, stdin);
		volume = atoi(buf);

		if (volume < kMinVol) //if user enters volume less than 0, volume = 0
		{
			volume = kMinVol;
			retCode = 1;
		}

		if (volume > kMaxVol) //if user enters volume greater than 100, volume = 100
		{
			volume = kMaxVol;
			retCode = 1;
		}
	}
	return retCode;
}
/*
* METHOD : SetVolume
* DESCRIPTION : Set the volume of the amfm radio from the user. Check to make sure valid entery was inputed.
* PARAMETERS : int volume: pass through a new volume
* RETURNS :  0 if it didnt change, 1 if it did change
*/
int AmFmRadio::SetVolume(int newVolume)
{

	char buf[20] = "";
	int retCode = 1;
	if (GetPower())
	{
		volume += newVolume;
		//display output if display is true
		if (displayOutput == true)
		{
			printf("\nEnter the volume level (0 - 100). ");
		}
		//get user input, store in buffer
		//then convert it into a int
		/*fgets(buf, sizeof buf, stdin);
		volume = atoi(buf);*/

		if (volume < kMinVol) //if user enters volume less than 0, volume = 0
		{
			volume = kMinVol;
			retCode =  0;
		}

		if (volume > kMaxVol) //if user enters volume greater than 100, volume = 100
		{
			volume = kMaxVol;
			retCode = 0;
		}
	}
	return retCode;
}
/*
* METHOD : ToggleFrequency()
* DESCRIPTION : Switch from AM to FM frequency. Store frequency's to retrieve when switching back to them
* PARAMETERS : int volume: pass through a new volume
* RETURNS :  0 if it didnt change, 1 if it did change
*/
void AmFmRadio::ToggleFrequency()
{
	//If it's AM then switch it to FM. Store the current station to struct saveSettings.
	//change FM stations to the saved FM station
	if (GetPower())
	{
		if (strcmp(frequency, "AM") == 0)
		{
			savedSettings.AMFreqs = (int)current_station;
			strcpy(frequency, "FM");
			current_station = savedSettings.FMFreqs;
		}
		//Switch to AM.
		//Save current station to the FM saved settings. 
		//change new AM station to the previously saved AM station
		else
		{
			savedSettings.FMFreqs = current_station;
			strcpy(frequency, "AM");
			current_station = savedSettings.AMFreqs;
		}
	}
}
/*
* METHOD : SetButton
* DESCRIPTION : save the button that was chosen by the user to the button.
* PARAMETERS : int button_num : the button number that is chosen
* RETURNS : 0 if it didnt change, 1 if it did change
*/
int AmFmRadio::SetButton(int button_num)
{
	int retCode = 0;
	//check to see if button is valid
	if( (button_num >= 0) && (button_num <= 4) )
	{
		if( strcmp("AM", frequency) == 0 )
		{
			//save button in AM to current station
			button[button_num].AMFreqs = (int) current_station;
			retCode = 1;
		}
		else
		{
			//save button in AM to current station
			button[button_num].FMFreqs = (double) current_station;
			retCode = 1;
		}
	}
	return retCode;
}
/*
* METHOD : SelectCurrentStation
* DESCRIPTION : change station to corresponding button
* PARAMETERS :	int button_num : the button number is chosen
* RETURNS :  0 if it didnt change, 1 if it did change
*/
int AmFmRadio::SelectCurrentStation(int button_num)
{
	int retCode = 0;
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", frequency) == 0)
		{
			current_station = button[button_num].AMFreqs;
			retCode = 1;
		}
		else
		{
			current_station = button[button_num].FMFreqs;
			retCode = 1;
		}
	}
	return retCode;
}

/*
* METHOD : ShowCurrentSettings
* DESCRIPTION : display the settings of the radio (bunch of outputs)
* PARAMETERS : void
* RETURNS : void
*/
void AmFmRadio::ShowCurrentSettings()
{

	if(GetPower())
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nFrequency: %s\n", frequency);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, frequency);
	printf("AM Button Settings: ");
	for( int i = 0; i < 5; ++i )
	{
		printf("%d) %6d ", i + 1, button[i].AMFreqs);
	}

	printf("\nFM Button Settings: ");
	for( int j = 0; j < 5; ++j )
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreqs);
	}
}

/*
* METHOD : ScanDown
* DESCRIPTION : scan the station down either by 10 for am or .2 of fm
* PARAMETERS : void
* RETURNS : void
*/
void AmFmRadio::ScanDown()
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 530, the current_station becomes 1700
		if (current_station == kMinAM)
		{
			current_station = kMaxAM;
		}
		//go down 10
		else
		{
			current_station = current_station - kScanAM;
		}
	}
	else
	{
		//if the current_station is 87.9, the current_station becomes 107.9
		//Note: car radios jump .2 for the FM. 
		if (current_station <= kMinFM)
		{
			current_station = kMaxFM;
		}
		else
		{
			current_station = current_station - kScanFM;
		}
	}
	if (displayOutput == true)
	{
		printf("\nCurrent station: %f %s\n", current_station, frequency);
	}
}
/*
* METHOD :	ScanUp
* DESCRIPTION : scan stations up. 10 for AM, .2 for FM
* PARAMETERS : void
* RETURNS : void
*/
void AmFmRadio::ScanUp()
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station == kMaxAM)
		{
			current_station = kMinAM;
		}
		else
		{
			current_station = current_station + kScanAM;
		}
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station >= kMaxFM)
		{
			current_station = kMinFM;
		}
		else
		{
			current_station = current_station + kScanFM;
		}
	}
	if (displayOutput == true)
	{
		printf("\nCurrent station: %f %s\n", current_station, frequency);
	}
}
/*
* METHOD : SaveCurrentStation
* DESCRIPTION : Save the freq's of AM and FM
* PARAMETERS : void
* RETURNS : void
*/
void AmFmRadio::SaveCurrentStation(double current_station, Freqs saved_station)
{
	if (strcmp(frequency, "AM") == 0)
	{
		saved_station.AMFreqs = (int)current_station;
	}
	else
	{
		strcpy(frequency, "AM");
		saved_station.FMFreqs = current_station;
	}
}

/*
* METHOD : ~AmFmRadio()
* DESCRIPTION : destuctor for AmFmRadio
* PARAMETERS : void
* RETURNS : void
*/
AmFmRadio::~AmFmRadio()
{
	printf("\nDrestroying AmfmRadio\n");
}




/*
* METHOD : GetButton
* DESCRIPTION : get the buttons from the struct
* PARAMETERS : void
* RETURNS : the start fo the button within Freq's struct
*/
Freqs* AmFmRadio::GetButton(int whichButton)
{
	return &button[whichButton];
}
/*
* METHOD : GetSavedSettings()
* DESCRIPTION : get saved settings
* PARAMETERS : void
* RETURNS : return the struct saved settings
*/
Freqs AmFmRadio::GetSavedSettings()
{
	return savedSettings;
}

/*
* METHOD : IsRadioOn
* DESCRIPTION : check to see if radio is on
* PARAMETERS : void
* RETURNS : ture if on false if off
*/
bool AmFmRadio::GetPower()
{
	return on;
}

/*
* METHOD : GetCurrent_Station
* DESCRIPTION : get the current station
* PARAMETERS : void
* RETURNS : reutn current station
*/
double AmFmRadio::GetCurrent_station()
{
	return current_station;
}

/*
* METHOD : GetFrequency
* DESCRIPTION : Get the current frecuency
* PARAMETERS : void
* RETURNS : return char frequency (AM OR FM)
*/
char* AmFmRadio::GetFrequency()
{
	return frequency;
}

/*
* METHOD :GetVolume
* DESCRIPTION :	get the current volume
* PARAMETERS :	void
* RETURNS : return the volume
*/
int AmFmRadio::GetVolume()
{
	return volume;
}

/*
* METHOD :GetDisplayOutput
* DESCRIPTION :	 get the display value
* PARAMETERS :	void
* RETURNS : return true or false if display output is on or off
*/
bool AmFmRadio::GetDisplayOutput()
{
	return displayOutput;
}

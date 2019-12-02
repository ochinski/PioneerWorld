/*
* FILE : AmFmRadio.h
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION : This file hold's the class of the AmFmRadio
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <string>
#include <new>

using namespace std;
#pragma once
#pragma warning(disable:4996)




#define kNumberOfButtons 5
#define kMaxFM 107.9
#define kMinFM 87.9
#define kMaxAM 1700
#define kMinAM 530
#define kScanAM 10
#define kScanFM .2
#define kMaxVol 100
#define kMinVol 0


struct Freqs
{
	int AMFreqs;
	double FMFreqs;
};

/*
* NAME : amFmRadio.h
* PURPOSE : The amfmRadio class has be created to accurately model the behavoir
* of a standard am/fm radio. The class has members to monitor the current station, the
* frequency, volume and weather it is on or off. Also, if allows for saving of diffrent
* stations. The amfmClass depends on weather the radio is on and off in according to the volume
* and saving the frequency when changed between am or fm, as well as if the radio is on or off.
*/

class AmFmRadio
{
/* ------------------------- */
/*        PRIVATE            */
/* ------------------------- */
private:
	Freqs	button[5];
	Freqs	savedSettings;
	double	current_station;
	char	frequency[3];
	int		volume;
	bool	on;
	bool	displayOutput;
	double prevStation;
	int savedVolume;

/* ------------------------- */
/*         PUBLIC            */
/* ------------------------- */
public:

	///toggle radio on or off
	AmFmRadio(bool on = false);
	//toogle radio on or off and the struct frequences
	AmFmRadio(bool on, Freqs newButtom[kNumberOfButtons]);

	virtual ~AmFmRadio(void);

	// accessors!
		Freqs*	GetButton(int whichButton);
		Freqs	GetSavedSettings();
		double  GetCurrent_station();
		char*	GetFrequency();
		int		GetVolume();
		bool	GetDisplayOutput();
		bool	GetPower();

	// mutaors
		int SetButton(int newButton_num);
		int SetVolume(void);
		int SetVolume(int newVolume);
		int SetCurrentStation(double newStation);
		int	SelectCurrentStation(int button_num);

	// other supporting / required method 
		void PowerToggle();
		void SaveCurrentStation(double current_station, Freqs saved_station);
		virtual void ShowCurrentSettings();
		virtual void ScanUp();
		virtual void ScanDown();
		virtual void ToggleFrequency();
		


};	 /* end of class --- */



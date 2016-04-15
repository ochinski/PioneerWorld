/*
* FILE : PioneerCarRadio.h
* PROJECT : PROG1385 - Assignment #4
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION : This file hold's the class of the PioneerCarRadio
*/



#include "AmfmRadio.h"
#pragma once

#define		kPower			'o'
#define		kVolUp			'+'
#define		kVolDown		'_'
#define		kScanUp			'='
#define		kScanDown		'-'
#define		kSwitchBand		'b'
#define		kAsciiNegative	49 //subtract 49 to get the actual value
#define		kExit			'x'
#define		Exit			1
#define		kVolPus			1
#define		kVolSub			-1
#define		kError			-500
#define		kKeyPressed		1


/*
* NAME : PioneerCarRadio
* PURPOSE : The PioneerCarRadio class is build to accuretly replicate a pioneer car radio model.
* This class inherits from the AmfmRadio and uses the functionality of a radio. The pioneerCarRadio adds new features
* allowing the user to interact with the radio in "realtime" with getch instead of typing in a number and enter.
*/
class PioneerCarRadio : public AmFmRadio
{
private:
	bool TerminateRadio;
	string radioName;
public:
	bool	GetTerminateRadio(void);
	string	GetRadioName(void);
	void	SetTerminateRadio(bool newTerminateRadio);
	void	SetRadioName(string radioName);
	PioneerCarRadio(bool power);
	virtual ~PioneerCarRadio();
	
	virtual void ShowCurrentSettings(void);
	virtual void KeyPress(void);	
};
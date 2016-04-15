/*
* FILE : ultimateRadio.cpp
* PROJECT : PROG1385 - Assignment #4
* PROGRAMMER : Robert Ochinski
* FIRST VERSION : 2016-04-08
* DESCRIPTION :
* The functions within this file are used to allow the user to create any kind of car radio's they choose. It also
* has a switch case that will allow the creation of any kind of radio chosen. 
*/

#include "PioneerWorld.h"
#define	 kTooFewArg 1

PioneerCarRadio* createRadio(char *[]);


int main(int argc, char * argv[])
{
	int retCode = 0;
	PioneerCarRadio* pRadio = NULL;
	if (argc != 2)
	{
		retCode = kTooFewArg;
	}
	else
	{
		try
		{
			pRadio = createRadio(argv);
			pRadio->ShowCurrentSettings();
			delete(pRadio);

			int buttonPress = 0;
			bool terminateProg = false;
			while (1) //endless loop to allow user to create new radio's. Program will end if user enters 'x' without starting a new radio
			{
				buttonPress = getch();
				switch (buttonPress)
				{
				case 'x':
					terminateProg = true;
					break;
				case 'c':
					pRadio = new PioneerCarRadio(false);
					break;
				case 'w':
					pRadio = new PioneerWorld(false);
					break;
				case 'a':
					pRadio = new PioneerAM(false);
					break;
				default:
					buttonPress = kError;
					break;
				}
				if (!terminateProg && buttonPress != kError)
				{
					pRadio->ShowCurrentSettings();
					delete(pRadio);
				}
				else if (terminateProg)
				{
					break;
				}
			}
		}
		catch (bad_alloc ba)
		{
			printf("%s", ba.what());
		}
		catch (string exception)
		{
			printf("exception thrown %s\n", exception.c_str());
		}
	}
	return retCode;
}




//
// FUNCTION : PioneerCarRadio* createRadio(char *argv[])
// DESCRIPTION : creates new radio depending on the switch statement. 
// PARAMETERS : taking in command line arguements. Valid arguments are "-car", "-am", "-world"
// RETURNS : PioneerCarRadio* : returns a pointer to a new object that was created 
// 

PioneerCarRadio* createRadio(char *argv[])
{
	int retCode = 0;
	PioneerCarRadio* pRadio = NULL;
	string argSwitch (argv[1]);
	size_t pos = argSwitch.find("-");
	if (pos != -1)
	{
		argSwitch = argSwitch.substr(pos);
		if (argSwitch.compare("-car") == 0)
		{
			pRadio = new PioneerCarRadio(false);
		}
		else if (argSwitch.compare("-am") == 0)
		{
			pRadio = new PioneerAM(false);
		}
		else if (argSwitch.compare("-world") == 0)
		{
			pRadio = new PioneerWorld(false);
		}
		else
		{
			throw string("invalid argument");
		}
	}
	if (pRadio == NULL)
	{
		printf("error - unable to allocate memory..\n");
		pRadio = NULL;
	}
	return pRadio;
}

# PioneerWorld
This is a radio simulator we had to create for a project.  It inherits everything from the AmfmRadio class. 
This program when compiled, can use command line arguments to choose what kind of radio to start running.
Once the radio is turned off, the controls are as follows:

 x : to exit the radio
 o : to turn it on/off
 b : to toggle band frequency (am/fm)
 + : volume up 
 _ : volume down
 = : toggle frequency up
 - : toggle frequency down
 1 - 5 : to change station to button saved
 Shift + 1 - 5 : to save station to a button

once the radio has been destroyed, you can turn on a new radio by pressed 
 w - for a pioneer WORLD radio (no fm frequency, the am frequency moves up by 9 instead of 10)
 a - for a pioneer AM radio (only am frequency)
 c - for a regular pioneer radio (both am and fm frequency)

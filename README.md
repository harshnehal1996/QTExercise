# QTExercise

# How to run the code
  1) git clone https://github.com/harshnehal1996/QTExercise.git
  2) sudo apt install -y qt5-default
  3) cd Testapp
  4) qmake Testapp.pro
  5) make
  6) ./Testapp
 
# Challenges :
  1) Figuring out where to start since QT has a vast pool of resources
  2) Creating dynamic check and uncheck buttons for bold, sub and superscript. Qt text edit
  changes text format automatically based on the cursor position. I have to figure out a
  way to change the select/unselect status button along with the format aswell. I used
  onTextFormatChanged signal provided by textEdit to handle it through a custom slot
  which select and unselects based on the signal arguments/
  3) Styling the About me page, Functionalities of tools like label, text browser where
  unknown so it took some time to go through them

# Issues :
  1) I am using a high dpi display so on a lower dpi monitor the About Me page may appear
  larger than desirable.
  2) The save option in notepad(although wasn’t part of the assignment) saves the textEdit in
  the txt file which doesn’t preserve the font and style option. Although I am aware that
  there may be an option to save it as html which I will explore later.
  3) Cannot figure out a way to organise file structure properly. Please open the project using
  QTEditor App

# Features :
  1) Options include “New”, “Save”, “Save As”, “Open”, “About Me”, “Exit”
  2) On “Exit” user is asked if he/she likes to save his work
  3) Dynamic bold, sub and superscript button
  4) Copy-paste, select-drop, sliders which all come prebuilt with QTextEdit
  5) About Me dialog box

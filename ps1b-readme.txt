/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: John Nay
OS: Ubuntu 18.04.1
Machine (e.g., Dell Latitude, MacBook Pro): Lenovo ThinkPad
Text editor: Sublime/Atom
Hours to complete assignment: 5
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I used the LFSR class that I created in ps1a to encrypt and decrypt the pixels of a  .png file. This is was accomplished by doing xor operations on the extracted color components of the file and the generating a new bit with my LFSR. 




/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I asked my professor, Charles Wilkes to clarify a few details on implementing my LFSR


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I am including the file van-gogh.png as that’s what I used for my image. The command line argument to encrypt the file is:
   $ ./PhotoMagic van_gogh.png output-file.png 01101000010100010000 16.

My program also works for pipe.png.

Finally, I am using my original file directory and makefile from ps1a for this assignment. For example , when the user types “make” in the command line my boost test file and my main.cpp will compile along with my PhotoMagic file. I also included a sub-directory with the just the necessary files to compile and execute PhotoMagic.cpp. It is titled ps1b_files and contains all the requirements for ps1a. All the necessary files “PhotoMagic.cpp, LFSR.cpp, LFSR.hpp and MakeFile” are in both directories.

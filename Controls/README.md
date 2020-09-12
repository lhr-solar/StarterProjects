# Controls System Starter Project

## Summary
The main goal of this project is to create a simplified version of the motor controller application that the Controls system is responsible for. By completing this project, you will learn the basics of Git, GitHub, CAN, Makefile, and a little bit of Python and C. 

## Motor Controller
Our car uses Tritium motor controllers which communicate to the Controls system via CAN. In order for the Tritium motor controllers to drive the motors, they need to receive a DRIVE command over CAN from the Controls system at least once every 250ms (we send it every 100ms to be safe).

## Sources of Information
The main sources of information are as follows:
- OneNote Controls section
  - Design information is under the System Design (New) page
  - There is a spreadsheet image here that specifies the proper CAN ID and message that needs to be sent
- Solar Google Drive
  - This will likely not be needed for this project but it holds valuable information regarding the car's systems
- GitHub
  - This has mostly all of the software for all of the systems that use software
  - The BPS & Controls Simulators use a similar method to pass data as this task will require. If you need an example, take a look at the BPS code since the Controls code is not as far along in the development process.
- Slack
  - If you cannot find what you are looking for, feel free to message me on Slack

## The Task
You will be provided with the link to this GitHub repository. You will need to **clone** the repository, create and checkout your own **branch**, complete the task, **push** to the remote repository, and open a **pull request**. The actual task is comprised of the following steps:

1. Develop code in ```MotorController.c``` that will send the appropriate message across the CAN bus in a simulated fashion. This means it will write to the CAN.csv file with the following format: ```0xCAN_ID, CAN_MESSAGE```. It should accept both the ```CAN_ID``` and the ```CAN_MESSAGE``` as parameters. 

2. Use the ```MotorController.h``` file to expose that written API by writing the function prototypes and then #including it in ```main.c``` and ```MotorController.c```.

3. Create a main loop in ```main.c``` that calls the function written in ```MotorController.c``` at a set time interval (the main loop will be an infinite while loop). There must be some sort of delay (it can just be a simple for loop that does nothing for a lot of iterations). The specific amount of time that delay comprises will vary based on machine so that is not important.

4. Create a ```Makefile``` that compiles both the C files using ```gcc```. It should create object files and an executable (all of which you should add to the ```.gitignore```).

5. Write a python script that reads from the CAN.csv file and displays the ID and message to the console in the following format: ```ID: 0x... Message: ...``` on an infinite loop. 

6. Finally, to ensure that the system is working correctly, write a test main function in ```main.c``` that will send a random number as the message each time. This way, we know that the CSV file is being updated properly.

## Tips
- Make sure to commit frequently. Not every time you save a file, but enough to show a good history of your work.
- Make sure you are working on your own branch and not the master branch.
- If you have any questions that cannot be answered by the resources above or the task instructions, feel free to ask.
- Do good Git Stuff

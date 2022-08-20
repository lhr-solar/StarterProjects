# Controls System Starter Project
## Summary
The main goal of this project is to exercise the skills you may have learned through LHR Solearns. This includes basic C programming, Git, and Github usage.

## Installation and Setup
Please refer to the installation guide provided on the [main Controls repository](https://github.com/lhr-solar/Controls/blob/master/README.md). Then, clone this repository using
```
git clone --recurse-submodules https://github.com/lhr-solar/StarterProjects.git
```

Make sure you are in the StarterProjects/Controls directory and run the *rtprio-setting.sh* file in your terminal. The script will set your realtime priority to be unlimited and allow the RTOS simulator to run:
```
sudo ./rtprio-setting.sh
```

Now, reboot your linux VM. Make sure your realtime priority limit has been set with:
```
ulimit -r
```
This should return *unlimited*. If it does not, ask someone for help or try the script again.

Create a branch for yourself after cloning the repository.
```
git checkout -b <your name>
```
All of your work will be on this branch.

## The Mission
In this starter project, you will be writing a mailbox and a cafe in the simulation version of the same Real-Time Operating System (RTOS) that runs on the car: the Micrium uCOS-III.

### Mailbox
The mailbox consists of the mailbox flag and the mailbox contents, both declared in ```Tasks.h```.
1. Write the Mailman task in ```Mailman.c``` to put a unique message in the mailbox. The mailbox is simply a string (character array). Use the mailbox flag semaphore to prevent simultaneous access of the mailbox.
2. Write the Recipient task in ```Recipient.c``` to print out the unique message in the mailbox. Use the mailbox flag semaphore to prevent simultaneous access of the mailbox.
3. Write the test file ```Tests/Test_Mail.c```. This test file should create any semaphores, tasks, or variables necessary to run both the Mailman and Recipient tasks.
4. To run the code, first compile with:
	```
	make all TEST=Mail
	```
	If this does not work or if you run into any issues, try ```make clean``` (this will remove any object files you just compiled) and recompile.

### Cafe
The cafe consists of the menu, item costs, and revenue, as well as the register occupied mutex. These are all declared in ```Tasks.h```
1. Write the Customer1 and Customer2 tasks in ```Customer1.c``` and ```Customer2.c``` to purchase the appropriate items on the menu, as well as increment the revenue appropriately. Take note that ```Customer1.c``` asks you to use **pointer math** to access items in arrays, while ```Customer2.c``` wants you to use **regular array indexing**.
2. Make sure you use the register occupied mutex to prevent simultaneous usage of the register.
3. Write the test file ```Tests/Test_Cafe.c```. This test file should create any semaphores, tasks, or variables necessary to run both Customer tasks.
4. To run the code, first compile with:
	```
	make all TEST=Cafe
	```
	If this does not work or if you run into any issues, try ```make clean``` (this will remove any object files you just compiled) and recompile.

Once you're done testing and verifying your code, please make sure the latest copy of your code is committed and create a pull request on github linked to your branch. Request somebody to review your code.

## Tips
- Make sure to commit frequently. Not every time you save a file, but enough to show a good history of your work.
- Make sure you are working on your own branch and not the master branch.
- If you have any questions that cannot be answered by the resources above or the task instructions, feel free to ask.

## Links
[Learn about mutexes and semaphores here.](https://www.youtube.com/watch?v=8wcuLCvMmF8)

Our team uses the Micrium microcontroller real-time operating system. Be sure to use the [Micrium OS documentation](https://www.analog.com/media/en/dsp-documentation/software-manuals/Micrium-uCOS-III-UsersManual.pdf) as a reference for this starter project, especially when using OS features such as mutexes, semaphores, tasks, etc.

If you want to learn about how the makefile compiles your code: [Makefile tutorial](https://makefiletutorial.com/)

Use the [Main Controls Repository](https://github.com/lhr-solar/Controls) as a reference for your code. Specifically, I suggest looking at the *Apps* and *Tests* directories.

Feel free to research/google anything else relevant to Solar or this starter project, or ask your system lead/another member for help.

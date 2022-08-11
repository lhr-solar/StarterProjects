# Controls System Starter Project
## Summary
The main goal of this project is to exercise the skills you may have learned through LHR Solar lessons. This includes basic C programming, Git, and Github usage.

## Installation and Setup
Please refer to the installation guide provided on the [main Controls repository](https://github.com/lhr-solar/Controls/blob/master/README.md). Then, clone this repository using
```git clone --recurse-submodules https://github.com/lhr-solar/StarterProjects.git```

Make sure you are in the StarterProjects/Controls directory and run the *rtprio-setting.sh* file in your terminal. The script will set your realtime priority to be unlimited and allow the RTOS simulator to run:
```sudo ./rtprio-setting.sh```

Now, reboot your linux VM. Test the simulator by running these commands:
```
make all
./controls-simulator.out
```

Initially, the error code should be **24204**. This is because you haven't created any tasks yet.

## The Mission



[Learn about mutexes and semaphores here.](https://www.youtube.com/watch?v=8wcuLCvMmF8)

Our team uses the Micrium microcontroller real-time operating system. Use the [Micrium OS documentation](https://www.analog.com/media/en/dsp-documentation/software-manuals/Micrium-uCOS-III-UsersManual.pdf) as a reference for this starter project.

Feel free to research/google anything else relevant to Solar or this starter project, or ask your system lead/another member for help.

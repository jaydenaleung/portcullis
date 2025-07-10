---
title: "Portcullis"
author: "Jayden Leung (Hack Club Slack: loliipoppi)"
description: "Automatic remote locking and unlocking system for home security door reinforcement locks moving along two conflicting axes."
created_at: "2025-07-01"
---

# Time Spent
- **Total hours: h**
- **Total days: days**
- **Time spent on CAD: h**
- **Time spent on PCB design: h**
- **Time spent on coding: h**
- **Time spent on physical assembly: (not yet completed)**
- **Time spent on sourcing parts, writing journal and readme, etc.: h**


# Prior Work

Originally, this project was called the "Keypad Autolock" when I worked on it before Highway. **However, I didn't have much of the project complete before Highway, so I decided that this could likely count for a project submission after consulting with others in the Slack.** Specifically, I had the case for the keypad, a model of the lock, a housing for the servo, and ideas for a linear actuator, among others, in place before Highway. **When I began this project for Highway, I still spent time doing research to figure out the most effective ways to navigate this mechanical engineering problem. I have still spent a significant amount of time in CAD, and I haven't done any prior PCB design work or firmware coding on this prior to Highway.**

The Keypad Autolock, now Portcullis (meaning the waffle-like iron gates that historically guarded castle doors following the drawbridge), is designed to open home security door reinforcement locks (HSDRLs) remotely using a keypad on the other side of the door. Alternatively (maybe in the future), I'm hoping that I can integrate remote connectivity to unlock and lock it from my phone.

**Total time spent (prior to Highway): 7h**


# July 1: Research

Prior to starting the project, I made sure to do my research. An HSDRL is a two-stage lock; it must first be pulled outwards and, after, rotated to be unlocked. However, the reason they were so secure - and difficult to unlock/lock with a mechanical design - is that these two axes were not the same. Consider an XYZ space with the Z axis pointing up/down and the XY plane lying flat. The HSDRL must first be pulled linearly along either the X/Y axis (a 'flat' axis) and then be rotated about the Z axis. This makes designing a remote locker/unlocker difficult as there needs to be two parts to the design. This also makes this project highly mechanical.

![67695ae9-2831-491d-8d26-9c6d92e1358c __CR0,0,970,600_PT0_SX970_V1___](https://github.com/user-attachments/assets/0a5fcd61-4e29-4be8-862f-dba296da0108)

From my prior work, I already had an idea of how it might work, but I wanted to see if there were more effective ways to go about it. I finally settled on the method that made the most sense to me. This was to incorporate a linear actuator to push the lock outwards and then rotating the lock with a servo. Below is the finished CAD design (the research was done beforehand, the diagram is just there to visualize the system better), which illustrates the above explanation. I also realized halfway through designing it that I overcomplicated the design and that the entire linear actuator part could be simplified by having the screw go through the U-shaped part and locking the U-shaped part's ability to rotate. However, I didn't want my work to go to waste, so I decided to continue, which also benefitted me in allowing me to learn more about springs and linear guide rails.

![Screenshot 2025-07-07 at 4 30 50 PM](https://github.com/user-attachments/assets/a28ab495-f1e5-4a06-bd02-e06de91af335)

**Total time spent: 1h**


# July 1-7: CAD

Then came the bulk of the project - CAD. Since this was a mechanically heavy project, I spent a good amount of time - about a week - on this part. Below is an in-depth explanation:

Keypad frame and housing:
- Housing box for the keypad, LCD, and PCB on the other side of the door
- Includes mounting holes on the housing and a hole for wires to exit the housing and travel under the door and to the Arduino microcontroller

![Screenshot 2025-07-07 at 4 32 23 PM](https://github.com/user-attachments/assets/dca403ce-5854-4b59-8bca-e5c50b6bc782)

Inside button:
- Button mounted on the side the lock is on
- User can lock/unlock without needing the password by pressing the button

PICTURE

Linear actuator: 
- Uses a continuous micro servo attached to a screw
- The housing for the servo allows it to slide linearly and includes a nut
- When the screw turns, it interacts with the nut and pulls itself and the servo forward
- The screw also touches (but is not connected to) the U-Pusher, a U-shaped part which pushes the lock linearly when the servo extends - this is the first step to unlocking the lock
- The U-Pusher and the servo housing are independent of each other and are not connected
- The U-Pusher and the servo housing are connected to a linear guide rail which allows the U-Pusher to slide closer and farther from the servo housing as the screw pulls forward/backward
- Springs are mounted to the U-Pusher and servo housing to keep the screw and U-Pusher together but not physically connected (implemented for when the screw retracts)

![Screenshot 2025-07-07 at 4 33 00 PM](https://github.com/user-attachments/assets/407c2db1-8fc6-42ee-89f0-00d818c90d12)

Rotational device:
- A cap is mounted onto the lock with two prongs extending upwards
- Another cap with one prong extending downward is mounted onto a positional servo and sits just to the side of the cap on the lock
- When the linear actuator pushes the lock, the prongs on both caps slide into place, next to each other
- The positional servo then turns the lock ~100° to fully unlock it
- (The linear actuator then retracts the screw to fix the lock into the unlocked position)

![Screenshot 2025-07-07 at 4 36 20 PM](https://github.com/user-attachments/assets/84ec5246-2932-4754-910b-601cb0af9950)

Microcontroller housing:
- A small box houses the microcontroller, where all of the wires feed to
- Also houses a battery pack that powers the Arduino
- It also might house a PCB because there are not enough native ground/5V ports on the Arduino

PICTURE

**Total time spent: 12h**


# July 7: PCB and Wiring

After I finished CADing, I moved onto PCB design. Now, after I finished designing my entire two-part PCB, I realized that it was much too impractical to even install one; in other words, I'd just wasted hours of my time. However, I wouldn't say it was entirely wasted, since I learned some valuable lessons:

One, think before you do! I tried this out when I was in the middle of designing the PCB late at night and realized what I was doing would overcomplicate the design and that there was a much simpler, faster, and more effective way to design my PCB. Two, I gained more experience and practice in PCB design, drawing footprints, etc. I found KiCAD's array feature which helped me to add multiple of the same type of through hole at once, saving me a lot of time and effort. Three, I needed a schematic anyway, and it helped me with my wiring diagram that I ended up making instead.

The PCB was not needed since different parts were on different sides of the door, and besides, even the servos that were on the same side were physically separated. It didn't make sense to have a PCB since I could not effectively mount all the parts. Instead, I would pass the wires under the door and plug them into the Arduino microcontroller, making sure to solder the 5V wires together and to secure the pins so that they wouldn't move.

Here's the schematic that I made:
PICTURE

Here's the PCB that I made (I saved it anyway):
![Screenshot 2025-07-08 at 2 15 36 PM](https://github.com/user-attachments/assets/fa000475-841b-4df9-b171-33b08540dd2a)

Here's the wiring diagram that I'll be using:
![unnamed](https://github.com/user-attachments/assets/f15fd83a-2a37-4e81-b933-9770a15415c7)

**Total time spent: 4h**


# July 8: Additional CAD

Usually, this would be the step where I would make changes to my CAD design to incorporate the PCB I just created. However, since a PCB wasn't needed for this project, I instead took this time to create a housing for my microcontroller, which also included a button I forgot to account for earlier. This button would also lock and unlock the door without needing a password (since it would be behind the door).

PICTURE

As you can see, I got a bit carried away in designing the case. I found a text FeatureScript in Onshape (a program that allowed me to add text into my CAD model), which would have been really helpful for my other hackpad project (I spent about an hour writing the text by hand using lines and curves). After that, I decided to make the case look like a real, medival portcullis, and I also wanted to include the button in the middle. It was nice to learn how to incorporate aesthetics in my CAD designs, though!

Additionally, I fixed up a few minor details with the servo housing and its cover. I also moved the hole in the keypad housing for the wires to pass out of to the bottom so I could attach my wire cover directly to the case.

**Total time spent: 5h**


# July 9-10: Firmware Coding

For the final piece of designing this project, I coded the firmware. It consisted of a few different parts: controlling the servos and the locking mechanism, the keypad logic to decide when to unlock or lock it, and updating the UI on the LCD. Coding the mechanical control of the servos wasn't too difficult except that I needed to get the angular speed of my continuous servo empirically, and I did not have the tools to do that at the moment. Instead, I went with 130 RPM, which is what the internet said was its max speed.

After that, I coded the keypad logic, which surprisingly was not as difficult as I imagined. Many conditionals, yes, but nothing too complicated. '*' meant clear the PIN, '#' meant enter, and everything else - including letters A-D and numbers 0-9 - was fair game for the PIN. However, the code began to get messy after I added in LCD text and LED light logic on top of that. But a few void-type functions for organization easily cleaned it up.

I thought I was finished, but it turned out that I had forgotten to include code for the LED light-up button on the inside of the door that allowed me to unlock and lock it without a passcode. It took me a few tries and some help from ChatGPT before I could get edge detection down, but I finally finished the program in 189 lines.

**Total time spent 4h**
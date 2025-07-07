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

PICTURE

From my prior work, I already had an idea of how it might work, but I wanted to see if there were more effective ways to go about it. I finally settled on the method that made the most sense to me. This was to incorporate a linear actuator to push the lock outwards and then rotating the lock with a servo. Below is the finished CAD design (the research was done beforehand, the diagram is just there to visualize the system better), which illustrates the above explanation. I also realized halfway through designing it that I overcomplicated the design and that the entire linear actuator part could be simplified by having the screw go through the U-shaped part and locking the U-shaped part's ability to rotate. However, I didn't want my work to go to waste, so I decided to continue, which also benefitted me in allowing me to learn more about springs and linear guide rails.

PICTURE

**Total time spent: 1h**


# July 1-7: CAD

Then came the bulk of the project - CAD. Since this was a mechanically heavy project, I spent a good amount of time - about a week - on this part. Below is an in-depth explanation:

Keypad frame and housing:
- Housing box for the keypad, LCD, and PCB on the other side of the door
- Includes mounting holes on the housing and a hole for wires to exit the housing and travel under the door and to the Arduino microcontroller

PICTURE

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

PICTURE

Rotational device:
- A cap is mounted onto the lock with two prongs extending upwards
- Another cap with one prong extending downward is mounted onto a positional servo and sits just to the side of the cap on the lock
- When the linear actuator pushes the lock, the prongs on both caps slide into place, next to each other
- The positional servo then turns the lock ~100° to fully unlock it
- (The linear actuator then retracts the screw to fix the lock into the unlocked position)

PICTURE

Microcontroller housing:
- A small box houses the microcontroller, where all of the wires feed to
- Also houses a battery pack that powers the Arduino
- It also might house a PCB because there are not enough native ground/5V ports on the Arduino

PICTURE

**Total time spent: 12h**
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

Then came the bulk of the project - CAD. Since this was a mechanically heavy project, I spent a good amount of time - about a week - on this part.

**Total time spent: h**
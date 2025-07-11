# Portcullis - the boltlock unlocker

A portcullis originally guarded a castle's entrance, known for its waffle-like iron gates coming down to cover the entrance of the castle's archway following the moat bridge.
-

Portcullis is an automated system that mechanically unlocks home security door reinforcement locks (HSDRLs), with access protected by a passcode using a keypad. HSDRLs act as boltlocks when mounted onto the doorframe next to the door being locked. See below for more information.

<img height="450" src="https://github.com/user-attachments/assets/94c1541d-03f8-46f5-a136-9490aab7b6f0" />
<img height="450" src="https://github.com/user-attachments/assets/3ccbe4f9-8308-4504-a4ca-c6801535a208" />

*The large block in the picture represents the wall that HSDRLs are mounted onto.*

<img height="900" alt="image" src="https://github.com/user-attachments/assets/8ac93096-7205-4f41-b9af-5183600e3394" />

*A medival portcullis. Credit: [https://www.dreamstime.com/stock-images-castle-portcullis-image7831724](url).*


# Figures

**Total Minimum Cost:** $43 USD

**Total Hours Spent:** 30 hrs

**Total Days Spent:** 10 days

*See JOURNAL.md and the BOM below for an in-depth explanation of these numbers.*


# How It Works

How do HSDRLs work?
-

HSDRLs lock a door by acting as a fixed stopper. In combination with this, their tough metal material allows it to be one of the strongest, safest, and most secure locks on the market. After turning them to their locked position, they will 'click' into place, effectively fixing itself against the door. Mechanically, this means that when the door pushes against it, its rigid position will hold the door back. See the picture below for how unlocking and locking an HSDRL works.

PICTURE

Portcullis
-

This specific mechanism works to solve this issue in three steps: one, using a linear actuator to push the HSDRL forward enough that it can be rotated. Two, rotate it to unlock or lock the door. Three, retract the linear actuator to lock the HSDRL in place. This is all controlled by an Arduino Uno R3 microcontroller, which connects to a continuous servo powering the linear actuator and a positional servo rotating the mechanism. Additionally, the locking/unlocking process is initiated by either entering the correct passcode on a keypad on the side of the door opposite the lock or by pressing a button (passcode not required) on the same side of the door as the lock.

<img height="450" src="https://github.com/user-attachments/assets/74bca56b-3ee4-4c82-a2ab-89780d6016b5" />

Additional Features
-

- 16x2 LCD interface to display entered PIN from the keypad
- Privacy covers when entering PIN - numbers show up as '*' instead of the entered number
- Three different possible screens for the LCD display
- Aesthetic microcontroller housing with LED lights on button
- Linear guide rails and tension springs for the linear actuator

Wiring Diagram
-

This project does not utilize a PCB because of the sparse placement of the connected parts. See this wiring diagram instead:

<img height="450" height="808" alt="image" src="https://github.com/user-attachments/assets/8e79eb41-f8b1-4f4b-ad0f-cb0adfbaf6f3" />

And this schematic:

<img height="450" alt="Screenshot 2025-07-10 165348" src="https://github.com/user-attachments/assets/61bf09af-021a-457f-b31a-9fe14c36c892" />


# The 'Why' Behind the Project

This project actually started a while ago when I wanted to ensure that no one would could come into my room without my permission, as I felt back then that it had become an issue. Using my engineering skills to solve real-world issues, I initially worked on developing my own boltlock before realizing that it would be much more efficient to just purchase a boltlock. Unfortunately, I would occasionally get locked out of my room, which was a significant issue. I again began to solve this issue by taking an engineering approach to it and working a system that could lock and unlock the boltlock for me when I was outside of my room. In addition to having a keypad, I envision pairing this mechanism with my phone so that it will be more easily accessible, especially if something happens to break or the wires to the keypad snap.


# Why This Is Worth Six Points

With the three-part unlocking/locking system mentioned earlier, this is a mechanically complex project that requires precise control of the motors in order to ensure reliability and stability. I spent many hours designing a system for this (over half of my hours spent were in CAD and research), learning a lot about linear guide rails, springs, and their standardizations, and how to effectively approach a real-life issue using engineering. Additionally, I spent a significant amount of time and effort designing logic for the keypad, LCD screens, and LED button as well as making them all work smoothly in tandem. My effort spent doing this project, seen in the thirty hours of work done in addition to prior work and excluding the process of physically building the device, qualifies this project for six points.


# Bill of Materials (BOM):

*Note: I am using Aliexpress for some and Amazon for others. Prices listed below are in USD and per part. e.g. 2x Nema 17 ($14) = $28 total. Also see the .csv file for the official BOM.*

| Quantity | Name | Price Per Part | Link | Notes |
|---|---|---|---|---|
| 2 | MGN7C linear guide rail + carriage | $12.78 | https://www.aliexpress.us/item/3256804722090559.html | 150mm length |
| 4 | M2 50pcs bolt | $1.27 | https://www.aliexpress.us/item/2255799955713291.html | 4mm, 6mm, 8mm, 10mm lengths |
| 1 | M2 50pcs nut | $1.52 | https://www.aliexpress.us/item/3256807407546447.html |  |
| 1 | M3 30pcs bolt | $1.43 | https://www.aliexpress.us/item/2255799955713291.html | 6mm length |
| 1 | M3 50pcs nut | $1.68 | https://www.aliexpress.us/item/3256807407546447.html |  |
| 1 | 10 pcs Tension spring w/ hook | $4.09 | http://www.aliexpress.us/item/3256805190632211.html | 50mm length, 0.3mm wire diameter, 5mm outer diameter |
| 2 | Pushbutton | $3.06 | https://www.aliexpress.us/item/3256807837994773.html | Red color (NOT with the power symbol), 3-6V, 19mm size, momentary type |
| 1 | 3m length wire cover | $5.39 | https://www.aliexpress.us/item/3256808858896776.html | A-White (A-type, white and red color) |
| 1 | Heat gun + Heat shrink tubes | $9.99 | https://www.aliexpress.us/item/3256807579039319.html | 1060 pcs, 110V US plug |
| 1 | Keypad | N/A | https://a.co/d/2Og2Gza | Already have this (no price). |
| 1 | LCD | $2.39 | https://www.aliexpress.us/item/3256806852105736.html | I2C LCD Green |
| 1 | Power bank + USB-B cable | N/A | Any works | Already have this (no price). |
| 1 | Positional SG90 Servo | N/A | https://a.co/d/dwwxeeT | Already have this (no price). |
| 1 | Continuous FS90R Servo | N/A | https://a.co/d/2raoKgm | Already have this (no price). |
| 1 | Jumper wires | N/A | https://a.co/d/hYEySLh | Already have this (no price). |
| 1 | 1kg spool of filament | N/A | Any works | Any color, any type. Already have this (no price). |
| 1 | Home security door reinforcement lock | N/A | https://a.co/d/iCTK5DP | Already have this (no price). |
| 1 | 330Ω resistor | N/A | N/A | Already have this (no price). |

| **Total minimum cost** | $43 |
| --------------------------------------------------- | ---- |
| **Total including shipping; sales tax (assumed ~6%); import and customs fees; etc.** | ~$75 |

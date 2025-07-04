---
title: "Thinkpad Keyboard to USB"
author: "Fionn (WheeledCord)"
description: "A PCB to allow a thinkpad laptop keyboard to be used as a USB keyboard"
created_at: "2025-07-03"
---

## 7/3/25 - 7-ish hours working.
### A little backstory:

I’ve always wanted to build one of those cyberdeck-y computers. the ones you see on reddit, crammed into a Pelican case. Problem is, most of the cool ones either skimp on the keyboard or use a generic 60% board. That’s fine for typing… if you’re a minimalist. But I need arrow keys, function keys, a proper Esc key, short enough keys to close the lid, while still being full size, and preferably something that doesn’t require me to lug around a mouse. If only there was a perfect keyboard with all those feats... Well there is! It is on the thinkpad T61. It’s compact, clicky, has a built in TrackPoint (the little red nipple thing you can use for a mouse), and it’s probably the best laptop keyboard ever made. One problem. It doesnt use USB. It uses some arcane ribbon cable protocol only Lenovo/IBM’s old motherboards understand. 


![image](https://github.com/user-attachments/assets/aab9e0a3-c339-4751-a479-a83be7046f18) (The Keyboard in question)


## The Plan
I'm gonna fix that. The goal is to design a PCB that acts as a USB adapter for a ThinkPad T61 (and probably also T60, T400, etc.) Ideally, you’d just plug the ribbon cable into this board, and out comes a USB HID signal. I don't have a T61 keyboard yet, but my good friend google should tell me the details I need. 

I found [this instructable](https://www.instructables.com/Make-a-ThinkPad-keyboard-USB-adapter-with-Arduino) from like eleven years ago. Which is not the best. I guess I can kind of use it as inspiration, but it's closed source, and uses external counters and IC, which would slow it down like crazy. I will probably use a teensy 4.0. Might be a little overkill but I'm dealing with some FPC ribbon cable with a JAE AA01B-S040VA1 receptacle. It's also used by a lot of DIY keyboard hobbyists. I found the AA01B-S040 keyboard connector used on the motherboard is available on [AliExpress](https://www.instructables.com/Make-a-ThinkPad-keyboard-USB-adapter-with-Arduino). After a ~bit~ LOT of research i've been able to make a vague parts list:
| Qty | Description |
|-----|-------------|
| 1   | Teensy 4.0 with pins and 2x7 right angle header pins |
| 4   | 0.1 µF 0603 10V 10% ceramic capacitors (C3 thru C6) |
| 2   | 2.2 µF 0603 10V 10% ceramic capacitors (C1 and C2) |
| 8   | 4.7K 0603 1% 0.1 W thick film resistors (R3 thru R10) |
| 1   | 17K 0603 1% 0.1 W thick film resistor (R12) |
| 1   | 100K 0603 1% 0.1 W thick film resistor (R11) |
| 2   | 715 Ω 0603 1% 0.1 W thick film resistors (R1 and R2) |
| 4   | BSS138 N Channel FETs Digikey part number [4530-BSS138CT-ND](https://www.digikey.com/en/products/detail/anbon-semiconductor-int-l-limited/BSS138/16708474?s=N4IgTCBcDaICwFYDMAGAtAIQMpYIxIA4BhAFTQDkAREAXQF8g) |
| 1   | [AA01B-S040](www.aliexpress.us/item/32930352581.html) connector |
| 1   | T61 keyboard (PN42T3241/42T3273) |
| 1   | Printed circuit board for schematic |

## The Start

I've been working on the schematic for about an hour. So far, I've placed the Teensy, wired power and USB, added decoupling caps, started the keyboard and TrackPoint connector wiring, built partial level shifters, added pull-ups. I'll continue this tomorrow. Hopefully I can complete the schematic by then.

## 7/3/25 - 6 hours working.
### The schematic:
![sch](https://github.com/user-attachments/assets/3a0c1622-3c18-48aa-836a-411c2d4945c5)

I started with the main johnson. The Teensy 4.0. It's a beast for its size, and good for what I'm doing. I wired in USB D+/D− lines from the connector on the left (J6), passing through a protection diode (D12), V from USB routed to the Teensy’s VIN pin (via J6 as well), and a reset circuit with a 100K pull-up on the reset line (R11) and 2.2 µF cap (C1). For power distribution and don’t-talk-to-each-other circuitry I used 0.1 µF decoupling caps (C3–C6) near VCC pins and 2.2 µF caps (C1, C2) for big energy social distancing. Also capacitors too. The keyboard connector (J4, AA01B-S040) takes all the row/col lines straight to GPIOs. I tried to keep it neat. GPIOs 0–31 cover the matrix, plus pull-ups where needed. TrackPoint was a bit trickier. It uses a 3.3V PS/2-style interface. The Teensy runs at 3.3V logic, and so does the TrackPoint, but I wasn’t 100% sure at first. To be safe, I added four BSS138 MOSFETs (Q1–Q4) with pull-up resistors (R3–R10) to handle level shifting between the TrackPoint clock/data lines and the Teensy. It’s probably overkill, but it doesn’t hurt. There’s also a header (J10) to break out the TrackPoint lines for debugging. J2 is a soft power switch connected to a GPIO, and R1/R2 (715 Ω) are current-limiting resistors for the indicator LEDs. It's been like 6 hours of research and making this, and I'm ready to hit the sack. I'll work on the PCB tomorrow.

 

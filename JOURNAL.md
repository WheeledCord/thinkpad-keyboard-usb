---
title: "Thinkpad Keyboard to USB"
author: "Fionn (WheeledCord)"
description: "A PCB to allow a thinkpad laptop keyboard to be used as a USB keyboard"
created_at: "2025-07-03"
---

## 7/3/25
### A little backstory:

I’ve always wanted to build one of those cyberdeck-y computers. the ones you see on reddit, crammed into a Pelican case. Problem is, most of the cool ones either skimp on the keyboard or use a generic 60% board. That’s fine for typing… if you’re a minimalist. But I need arrow keys, function keys, a proper Esc key, short enough keys to close the lid, while still being full size, and preferably something that doesn’t require me to lug around a mouse. If only there was a perfect keyboard with all those feats... Well there is! It is on the thinkpad T61. It’s compact, clicky, has a built in TrackPoint (the little red nipple thing you can use for a mouse), and it’s probably the best laptop keyboard ever made. One problem. It doesnt use USB. It uses some arcane ribbon cable protocol only Lenovo’s old motherboards understand. 

![image](https://github.com/user-attachments/assets/aab9e0a3-c339-4751-a479-a83be7046f18)

## The Plan
I'm gonna fix that. The goal is to design a PCB that acts as a USB adapter for a ThinkPad T61 (and probably also T60, T400, etc.) Ideally, you’d just plug the ribbon cable into this board, and out comes a USB HID signal. I don't have a T61 keyboard yet, but my good friend google should tell me the details I need. 

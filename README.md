# Tableturf Battle for 3ds
Always tought about the tableturf battle game from Splatoon 3 to fit just perfectly on the 3ds, tried to search if anyone had done a port before but could'nt find it, so I'm doing one myself, while I learn a new language!

Since this project is kinda big for what I want it to be, any help with the code is very welcomed! I have a general idea and planning for developing this, so if you want to be a bigger help you can send me a message on discord @caioempessoa !

---
## SETUP:
It was a bit challenging to set up the development environment on my personal computer, but it worked well on all other devices I tried. If you need help, I followed [this tutorial](https://gbatemp.net/attachments/nintendo-3ds-homebrewing-getting-started-guide-2-1-pdf.482875/) to finish the installation on my computer, and everything worked well after that.

## BUILD:
If everything is set up correctly with your devkitPro installation, you can just type `make` in your terminal on the project folder to build the project.

## TEST/RUN:
Once your project is built, you can transfer the output files to your 3DS via an SD card, FTP, or any method you prefer. 

To dev-test the files you can also:
1. Open the Homebrew Launcher on your 3DS.
2. Press "Y" to open the developer options.
3. Navigate to `devkitPro/tools/bin/` and launch `3dslink.exe`.
4. Select your built file as the argument for 3dslink.

This method provides a smoother testing experience compared to just using the SD card, and still donwloads the project to your device, so you can access it later.

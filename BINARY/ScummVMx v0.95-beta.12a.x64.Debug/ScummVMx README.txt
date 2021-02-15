This is a Demonstration Alpha, v0.93-beta.1.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
SCUMMVMx SCI Engine HiRes Support Mod!

This mod loads .png files from the Launcher defined "Extra" folder.
It does not come with any replacement graphics or games.

Files must be exactly 4x their original size or PADDED 1 transparent pixel (4 transparent pixels at 4x),
all the way around.
They should be true color and not paletted.

They should be named as follows (Case-Sensitive / Non-0-Padded):
pic.#.png
view.#.#.#.png

The original graphics can be dumped with my custom ALSO modified version of SCICompanion,
"SCICompanionX", this "X" version batch dumps views as individual cels instead of sprite sheets.
Individual Cel format is required by the HiRes Mod, and trust me exporting individual cels with
the original SCICompanion could take WEEKS of careful clicking.

Simply open your game in SCICompanionX, and in the top menu go to Tools->Extract all resources..
You will likely want to only "Generate bitmaps for pics" and "Generate bitmaps for views",
Un-checking the other options.

Currently Pics are exported as .bmp, you will need to scale them somehow to 4x and save as 
unpaletted true color .png. Views are however dumped as .png but will crash the game if not
scaled exactly 4x or padded 1 original pixel. 

I enjoy "CupScale", but only because I don't have the time to program / and redo the Art by hand in Photoshop.
I have also heard great things about GigaPixel AI.

KNOWN BUGS :
Some untested games may not work, for instance "QFG - Shadows of Darkness" (Sorry ;|)

Please feel free to track me down (Myles Johnston aka MiLO83) on YouTube / Discord / Facebook with
Questions, Positive Comments, Help, Bug Reports, Etc.

Again this is not yet finished or polished, people seem to want to try it themselves before 100% compatibility.

TUTORIALS : 
https://youtu.be/FIGgY-STMYw (PART 1)
https://youtu.be/9ce4iZALjHo (PART 2)
https://youtu.be/JxHww6Kb9o0 (PART 3)

YOU WILL NEED :
https://github.com/MiLO83/scummvmx
https://github.com/MiLO83/SCICompanionX
https://github.com/MiLO83/ArcadaAccordion

  - Myles Johnston
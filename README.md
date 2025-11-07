Calculates curves in a 3D space based on a given set of data.

![allcurves](https://github.com/user-attachments/assets/87d77f81-a9f8-42d3-8226-893bc126f279)



Explanations for everything are in their respective files. ConnectedLineSegments.txt
contains the given points and is required for the program to run.

*Running the program*

  To compile:
    "make"

  PROVIDED CLS *Make sure ConnectedLineSegments.txt is in the directory*

  To run BOTH subd and catrom on the provided CLS:
    "make run"

  To run ONLY subd on the provided CLS:
    "make runSubd"

  To run ONLY catrom on the provided CLS:
    "make runCatrom"

  GENERATED SPIRAL

  To generate spiral and run BOTH subd and catrom:
    "make runSpiral"

  To generate spiral:
    "make genSpiral"

  To run ONLY subd on the spiral: *Make sure you already used "genSpiral"*
    "make runSubdSpiral"

  To run ONLY catrom on the spiral: *Make sure you already used "genSpiral"*
    "make runCatromSpiral"


  To get rid of files:
    "make clean"

  *Un-comment out the last line of the makefile if you wish to remove the txt
  files as well*

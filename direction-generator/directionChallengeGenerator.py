#Randomly chooses directions for students to use during their Bumper sensor direction challenge.
#
#Author: Joseph Rivera; Based off python script by Bill Stanard.
#Email: jrivera@palmertrinity.org


import random
import time

#possible directions for students to follow. Should read this in from a file.
directions = ["NEWS", "NSWE", "WENS", "SWNE", "ESNW", "SNEW"]

#possible loading messages - courtesy of Sim City.
messages = ["Perturbing Matrices", "Reticulating Splines", "Retracting Phong Shader",
            "Synthesizing Wavelets", "Realigning Alternate Time Frames", "Initializing Rhinoceros Breeding Timetable",
            "Computing Optimal Bin Packing", "Compounding Inert Tessellations", "Attempting to Lock Back-Buffer",
            "Graphing Whale Migration", "Calculating Llama Expectoration Trajectory",
            "Iterating Errant Subsystems", "Projecting Law Enforcement Pastry Intake",
            "Partitioning Grid Singularities", "Fluxing Capacitors..."]

used = []
for i in range(4):
  next = random.randint(0, len(messages) - 1)
 
  while next in used:
    next = random.randint(0, len(messages) - 1)

  used.append(next)
  print(messages[next], end="")
  for i in range(0, 5):
    print(".", end="");
    time.sleep(.2)
  print(".")


print("Generating directions", end="")
for i in range(0, 5):
  print(".", end="");
  time.sleep(1)

used.clear()

print("\nDirections for test:")
print("=======================")

for i in range(0, 3):
  next = random.randint(0, len(directions) - 1)
  while next in used:
    next = random.randint(0, len(directions) - 1)
  
  print(directions[next])
  used.append(next)

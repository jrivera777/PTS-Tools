# Create random seating arrangment from given normal arrangement. No two
# students who normally sit next to one another should end up next to each other.
#
# Author: Joseph Rivera
# Email: jrivera@palmertrinity.org
# Created: 9/26/2016
#
# Program usage: python randomSeating.py <InputFile>
#   - InputFile: text file with each student name on a separate line. Names
#     above or below each other are neighbors.

import argparse
import random

def getNeighbors(population, person):
    if not population:
        raise RuntimeError("No population to find neighbors in.")
    pidx = population.index(person)

    if len(population) == 1:
        return []

    if pidx == 0:
        return population[pidx + 1:pidx+2]
    if pidx == len(population) - 1:
        return population[-2:-1]

    return [population[pidx - 1], population[pidx + 1]]


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Generate a random seating arrangement "
                                                 "such that no two students that are seated "
                                                 "next to each other in class, based on the "
                                                 "given text file, end up next to each other.")
    
    parser.add_argument("-s", "--spaced", action="store_true", help="Students should be spaced "
                                                                    "out with one seat between each")
    parser.add_argument("studentFile", help="File containing student names, each on a separate line. "
                                            "Students directly above or below each other sit next to "
                                            "each other in class.")
    args = parser.parse_args()

    #read students from    
    students_ordered = open(args.studentFile).readlines()
    students_ordered = [name.strip() for name in students_ordered]
    
    students = students_ordered[:]
    studentCount = len(students_ordered)
    
    newSeating = [] #load with new seating arangement

    #keep working until we've seated everyone
    done = False
    while len(newSeating) != studentCount:
        nextStudent = random.choice(students)
        while nextStudent in newSeating:
            nextStudent = random.choice(students)

        if newSeating: #is anyone seated?
            if len(students) != 1:
                if newSeating[-1] in getNeighbors(students_ordered, nextStudent):
                    continue
            else: #only one student left to seat. Find a safe spot to put them.
                for i in range(1, studentCount - 1):
                    neighbors = getNeighbors(students_ordered, nextStudent)
                    if newSeating[i - 1] not in neighbors and newSeating[i] not in neighbors:
                        newSeating.insert(i, nextStudent)
                        students.remove(nextStudent)
                        done = True
                        break;
        #we are only done when we've safely added the last student to the list. Otherwise,
        #we are simply adding the next student to the end of the seating list.
        if not done:
            students.remove(nextStudent)
            newSeating.append(nextStudent)

#display where each student sits, according to computer number in STEM Lab.        
for i in range(0, studentCount):
    print("Station", i + 2, "-", newSeating[i])

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

    parser = argparse.ArgumentParser()
    parser.add_argument("studentFile")
    args = parser.parse_args()

    #read students from    
    students_ordered = open(args.studentFile).readlines()
    students_ordered = [name.strip() for name in students_ordered]
    
    students = students_ordered[:]
    studentCount = len(students_ordered)
    
    newSeating = [] #load with new seating arangement

    #keep working until we've seated everyone
    while len(newSeating) != studentCount:
        nextStudent = random.choice(students)
        while nextStudent in newSeating:
            nextStudent = random.choice(students)

        if newSeating:
            if len(students) != 1:
                if newSeating[-1] in getNeighbors(students_ordered, nextStudent):
                    continue
        
        students.remove(nextStudent)
        newSeating.append(nextStudent)
        
for i in range(0, studentCount):
    print(i + 2, " - ", newSeating[i])


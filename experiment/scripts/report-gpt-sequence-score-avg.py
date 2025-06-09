#!/usr/bin/python3

##########################################################
#
# report-gpt-sequence-score-avg.py <file_project_names>
# 
##########################################################

import pandas as pd
import sys
import os

def extractData(line):
    data = line.split(";")
    del data[11]
    del data[11]
    del data[2]
    del data[1]
    del data[0]
    return data

def listDataAverage(project,file_name):
    average={}

    with open(file_name) as f:
        for line in f:
            if (project in line):
                data = extractData(line)
                if (project in average.keys()):
                    previousData = average[project]
                    newData = [float(previous) + float(new) for previous, new in zip(previousData, data)]
                    average[project] = newData
                else:
                    average[project] = data

    # Calculate the average
    previousData = average[project]
    newData = [previous / 10 for previous in previousData]
    
    return newData

def main():
    # total arguments
    n = len(sys.argv)
    if (n < 1):
        print("Usage: report-gpt-sequence-score-avg.py <file_project_names>")
        exit(1)
    else:
        file_name = sys.argv[1]

        outputFile = open(os.path.join(".", "mode-test-empty-driver", f"syntese-score-gpt-4.0-sequence-average.csv"), "w")
        outputFile.write(f"PROG;ACTIVE-OP;ALIVE-OP;EQUIVALENT-OP;SCORE-OP;ACTIVE-ALL;ALIVE-ALL;EQUIVALENT-ALL;SCORE-ALL;EXEC-TIME;#TC\n")

        with open(file_name) as f:
            for line in f:
                project = line.strip()
                print(f"Working on Project {project}")

                data = listDataAverage(project,f"mode-test-empty-driver/{project}/syntese-score-gpt-4.0-per-sequence.csv")

                outputFile.write(f"{project}")
                for d in data:
                    outputFile.write(f";{d}")
                outputFile.write(f"\n")
        outputFile.close()

if (__name__ == "__main__"):
    main()
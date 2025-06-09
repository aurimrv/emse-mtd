# Script Execution

The experimental package is available on GitHub

```
git clone 
```

After cloning, the scripts below must be executed in the order they are described, once the output of the previous script is used as input to the following.

## Test Session Creation

Script `run-research.sh`

This script creates a Proteum/IM test session for all programs in the benchmark. It creates a test session in the research mode, executing all test cases with all mutants.

```
./scripts/run-research.sh $PWD/programs files.txt
```

## Generate Test Session Variations

Script `run-one-op.sh`

This script extracts the adequate test set of a given mutation operator (one-op strategy). It creates different permutations in the adequate test set order and computes the increment in the mutation score against the one-op operator and the entire set of mutations. 

For instance, the command below uses the operator SSDL and creates 10 variations on the order of its adequate test set.

```
./scripts/run-one-op.sh $PWD/programs files.txt SSDL 10
```

After script execution, a set of subdirectories seq-1 to seq-10 contains an incremental test report for each test case, which is randomly executed incrementally.

## Generate Syntesis Report

Script `syntesis-score-one-op.sh`

./scripts/syntesis-score-one-op.sh $PWD/programs files.txt SSDL 10

After script execution, a file named `syntese-score-SSDL.csv` is created on each program folder.

## Generate Synthesis Average Report

Script `syntesis-average-score-one-op.py`

```
python ./scripts/syntesis-average-score-one-op.py $PWD/programs files1.txt SSDL 10
```

After script execution, a file named `syntese-average-score-SSDL.csv` is created in each program folder. The file contains the incremental average number of live mutants for the one-op strategy, the average mutation score, the average live mutants against all mutation operators, and the average mutation score against all mutation operators, considering each adequate test set applied incrementally.

## Generate Synthesis Incremental Test Evolution Report

Script `syntesis-average-all-incremental.py`

The results of all programs were combined, test by test, illustrating the evolution in the mutation score and the number of live mutants.

```
python ./scripts/syntesis-average-all-incremental.py $PWD/programs files.txt SSDL 0
python ./scripts/syntesis-average-all-incremental.py $PWD/programs files.txt SSDL 1
python ./scripts/syntesis-average-all-incremental.py $PWD/programs files.txt SSDL 2
...
python ./scripts/syntesis-average-all-incremental.py $PWD/programs files.txt SSDL 23
python ./scripts/syntesis-average-all-incremental.py $PWD/programs files.txt SSDL 24
```
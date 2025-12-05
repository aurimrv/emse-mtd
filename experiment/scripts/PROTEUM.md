# Proteum Execution for Data Collection


## Environment Variables
```
EXPER_HOME=<path to programs>
PROG=<test program directory name>
```

For example:

```
EXPER_HOME=$HOME/programs
PROG=boundedQueue
SESSION=S_$PROG
```

## Execution Commands

1. Compiling the code
```
cd $EXPER_HOME/$PROG
compilation=$(cat compile.txt)
$compilation
```

2. Creating the Test Session
```
test-new -S $PROG -E $PROG -C "$compilation"  $SESSION
```

2.1. Create instrumented version code
```
instrum -EE $SESSION __${PROG}
```

2.2. Compile instrumented code
```
gcc __${PROG}_inst.c  __${PROG}_pp.c driver.c -o ${PROG}_inst -w -lm -I$PROTEUMIMHOME
```

3. Generating Unit Mutants
```
functions=$(cat functions.txt | awk '{printf("-unit %s ", $1)}')
muta-gen $functions -u- 1.0 0 $SESSION
```

3.1. Generating the initial report
```
exemuta -exec -v . -trace $SESSION
report -tcase -S ${PROG}_initial $SESSION
```

4. Marking Equivalent Mutants
```
equivalents=$(cat equivalent-${PROG}.txt)
muta -equiv -x "$equivalents" $SESSION
```

5. Import test cases
```
tc=1
NTC=$(wc -l testset.txt | awk '{print $1}')
while [ $tc -le $NTC ]; 
do
   param=$(head -$tc testset.txt | tail -1)
   tcase-add -p "$param" -EE ${PROG}_inst -trace $SESSION
   tc=$((tc + 1))
done
```

6. Execute Mutants
```
exemuta -exec -v . -trace $SESSION
```

7. Generating the Report
```
report -tcase -S ${PROG}_final $SESSION
```
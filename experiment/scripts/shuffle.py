import random


def generate_random(size):
    arr = list(range(1,size+1))
    for i in range(size):
        j = random.randint(0, size-1)
        element = arr.pop(j)
        arr.append(element)
    return " ".join(map(str, arr))


def list_randomize(fileName):
    good=[]
    file = open(fileName, 'r')
    lines = file.readlines()
    for line in lines:
        good.append(line.strip())

    random.shuffle(good)

    return " ".join(good)

    
if (__name__ == "__main__"):
    import argparse
    parser = argparse.ArgumentParser(description='Shuffle test set sequency')
    parser.add_argument('--good', metavar='file', required=True,
                        help='text file with good test case numbers (one per line)')
    args = parser.parse_args()

    print(list_randomize(args.good))
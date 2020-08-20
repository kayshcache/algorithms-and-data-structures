'''
Ex1 Wk2 Daniel Lombardo (dll222)
'''
from __future__ import print_function

SIZE = 10
top_index = -1
stack = [str()] * SIZE

def is_empty():
    global top_index
    if top_index == -1:
        top_index = SIZE-1
        return True
    else:
        return False

def push(word):
    global top_index
    if is_empty():
        stack[SIZE-1] = word
    else:
        top_index -= 1
        stack[top_index] = word

def pop():
    if is_empty():
        return None
    return stack[top_index-1]

def main():
    filename = raw_input()
    global top_index
    try:
        with open(filename,'r') as input_file:
            for ln in input_file:
                for wd in ln.split():
                    push(wd)
            input_file.close()
        while top_index != SIZE:
            top_index += 1
            print(pop(), end=' ')
    except IOError as err:
        print(err)
        print('Packing up and exiting gracefully')
        exit()
    except:
        print('Error: but unknown at this time')
        exit()

if __name__=='__main__':
    main()

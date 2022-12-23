# FILE COMPARATOR
> *For when you have test cases to check but your eyes are not trustworthy*
## Why?
Because sometimes you are a Bilkent student and your outputs must match line by line, character by character.
## What?
File comparator takes two files and reads them line by line. It checks whether each line matches or not. There are a few possibilities for the output:
* Nothing: This is actually an error but you will not explicitly receive the error if you run from the terminal. Follow the [guidelines](#how) to avoid this.
* Incorrect Files: You will get this output if the files you specify are not found during the execution. The program presents a feedback on which files are missing.
* Non-matching *END_OF_FILE*s: If one file you provided has more lines than the other, the program regards files to be **completely different** and does not tell you how many lines are matching. We have strict boundaries here.
* Mismatch Report: If you were not caught by anything listed above, the program actually presents you the number of lines read, the number of matching lines and the number of mismatching lines; followed by each mismatch with their line numbers and each file's line content. If the files match completely, you will have something like this:
    > `X lines were compared. There are a total of X correct lines and 0 mismatches:`
* Note that the delimiter for the line reading is the new line character `'\n'`, meaning that empty lines are taken into account when counting. This might mean that if one of the files contain extra emtpy lines, you are in trouble :D
## How?
0. The source code is here just for those who are curious. It is not required for the app to run
1. Copy the files that you want to compare into the directory where you have `FileComparator.exe`
2. Open the terminal in that directory
3. Run the command `/.FileComparator FILE_1 FILE_2` where `FILE_1` is the name and extension of the first file—for example `output.txt`—and you can now derive what `FILE_2` is. Here, the file names are the arguments passed to the main function. If you do not provide two, the program will crash because of the lazy way I coded it (it will attempt an [illegal read operation](https://www.youtube.com/watch?v=v4tby3znOy8))
4. ***OBSERVE!***

### Note:
You needn't have the files to be compared in the same directory as the executable. You can use their relative paths. But reading the mismatch report will be more difficult if you choose to do so

## Who?
Me. You are free to do whatever you want with this code. Copy it, break it, fix it, improve it... Whatever you choose to do, I will be genuinely happy if you inform me.
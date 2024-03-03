# Wolf Tracker

## Overview

Wolf Tracker is a C++ program designed to process real-time location data of collared wolves in a park. Lydia, the researcher, uses GPS collars on the wolves, which communicate with satellites and send signals to radio antennae. Lydia collects the data for each wolf every 15 minutes over a 24-hour period, storing it in separate text files. The program's goal is to identify the longest "out-and-back" track sequence, where wolves follow a route, stop, and then backtrack on the exact same route.

## Features

- Reads and processes data from text files with timestamps, x-coordinates, and y-coordinates.
- Converts 2D coordinates to a 1D equivalent for efficient sequence identification.
- Identifies the longest out-and-back track sequence by elapsed time/number of data points.
- Reports the total sequence length along with the coordinates of the sequence.
- Handles multiple paths of equal length, reporting the first/earliest such path.

## Usage

1. **Compilation:**
   - Compile the program using a C++ compiler.
   ```bash
   g++ WolfTracker.cpp -o WolfTracker
   ```

2. **Execution:**
   - Run the compiled program, providing a text file with wolf location data as input.
   ```bash
   ./WolfTracker < wolf1.txt
   ```

3. **Input Format:**
   - The program reads data from standard input in the following format for each line:
     ```
     hh:mm x: x y: y
     ```

4. **Output Format:**
   - The program outputs the total sequence length and the coordinates of the longest out-and-back sequence.

## Example

```bash
./WolfTracker < wolf1.txt
```

## Files

1. `WolfTracker.cpp`: The main C++ source code for the Wolf Tracker program.
2. `wolf1.txt`: Sample input file containing real-time location data for a wolf.
3. `wolf2.txt`: Another sample input file with different wolf location data.

## Additional Notes

- Ensure that input files are correctly formatted with 96 data points, representing 15-minute intervals for a 24-hour period.
- The program uses arrays to store timestamps, x-coordinates, and y-coordinates for efficient processing.
- The conversion of 2D coordinates to 1D values simplifies sequence identification.

Feel free to use, modify, or contribute to this project as needed!

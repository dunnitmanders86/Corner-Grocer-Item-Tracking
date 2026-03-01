# Corner Grocer Item-Tracking Program

## Project Overview
This project is a C++ console application that analyzes grocery purchase data from a text file. The program reads item names, counts how often each item appears, and allows the user to search for specific items or display all frequencies. It also generates a backup file for data persistence.

The goal of this project was to practice file input/output, object-oriented programming, and data structures while building a practical tool that could help a store track purchasing trends and manage inventory.

## Strengths of the Project
A key strength of this project is its organization and structure. I created a GroceryTracker class to separate file processing, frequency counting, and display logic from main(), making the program easier to maintain. 

I used a map<string, int> to store item frequencies efficiently and implemented case-insensitive handling to improve usability. Clear comments and documentation headers were included to improve readability.

## Areas for Improvement
While the program functions correctly, it could be improved with stronger input validation and stronger error handling for file-related issues. It could also be expanded to support larger datasets or dynamic updates. These enhancements would improve efficiency, reliability, and scalability in a real-world setting.

## Challenges and Solutions
The most challenging part of this project was handling file input/output and making sure the item counts were accurate and case-insensitive. Small mistakes in my loops or map usage sometimes caused incorrect results, so debugging required patience and careful testing. I also had to make sure the backup file was created correctly without causing errors.

I overcame these challenges by testing the program step by step after each change instead of trying to fix everything at once. I used print statements to check values while debugging and reviewed C++ documentation to better understand how maps and file streams work. I used course materials, and trusted online like cppreference to help me with these challenges.

## Skills Demonstrated
This project strengthened my skills in object-oriented design, file I/O, and using STL containers such as map. It also reinforced the importance of writing modular, readable, and maintainable code skills that transfer directly to larger software systems and backend development.

## Maintainability
To keep the program maintainable, I used meaningful naming conventions, focused each function on a single responsibility, and separated core logic into a class instead of placing everything in main(). These design decisions make the program easier to expand, debug, and reuse in future projects.

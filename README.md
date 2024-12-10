# PyCrawler++
## Made by Jake La Raia and Henry Cussatt for CS2300
PyCrawler++ is a C++ based dungeon crawling game with randomly generated dungeons to explore, turn-based combat, and an upgrade system! After running the Python built map generation tool, you are given 3 different levels to explore, all with randomized layouts of rooms! 

Demo Video: https://www.youtube.com/watch?v=Hw6ffQpqGEw
## Modules and Concepts from CS2300
Concepts were used and applied from all four modules, including:

State-based programming from module 4, allowing for dynamic player input. This also uses concepts from module 1, having precise input validation, allowing the user to reattempt incorrect inputs with no risk of bugging/proceeding the program in an unintended way.

Is-A relationships from module 2, allowing for a general Enemy object to be differentiated into three different types, a Goblin, an Orc, and a Dragon. Each enemy has different stats, and therefore has different constructors. However the individual stats can be reached in the same way, making the Is-A relationship fitting. 

## Operating System Required
This project was built on both Mac and Windows, but final testing/compiling was performed on a Mac. Project is completely stable on Mac, but may/may not run on Windows.
No added installations are necessary.
To play, simply run mapTester.py from terminal (May require sudo privileges)

## Citations and Coding References
https://stackoverflow.com/questions/43629363/how-to-check-if-a-string-contains-a-char
https://www.w3schools.com/cpp/cpp_arrays_multi.asp 

## Points Deserved
| | 0 points | 10 points | 20 points |
|---|---|---|---|
|Concepts: Is-A or Has-A class relationship|No such C++ class relationship present in the program|Class relationship is trivial, poorly designed, and/or poorly implemented|Class relationship is designed well, implemented robustly, and used in the main program in a way that makes sense|

| | 0 points | 10 points                                  | 20 points                                          |
|---|---|--------------------------------------------|----------------------------------------------------|
|Concept: Use of multiple languages|The program only uses one language| The use of multiple languages makes sense. | The amount of work in each language is impressive. |

|                                         | 0 points                                         | 10 points                                           | 20 points                                                        |
|-----------------------------------------|--------------------------------------------------|-----------------------------------------------------|------------------------------------------------------------------|
| Concept: Use of State-based programming | The program does not use State-based programming | The use of State-based programming is not redundant | State based programming is used to substantially streamline code |

|                           | 0 points                     | 10 points                          | 20 points                                                                                                |
|---------------------------|------------------------------|------------------------------------|----------------------------------------------------------------------------------------------------------|
| Concept: Input Validation | There is no input validation | Input validation prevents crashing | Input validation prevents the user from interacting with the program in unintended ways without crashing |

|          | 0 points           | 10 points                          | 20 points                                                                      |
|----------|--------------------|------------------------------------|--------------------------------------------------------------------------------|
| Stablity | Does not build/run | Has occasional crash/infinite loop | No instances of crashing or instances where the program can no longer function |

All together, meaning the project should be worth a total of at least 100 points.
Note to graders: Project was initially started by Henry Cussatt on different github repository, but we decided to consolidate to this branch later on.
Original link with dated files: https://github.com/uvmcs2300f2024/Final-Project-hcussatt-jlaraia
import mapGen
import os
import platform
import subprocess
from subprocess import Popen, PIPE, check_output


filename = "map"
filehandle = ".txt"
for i in range(1,4):
    map = mapGen.buildMap()

    # Add padding to avoid excess testing in C++
    for row in map:
        row.append(9)
        row.insert(0, 9)
    map.append([9, 9, 9, 9, 9, 9, 9, 9, 9])
    map.insert(0, [9, 9, 9, 9, 9, 9, 9, 9, 9])
    
    file = f"{filename}{i}{filehandle}"
    with open(file, 'w') as f:
        for row in map:
            for item in row:
                if item == 9:
                    f.write(str(item))
                else:
                    f.write("(")
                    for growth in item:
                        f.write(str(growth))
                    f.write(")")
            f.write("\n")


    left = ""
    right = ""
    up = ""
    down = ""

    # 0 = north
    # 1 = south
    # 2 = west
    # 3 = east

    for row in map:
        drawRow = []
        for item in row:
                
                left = "|"
                right = "|"
                up = "-"
                down = "_"
                empty = ""

                try:
                    if 0 in item:
                        up = "~"
                    if 1 in item:
                        down = "~"
                    if 2 in item:
                        left = "~"
                    if 3 in item:
                        right = "~"
                        
                except TypeError:
                    empty = "X"
                    up = ""
                    down = ""
                    left = ""
                    right = ""
                    
                box = [f"{up}{up}{up}{empty}{empty}{empty}", 
                        f"{left}{empty} {empty}{right}",
                        f"{left}{empty} {empty}{right}",
                        f"{down}{down}{down}{empty}{empty}{empty}"]
                drawRow.append(box)


        for i in range(4):
            print()
            for square in drawRow:
                    print(square[i], end="")


# try:
#     # This is Python's way of calling the command line. We use it to compile the C++ files.
#     subprocess.check_output("g++ -std=c++17 main.cpp",stdin=None,stderr=subprocess.STDOUT,shell=True)
# except subprocess.CalledProcessError as e:
#     print("<p>",e.output,"</p>")
#     raise SystemExit

# # Depending on your OS, different executable files will be produced. Run the executable.
# if platform.system() == 'Windows':
#     p = Popen('a.exe '+str(0), shell=True, stdout=PIPE, stdin=PIPE)
#     os.remove("a.exe")
# else: # Mac and Linux case
#     p = Popen(['./a.out '+str(0)], shell=True, stdout=PIPE, stdin=PIPE)
#     os.remove("a.out")

subprocess.run(["g++", "-std=gnu++2b", "main.cpp", "Dragon.cpp", "Enemy.cpp", "Goblin.cpp", "Orc.cpp", "-o", "cpp"])

if platform.system() == 'Windows':
    subprocess.run(["./cpp.exe"])
else:
    subprocess.run(["./cpp"])

                
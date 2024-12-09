import mapGen



filename = "map"
filehandle = ".txt"
for i in range(1,4):
    map = mapGen.buildMap()
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

            
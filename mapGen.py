import random
import math

def testDirection(currentCoord, mapSize, maxGrowth, map):
    splittingPath = random.randint(0,3)
    if mapSize <= 8 and splittingPath == 0:
        splittingPath += 1
        
            
    if maxGrowth != 0:
        splittingPath = 0

    direction = []
    availableDirection = []

    # Tests north for bounds/filled
    if currentCoord[0] != 0:
        if map[currentCoord[0] - 1][currentCoord[1]] == 9:
            availableDirection.append(0)

    # Tests south for bounds/filled
    if currentCoord[0] != 6:
        if map[currentCoord[0] + 1][currentCoord[1]] == 9:
            availableDirection.append(1)

    # Tests west for bounds/filled
    if currentCoord[1] != 0:
        if map[currentCoord[0]][currentCoord[1] - 1] == 9:
            availableDirection.append(2)

    # Tests east for bounds/filled
    if currentCoord[1] != 6:
        if map[currentCoord[0]][currentCoord[1] + 1] == 9:
            availableDirection.append(3)
    
    # Repeats for how many branching paths will spawn
    for i in range(splittingPath):
        if len(availableDirection) != 0:
            random.shuffle(availableDirection)
            direction.append(availableDirection.pop())

    return direction     
                    

def buildMap(): 
    map = [[9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9],
        [9, 9, 9, 9, 9, 9, 9]]


    startingCoord = (random.randint(0,6),random.randint(0,6))
    print(f"Starting Coord: {startingCoord}")

    map[startingCoord[0]][startingCoord[1]] = 10
    for x in range(7):
            print(map[x])
    print("\n")
    endGenerated = False


    # 0 = north
    # 1 = south
    # 2 = west
    # 3 = east

    mapSize = 0
    maxGrowth = False
    currentCoord = startingCoord
    tilesToTest = []

    #while endGenerated == False:
    for i in range(40):
        print(f"Current Cord: {currentCoord}")
        growth = testDirection(currentCoord, mapSize, maxGrowth, map)

        # Only tests new pieces if maxGrowth has not been achieved
        if maxGrowth != True:
            print(f"Growth: {growth}")
            if 0 in growth:
                print("north")
                tilesToTest.append((currentCoord[0] - 1,currentCoord[1], (currentCoord[0], currentCoord[1])))
            if 1 in growth:
                print("south")
                tilesToTest.append((currentCoord[0] + 1,currentCoord[1], (currentCoord[0], currentCoord[1])))
            if 2 in growth:
                print("west")
                tilesToTest.append((currentCoord[0],currentCoord[1] - 1, (currentCoord[0], currentCoord[1])))
            if 3 in growth:
                print("east")
                tilesToTest.append((currentCoord[0],currentCoord[1] + 1, (currentCoord[0], currentCoord[1])))
        
        lastCoord = currentCoord
        shape = ""
        if currentCoord != startingCoord:
            if currentCoord[2][0] == currentCoord[0]:
                if currentCoord[2][1] < currentCoord[1]:
                    # root tile is to the left of new tile
                    # include west in growth drawing
                    growth.append(2)
                else:
                    # root tile is to the right of new tile
                    # include east in growth drawing
                    growth.append(3)
            else:
                if currentCoord[2][0] < currentCoord[0]:
                    # root tile is above new tile
                    # include north in growth drawing
                    growth.append(0)
                else:
                    # root tile is below new tile
                    # include south in growth drawing
                    growth.append(1)
        


        # If max growth is found true, finishes building board and empties tilesToTest without growing.
        if maxGrowth == True:
            while tilesToTest:

                if currentCoord[2][0] == currentCoord[0]:
                    if currentCoord[2][1] < currentCoord[1]:
                        # root tile is to the left of new tile
                        # include west in growth drawing
                        mapSize += 1
                        growth = [2]
                    else:
                        # root tile is to the right of new tile
                        # include east in growth drawing
                        mapSize += 1
                        growth = [3]
                else:
                    if currentCoord[2][0] < currentCoord[0]:
                        # root tile is above new tile
                        # include north in growth drawing
                        mapSize += 1
                        growth = [0]
                    else:
                        # root tile is below new tile
                        # include south in growth drawing
                        mapSize += 1
                        growth = [1]
                
                if map[currentCoord[0]][currentCoord[1]] == 9:
                    map[currentCoord[0]][currentCoord[1]] = growth
                currentCoord = tilesToTest.pop()
                print()
                for x in range(7):
                    print(map[x])

        if len(tilesToTest) == 0:
            for row in map:
                for item in row:
                    if item != 9:
                        if 0 in item:
                            try:
                                slot = row.index(item)
                                slotR = map.index(row)
                                if not 1 in map[slotR-1][slot]:
                                    item.pop(item.index(0))
                            except IndexError:
                                item.pop(item.index(0))
                            except TypeError:
                                item.pop(item.index(0))

                        if 1 in item:
                            try:
                                slot = row.index(item)
                                slotR = map.index(row)
                                if not 0 in map[slotR+1][slot]:
                                    item.pop(item.index(1))
                            except IndexError:
                                item.pop(item.index(1))
                            except TypeError:
                                item.pop(item.index(1))
                                
                        
                        if 2 in item:
                            try:
                                slot = row.index(item)
                                slotR = map.index(row)
                                if not 3 in map[slotR][slot-1]:
                                    item.pop(2)
                            except IndexError:
                                item.pop(item.index(2))
                            except TypeError:
                                item.pop(item.index(2))

                        if 3 in item:
                            try:
                                slot = row.index(item)
                                slotR = map.index(row)
                                if not 2 in map[slotR][slot+1]:
                                    item.pop(item.index(3))
                            except IndexError:
                                item.pop(item.index(3))
                            except TypeError:
                                item.pop(item.index(3))

                        if len(item) == 0:
                            map[slotR][slot] = 9

            print(f"Map Size: {mapSize}")
            print("Final Map: ")
            for x in range(7):
                print(map[x])
            print("\n")
            return map
            
        else:
            if map[currentCoord[0]][currentCoord[1]] != 10:
                map[currentCoord[0]][currentCoord[1]] = growth
                currentCoord = tilesToTest.pop()
            else:
                map[currentCoord[0]][currentCoord[1]] = growth
                currentCoord = tilesToTest.pop()

        mapSize += 1

        if mapSize > 8:
            logValue = mapSize - 7
            logValue = math.log10(logValue)
            print(logValue)
            
            tester = random.random()
            print(tester)
            if logValue > tester:
                maxGrowth = True

        print(f"Map Size: {mapSize}")
        print(f"Tiles to Test: {tilesToTest}")
        for x in range(7):
            print(map[x])
        print("\n")

        




        
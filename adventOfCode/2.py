n = 0
soma_mins = 0
while n < 100:
    game = input()
    game = game.split(':')
    id = game[0].split(' ')[1]
    print(id)
    set_of_colors = game[1].split(';')
    possible = True
    INF = 1000000
    red, green, blue = set(), set(), set()

    for colors in set_of_colors:
        colors = colors.split(',')
        for color in colors:
            #i want split and exclude all empty spaces
            color = color.split(' ')
            color = [x for x in color if x != '']
            if color[1] == 'red':
                red.add(int(color[0]))
            elif color[1] == 'green':
                green.add(int(color[0]))
            elif color[1] == 'blue':
                blue.add(int(color[0]))
    
    if possible:
        #get the minimum of each color and multiply
        mini = 1
        if len(red) > 0:
            mini = max(red)
        if len(green) > 0:
            mini = (mini * max(green))
        if len(blue) > 0:
            mini = (mini * max(blue))
        soma_mins += mini
    n += 1
print(soma_mins)
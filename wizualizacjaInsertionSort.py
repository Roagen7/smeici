from datetime import datetime
import pygame




random.seed(datetime.now())

lines = []

width = int(input("width: "))
height = int(input("height: "))

for i in range(0,width):
    lines.append(random.randint(0,height))

pygame.init()



screen = pygame.display.set_mode((width,height))
clock = pygame.time.Clock()



shift = 0
i = 0
j = 0

j = shift
maxValue = lines[i]
maxIndex = i




while i < len(lines) - 1:


    for j_increase in range(0,100):
        j += 1
        if j < len(lines):
            if lines[j] > maxValue:
                maxValue = lines[j]
                maxIndex = j


    screen.fill((0,0,0))
    for n in range(0,len(lines)):
        pygame.draw.line(screen,(250,250,250),(n,height),(n,height - lines[n]))

    pygame.display.update()

    if j >= len(lines):
        shift+= 1
        lines[i],lines[maxIndex] = lines[maxIndex],lines[i]
        i += 1
        j = shift
        maxValue = lines[i]
        maxIndex = i
input("                                END                           ")

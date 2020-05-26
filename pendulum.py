import pygame
import math

mass = 10
theta = 0
width = 500
height = 500
r = 200
omega = 0.001
epsilon = 0

t = 0
g = 9.81
T = 1 

amplitude = r/9/T

FPS = 60


x0 = width/2
y0 = height/4





screen = pygame.display.set_mode((width,height))
clock = pygame.time.Clock()





while True:
    t += 1 / FPS
    omega = amplitude * math.cos(2 * math.pi / T * t) / r
    

    x =  r * math.sin(theta) + x0
    y = r * math.cos(theta) + y0
    theta += omega 
    screen.fill((0,0,0))
    pygame.draw.line(screen,(250,250,250),(x0,y0),(x,y))
    pygame.draw.circle(screen,(250,0,0),(int(x),int(y)),mass) 
    clock.tick(FPS)
    pygame.display.update()

    




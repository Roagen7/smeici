import pygame
from random import randint,seed
import datetime


class Ball():
    def __init__(self,screen):
        self.radius = randint(5,20)
        seed(datetime.datetime.now())
        self.color = (randint(0,250),randint(0,250),randint(0,250))
        self.x = randint(100,1500)
        self.y = randint(100,1000)
        self.direction_x = randint(-5,5)
        self.direction_y = randint(-4,4)
        self.screen = screen
            
    def draw(self):
        pygame.draw.circle(self.screen,self.color,[self.x,self.y],self.radius)
    
pygame.init()
screen = pygame.display.set_mode((1280,720))
tick = 0
balls = []

for i in range(0,250):
    balls.append(Ball(screen))
    
while True:
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
    if tick%5 == 0:
        screen.fill((0,0,0))
    
    screen.fill((0,0,0))


    for ball in balls:
        if ball.x > 1280 or ball.x < 0:
            ball.direction_x = -ball.direction_x

        if ball.y > 720 or ball.y < 0:
            ball.direction_y = -ball.direction_y       
        
        ball.x += ball.direction_x
        ball.y += ball.direction_y
        ball.draw()    

    pygame.display.update()

    tick +=1
    pygame.time.Clock().tick(60)    



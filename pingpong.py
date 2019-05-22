import pygame
import time

class Paddle():
    def __init__(self,surface,x,y,size_x = 5, size_y = 50):
        self.surface = surface
        self.x = x
        self.y = y
        self.size_x = size_x
        self.size_y = size_y
        self.change = 0

    def draw_paddle(self):
        pygame.draw.rect(self.surface,(250,250,250),[self.x,self.y,self.size_x,self.size_y],0)

class Ball():
    def __init__(self,surface,x,y,radius = 5):
        self.surface = surface
        self.x = x
        self.y = y
        self.radius = radius
        self.velocity_x = 2
        self.velocity_y = 2

    def draw_ball(self):
        pygame.draw.circle(self.surface,(250,0,0),[self.x,self.y],self.radius,0)
    
pygame.init()
pygame.font.init()
InfoObject = pygame.display.Info()
gameDisplay = pygame.display.set_mode((int(InfoObject.current_w/2),int(InfoObject.current_h/2)))
pygame.display.set_caption("pong.py")

#some variables useful for later
game_run = True
score_1 = 0 
score_2 = 0

winner_space = 0
font = pygame.font.SysFont('Molot',30)
color = (250,250,250)
pad_1 = Paddle(gameDisplay,int(InfoObject.current_w/2) - 10,int(InfoObject.current_h/4)-25)
pad_2 = Paddle(gameDisplay,5,int(InfoObject.current_h/4)-25)
ball = Ball(gameDisplay,int(InfoObject.current_w/4),int(InfoObject.current_h/4))
cut = False
plunge = False
round_end = False

while game_run:

    #border check

    if pad_1.y < 0 or pad_1.y > int(InfoObject.current_h/2) - 50:
        fix_change = 1 if pad_1.y < 0 else -1
        pad_1.y += fix_change
    else: 
        pad_1.y += pad_1.change

    if pad_2.y < 0 or pad_2.y > int(InfoObject.current_h/2) - 50:
        fix_change = 1 if pad_2.y < 0 else -1
        pad_2.y += fix_change 
    else:
        pad_2.y += pad_2.change

    ball.x += ball.velocity_x
    ball.y += ball.velocity_y        

    #ball "physics"
    if ball.y >= int(InfoObject.current_h/2) or ball.y <= 0:
        ball.velocity_y = - ball.velocity_y

    if ball.x >= pad_1.x:
        if ball.y > pad_1.y-5 and ball.y < pad_1.y +55:
            if pad_1.change and not cut and not plunge:
                ball.velocity_x = -ball.velocity_x
                ball.velocity_y = int(ball.velocity_y*2)
                cut = True
            elif ball.y > pad_1.y +10 and ball.y < pad_1.y + 40 and not plunge:
                ball.velocity_x = -ball.velocity_x * 2
                ball.velocity_y = int(ball.velocity_y /2)
                plunge = True
            elif plunge:
                ball.velocity_x = -int(ball.velocity_x/2)
                ball.velocity_y = ball.velocity_y*2
                plunge = False
            elif cut and not pad_1.change and not plunge:
                ball.velocity_x = -ball.velocity_x
                ball.velocity_y = int(ball.velocity_y/2)
                cut = False
            else:
                ball.velocity_x = -ball.velocity_x
        else:
            round_end = True
            ball.velocity_x = -2
            ball.velocity_y = -2
            score_2 += 1
    if ball.x +5 <= pad_2.x+10:
        if ball.y > pad_2.y-5 and ball.y < pad_2.y +55: 
            if pad_2.change and not cut and not plunge:
                ball.velocity_x = -ball.velocity_x
                ball.velocity_y = int(ball.velocity_y*2)
                cut = True
            elif ball.y > pad_1.y +10 and ball.y < pad_1.y + 40 and not plunge:
                ball.velocity_x = -ball.velocity_x * 2
                ball.velocity_y = int(ball.velocity_y /2)
                plunge = True
            elif plunge:
                ball.velocity_x = -int(ball.velocity_x/2)
                ball.velocity_y = ball.velocity_y*2
                plunge = False
            elif cut and not pad_2.change and not plunge:
                ball.velocity_x = -ball.velocity_x
                ball.velocity_y = int(ball.velocity_y/2)
                cut = False
            else:
                ball.velocity_x = -ball.velocity_x
        else:
            round_end = True
            ball.velocity_x = 2
            ball.velocity_y = 2
            score_1 += 1
    #event handling    

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_run = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                pad_1.change = -5
            if event.key == pygame.K_DOWN:
                pad_1.change = 5
            if event.key == pygame.K_w:
                pad_2.change = -5
            if event.key == pygame.K_s:
                pad_2.change = 5
            
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                pad_1.change = 0
            if event.key == pygame.K_w or event.key == pygame.K_s:
                pad_2.change = 0

   #what happens when player gets a point 
    if round_end:
            ball.x = int(InfoObject.current_w/4)
            ball.y = int(InfoObject.current_h/4)
           #if this point was the 10th one, game ends
            if score_1 == 10 or score_2 == 10:
               winner = "player right" if score_1 == 10 else "player left"     
               winner_space = font.render(f"winner is {winner}",True,(250,0,0))
               score_1,score_2 = 0,0
    #drawing all the objects
    gameDisplay.fill((0,0,0))
    text_space = font.render(f"{score_1} : {score_2}",True,(250,250,250))
    gameDisplay.blit(text_space,(445,10))
    if winner_space:
        gameDisplay.blit(winner_space,(335,270))
        winner_space = 0
    pad_1.draw_paddle()
    pad_2.draw_paddle()
    ball.draw_ball()
    pygame.display.update()
    pygame.time.Clock().tick(100)
    
    if round_end:
        round_end = False
        time.sleep(3)
        

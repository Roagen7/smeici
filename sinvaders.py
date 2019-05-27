import pygame
from time import sleep

pygame.init()
pygame.font.init()

class Gun():
    def __init__(self,surface,color,x,y):
        self.width = 60
        self.height = 20
        self.change = 0
        self.velocity = 10
        self.surface = surface
        self.color = color
        self.x = x
        self.y = y
    def draw(self):
        pygame.draw.rect(self.surface,self.color,[self.x+self.width/4,self.y-self.height/2,self.width/2,self.height/2])
        pygame.draw.rect(self.surface,self.color,[self.x,self.y,self.width,self.height],0)

class Cowboy():
    def __init__(self,surface,color,x,y):
        self.radius = 25
        self.surface = surface
        self.color = color
        self.x = x
        self.y = y
        self.move = False
        
    def draw(self):
        pygame.draw.circle(self.surface,self.color,[self.x,self.y],self.radius)
 
def enemies_draw(enemies,change,change2):
    
    for enemy in enemies:
        enemy.x += change
        if change2:
            enemy.y += 10
        enemy.draw()

      

white = (250,250,250)
red = (250,0,0)
blue = (0,0,250)
green = (0,250,0)
black = (0,0,0)

screen = pygame.display.set_mode((1280,720)) 
clock = pygame.time.Clock()
font = pygame.font.SysFont('Molot',72)
GAME_LOOP = True
GAME_WIN = False
GAME_LOSE = False
shoot = False
shoot_2_mid = False
shoot_2 = False
enemy_change = 5
enemy_change_y = False

gun = Gun(screen,white,690,710)
enemies = {"row1":[],"row2":[],"row3":[],"row4":[]}



widt = 100
heit = 10
for row in enemies:
    
    for i in range(1,11):
        enemies[row].append(Cowboy(screen,green,widt*i, heit))
    heit += 60
    
        
    
while GAME_LOOP:
    
   

    gun.x += gun.change 

    #collisions

    if gun.x < 0:
        gun.x = 0
    if gun.x > 1220:
        gun.x = 1220
   
    #enemies hitbox + movement
    
    for row in enemies:
        if len(enemies[row]):  
            if enemies[row][-1].x > 1280:
                enemy_change = -5
                enemy_change_y = True
            if enemies[row][0].x < 0:
                enemy_change = 5
                enemy_change_y = True
            

            for i in range(len(enemies[row])):
                if enemies[row][i-1].y > 600:
                    GAME_LOSE = True


                if shoot and bullet_x > enemies[row][i-1].x - 30 and bullet_x < enemies[row][i-1].x + 30 and bullet_y < enemies[row][i-1].y + 60:
                    shoot = False
                    bullet_x = 0
                    bullet_y = 0
                    if len(enemies[row]) == 1: 
                        for enemy in enemies[row]:
                            enemies[row] = []        
                    else:    
                        del(enemies[row][i-1])
                        
    

    #event handling

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            GAME_LOOP = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                gun.change = -gun.velocity
            if event.key == pygame.K_RIGHT:
                gun.change = gun.velocity
            if event.key == pygame.K_SPACE and not shoot:
                shoot = True
                bullet_x = int(gun.x+gun.width/2)
                bullet_y = int(gun.y-gun.height/2) 
        
        if event.type == pygame.KEYUP:
                gun.change = 0

    
    #draw everything   
 
    screen.fill((0,0,0))

    line_change = 0
    for i in range(0,500):
        pygame.draw.rect(screen,red,[line_change,600,5,5],0) 
        line_change+=10


    if GAME_WIN:
        text_space = font.render("YOU WON",True,white)
        screen.blit(text_space,(590,20))
        pygame.display.update()
        sleep(5)
        GAME_LOOP = False
    
    if GAME_LOSE:
        text_space = font.render("YOU LOSE",True,white)
        screen.blit(text_space,(590,20))
        pygame.display.update()
        sleep(5)
        GAME_LOOP = False
    


    if shoot:
        bullet_y -= gun.velocity * 3 
        pygame.draw.circle(screen,red,[bullet_x,bullet_y],5)  
        if bullet_y < 0:
            shoot = False
    
    for row in enemies:    
        enemies_draw(enemies[row],enemy_change,enemy_change_y)
    if enemy_change_y:
        enemy_change_y = False
    
    summary = 0
    for row in enemies:
        summary += len(enemies[row]) 
    if summary == 0:
        GAME_WIN = True
    
   # print(len(enemies["row1"]))

    gun.draw()
    pygame.display.update()
    clock.tick(60)

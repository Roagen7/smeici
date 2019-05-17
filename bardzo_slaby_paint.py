import pygame
#prints instruction

instruction = """
    n - to clear page or while holding left mouse to fill entire screen with 
    the held color
    b - blue
    g - green
    r - red
    z - black
    x - white
    s - switch shape rectangle / circle
    scroll up - increase size
    scroll down - decrease size


    and of course either left or right click to draw

    thats it... have fun 

"""
print(instruction)
input("press enter to continue")

#_________initialise 
pygame.init()
infoObject = pygame.display.Info()
gameDisplay = pygame.display.set_mode((int(infoObject.current_w/2), int(infoObject.current_h/2)))
pygame.display.set_caption("pixpaint")

#constant variables
appExit = False
black = (0,0,0)
white = (250,250,250)
blue = (0,0,250)
green = (0,250,0)
red = (250,0,0)

global color
color = black
x = 0
y = 0
not_draw = False
size = 10
shape = True

#main game loop
while not appExit:
    x,y = pygame.mouse.get_pos()
    
    for event in pygame.event.get():
        print(event)
        if event.type == pygame.QUIT:
            appExit = True
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_n:
                gameDisplay.fill(color)
                pygame.display.update()
            if event.key == pygame.K_b:
                color = blue
            if event.key == pygame.K_g:
                color = green
            if event.key == pygame.K_g:
                color = green
            if event.key == pygame.K_r:
                color = red
            if event.key == pygame.K_z:
                color = black
            if event.key == pygame.K_x:
                color = white
            if event.key == pygame.K_s:
                if shape:
                    shape = False
                else:
                    shape = True
                
        
        if event.type == pygame.MOUSEBUTTONDOWN:
            
            if event.button == 1 or event.button == 3:  
                not_draw = False   
            else:    
                not_draw = True
                if event.button == 4:
                    size += 1
                if event.button == 5:
                    size -= 1        
   
        if event.type == pygame.MOUSEBUTTONUP:
            not_draw = True
            
            
            

        
    if not not_draw:

        if shape:
            pygame.draw.rect(gameDisplay,color,[x,y,size,size],0) 
            
        else:
            pygame.draw.circle(gameDisplay,color,[x,y],size,0)

        pygame.display.update() 

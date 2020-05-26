import pygame, thorpy, math

def airFunction():
    global v 
    global color
    v = 340
    color = (255,255,255)

def waterFunction():
    global v
    global color
    v = 1500
    color = (0,0,255)

def iceFunction():
    global v
    global color
    v = 3400
    color = (0,0,0)

  

width = 1000
height = 500

f = 2
f_prime = f
width = 1000
height = 500
v = 340
wavelength = v /f
color = (255,255,255)
t = 1
FPS = 90
A = height/10
toChange = False

screen = pygame.display.set_mode((width,height))
clock = pygame.time.Clock()
snd = pygame.font.init()

buttonAir = thorpy.make_button("powietrze, v = 340 m/s",airFunction)
buttonWater = thorpy.make_button("woda, v = 1500 m/s",waterFunction)
buttonIce = thorpy.make_button("lód, v = 3400 m/s",iceFunction)
slider = thorpy.SliderX(int(width/6),(1,10),"f[HZ]")
slider2 = thorpy.SliderX(int(width/6),(1,height/5),"A")
box = thorpy.Box(elements = [slider,slider2,buttonAir,buttonWater,buttonIce])

menu = thorpy.Menu(box)

for element in menu.get_population():
    element.surface = screen

box.set_topleft((0,0))
box.center()
box.blit()
box.update()

APP_ON = True


while APP_ON:
    clock.tick(FPS)
    t+= 1/FPS

    screen.fill(color)
    box.set_topleft((50,50))
    box.blit()
    box.update()
    wavelength = v / f
    f = slider.get_value()
    A = slider2.get_value()
    for x in range(0,width):

        y = int(A * math.pow(math.sin(2 * math.pi * f * t - 5 * math.pi / wavelength * x ),1))
        pygame.draw.circle(screen,(250,0,0),(x,int(height/2 + y)),1)

    pygame.display.update()

    
    for event in pygame.event.get():
         
        
        if event.type == pygame.QUIT:
            APP_ON = False
            break
        
        menu.react(event)

pygame.quit()
    


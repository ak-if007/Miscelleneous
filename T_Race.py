import random
import time
import turtle
Colors=['red','cyan','black','yellow','orange','gold','maroon','purple','navy','blue','green','gray','chocolate','brown','magenta']
WIDTH,HEIGHT=600,600
   

def get_input():
    while True:
        racer=input('Enter number of racers (2-15) : ')
        if racer.isdigit() and 2<=int(racer)<=15:
            return int(racer)
        else:
            print('Invalid Input. Try Again!!')
            
def screen_init():
    screen= turtle.Screen()
    screen.setup(WIDTH,HEIGHT)
    screen.title('Turtle Race!!!')
    line=turtle.Turtle()
    line.color('red')
    line.penup()
    line.setpos(-WIDTH//2,HEIGHT//2-40)
    line.pendown()
    line.forward(WIDTH)
    


def race(colors):   
    screen_init()
    racers=[]
    space_x=WIDTH//(len(colors)+1)
    for i,color in enumerate(colors):
        racer=turtle.Turtle()
        racer.color(color)
        racer.penup()
        racer.left(90)
        racer.setpos(-WIDTH//2+(i+1)*space_x,-HEIGHT//2+40)
        racer.shape('turtle')
        racer.pendown()
        racers.append(racer)
    while True:
        for j,i in enumerate(racers):
            distance=random.randrange(1,20)
            i.forward(distance)
            x,y=i.pos()
            if y>=HEIGHT//2-40:
                
                print('The Winner is '+colors[j]+'!!!!!')
                time.sleep(5)
                return


n=get_input()
random.shuffle(Colors)
colors=Colors[:n] 
race(colors)


from tkinter import *
import tkinter.ttk as ttk

Symbol1="X"
Symbol2="O"

Color1="orange"
Color2="lightblue"

Button_Color="#666"

Game=Tk()
Game.title("Tic Tac Toe")
Game.iconbitmap("icons/tic-tac-toe.ico")


font1="{Consolas} 30 normal"
paddingx=5
paddingy=5

mywidth=5
myheight=2

button_Clicked=0

#===========================================================================================================================================
def win(Winner):
    #print("You Win")
    disable_Button()
    Win_Label=Label(Game,text=Winner,font="{Consolas} 15 normal",relief='solid',padx=30,pady=30,bg='#ccc',fg='green')
    Win_Label.place(relx=0.5,rely=0.5,anchor='center')

#============================================================================================================================================
def color(a):
    #---color-----
    global Color1,Color2,button_Clicked,Symbol1
    tempcolor=Color1
    Color1=Color2
    Color2=tempcolor
    a["bg"]=Color1
    a['state']='disable'
    #-------------------------count number of button clicked
    button_Clicked+=1
    if(button_Clicked==9):
        Symbol1="Draw"
        win("Game Draw")

def disable_Button():
    Key_00["state"]="disable"
    Key_01["state"]="disable"
    Key_02["state"]="disable"
    Key_10["state"]="disable"
    Key_11["state"]="disable"
    Key_12["state"]="disable"
    Key_20["state"]="disable"
    Key_21["state"]="disable"
    Key_22["state"]="disable"

def swap():
    global Symbol1,Symbol2
    temp=Symbol1
    Symbol1=Symbol2
    Symbol2=temp



def Button_1():
    Key_00['text']=Symbol1
    color(Key_00)
    if((Key_01["text"]==Symbol1 and Key_02["text"]==Symbol1)or(Key_10["text"]==Symbol1 and Key_20["text"]==Symbol1)or(Key_11["text"]==Symbol1 and Key_22["text"]==Symbol1)):
        win("Winner "+Symbol1) 
    swap()
    
def Button_2():
    Key_01['text']=Symbol1
    color(Key_01)
    if((Key_00["text"]==Symbol1 and Key_02["text"]==Symbol1)or(Key_11["text"]==Symbol1 and Key_21["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_3():
    Key_02['text']=Symbol1
    color(Key_02)
    if((Key_00["text"]==Symbol1 and Key_01["text"]==Symbol1)or(Key_12["text"]==Symbol1 and Key_22["text"]==Symbol1)or(Key_20["text"]==Symbol1 and Key_11["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_4():
    Key_10['text']=Symbol1
    color(Key_10)
    if((Key_00["text"]==Symbol1 and Key_20["text"]==Symbol1)or(Key_11["text"]==Symbol1 and Key_12["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_5():
    Key_11['text']=Symbol1
    color(Key_11)
    if((Key_00["text"]==Symbol1 and Key_22["text"]==Symbol1)or(Key_02["text"]==Symbol1 and Key_20["text"]==Symbol1)or(Key_01["text"]==Symbol1 and Key_21["text"]==Symbol1)or(Key_10["text"]==Symbol1 and Key_12["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_6():
    Key_12['text']=Symbol1
    color(Key_12)
    if((Key_10["text"]==Symbol1 and Key_11["text"]==Symbol1)or(Key_02["text"]==Symbol1 and Key_22["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_7():
    Key_20['text']=Symbol1
    color(Key_20)
    if((Key_00["text"]==Symbol1 and Key_10["text"]==Symbol1)or(Key_21["text"]==Symbol1 and Key_22["text"]==Symbol1)or(Key_11["text"]==Symbol1 and Key_02["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_8():
    Key_21['text']=Symbol1
    color(Key_21)
    if((Key_20["text"]==Symbol1 and Key_22["text"]==Symbol1)or(Key_01["text"]==Symbol1 and Key_11["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()
    
def Button_9():
    Key_22['text']=Symbol1
    color(Key_22)
    if((Key_02["text"]==Symbol1 and Key_12["text"]==Symbol1)or(Key_20["text"]==Symbol1 and Key_21["text"]==Symbol1)or(Key_00["text"]==Symbol1 and Key_11["text"]==Symbol1)):
        win("Winner "+Symbol1)
    swap()

#==============================================================================================================================================    
Game_Frame=Frame(Game,bg="#222")
Key_00=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_1)
Key_00.grid(row=0,column=0,padx=paddingx,pady=paddingy)
Key_01=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_2)
Key_01.grid(row=0,column=1,padx=paddingx,pady=paddingy)
Key_02=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_3)
Key_02.grid(row=0,column=2,padx=paddingx,pady=paddingy)
Key_10=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_4)
Key_10.grid(row=1,column=0,padx=paddingx,pady=paddingy)
Key_11=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_5)
Key_11.grid(row=1,column=1,padx=paddingx,pady=paddingy)
Key_12=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_6)
Key_12.grid(row=1,column=2,padx=paddingx,pady=paddingy)
Key_20=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_7)
Key_20.grid(row=2,column=0,padx=paddingx,pady=paddingy)
Key_21=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_8)
Key_21.grid(row=2,column=1,padx=paddingx,pady=paddingy)
Key_22=Button(Game_Frame,text='',font =font1,relief='solid',bg=Button_Color,width=mywidth,height=myheight,command=Button_9)
Key_22.grid(row=2,column=2,padx=paddingx,pady=paddingy)

Game_Frame.pack(side='top')

Game.mainloop()

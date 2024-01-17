import random


def roll_dice():


    return random.randint(1,6)

def check_ladder(position):

    ladder={2:17,9:65,5:46,19:77,43:98,63:78}

    if position in ladder:

        print("wow! you landed on the ladder🪜")

        return ladder[position]
    
    return position

def check_snake(position):

    snake={33:2,55:6,88:54,98:3,33:13}

    if position in snake:

        print("opps! no you had landed on snake🐍")

        return snake[position]
    
    return position
  
def play_game():

    player1_position=0

    player2_position=0

    player1_name=input("enter player1 name🙋🏻: ")

    player2_name=input("enter player2 name🙋🏻: ")

    i=0


    while True:

        if i%2==0:

            current_player=player1_name

            current_position=player1_position

        else:

            current_player=player2_name

            current_position=player2_position

        print(current_player,"turns")

        input("press enter to roll dice...🎲")

        roll=roll_dice()

        print(current_player , 'has rolled' ,roll,"!")


        current_position+=roll

        
        
        current_position=check_ladder(current_position)

        current_position=check_snake(current_position)

        if current_position > 100:


            current_position-=roll
           
            print(" you are at the position",current_position)

        elif current_position <100:
             
             print(current_player,'at',current_position)    
          

        elif current_position == 100:

            print(current_player,'🎉had win the match🎉')

            break

        if i%2==0:

            player1_position=current_position

        else:

            player2_position=current_position   
    
        i+=1

play_game()               








   
  
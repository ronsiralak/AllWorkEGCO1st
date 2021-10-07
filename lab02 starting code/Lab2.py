import random
import graphics, button, dieview, msdie, roller
totalChips = int(input("Enter your buy-in: "))
quit = False
while quit == False:
  userBet = int(input("Enter your bet: "))
  if userBet > totalChips:
    print("Can't place bet, not enough chips")
  else:
    randomDice1 = random.randint(1,6)
    randomDice2 = random.randint(1,6)

    if randomDice1 == 1:
      print("Dice 1 = ",randomDice1)
    if randomDice1 == 2:
      print("Dice 1 = ",randomDice1)
    if randomDice1 == 3:
      print("Dice 1 = ",randomDice1)
    if randomDice1 == 4:
      print("Dice 1 = ",randomDice1)
    if randomDice1 == 5:
      print("Dice 1 = ",randomDice1)
    if randomDice1 == 6:
      print("Dice 1 = ",randomDice1)

    if randomDice2 == 1:
      print("Dice 1 = ",randomDice2)
    if randomDice2 == 2:
      print("Dice 1 = ",randomDice2)
    if randomDice2 == 3:
      print("Dice 1 = ",randomDice2)
    if randomDice2 == 4:
      print("Dice 1 = ",randomDice2)
    if randomDice2 == 5:
      print("Dice 1 = ",randomDice2)
    if randomDice2 == 6:
      print("Dice 1 = ",randomDice2)

    sumOfdices = randomDice1 + randomDice2
    if sumOfdices == 2 or sumOfdices == 3 or sumOfdices == 11:
      totalChips = totalChips + userBet
      print("Winner!! You doubled your money!")
      print(totalChips)
    elif sumOfdices == 7 or sumOfdices == 11:
      totalChips = totalChips - userBet
      print("Aw Craps!! You lose your bet")
      print(totalChips)
    else:
      print("Whew, safe! Roll again")
    if totalChips == 0:
      print("Out of Chips! Game over!")
      quit = True
  if quit == False:
    userInput = input("Quit? :")
    if userInput == "yes":
      quit = True
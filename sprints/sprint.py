def random(n):
    while True :
        if n == 23:
            return ("Your guess is right, congrats ")
        elif n not 23:
            num = int(input("Input your guess please once more, dont give up : " ))

num = int(input ("Input your guess please : "))
print(random(num))

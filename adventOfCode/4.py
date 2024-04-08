n = 1
ans = 0
maximo = 202
contar_cartas = {}
while n <= maximo:
    if(n not in contar_cartas.keys()):
        contar_cartas[n] = 1
    game = input()
    game = game.split(':')
    
    all_cards = game[1].split('|')
    winning_cards = {card for card in all_cards[0].split(" ")}
    my_cards = {card for card in all_cards[1].split(" ")}
    #remove empty spaces
    winning_cards = {x for x in winning_cards if x != ''}
    my_cards = {x for x in my_cards if x != ''}
    print("Winning Cards: ",winning_cards)
    print("My Cards: ",my_cards)
    intersection = winning_cards.intersection(my_cards)
    if len(intersection) == 0:
        ans += contar_cartas[n]
        n += 1
        continue
    soma = len(intersection)
    for i in range(n+1, n+soma+1):
        if (i > maximo):
            break
        if (i not in contar_cartas.keys()):
            contar_cartas[i] = 1
        
        contar_cartas[i] += contar_cartas[n]
    ans += contar_cartas[n]

    n += 1
print(ans)
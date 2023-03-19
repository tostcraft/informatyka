#!usr/bin/Python3

def czy_anagramy(x :str,y:str) -> bool:
    '''
    anagramy bitch
    '''
    slownik1={}
    slownik2={}
    for i in range(len(x)):
        if x[i] in slownik1:
            slownik1[x[i]]+=1
        else:
            slownik1[x[i]]=0
    for i in range(len(y)):
        if y[i] in slownik2:
            slownik2[y[i]] += 1
        else:
            slownik2[y[i]] = 0
    slowo1 = ''
    slowo2 = ''
    for e in slownik1:
        slowo1+=e*slownik1[e]
    for e in slownik2:
        slowo2+=e*slownik2[e]
    if slowo1==slowo2:
        return True
    else:
        return False

def main():
    p=str(input())
    d=str(input())
    ok : bool = czy_anagramy(p, d)
    if ok:
        print("TAK")
    else:
        print("NIE")

main()
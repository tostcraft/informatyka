data = []
with open("/home/stasiek/SZKOLA/informatyka-main/informatyka/SZKOpul/Listopad/naw1_data.txt", 'r', encoding="UTF-8") as file:
    data = file.readlines();
# n=int(input())
wyrazenia=[]
for d in data:
    try:
        n = int(d)
    except ValueError:
        wyrazenia.append(d[:-1])
# for i in range(n):
#     pom=str(input(""))
#     wyrazenia.append(pom)
odp=[]
print(wyrazenia)
for i in range(len(wyrazenia)):
    if len(wyrazenia[i])%2!=0:
        odp.append("N")
    else:
        stos=[]
        for j in range(len(wyrazenia[i])):
            if wyrazenia[i][j] == "(" or wyrazenia[i][j] == "[" or wyrazenia[i][j] == "{" or wyrazenia[i][j] == "<":
                stos.append(wyrazenia[i][j])
            else:
                if len(stos)==0:
                    stos.append("X")
                    break
                if wyrazenia[i][j]==")":
                    if stos[len(stos)-1]=="(":
                        stos.pop()
                    else:
                        break
                if wyrazenia[i][j] == "]":
                    if stos[len(stos)-1]=="[":
                        stos.pop()
                    else:
                        break
                if wyrazenia[i][j] == "}":
                    if stos[len(stos)-1]=="{":
                        stos.pop()
                    else:
                        break
                if wyrazenia[i][j] == ">":
                    if stos[len(stos)-1]=="<":
                        stos.pop()
                    else:
                        break
        if len(stos)==0:
            odp.append("T")
        else:
            odp.append("N")
            
with open("/home/stasiek/SZKOLA/informatyka-main/informatyka/SZKOpul/Listopad/naw1_output1.txt", 'w', encoding="UTF-8") as output:
    for o in odp:
        output.write(o + "\n")

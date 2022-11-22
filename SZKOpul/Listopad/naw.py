#!usr/bin/Python3

def count_parentheses(text: str):
    layers = [0]
    stack = []
    depth =0
    mc = 0
    for c in text:
        if c == "(":
            stack.append(c)
            layers.append(0)
            depth+=1
        
        else:
            if len(stack)==0:
                continue
            depth-=1
            layers[depth]+=1
            mc+=int(layers[depth+1]*(layers[depth+1]+1)/2)
            del layers[depth+1]
            del stack[-1]
        print(depth, mc, layers, stack)
    
    for l in layers:
        mc+= int(l*(l+1)/2)
    return mc

s = input()
print(count_parentheses(s))
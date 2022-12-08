def naw1(seqs: list):
    for seq in seqs:
        if len(seq) % 2 == 1:
            print("N")
            continue

        stack = []
        for char in seq:
            if char in "({[<":
                stack.append(char)

            else:
                if len(stack) == 0:
                    break
                if char == ")" and stack[-1] == "(":
                    stack.pop()
                elif char == "}" and stack[-1] == "{":
                    stack.pop()
                elif char == "]" and stack[-1] == "[":
                    stack.pop()
                elif char == ">" and stack[-1] == "<":
                    stack.pop()
                else:
                    break

        if len(stack) == 0:
            print("T")
        else:
            print("N")


n = int(input())
l = [input() for i in range(n)]
naw1(l)

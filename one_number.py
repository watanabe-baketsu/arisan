print("Nを入力してください")
print("N : ")
N = input()

n = len(N) # Nの桁数を求める。
if n == 1:
    ans = 1
    print("Nまでの1の出現数 : {}個".format(ans))
    exit()
cell_dic = {} # 10^(n-1)までの各桁の1の数を最大値を辞書化。
cell_dic["0"] = 0
cell_dic["1"] = 1
for i in range(2,n):
    # example: 2桁の数の1の最大出現回数
    # 2*10**(2-1)=20　一般化するとしたの式に
    cell_dic[str(i)] = i*10**(i-1)

num_N = int(N)
if num_N < 1:
    print("Nは1以上の整数である必要があります。")
    exit()
else:
    ans = 0
    #ans = cell_dic[str(n-1)] # Nの桁数から最小の1の数を算出。足りない分を以後足していく。
    if N[0] != "1":
        ans += 10**(n-1)
    else:
        ans += num_N-10**(n-1)

    for i in range(n):
        if N[i] == "0":
            pass
        else:
            ans += int(N[i])*cell_dic[str(n-i-1)]
        
        if i == n-2:
            if N[i+1] != "0":
                ans += int(N[i])
            else:
                ans += int(N[i])-1
            break
    


print("Nまでの1の出現数 : {}個".format(ans))

from math import sqrt
from matplotlib import pyplot as plt
from time import sleep

def filter(line):
    if len(line.split()) > 1:
        return [line.split()[0],line.split()[1]]
    return ["N", line]

class P:
    def __init__(self, P) -> None:
        self.P = P
        self.B = []
class I:
    def __init__(self, I) -> None:
        self.I = I
        self.P = []

def decide(info, data, buffer):
    print(info)
    print(data)
    print(buffer)
    if len(data) == 0:
        data.append(I(info))
        return

    if ((1.3)*(sum(buffer)/(len(buffer)+1))) < info and (len(buffer)+1)%3 == 0:
        data.append(I(info)) # Having I means cleaning the buffer
        buffer.clear()
        return

    if (len(buffer)+1)%3:
        data[len(data)-1].P = P(info)
        buffer.append(1)
        return

    data.append[len(data)-1].P.B.append(info)
    buffer.append(1)
    return
    
def main():
    data = []
    buffer = []
    f = open("BaseIBP.txt", "r")
    lines = f.readlines()
    data = []
    index = []
    count = 0
    for line in lines:
        if line == "" or line == "\n":
            continue
        filtered = filter(line)
        if (filtered[0] != "I" and len(data) == 0):
            continue
        decide(int(filtered[1]), data, buffer)
        index.append(count)
        count += 1
    I = [info.I for info in data if info]
    P = [info.I.P for info in data if info]
    B = []
    for part in data:
        for items in part.I.P:
            for numbers in items.B:
                B.append(numbers)
    print(I)
    print(P)
    print(B)
    # mDados = sum(data)/count
    # mIndex = sum(index)/count
    # VData = 0
    # VIndex = 0
    # Cov = 0
    # for i in range(count):
    #     Cov += (data[i] - mDados)*(index[i] - mIndex)
    #     VData += pow(data[i]-mDados, 2)
    #     VIndex += pow(index[i]-mIndex, 2)

    # VData   = VData/(count-1)
    # VIndex  = VIndex/(count-1)
    # Cov = Cov/(count-1)
    # DData   = sqrt(VData)
    # DIndex  = sqrt(VIndex)
    # Cor     = Cov/(DData*DIndex)
    # print(f"A média é {round(mDados, 2)}")
    # print(f"A variância é {round(VData, 2)}")
    # print(f"A covariancia é {round(Cov, 2)}")
    # print(f"O Desvio padrão dos dados é {round(DData, 2)}")
    # print(f"O Desvio padrão dos índices é {round(DIndex, 2)}")
    # print(f"A correlação dos dados é de {round(100*Cor, 3)}")
    plt.plot(index, data)
    plt.xlabel("Index")
    plt.ylabel("Data")
    plt.title("Base IBP")
    plt.show()
if __name__ == "__main__":
    main()
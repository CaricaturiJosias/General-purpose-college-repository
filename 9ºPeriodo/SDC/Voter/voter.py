#!/usr/bin/env python3

import Pyro5.api, math, signal
from sys import argv

@Pyro5.api.expose
class Voter:
    def __init__(self, meu_id):
        self.id = meu_id
        self.cont = 0
        self.msgs = {}

    def trata_sinal(self, nsinal, pilha):
        # Se chegou aqui, não tem todos
        maioria = math.ceil((self.cont+1)/2)
        for msg in self.msgs:
            if self.msgs[msg] >= maioria:
                print(f"Vencedora: {msg}")
                self.reset()
                return
        print("Inconclusivo")
        self.reset()
    
    def reset(self):
        self.msgs = {}
        self.cont = 0

    def send(self, msg):
        self.cont += 1
        # Dicionario vazio
        if msg not in self.msgs:
            self.msgs[msg] = 1
            signal.setitimer(signal.ITIMER_REAL, 5)
        else:
            self.msgs[msg] += 1
        if self.cont == ve:
            signal.alarm(0)
            vencedora = None
            for msg in self.msgs:
                if vencedora == None:
                    vencedora = msg
                elif (self.msgs[vencedora] < self.msgs[msg]):
                    vencedora = msg
            if (self.msgs[vencedora] == math.ceil((ve+1)/2)):
                print("Veredito: " + vencedora)
            else:
                print("Inconclusivo")
            self.reset()

if len(argv) < 3:
    print(f"Correct usage: {argv[0]} <id> <ve>")
    exit()

meuid = argv[1]
ve = int(argv[2])

voter = Voter(meuid)

signal.signal(signal.SIGALRM, voter.trata_sinal)
daemon = Pyro5.api.Daemon()
uri = daemon.register(voter)
sn = Pyro5.api.locate_ns()
sn.register(meuid, uri)

print("Aguardando requisição")
daemon.requestLoop()



#!/usr/bin/env/ python3


import json
from flask import Flask, request
from flask_restful import Resource, Api, reqparse

aplicacao = Flask(__name__)
api = Api(aplicacao)

class Banco:
    def __init__(self):
        self._saldo = 0
   
    def saldo(self):
        print(f"Saldo atual: {self._saldo}")
        return self._saldo

    def saque(self, msg):
        try:
            print(request)
            valor = float(msg)
            if (valor < 0):
                valor = -valor
            if (valor > self._saldo):
                return "Negado"
            self._saldo = self._saldo - valor
            resposta = f"Saque realizado em {valor} unidades, {self._saldo} restante"
            print(resposta)
            return resposta
        except:
            return "Algo deu errado"
       
    def deposito(self,msg):
        try:
            valor = float(msg)
            if (valor < 0):
                valor = -valor
            if (valor > 150000):
                valor = 150000
            self._saldo = self._saldo + valor
            resposta =  f"Deposito realizado com {valor} unidades, {self._saldo} atualmente"
            print(resposta)
            return resposta
        except:
            return "Algo deu Errado"

banco = Banco()
apiParser = reqparse.RequestParser()

apiParser.add_argument("op")
apiParser.add_argument("valor", type=float)

class BancoApi(Resource):
    def get(self):
        return {'saldo': f'{banco.saldo()}'}
   
    def patch(self):
        requestData = json.loads(request.get_data())
        op = requestData['op']
        valor = requestData['valor']
        if 'saque' in op:
            return {'Resposta': banco.saque(valor)}
        elif 'deposito' in op:
            return {'Resposta': banco.deposito(valor)}
        return {'error': 'Operação desconhecida.'}

    def put(self):
        return self.patch()

api.add_resource(BancoApi, "/contas/1234-5")

aplicacao.env = 'development'
if (__name__) == '__main__':
    aplicacao.run(port=45256, debug=True)

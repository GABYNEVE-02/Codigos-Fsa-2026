class Conta:
    def __init__(self, titular, saldo):
        self.titular = titular
        self.__saldo = saldo  # O __ indica que o atributo é privado

    def depositar(self, valor):
        if valor > 0:
            self.__saldo += valor
            print(f"Depósito de {valor} realizado com sucesso.")
        else:
            print("Valor de depósito inválido.")

    def sacar(self, valor):
        if 0 < valor <= self.__saldo:
            self.__saldo -= valor
            print(f"Saque de {valor} realizado com sucesso.")
        else:
            print("Saldo insuficiente ou valor inválido.")

    def consultar_saldo(self):
        return self.__saldo
    
ContaGabriel = Conta("Gabriel", 1000)
print(f"Saldo inicial: {ContaGabriel.consultar_saldo()}")
# ContaGabriel[self.__saldo] = 500  # Tentativa de acessar o saldo diretamente (não permitido)
ContaGabriel.depositar(500) # Depósito de 500 realizado com sucesso.
print(f"Saldo após depósito: {ContaGabriel.consultar_saldo()}")
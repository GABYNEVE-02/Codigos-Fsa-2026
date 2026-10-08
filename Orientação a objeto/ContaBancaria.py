N = 1
class Conta:
    def __init__(self,Titular):
        global N
        self.id = N; N += 1
        self.Titular = Titular
        self.__Saldo = 0
        
    def MostrarSaldo(self):
        print(f"O saldo da conta é R${self.__Saldo}")
        print(" ")
        
    def MostrarDados(self):
            print("------------Dados------------")
            print(f"Conta: {self.id}")
            print(f"Titular: {self.Titular}") 
            print(f"Saldo: R${self.__Saldo}") 
            print("-----------------------------")
            print(" ")
        
    def Depositar(self, Valor):
            if Valor > 0:
                self.__Saldo += Valor
                print(f"O Valor de R$+{Valor} foi depositado na conta")
                print(" ")
            
    def Sacar(self, Valor):
            if Valor > 0:
                self.__Saldo -= Valor
                print(f"O Valor de R$-{Valor} foi Retirado da conta")
                print(" ")
            
            
ContaGabriel = Conta("Gabriel Andrade")
ContaGabriel.Depositar(1000)
ContaGabriel.Depositar(300)
ContaGabriel.Sacar(100)
ContaGabriel.MostrarDados()

ContaSeila = Conta("Não sei Da Silva")
ContaSeila.Sacar(700)
ContaSeila.MostrarDados()
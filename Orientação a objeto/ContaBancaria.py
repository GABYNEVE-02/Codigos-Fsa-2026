#Atividade 1 - Orientação a objetos
#ContaBancaria
#Gabriel Andrade de Oliveira - 763094
#Marina Apostolo de Oliveira - 764018
#Gustavo Marchi de Barros - 765044


N = 1
class Conta:
    def __init__(self,Titular):
        global N
        self.__id = N; N += 1
        self.__Titular = Titular
        self.__Saldo = 0 # O saldo fica privado para não poder ser alterado diretamente e ao longo do codigo ele não é posibilitado de ficar negativo

    def MostrarSaldo(self):
        print(f"O saldo da conta é R${self.__Saldo}")
        print(" ")

    def RetornarSaldo(self):
        return self.__Saldo
    def RetornarTitular(self):
            return self.__Titular
    def Retornarid(self):
            return self.__id
    
    def Depositar(self, Valor):
            if isinstance(Valor, (int, float)) and Valor > 0: #Verifica se o valor do depoisito não é negativo e se a variavel é do tipo int ou float
                self.__Saldo += Valor
                print(f"O Valor de R$+{Valor} foi depositado na conta: {self.__id} - {self.__Titular}")
                print(" ")

            else:
                print("Depósito Inválido")
                print(" ")

    def Sacar(self, Valor):
            if isinstance(Valor, (int, float)) and Valor > 0 and self.__Saldo >= Valor: #Verifica se o valor do depoisito não é negativo e se a conta tem saldo suficiente e se a variavel é do tipo int ou float        
                self.__Saldo -= Valor
                print(f"O Valor de R$-{Valor} foi Retirado da conta: {self.__id} - {self.__Titular}")
                print(" ")
            else:
                print("Saque Invalido")
                print(" ")

    def DepositarSilencioso(self, Valor): #Função para depositar sem printar na tela para o pix
                if isinstance(Valor, (int, float)) and Valor > 0: #Verifica se o valor do depoisito não é negativo e se a variavel é do tipo int ou float
                    self.__Saldo += Valor       
            
    def SacarSilencioso(self, Valor): #Função para sacar sem printar na tela para o pix
                if isinstance(Valor, (int, float)) and Valor > 0 and self.__Saldo >= Valor: #Verifica se o valor do depoisito não é negativo e se a conta tem saldo suficiente e se a variavel é do tipo int ou float        
                    self.__Saldo -= Valor
 

class Banco:
    def __init__(self):
        self.Contas = []

    def CriarConta(self,Titular):
        conta = Conta(Titular)
        self.Contas.append(conta)
        print(f"Conta criada com sucesso! ID da conta: {conta.Retornarid()}, Titular: {conta.RetornarTitular()}")
        print(" ")

    def MostrarContas(self):
        print("Contas cadastradas:")
        if len(self.Contas) == 0: #Verifica se existe alguma conta no banco
            print("Nenhuma conta cadastrada.")
            print(" ")
        else:
            for conta in self.Contas:
                print(f"ID: {conta.Retornarid()}, Titular: {conta.RetornarTitular()}, Saldo: R${conta.RetornarSaldo()}")
            print(" ")

    def Pix(self, ContaPg, ContaRc, Valor):
        if isinstance(Valor, (int, float)) and Valor > 0 and ContaPg.RetornarSaldo() >= Valor and ContaPg != ContaRc:#Verifica se o pix não é para a propia conta, se o valor do pix não é negativo e se a conta tem saldo suficiente e se a variavel é do tipo int ou float    
            ContaPg.SacarSilencioso(Valor)
            ContaRc.DepositarSilencioso (Valor)
            print(f"Transferência: {ContaPg.RetornarTitular()} (R${Valor}) --> {ContaRc.RetornarTitular()}")
            print(" ")
        else:
            print("Pix Invalido")
            print(" ")


Master = Banco()

Master.CriarConta("Gabriel")
Master.CriarConta("Teodoro")
Master.CriarConta("Lilica")

for conta in Master.Contas:
    conta.Depositar(1600)

Master.MostrarContas()

Master.Contas[0].Depositar(2700)
Master.Contas[0].Depositar("MIl Reais")
Master.Contas[2].Sacar(100)
Master.Contas[2].Sacar(5000)
Master.Pix(Master.Contas[0], Master.Contas[1], 500)
Master.Pix(Master.Contas[0], Master.Contas[0], 10000000)

Master.MostrarContas()



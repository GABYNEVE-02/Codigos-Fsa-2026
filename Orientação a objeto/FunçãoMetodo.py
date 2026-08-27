#Mundo Real -> Modelo Mental -> Classe -> Objeto
class Pessoa:
    def __init__(self, Nome, Idade):
        self.Nome = Nome
        self.Idade = Idade

    def Aniversario(self):
        self.Idade += 1

class Aluno(Pessoa):
    def __init__(self, Nome, Idade, Nota1, Nota2):
        super().__init__(Nome, Idade)
        self.Nota1 = Nota1
        self.Nota2 = Nota2
    
    def Calcular_Media(self):
        return (self.Nota1 + self.Nota2) / 2

class Carro:
    def __init__(self, Cor, Ano, Modelo, Motor,Velocidade = 0):
        self.Cor = Cor
        self.Ano = Ano
        self.Modelo = Modelo
        self.Motor = Motor
        self.velocidade = Velocidade

    def Ligar_e_Desligar(self):
        if self.Motor == False:
            self.Motor = True

        elif self.Motor == True:
            self.Motor = False

    def Acelerar(self):
        if self.Motor == False:
            print("O Motor do Carro esta desligado ")
        else:
            self.velocidade += 10

    def Freiar(self):
        if (self.velocidade <= 0):
            print("O carro está parado")
        else:
            self.velocidade -= 10

Aluno1 = Aluno("Ana", 17, 8, 7)
print(f"A media das Nota de {Aluno1.Nome} é {Aluno1.Calcular_Media()} ")

Aluno1.Aniversario()

print(f"A {Aluno1.Nome} tem {Aluno1.Idade} agora que fez aniversario")

Carro1 = Carro("Preto", 2020, "Civic", False)
Carro1.Ligar_e_Desligar()
for i in range(4):
    Carro1.Acelerar()

print(f"A velocidade do carro é {Carro1.velocidade} km/h")
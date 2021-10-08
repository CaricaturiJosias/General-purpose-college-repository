import mysql.connector as mysql

def conectSQL():
    Host = 'localhost'
    User = 'petinho'
    Password = 'senhaPetinho123@#!'
    db = 'meupetinho'
    return mysql.connect(
        host = Host,
        user = User,
        passwd = Password,
        database = db
        )

class Informacao:
    def __init__(self,usuario,senha,data_nascimento,email):
        self.usuario         = usuario
        self.__senha         = senha
        self.data_nascimento = data_nascimento
        self.email           = email
        
    def Obtem_senha(self):
        return str(self.__senha)

class InformacaoPet:
    def __init__(self, id_dono, nome_pet, animal_pet):
        self.__id_dono  = id_dono
        self.nome_pet = nome_pet
        self.animal   = animal_pet
    def Obtem_iddono(self):
        return self.__id_dono
    
class BancoDeDados:
    def Cadastrar_Usuario(novo_usuario):
        conn = conectSQL()
        if conn != None:
            print('Conectado com sucesso')
        crs  = conn.cursor()
        crs.execute( f"""
                    INSERT INTO usuarios VALUES (NULL, {novo_usuario.usuario},{novo_usuario.Obtem_senha()},{novo_usuario.data_nascimento},{novo_usuario.email}, 0)
                    """
                    )
        conn.commit()
        conn.close()
        return True
    def Checa_Login(login_usuario):
        if login_usuario == '':
            return None
        conn = conectSQL()
        if conn != None:
            print('Conectado com sucesso')
        crs  = conn.cursor()
        crs.execute(f"""
                SELECT * FROM usuarios
                WHERE usuario LIKE '{login_usuario}'
                       """
                    )
        login = crs.fetchone()
        conn.close()
        if login == None:
            return None
        else: 
            return login[0]
    
    def Checa_Senha(senha_usuario):
        if senha_usuario == '':
            return None
        conn = conectSQL()
        if conn != None:
            print('Conectado com sucesso')
        crs  = conn.cursor()
        crs.execute(f"""
                SELECT * FROM usuarios
                WHERE senha LIKE '{senha_usuario}'
                       """
                    )
        senha = crs.fetchone()
        conn.close()
        if senha == None:
            return None
        else:
            return senha[0]
    def Cadastrar_Pet(novo_pet):
        conn = conectSQL()
        if conn != None:
            print('Conectado com sucesso')
        crs  = conn.cursor()
        crs.execute( f"""
                    INSERT INTO pets
                    VALUES ({novo_pet[0]},{novo_pet[1]},{novo_pet[2]})
                    """
                    )
        conn.commit()
        conn.close()
        print('Conectado com sucesso')
    
    def Checa_Pets(id_dono):
        conn = conectSQL()
        if conn != None:
            print('Conectado com sucesso')
        crs  = conn.cursor()
        crs.execute( f"""
                    SELECT * FROM pets
                    WHERE id_dono LIKE '{id_dono}'
                """
                    )
        encontrado = list()
        for pets in crs.fetchall():
            c = InformacaoPet(pets[0], pets[1], pets[2])
            encontrado.append(c)
        
        conn.close()
        print('Conectado com sucesso')
        return encontrado
        
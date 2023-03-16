using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data;
using MySql.Data.MySqlClient;
using System.Data;

namespace SistemaCadastro
{
    internal class ConectaBanco
    {
        MySqlConnection conexao = new MySqlConnection("server=localhost;user id=root;password=;database=banco_cadastro");
        public string mensagem;

        public DataTable listaGeneros()
        {
            MySqlCommand cmd = new MySqlCommand("lista_generos", conexao); //Atribui para o CMD o comando "Lista_generos"
            cmd.CommandType = CommandType.StoredProcedure; // Define o tipo como stored procedure 
            try
            {
                conexao.Open(); // Abre a conexão
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataTable tabela = new DataTable(); // Cria uma tabela virtual 
                da.Fill(tabela); // Preencher a tabela, a partir do comando CMD 
                return tabela; // Retorna a tabela 
            }// fim try
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message; // Exibe o erro
                return null;
            }
            finally
            {
                conexao.Close(); // Fecha a conexão
            }

        }// fim lista_generos




    }

}

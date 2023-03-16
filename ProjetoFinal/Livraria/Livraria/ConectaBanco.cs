using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data;
using MySql.Data.MySqlClient;
using System.Data;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace Livraria
{
    internal class ConectaBanco
    {
        MySqlConnection conexao = new MySqlConnection("server=localhost;user id=root;password=;database=livraria2si");
        public String? mensagem;

        public DataTable? lista_editora()
        {
            // comentario
            MySqlCommand cmd = new MySqlCommand("Lista_Editora", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            try
            {
                conexao.Open();
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataTable tabela = new DataTable();
                da.Fill(tabela);
                return tabela;
            }// fim try
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message;
                return null;
            }
            finally
            {
                conexao.Close();
            }

        }// fim lista_editora

        public DataTable? listaCliente()
        {
            MySqlCommand cmd = new MySqlCommand("lista_cliente", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            try
            {
                conexao.Open();
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataTable tabela = new DataTable();
                da.Fill(tabela);
                return tabela;
            }// fim try
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message;
                return null;
            }
            finally
            {
                conexao.Close();
            }

        }// fim lista_cliente


        public bool insereCliente(Cliente cliente)
        {
            MySqlCommand cmd = new MySqlCommand("insere_cliente", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("nome", cliente.Nome);
            cmd.Parameters.AddWithValue("dataNascimento", cliente.DataNascimento);
            cmd.Parameters.AddWithValue("cpf", cliente.CPF);
            cmd.Parameters.AddWithValue("uf", cliente.UF);
            cmd.Parameters.AddWithValue("endereco", cliente.Endereco);
            cmd.Parameters.AddWithValue("bairro", cliente.Bairro);
            cmd.Parameters.AddWithValue("cidade", cliente.Cidade);
            cmd.Parameters.AddWithValue("cep", cliente.CPF );
            cmd.Parameters.AddWithValue("email", cliente.Email);



            try
            {
                conexao.Open();
                cmd.ExecuteNonQuery(); // executa o comando
                return true;
            }
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message;
                return false;
            }
            finally
            {
                conexao.Close();
            }
        }// fim insereCliente

        public bool alteraCliente(Cliente b, int idAlterar)
        {
            MySqlCommand cmd = new MySqlCommand("altera_Cliente", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("novoNome", b.Nome);
            cmd.Parameters.AddWithValue("novaData", b.DataNascimento);
            cmd.Parameters.AddWithValue("novoCpf", b.CPF);
            cmd.Parameters.AddWithValue("novoUf", b.UF);
            cmd.Parameters.AddWithValue("novoEnd", b.Endereco);
            cmd.Parameters.AddWithValue("novoBairro", b.Bairro);
            cmd.Parameters.AddWithValue("novaCity", b.Cidade);
            cmd.Parameters.AddWithValue("novoCep", b.CEP);
            cmd.Parameters.AddWithValue("novoEmail", b.Email);
            cmd.Parameters.AddWithValue("codigo", idAlterar);


            try
            {
                conexao.Open();
                cmd.ExecuteNonQuery(); // executa o comando
                return true;
            }
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message;
                return false;
            }
            finally
            {
                conexao.Close();
            }
        }// fim updateCliente

        public bool insereEditora(Editora editora)
        {
            MySqlCommand cmd = new MySqlCommand("insere_editora", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("novoNome", editora.Nome);
            try
            {
                conexao.Open();
                cmd.ExecuteNonQuery(); // executa o comando
                return true;
            }
            catch (MySqlException e)
            {
                mensagem = "Erro:" + e.Message;
                return false;
            }
            finally
            {
                conexao.Close();
            }
        }// fim insereEditora

        public bool verifica(string user, string pass)
        {
            string senhaHash = BibliotecaHash.makeHash(pass);
            MySqlCommand cmd = new MySqlCommand("consultaLogin", conexao);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("usuario", user);
            cmd.Parameters.AddWithValue("senha", senhaHash);
            try
            {
                conexao.Open();//abrindo a conexão;
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();// tabela virtual
                da.Fill(ds); //passando os valores consultados para o DataSet
                if (ds.Tables[0].Rows.Count > 0) // verifica se houve retorno
                    return true;
                else
                    return false;

            }
            catch (MySqlException er)
            {
                mensagem = "Erro" + er.Message;
                return false;
            }
            finally
            {
                conexao.Close();
            }
        }

        internal bool alteraCliente(Livraria l, int idAlterar)
        {
            throw new NotImplementedException();
        }
    }
}

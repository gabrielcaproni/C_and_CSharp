using MySql.Data.MySqlClient;
using System.Data;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace Livraria
{
    public partial class Livraria : Form
        
    {
        int idAlterar;//variavel global
        private object txtnome;
        private object txtvenda;

        public Livraria()
        {
            InitializeComponent();
        }
        private void lista_Editora()
        {
            ConectaBanco con = new ConectaBanco();
            dgEditora.DataSource = con.lista_editora();
            lblerro.Text = con.mensagem;
        }
        private void listaCliente()
        {
            ConectaBanco con = new ConectaBanco();
            dgClientes.DataSource = con.listaCliente();
            lblerro.Text = con.mensagem;
        }

        private void Livraria_Load_1(object sender, EventArgs e)
        {
            lista_Editora();
            listaCliente();

        }

        private void BtnConfirmaCadastro_Click(object sender, EventArgs e)
        {

            Cliente b = new Cliente();
            b.Nome = txtcliente.Text;
            b.DataNascimento = txtdata.Text;
            b.CPF = txtcpf.Text;
            b.UF = txtuf.Text;
            b.Endereco = txtendereco.Text;
            b.Bairro = txtbairro.Text;
            b.Cidade = txtcidade.Text;
            b.CEP = txtcep.Text;
            b.Email = txtemail.Text;
            // Enviar para o banco

            ConectaBanco conecta = new ConectaBanco();
            bool retorno = conecta.insereCliente(b);
            if (retorno == true)
            {
                MessageBox.Show("Dados inseridos com sucesso !");
            }
            else
                lblerro.Text = conecta.mensagem;

       

        lista_Editora();
        listaCliente();
            
 }

        private void txtnomeEditora_TextChanged(object sender, EventArgs e)
            {

            }

            private void button1_Click(object sender, EventArgs e)
            {
                Editora b = new Editora();

                b.Nome = txtnomeEditora.Text;
                ConectaBanco conecta = new ConectaBanco();
                bool retorno = conecta.insereEditora(b);
                if (retorno == true)
                {
                    MessageBox.Show("Dados inseridos com sucesso !");
                }
                else
                    lblerro.Text = conecta.mensagem;
            }

            private void tabCadastrar_Click(object sender, EventArgs e)
            {

            }

            private void dgProdutos_CellContentClick(object sender, DataGridViewCellEventArgs e)
            {

            }

        private void dgClientes_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            (dgClientes.DataSource as DataTable).DefaultView.RowFilter = String.Format("nome like '%{0}%'", txtBuscaCliente.Text);
        }

        private void txtEditoras_TextChanged(object sender, EventArgs e)
        {
            (dgEditora.DataSource as DataTable).DefaultView.RowFilter = String.Format("nome like '%{0}%'", txtEditoras.Text);
        }

        private void closebtn_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void btnAlterarCliente_Click(object sender, EventArgs e)
        {
            int linha = dgClientes.CurrentRow.Index; // pega linha selecionada 
            idAlterar = Convert.ToInt32(dgClientes.Rows[linha].Cells["codCliente"].Value.ToString());
            txtAltCliente.Text = dgClientes.Rows[linha].Cells["nome"].Value.ToString();
            txtAltData.Text = dgClientes.Rows[linha].Cells["dataNascimento"].Value.ToString();
            txtAltCpf.Text = dgClientes.Rows[linha].Cells["cpf"].Value.ToString();
            txtAltUF.Text = dgClientes.Rows[linha].Cells["uf"].Value.ToString();
            txtAltEndereco.Text = dgClientes.Rows[linha].Cells["endereco"].Value.ToString();
            txtAltBairro.Text = dgClientes.Rows[linha].Cells["bairro"].Value.ToString();
            txtAltCidade.Text = dgClientes.Rows[linha].Cells["cidade"].Value.ToString();
            txtAltCEP.Text = dgClientes.Rows[linha].Cells["cep"].Value.ToString();
            txtAltEmail.Text = dgClientes.Rows[linha].Cells["email"].Value.ToString();
            BuscaCliente.SelectedTab = AlteraCliente1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
           Cliente l = new Cliente();
           
            l.Nome = txtAltCliente.Text;
            l.DataNascimento = txtAltData.Text;
            l.CPF = txtAltCpf.Text;
            l.UF = txtAltUF.Text;
            l.Endereco = txtAltEndereco.Text;
            l.Bairro = txtAltBairro.Text;
            l.Cidade = txtAltCidade.Text;
            l.CEP = txtAltCEP.Text;
            l.Email = txtAltEmail.Text;

            // Envia os dados para alterar
            ConectaBanco conecta = new ConectaBanco();
            bool retorno = conecta.alteraCliente(l, idAlterar);
            if (retorno == true)
                MessageBox.Show("Dados alterados com sucesso");
            else
                lblerro.Text = conecta.mensagem;

            listaCliente();
        }
    }
 }